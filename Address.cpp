#pragma once
#include <string>

class Location {                    // 3 поля, 1 метод
    std::string city;
    std::string country;
    std::string zip;
public:
    Location(const std::string& c, const std::string& co, const std::string& z)
        : city(c), country(co), zip(z) {
    }
    std::string full() const { return country + ", " + city + " " + zip; }
};

class TimeSlot {                    // 3 поля, 1 метод
    int id;
    std::string startTime;
    int activeUsers;
public:
    TimeSlot(int i, const std::string& s) : id(i), startTime(s), activeUsers(0) {}
    bool isPeak() const { return startTime > "18:00" && startTime < "23:00"; }
};

class Filter {                      // 3 поля, 1 метод
    int id;
    int usesCount;
    bool active;
public:
    Filter(int i) : id(i), usesCount(0), active(true) {}
    void apply() {
        usesCount++;
        if (usesCount > 10000) active = false;
    }
};

class ModerationLog {               // 3 поля, 2 метода
    int id;
    int postId = 0;
    int violations;
    bool closed;
public:
    ModerationLog(int i) : id(i), violations(0), closed(false) {}
    void addViolation() { violations++; }
    bool hasViolations() const { return violations > 0; }
};