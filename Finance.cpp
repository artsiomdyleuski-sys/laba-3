#pragma once
#include <string>
#include "Exception.cpp"
#include "Worker.cpp"      // PremiumSubscription → User
#include "Part.cpp"        // Transaction → Post

class Transaction {                 // 3 поля, 2 метода
    int id;
    double amount;
    std::string status;
public:
    Transaction(int i, double a) : id(i), amount(a), status("pending") {}
    void process() {
        if (amount <= 0) throw InvalidSubscriptionException("bad amount");
        status = "processed";
    }
    bool isProcessed() const { return status == "processed"; }
};

class PremiumSubscription {         // 3 поля, 2 метода
    int id;
    int userId = 0;
    double base;
    double bonus;
public:
    PremiumSubscription(int i, double b, int bonus) : id(i), base(b), bonus(0) {}
    void addBonus(double b) { bonus += b; }
    double calculateTotal() const { return base + bonus; }
};

class AdInvoice {                   // 3 поля, 2 метода
    int id;
    double amount;
    int postId = 0;
    std::string number;
public:
    AdInvoice(int i, const std::string& n, double a) : id(i), number(n), amount(a) {}
    double calculateTax(double rate) const { return amount * rate; }
    bool isLarge() const { return amount > 10000; }
};

class Advertiser {
    int id;
    std::string name;
    double budgetLimit;
public:
    Advertiser(int i, const std::string& n, double bl) : id(i), name(n), budgetLimit(bl) {}
    bool canBuyAd(double amount) const { return amount <= budgetLimit; }
    void increaseLimit(double amount) { budgetLimit += amount; }
    void deactivate() {}
};

class AdCampaign {
    int id;
    int advertiserId;
    double totalSpent;
    std::string status;
public:
    AdCampaign(int i, int aid, double p) : id(i), advertiserId(aid), totalSpent(p), status("active") {}
    void pause() { status = "paused"; }
    double applyDiscount(double percent) {
        if (percent < 0 || percent > 50) throw InvalidSubscriptionException("bad discount");
        totalSpent *= (1 - percent / 100.0);
        return totalSpent;
    }
    bool isFinished() const { return status == "finished"; }
};

class NetworkBudget {               // 3 поля, 2 метода
    double budget;
    double spent;
    double income;
public:
    NetworkBudget(double b) : budget(b), spent(0), income(0) {}
    bool spend(double amount) {
        if (spent + amount > budget) throw NetworkException("over budget");
        spent += amount;
        return true;
    }
    double balance() const { return income - spent; }
};