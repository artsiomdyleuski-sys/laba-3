#pragma once
#include <string>
#include "Exception.cpp"
#include "Material.cpp"    // mediaType

class Profile {
protected:
    int id;
    std::string name;
    double popularity;
    double value;
    bool verified;
    std::string mediaType;
public:
    Profile(int i, const std::string& n, double w, double c, const std::string& mat = "Unknown")
        : id(i), name(n), popularity(w), value(c), verified(false), mediaType(mat) {
    }
    virtual ~Profile() = default;

    virtual double calculateValue() const { return value; }
    virtual bool validate() const {
        if (name.empty() || popularity < 0) throw InvalidUserDataException("bad fields");
        return true;
    }
    void markVerified() { verified = true; }
    bool isVerified() const { return verified; }
};

class BusinessProfile : public Profile {
    int employeeCount;
    int followers;
    bool promoted;
public:
    BusinessProfile(int i, const std::string& n, double w, double c, int cc, int po, bool tb)
        : Profile(i, n, w, c), employeeCount(cc), followers(po), promoted(tb) {
    }
    bool isInfluential() const { return followers > 10000 && promoted; }
};

class InfluencerProfile : public Profile {
    int postCount;
    double engagementRate;
    bool partner;
public:
    InfluencerProfile(int i, const std::string& n, double w, double c, int gc, double tc, bool s)
        : Profile(i, n, w, c), postCount(gc), engagementRate(tc), partner(s) {
    }
    bool canMonetize(double t) const { return t <= engagementRate; }
};

class FanProfile : public Profile {
    double loyaltyScore;
    double spendLimit;
    int lifespanDays;
public:
    FanProfile(int i, const std::string& n, double w, double c, double fc, double mt, int life)
        : Profile(i, n, w, c), loyaltyScore(fc), spendLimit(mt), lifespanDays(life) {
    }
    double calculateEngagement(double pressure) const { return pressure * loyaltyScore; }
    bool needsReactivation(int days) const { return days >= lifespanDays; }
};

class PrivateProfile : public Profile {
    double privacyLevel;
    double followersCount;
public:
    PrivateProfile(int i, const std::string& n, double w, double c, double s, double lc)
        : Profile(i, n, w, c), privacyLevel(s), followersCount(lc) {
    }
    bool canFollow(double weight) const { return weight <= followersCount; }
};

class VerifiedProfile : public Profile {
    double trustScore;
    double reach;
    bool official;
public:
    VerifiedProfile(int i, const std::string& n, double w, double c, double v, double cur, bool wp)
        : Profile(i, n, w, c), trustScore(v), reach(cur), official(wp) {
    }
    double calculateInfluence() const { return reach / trustScore; }
    bool isSafe() const { return trustScore > 0.8 && official; }
};