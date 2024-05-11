#include <iostream>
#include <string>
#include <vector>

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

void Product::SetQuantity(int quantity)
{
    this->quantity = quantity;
}

int Product::GetQuantity()
{
    return quantity;
}

void Product::SetProductCode(int productCode)
{
    this->productCode = productCode;
}

int Product::GetProductCode()
{
    return productCode;
}

void Product::SetPrice(double price)
{
    this->price = price;
}

double Product::GetPrice()
{
    return price;
}

void Product::SetSupplier(const string &supplier)
{
    this->supplier = supplier;
}

const string &Product::GetSupplier()
{
    return supplier;
}

void Product::SetProductName(const string &productName)
{
    this->productName = productName;
}

const string &Product::GetProductName()
{
    return productName;
}

void Product::SetCountryOrigin(const string &countryOrigin)
{
    this->countryOrigin = countryOrigin;
}

const string &Product::GetCountryOrigin()
{
    return countryOrigin;
}

Product::Product()
{
    cout << "The default constructor is called" << endl;

    this->quantity = 0;
    this->productCode = 0;
    this->price = 0;
    this->supplier = "Not specified";
    this->productName = "Not specified";
    this->countryOrigin = "Not specified";
}

Product::Product(int quantity) : productCode(0), price(0), supplier("Not specified"), productName("Not specified"), countryOrigin("Not specified")
{
    cout << "The first constructor is called" << endl;

    this->quantity = quantity;
}

Product::Product(int quantity, int productCode) : Product(quantity)
{
    cout << "The second constructor is called" << endl;

    this->productCode = productCode;
}

Product::Product(int quantity, int productCode, double price) : Product(quantity, productCode)
{
    cout << "The third constructor is called" << endl;

    this->price = price;
}

Product::Product(int quantity, int productCode, double price, string supplier) : Product(quantity, productCode, price)
{
    cout << "The fourth constructor is called" << endl;

    this->supplier = supplier;
}

Product::Product(int quantity, int productCode, double price, string supplier, string countryOrigin) : Product(quantity, productCode, price, supplier)
{
    cout << "The fifth constructor is called" << endl;

    this->countryOrigin = countryOrigin;
}

Product::Product(int quantity, int productCode, double price, string supplier, string countryOrigin, string productName)
{
    cout << "The sixthp constructor is called" << endl;

    this->quantity = quantity;
    this->productCode = productCode;
    this->price = price;
    this->supplier = supplier;
    this->countryOrigin = countryOrigin;
    this->productName = productName;
}

Product::~Product()
{
    cout << "The destructor is called" << endl;
}

void Product::ShowInformationProduct()
{
    cout << "Product information:" << endl;
    cout << "Product name: " << this->productName << endl;
    cout << "Product code: " << this->productCode << endl;
    cout << "Supplier: " << this->supplier << endl;
    cout << "Price: " << this->price << endl;
    cout << "Country of origin: " << this->countryOrigin << endl;
    cout << "Quantity: " << this->quantity << endl;

    cout << endl;
}

void StartWorkWithMassive(vector<Product> &products)
{
    int size = 0;
    cout << "Hello! To start working with an array, you need to enter its size" << endl;

    while (size <= 0)
    {
        cin >> size;
        if (size <= 0)
        {
            cout << "Sorry, but you must enter a number greater than zero" << endl;
        }
    }

    for (int i = 0; i < size; i++)
    {
        products.push_back(Product());
    }

    for (int i = 0; i < size; i++)
    {
        cout << "Enter product information for number " << i + 1 << ":" << endl;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Product name: ";
        getline(cin, products[i].productName);

        cout << "Country of origin: ";
        getline(cin, products[i].countryOrigin);

        cout << "Supplier: ";
        getline(cin, products[i].supplier);

        cout << "Product code: ";
        cin >> products[i].productCode;

        cout << "Price: ";
        cin >> products[i].price;

        cout << "Quantity: ";
        cin >> products[i].quantity;

        cout << endl;
    }
}

void Product::ComparePrice(const Product &other)
{
    cout << "Price of: " << this->productName;
    cout << " - " << this->price << endl;

    cout << "Price of: " << other.productName;
    cout << " - " << other.price << endl;

    if (this->price > other.price)
    {
        cout << "The price is higher " << this->productName << " than in " << other.productName << endl;
    }
    if (this->price < other.price)
    {
        cout << "The price is higher " << other.price << " than in " << this->price << endl;
    }
    else if (this->price == other.price)
    {
        cout << "The price is the same for both products" << endl;
    }

    cout << endl;
}

void Product::FindExpensiveProduct(const vector<Product> &other)
{
    string nameProd = "";
    double priceProd;

    if (other.size() == 1)
    {
        cout << "There is only one product in the list, so: " << other[0].price << " is the most expensive" << endl;
        return;
    }

    double maxPrice = other[0].price;

    for (int i = 0; i < other.size(); i++)
    {
        if (maxPrice < other[i].price)
        {
            maxPrice = other[i].price;
            nameProd = other[i].productName;
            priceProd = other[i].price;
        }
    }

    cout << "The most expensive product:" << "\nName: " << nameProd << "\nPrice: " << priceProd << endl;
}

int main()
{
    Product a(10, 4540454, 2.50, "Golden", "Ukraine", "Golden Apple");
    a.ShowInformationProduct();

    vector<Product> products;
    StartWorkWithMassive(products);

    products[0].ComparePrice(products[1]);
    products[1].ShowInformationProduct();
    products[0].FindExpensiveProduct(products);

    return 0;
}
