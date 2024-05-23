#include <iostream>
#include <string>
#include <vector>
#include "product_class.cpp"

using namespace std;

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
