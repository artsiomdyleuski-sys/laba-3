#pragma once
#include <string>
#include "Exception.cpp"
#include "Machine.cpp"     // Admin::check(ServerNode&)

class User {
protected:
    int id;
    std::string userName;
    double reputation;
    bool active;
    int groupId;
    int accountAge;
public:
    User(int i, const std::string& n, double s, int ws, int exp = 0)
        : id(i), userName(n), reputation(s), active(true), groupId(ws), accountAge(exp) {
    }
    virtual ~User() = default;

    virtual double calculateRating() const { return reputation; }
    virtual bool canAccess(const std::string&) const {
        if (!active) throw AccountBannedException(userName);
        return true;
    }
    void setActive(bool a) { active = a; }
    bool isActive() const { return active; }
    void giveBonus(double percent) {
        if (percent < 0) throw InvalidUserDataException("bad bonus");
        reputation *= (1 + percent / 100.0);
    }
};

class Moderator : public User {
    std::string role;
    bool certified;
public:
    Moderator(int i, const std::string& n, double s, int ws, const std::string& mt, bool c)
        : User(i, n, s, ws), role(mt), certified(c) {
    }
    bool canAccess(const std::string& type) const override {
        if (!active) throw AccountBannedException(userName);
        return type == role && certified;
    }
};

class Admin : public User {
    std::string level;
    int actionsDone;
public:
    Admin(int i, const std::string& n, double s, int ws, const std::string& sp)
        : User(i, n, s, ws), level(sp), actionsDone(0) {
    }
    double calculateRating() const override { return reputation + actionsDone * 500; }
};

class Tester : public User {
    int checksDone;
    int bugsFound;
public:
    Tester(int i, const std::string& n, double s, int ws)
        : User(i, n, s, ws), checksDone(0), bugsFound(0) {
    }
    void performCheck() { checksDone++; }
    void registerBug() {
        bugsFound++;
        if (bugsFound > 100) throw SpamLimitExceededException("too many");
    }
};

class SupportAgent : public User {
    int ticketsClosed;
public:
    SupportAgent(int i, const std::string& n, double s, int ws)
        : User(i, n, s, ws), ticketsClosed(0) {
    }
    void repair(ServerNode& m) { m.start(); ticketsClosed++; }
};

class Recruiter : public User {
    int hiredCount;
public:
    Recruiter(int i, const std::string& n, double s, int ws)
        : User(i, n, s, ws), hiredCount(0) {
    }
    void hire() { hiredCount++; }
};

class SecurityAuditor : public User {
    int violationsFound;
public:
    SecurityAuditor(int i, const std::string& n, double s, int ws)
        : User(i, n, s, ws), violationsFound(0) {
    }
    void reportViolation() {
        violationsFound++;
        if (violationsFound > 20) throw NetworkException("too many violations");
    }
};