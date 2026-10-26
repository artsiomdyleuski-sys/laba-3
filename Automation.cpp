#pragma once
#include <string>
#include "Exception.cpp"   // ConnectionFailureException
#include "Machine.cpp"     // connect(Server&)
#include "Worker.cpp"
class Metric {                      // 3 поля, 2 метода
    int id;
    double value;
    double target;
public:
    Metric(int i, double t) : id(i), value(0), target(t) {}
    void update(double v) { value = v; }
    bool isAchieved() const { return value >= target; }
};

class SpamRate {                    // 3 поля, 2 метода
    int userId;
    int totalPosts;
    int spamPosts;
public:
    SpamRate(int uid) : userId(uid), totalPosts(0), spamPosts(0) {}
    void addBatch(int total, int spam) {
        if (spam > total) throw SpamLimitExceededException("spam > total");
        totalPosts += total; spamPosts += spam;
    }
    double compute() const { return totalPosts ? 100.0 * spamPosts / totalPosts : 0.0; }
};

class RecommendationSystem {        // 3 поля, 2 метода
    int id;
    bool online;
    int connectedUsers;
public:
    RecommendationSystem(int i) : id(i), online(false), connectedUsers(0) {}
    void connect(User& u) {
        if (!u.isActive()) throw UserNotAvailableException("offline");
        connectedUsers++;
    }
    void goOnline() { online = true; }
};

class EventLogger {                 // 2 поля, 2 метода
    std::string fileName;
    int entries;
public:
    EventLogger(const std::string& f) : fileName(f), entries(0) {}
    void log() { entries++; }
    bool isVerbose() const { return entries > 1000; }
};