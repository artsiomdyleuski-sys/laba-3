#pragma once
#include <string>
#include "Exception.cpp"
#include "Part.cpp"        // Moderation → Profile

class Moderation {
    int id;
    int profileId;
    bool passed;
    int violationsFound;
public:
    Moderation(int i, int pid) : id(i), profileId(pid), passed(false), violationsFound(0) {}
    void registerViolation() {
        violationsFound++;
        if (violationsFound > 50) throw SpamLimitExceededException("too many");
    }
    void pass() { passed = true; }
    void fail() { throw ModerationFailedException("profile " + std::to_string(profileId)); }
};

class Violation {
    int id;
    int profileId;
    std::string severity;
public:
    Violation(int i, int pid, const std::string& s) : id(i), profileId(pid), severity(s) {}
    bool isCritical() const { return severity == "critical"; }
    void escalate() { severity = "critical"; }
};

class ModerationReport {
    int id;
    std::string title;
    int violationCount;
public:
    ModerationReport(int i, const std::string& t) : id(i), title(t), violationCount(0) {}
    void addViolation() { violationCount++; }
    bool hasViolations() const { return violationCount > 0; }
};

class Check {
protected:
    int id;
    double minAcceptable;
    double maxAcceptable;
public:
    Check(int i, double mn, double mx) : id(i), minAcceptable(mn), maxAcceptable(mx) {}
    virtual ~Check() = default;
    virtual bool run(double v) {
        if (v < minAcceptable || v > maxAcceptable) {
            throw ModerationFailedException("check failed");
        }
        return true;
    }
};

class SecurityCheck : public Check {
    bool strictMode;
public:
    SecurityCheck(int i, double mn, double mx, bool d) : Check(i, mn, mx), strictMode(d) {}
    bool isStrict() const { return strictMode; }
};