#include <iostream>
#include <string>

// Клас Address
class Address {
private:
    int index;
    std::string country;
    std::string city;
    std::string street;
    int house;
    int apartment;

public:
    Address(int idx, const std::string& c, const std::string& ct, const std::string& st, int h, int apt)
        : index(idx), country(c), city(ct), street(st), house(h), apartment(apt) {}

    int getIndex() const {
        return index;
    }

    void setIndex(int idx) {
        index = idx;
    }

    const std::string& getCountry() const {
        return country;
    }

    void setCountry(const std::string& c) {
        country = c;
    }

    const std::string& getCity() const {
        return city;
    }

    void setCity(const std::string& ct) {
        city = ct;
    }

    const std::string& getStreet() const {
        return street;
    }

    void setStreet(const std::string& st) {
        street = st;
    }

    int getHouse() const {
        return house;
    }

    void setHouse(int h) {
        house = h;
    }

    int getApartment() const {
        return apartment;
    }

    void setApartment(int apt) {
        apartment = apt;
    }
};

// Клас Converter
class Converter {
private:
    double usd;
    double eur;
    double pln;

public:
    Converter(double usd, double eur, double pln)
        : usd(usd), eur(eur), pln(pln) {}

    double convertToCurrency(double amount, const std::string& currency) const {
        if (currency == "USD")
            return amount / usd;
        else if (currency == "EUR")
            return amount / eur;
        else if (currency == "PLN")
            return amount / pln;
        else
            return 0.0;
    }

    double convertFromCurrency(double amount, const std::string& currency) const {
        if (currency == "USD")
            return amount * usd;
        else if (currency == "EUR")
            return amount * eur;
        else if (currency == "PLN")
            return amount * pln;
        else
            return 0.0;
    }
};

// Клас Employee
class Employee {
private:
    std::string lastName;
    std::string firstName;
    std::string position;
    int experience;

public:
    Employee(const std::string& last, const std::string& first)
        : lastName(last), firstName(first), position("Робітник"), experience(0) {}

    void calculateSalary() {
        double salary = 0.0;

        if (position == "Менеджер") {
            if (experience >= 5)
                salary = 50000.0;
            else
                salary = 40000.0;
        }
        else if (position == "Робітник") {
            if (experience >= 10)
                salary = 30000.0;
            else
                salary = 25000.0;
        }

        double tax = 0.1 * salary;

        std::cout << "Прізвище: " << lastName << std::endl;
        std::cout << "Ім'я: " << firstName << std::endl;
        std::cout << "Посада: " << position << std::endl;
        std::cout << "Оклад: " << salary << " грн" << std::endl;
        std::cout << "Податковий збір: " << tax << " грн" << std::endl;
    }

    void setPositionAndExperience(const std::string& pos, int exp) {
        position = pos;
        experience = exp;
    }
};

// Клас User
class User {
private:
    std::string login;
    std::string firstName;
    std::string lastName;
    int age;
    const std::string registrationDate;

public:
    User(const std::string& lg, const std::string& first, const std::string& last, int a)
        : login(lg), firstName(first), lastName(last), age(a), registrationDate(getCurrentDate()) {}

    // Метод для отримання поточної дати (просто для прикладу)
    std::string getCurrentDate() const {
        // Реалізацію отримання поточної дати можна додати за потребою
        return "2023-09-17";
    }

    void printUserInfo() const {
        std::cout << "Логін: " << login << std::endl;
        std::cout << "Ім'я: " << firstName << std::endl;
        std::cout << "Прізвище: " << lastName << std::endl;
        std::cout << "Вік: " << age << " років" << std::endl;
        std::cout << "Дата реєстрації: " << registrationDate << std::endl;
    }
};

int main() {
    // Приклад використання класів

    // Клас Address
    Address address(12345, "Україна", "Київ", "Вулиця Прикладна", 42, 10);
    std::cout << "Інформація про адресу:" << std::endl;
    std::cout << "Індекс: " << address.getIndex() << std::endl;
    std::cout << "Країна: " << address.getCountry() << std::endl;
    std::cout << "Місто: " << address.getCity() << std::endl;
    std::cout << "Вулиця: " << address.getStreet() << std::endl;
    std::cout << "Будинок: " << address.getHouse() << std::endl;
    std::cout << "Квартира: " << address.getApartment() << std::endl;

    // Клас Converter
    Converter converter(26.5, 31.2, 6.7);
    double amountInUah = 1000.0;
    double amountInUsd = converter.convertToCurrency(amountInUah, "USD");
    std::cout << amountInUah << " UAH = " << amountInUsd << " USD" << std::endl;
    double amountInUah2 = converter.convertFromCurrency(500.0, "USD");
    std::cout << "500 USD = " << amountInUah2 << " UAH" << std::endl;

    // Клас Employee
    Employee employee("Петров", "Іван");
    employee.setPositionAndExperience("Менеджер", 6);
    employee.calculateSalary();

    // Клас User
    User user("user123", "Іван", "Петров", 30);
    user.printUserInfo();

    return 0;
}