#pragma once
#include <string>
#include "Exception.cpp"
#include "Material.cpp"    // MediaFile
#include "Part.cpp"        // Profile

class ContentCreator {
    int id;
    std::string name;
    double rating;
public:
    ContentCreator(int i, const std::string& n, double r) : id(i), name(n), rating(r) {}
    bool isPopular() const { return rating > 4.0; }
    void rate(double r) {
        if (r < 0 || r > 5) throw InvalidSubscriptionException("bad rating");
        rating = r;
    }
    void deactivate() {}
};

class Partnership {                 // 4 поля, 2 метода
    int id;
    int creatorId;
    double amount;
    bool signed_;
public:
    Partnership(int i, int cid, double a) : id(i), creatorId(cid), amount(a), signed_(false) {}
    void sign() { signed_ = true; }
    double calculatePenalty(double delayDays) const { return amount * 0.01 * delayDays; }
};

class ContentDelivery {             // 3 поля, 2 метода
    int id;
    double sizeMb;
    std::string status;
public:
    ContentDelivery(int i, double q) : id(i), sizeMb(q), status("pending") {}
    void receive() { status = "delivered"; }
    void checkSize(double expected) const {
        if (sizeMb < expected) throw ContentNotFoundException("delivery short");
    }
};

class Server {
    int id;
    double capacity;
    double currentLoad;
    bool active;
    std::string location;
public:
    Server(int i, double cap, const std::string& loc)
        : id(i), capacity(cap), currentLoad(0), active(true), location(loc) {
    }
    bool store(double amount) {
        if (currentLoad + amount > capacity) throw StorageLimitException("full");
        currentLoad += amount;
        return true;
    }
    void retrieve(double amount) {
        if (amount > currentLoad) throw StorageLimitException("empty");
        currentLoad -= amount;
    }
    double utilization() const { return 100.0 * currentLoad / capacity; }
    double freeSpace() const { return capacity - currentLoad; }
};

class Cache {                       // 3 поля, 2 метода
    int id;
    int profileId;
    int quantity;
public:
    Cache(int i, int pid, int q) : id(i), profileId(pid), quantity(q) {}
    void add(int q) { quantity += q; }
    void remove(int q) {
        if (q > quantity) throw StorageLimitException("not enough");
        quantity -= q;
    }
};