#include "Exception.cpp"
#include "Material.cpp"
#include "Part.cpp"
#include "Machine.cpp"
#include "Worker.cpp"
#include "Workshop.cpp"
#include "QualityControl.cpp"
#include "Logistics.cpp"
#include "Finance.cpp"
#include "Automation.cpp"
#include "Address.cpp"

#include <iostream>
#include <windows.h>

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    try {
        std::cout << "=== СОЦИАЛЬНАЯ СЕТЬ: СИМУЛЯЦИЯ ===\n\n";

        // ---------- МЕДИА ----------
        std::cout << "--- Медиафайлы ---\n";
        VideoFile video(1, 1000, 1080, 0.4);
        ImageFile image(2, 500, 24, true);
        AudioFile audio(3, 300, 48, true);

        std::cout << "Video: 1000 МБ, HD? " << (video.isHD() ? "да" : "нет") << "\n";
        std::cout << "Image: 500 МБ, Pro? " << (image.isProQuality() ? "да" : "нет") << "\n";
        std::cout << "Audio: 300 МБ, Studio? " << (audio.isStudioQuality() ? "да" : "нет") << "\n";

        // ---------- ПРОФИЛИ ----------
        std::cout << "--- Профили ---\n";
        FanProfile fan(101, "FanBoy", 5.2, 120, 0.45, 700, 60000);
        fan.validate();
        fan.markVerified();

        std::cout << "Fan: популярность = 5.2, верифицирован? "
            << (fan.isVerified() ? "да" : "нет") << "\n";
        std::cout << "  Сила влияния: " << fan.calculateEngagement(1000) << "\n";

        BusinessProfile business(102, "Company", 25.0, 800, 4, 220, true);
        std::cout << "Business: последователей = 220, влиятельный? "
            << (business.isInfluential() ? "да" : "нет") << "\n\n";

        // ---------- СЕРВЕРА ----------
        std::cout << "--- Серверные узлы ---\n";
        DatabaseNode db(1, "PostgreSQL", 15, 0.001, 3);
        db.start();
        db.logHours(8);
        std::cout << "DB: запущен, стоимость обслуживания: " << db.calculateMaintenanceCost() << "\n";

        AuthNode auth(2, "Auth", 8, 256);
        auth.enable2FA();
        auth.verifyConnection();
        std::cout << "Auth: 2FA включена, проверка пройдена\n";

        MediaNode media(3, "CDN", 30, 500, true);
        std::cout << "CDN: безопасен? " << (media.isSafe() ? "да" : "нет") << "\n";

        BackupNode backup(4, "Backup", 12, 50);
        backup.backup();
        backup.clean();
        std::cout << "Backup: бэкап сделан, очистка выполнена\n\n";

        // ---------- ПОЛЬЗОВАТЕЛИ ----------
        std::cout << "--- Пользователи ---\n";
        Moderator mod(1, "Mod_John", 500, 1, "Content", true);
        std::cout << "Модератор: рейтинг = " << mod.calculateRating() << "\n";
        std::cout << "  Может работать с Content? " << (mod.canAccess("Content") ? "да" : "нет") << "\n";
        std::cout << "  Может работать с Admin? " << (mod.canAccess("Admin") ? "да" : "нет") << "\n";

        Admin admin(2, "Admin_Anna", 1200, 1, "Super");
        std::cout << "Админ: рейтинг = " << admin.calculateRating() << "\n";

        Tester tester(3, "Tester_Oleg", 800, 1);
        tester.performCheck();
        tester.registerBug();
        std::cout << "Тестировщик: проверок = 1, багов = 1\n";

        SupportAgent support(4, "Support_Sergey", 700, 1);
        support.repair(db);
        std::cout << "Поддержка: перезапустил DB\n";

        Recruiter hr(5, "HR_Elena", 1000, 1);
        hr.hire();
        std::cout << "Рекрутер: нанял 1 сотрудника\n";

        SecurityAuditor sec(6, "Sec_Petr", 900, 1);
        sec.reportViolation();
        std::cout << "Аудитор: зафиксировал 1 нарушение\n\n";

        // ---------- ГРУППЫ ----------
        std::cout << "--- Группы и лента ---\n";
        Group group(1, "Gamers", 500);
        group.addMember();
        group.addMember();
        std::cout << "Группа Gamers: участников = 2, размер на участника: "
            << group.sizePerMember() << "\n";

        NewsFeed feed(1, 100);
        feed.addLoad(40);
        std::cout << "Лента: загрузка 40/100, загруженность = " << feed.utilization() << "%\n";

        Post post(1, "Gaming News", 500, 1, "2026-12-01");
        post.start();
        post.complete();
        std::cout << "Пост: завершён, стоимость = " << post.calculateCost(120) << "\n";

        ContentPlan plan(1, 1000);
        plan.completePost();
        std::cout << "Контент-план: выполнено 1 из 1000, эффективность = " << plan.efficiency() << "%\n\n";

        // ---------- МОДЕРАЦИЯ ----------
        std::cout << "--- Модерация ---\n";
        Moderation moderation(1, 101);
        moderation.pass();
        std::cout << "Модерация профиля #101: пройдена\n";

        Violation v(1, 101, "critical");
        std::cout << "Нарушение: критическое? " << (v.isCritical() ? "да" : "нет") << "\n";

        ModerationReport report(1, "Report");
        report.addViolation();
        std::cout << "Отчёт: нарушений = 1, есть нарушения? " << (report.hasViolations() ? "да" : "нет") << "\n";

        SecurityCheck check(1, 0, 1000, false);
        check.run(750);
        std::cout << "Проверка безопасности: 750 в пределах — пройдена\n\n";

        // ---------- ЛОГИСТИКА ----------
        std::cout << "--- Партнёрства и серверы ---\n";
        ContentCreator creator(1, "Blogger", 4.7);
        std::cout << "Создатель: рейтинг = 4.7, популярен? " << (creator.isPopular() ? "да" : "нет") << "\n";

        Partnership partner(1, 1, 100000);
        partner.sign();
        std::cout << "Партнёрство: подписано на 100000, штраф за 5 дней: "
            << partner.calculatePenalty(5) << "\n";

        ContentDelivery delivery(1, 500);
        delivery.receive();
        delivery.checkSize(400);
        std::cout << "Доставка: 500 МБ получено, проверка пройдена\n";

        Server server(1, 10000, "DataCenter A");
        server.store(500);
        std::cout << "Сервер: загружено 500, занято = " << server.utilization() << "%\n";
        server.retrieve(100);
        std::cout << "Сервер: выдано 100, свободно = " << server.freeSpace() << "\n";

        Cache cache(1, 101, 200);
        cache.add(50);
        cache.remove(30);
        std::cout << "Кэш: итог = 220\n\n";

        // ---------- ФИНАНСЫ ----------
        std::cout << "--- Финансы ---\n";
        Transaction pay(1, 5000);
        pay.process();
        std::cout << "Транзакция 5000: обработана? " << (pay.isProcessed() ? "да" : "нет") << "\n";

        PremiumSubscription prem(1, 1, 500);
        prem.addBonus(100);
        std::cout << "Премиум: итог = " << prem.calculateTotal() << "\n";

        AdInvoice invo(1, "INV-001", 25000);
        std::cout << "Счёт INV-001: налог 20% = " << invo.calculateTax(0.2) << "\n";

        Advertiser advertiser(1, "AdCorp", 100000);
        std::cout << "Рекламодатель: может купить на 50000? " << (advertiser.canBuyAd(50000) ? "да" : "нет") << "\n";

        AdCampaign campaign(1, 1, 5000);
        campaign.pause();
        std::cout << "Кампания: цена после скидки 10% = " << campaign.applyDiscount(10) << "\n";

        NetworkBudget budget(500000);
        budget.spend(100000);
        std::cout << "Бюджет сети: потрачено 100000, баланс = " << budget.balance() << "\n\n";

        // ---------- АНАЛИТИКА ----------
        std::cout << "--- Аналитика ---\n";
        Metric metric(1, 2.0);
        metric.update(1.5);
        std::cout << "Метрика: значение 1.5, цель 2.0, достигнута? " << (metric.isAchieved() ? "да" : "нет") << "\n";

        SpamRate spam(101);
        spam.addBatch(1000, 15);
        std::cout << "Процент спама: " << spam.compute() << "%\n";

        RecommendationSystem recs(1);
        recs.connect(mod);
        recs.goOnline();
        std::cout << "Рекомендации: онлайн, пользователей подключено = 1\n";

        EventLogger log("network.log");
        log.log();
        log.log();
        std::cout << "Логгер: записей = 2\n";

        Filter filter(1);
        filter.apply();
        std::cout << "Фильтр: применён 1 раз\n";

        ModerationLog modLog(1);
        modLog.addViolation();
        std::cout << "Лог модерации: нарушений = 1, есть нарушения? " << (modLog.hasViolations() ? "да" : "нет") << "\n";

        TimeSlot shift(1, "08:00");
        std::cout << "Время: 08:00, пик? " << (shift.isPeak() ? "да" : "нет") << "\n";

        Location addr("Berlin", "Germany", "10115");
        std::cout << "Локация: " << addr.full() << "\n\n";

        std::cout << "=== ВСЕ СИСТЕМЫ РАБОТАЮТ ШТАТНО ===\n";
    }
    catch (const NetworkException& e) {
        std::cerr << "!!! ОШИБКА: " << e.what() << "\n";
        return 1;
    }
    return 0;
}