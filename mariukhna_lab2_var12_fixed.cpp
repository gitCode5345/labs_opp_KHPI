#include <iostream>
#include <string>

using namespace std;

class Dish
{
public:
    Dish();
    Dish(string name, string ingradients, double price, double caloricValue);

    double GetPrice();
    void SetPrice(double price);

    string GetName();
    void SetName(string name);

    string GetIngredients();
    void SetIngredients(string ingredients);

    double GetCaloricValue();
    void SetCaloricValue(double calory);

    void ShowInformation(); 
    void CompareCaloric(Dish & otherDish);

private:
    double caloricValue;
    double price;
    string nameOfDish;
    string ingredients;
    
};

double Dish::GetPrice()
{
    return this->price;
}

void Dish::SetPrice(double price)
{
    this->price = price;
}

string Dish::GetName()
{
    return this->nameOfDish;
}

void Dish::SetName(string name)
{
    this->nameOfDish = name;
}

string Dish::GetIngredients()
{
    return this->ingredients;
}

void Dish::SetIngredients(string ingredients)
{
    this->ingredients = ingredients;
}

double Dish::GetCaloricValue()
{
    return this->caloricValue;
}

void Dish::SetCaloricValue(double calory)
{
    this->caloricValue = calory;
}

void Dish::ShowInformation()
{
    cout << "Information about the dish:" << endl;

    cout << "Name of the dish: " << this->nameOfDish
         << "Price: " << this->price << "$"
         << "Ingredients for the dish: "
         << "The number of calories: " << this->caloricValue << endl << endl;

}

Dish::Dish(string name, string ingredients, double price, double caloricValue)
{
    this->nameOfDish = name;
    this->ingredients = ingredients;
    this->price = price;
    this->caloricValue = caloricValue;
}

Dish::Dish()
{
    this->nameOfDish = "Name not specified";
    this->ingredients = "Ingredients are not specified";
    this->price = 0;
    this->caloricValue = 0;
}

void Dish::CompareCaloric(Dish & otherDish)
{
    cout << "Caloric of: " << this->nameOfDish;
    cout << " - " << this->caloricValue << endl;

    cout << "Caloric of: " << otherDish.nameOfDish;
    cout << " - " << otherDish.caloricValue << endl;

    if (this->caloricValue > otherDish.caloricValue)
        cout << "More calories in " << this->nameOfDish << " than in " << otherDish.nameOfDish << endl;

    if (this->caloricValue < otherDish.caloricValue)
        cout << "More calories in " << otherDish.nameOfDish << " than in " << this->nameOfDish << endl;

    else if(this->caloricValue == otherDish.caloricValue)
        cout << "Calories are equal in two dishes" << endl;
    
    cout << endl;
}

int main()
{
    Dish borsh("Borsh", "meat, potato, tomato, cabbage", 2.50, 1590);
    borsh.ShowInformation();

    Dish firedPotators("Fired potato", "Potato, oil", 3.90, 2576.80);

    firedPotators.CompareCaloric(borsh);

    return 0;
}
