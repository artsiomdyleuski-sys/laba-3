#pragma once
#include <string>
#include "Exception.cpp"

class ServerNode {
protected:
    int id;
    std::string name;
    double powerConsumption;
    bool operational;
    int uptimeHours;
    std::string model;
public:
    ServerNode(int i, const std::string& n, double pc, const std::string& m)
        : id(i), name(n), powerConsumption(pc), operational(true), uptimeHours(0), model(m) {
    }
    virtual ~ServerNode() = default;

    virtual void start() {
        if (!operational) throw ConnectionFailureException(name);
    }
    virtual double calculateMaintenanceCost() const { return uptimeHours * 0.5; }
    void logHours(int h) { uptimeHours += h; }
    void breakDown() { operational = false; throw ConnectionFailureException(name); }
    void repair() { operational = true; }
    bool isActive() const { return operational; }
};

class DatabaseNode : public ServerNode {
    double querySpeed;
    int tableCount;
public:
    DatabaseNode(int i, const std::string& n, double pc, double qs, int tc)
        : ServerNode(i, n, pc, "DB"), querySpeed(qs), tableCount(tc) {
    }
    double calculateMaintenanceCost() const override { return uptimeHours * 1.2 + tableCount * 50; }
};

class MediaNode : public ServerNode {
    double bandwidth;
    bool secure;
public:
    MediaNode(int i, const std::string& n, double pc, double bw, bool s)
        : ServerNode(i, n, pc, "Media"), bandwidth(bw), secure(s) {
    }
    bool isSafe() const { return secure; }
};

class AuthNode : public ServerNode {
    double encryptionLevel;
    bool twoFactor;
public:
    AuthNode(int i, const std::string& n, double pc, double el)
        : ServerNode(i, n, pc, "Auth"), encryptionLevel(el), twoFactor(false) {
    }
    void enable2FA() { twoFactor = true; }
    void verifyConnection() {
        if (!twoFactor) throw ConnectionFailureException("no 2FA");
    }
};

class BackupNode : public ServerNode {
    double storageVolume;
    int backupCount;
public:
    BackupNode(int i, const std::string& n, double pc, double sv)
        : ServerNode(i, n, pc, "Backup"), storageVolume(sv), backupCount(0) {
    }
    void backup() {
        if (storageVolume <= 0) throw StorageLimitException("no space");
        storageVolume -= 0.05;
        backupCount++;
    }
    void clean() { storageVolume += 10; }
};