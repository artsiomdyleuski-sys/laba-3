#pragma once
#include <string>
#include "Exception.cpp"
#include "Worker.cpp"
#include "Machine.cpp"

class Group {                       // 4 поля, 2 метода
    int id;
    std::string name;
    double sizeMb;
    int memberCount;
    std::string location;
public:
    Group(int i, const std::string& n, double a)
        : id(i), name(n), sizeMb(a), memberCount(0) {
    }
    void addMember() { memberCount++; }
    double sizePerMember() const { return memberCount ? sizeMb / memberCount : 0.0; }
};

class NewsFeed {                    // 3 поля, 2 метода
    int id;
    int capacity;
    int currentLoad;
public:
    NewsFeed(int i, int cap) : id(i), capacity(cap), currentLoad(0) {}
    void addLoad(int amount) {
        if (currentLoad + amount > capacity) throw InvalidPostException("overload");
        currentLoad += amount;
    }
    double utilization() const { return 100.0 * currentLoad / capacity; }
};

class Post {
    int id;
    std::string contentName;
    int quantity;
    std::string status;
    int groupId;
    std::string deadline;
public:
    Post(int i, const std::string& p, int q, int ws, const std::string& d = "Unknown")
        : id(i), contentName(p), quantity(q), status("draft"), groupId(ws), deadline(d) {
        if (q <= 0) throw InvalidPostException("quantity <= 0");
    }
    void start() {
        if (status != "draft") throw InvalidPostException("already started");
        status = "published";
    }
    void complete() {
        if (status != "published") throw InvalidPostException("not started");
        status = "archived";
    }
    double calculateCost(double costPerUnit) const { return quantity * costPerUnit; }
    bool isOverdue(const std::string& currentDate) const {
        return status != "archived" && currentDate > deadline;
    }
};

class ContentPlan {
    int id;
    int plannedPosts;
    int completedPosts;
public:
    ContentPlan(int i, int planned) : id(i), plannedPosts(planned), completedPosts(0) {}
    void completePost() { completedPosts++; }
    double efficiency() const { return plannedPosts ? 100.0 * completedPosts / plannedPosts : 0.0; }
};