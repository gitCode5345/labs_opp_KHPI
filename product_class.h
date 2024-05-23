#ifndef PRODUCT_CLASS_H
#define PRODUCT_CLASS_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Product
{
public:
    Product();
    Product(int quantity);
    Product(int quantity, int productCode);
    Product(int quantity, int productCode, double price);
    Product(int quantity, int productCode, double price, string supplier);
    Product(int quantity, int productCode, double price, string supplier, string countryOrigin);
    Product(int quantity, int productCode, double price, string supplier, string countryOrigin, string productName);
    ~Product();

    void SetQuantity(int quantity);
    int GetQuantity();

    void SetProductCode(int productCode);
    int GetProductCode();

    void SetPrice(double price);
    double GetPrice();

    void SetSupplier(const string &supplier);
    const string &GetSupplier();

    void SetProductName(const string &productName);
    const string &GetProductName();

    void SetCountryOrigin(const string &countryOrigin);
    const string &GetCountryOrigin();

    void ShowInformationProduct();
    friend void StartWorkWithMassive(vector<Product> &products);
    void ComparePrice(const Product &other);
    void FindExpensiveProduct(const vector<Product> &other);

private:
    int quantity;
    int productCode;
    double price;
    string supplier;
    string productName;
    string countryOrigin;
};

#endif
