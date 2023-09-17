#include <iostream>
#include <string>
using namespace std;

class Address {
private:
    int index;
    string country;
    string city;
    string street;
    string house;
    string apartment;

public:
    Address(int idx, const string& cntry, const string& cty, const string& st, const string& hse, const string& apt) {
        index = idx;
        country = cntry;
        city = cty;
        street = st;
        house = hse;
        apartment = apt;
    }

    int getIndex() {
        return index;
    }

    void setIndex(int idx) {
        index = idx;
    }

    string getCountry() {
        return country;
    }

    void setCountry(const string& cntry) {
        country = cntry;
    }

    string getCity() {
        return city;
    }

    void setCity(const string& cty) {
        city = cty;
    }

    string getStreet() {
        return street;
    }

    void setStreet(const string& st) {
        street = st;
    }

    string getHouse() {
        return house;
    }

    void setHouse(const string& hse) {
        house = hse;
    }

    string getApartment() {
        return apartment;
    }

    void setApartment(const string& apt) {
        apartment = apt;
    }
};

class Converter {
private:
    double usdRate;
    double eurRate;
    double plnRate;

public:
    Converter(double usd, double eur, double pln) {
        usdRate = usd;
        eurRate = eur;
        plnRate = pln;
    }

    double convertToCurrency(double amount, const string& currency) {
        if (currency == "USD") {
            return amount / usdRate;
        }
        else if (currency == "EUR") {
            return amount / eurRate;
        }
        else if (currency == "PLN") {
            return amount / plnRate;
        }
        else {
            cout << "Непідтримувана валюта: " << currency << endl;
            return 0.0;
        }
    }

    double convertFromCurrency(double amount, const string& currency) {
        if (currency == "USD") {
            return amount * usdRate;
        }
        else if (currency == "EUR") {
            return amount * eurRate;
        }
        else if (currency == "PLN") {
            return amount * plnRate;
        }
        else {
            cout << "Непідтримувана валюта: " << currency << endl;
            return 0.0;
        }
    }
};

int main() {
    // Створення екземпляру класу Address з встановленою адресою
    Address myAddress(12345, "Україна", "Київ", "Головна вулиця", "10", "42");

    // Виведення на екран значень полів, що описують адресу
    cout << "Index: " << myAddress.getIndex() << endl;
    cout << "Country: " << myAddress.getCountry() << endl;
    cout << "City: " << myAddress.getCity() << endl;
    cout << "Street: " << myAddress.getStreet() << endl;
    cout << "House: " << myAddress.getHouse() << endl;
    cout << "Apartment: " << myAddress.getApartment() << endl;

    // Ініціалізуємо об'єкт класу Converter з курсами валют
    Converter converter(36.5, 40.5, 8.5);

    // Конвертація з гривні в інші валюти
    double amountInUah = 1000.0;
    cout << amountInUah << " грн = " << converter.convertToCurrency(amountInUah, "USD") << " USD" << endl;
    cout << amountInUah << " грн = " << converter.convertToCurrency(amountInUah, "EUR") << " EUR" << endl;
    cout << amountInUah << " грн = " << converter.convertToCurrency(amountInUah, "PLN") << " PLN" << endl;

    // Конвертація з інших валют в гривню
    double amountInUsd = 100.0;
    cout << amountInUsd << " USD = " << converter.convertFromCurrency(amountInUsd, "UAH") << " грн" << endl;
    double amountInEur = 50.0;
    cout << amountInEur << " EUR = " << converter.convertFromCurrency(amountInEur, "UAH") << " грн" << endl;
    double amountInPln = 200.0;
    cout << amountInPln << " PLN = " << converter.convertFromCurrency(amountInPln, "UAH") << " грн" << endl;

    return 0;
}
