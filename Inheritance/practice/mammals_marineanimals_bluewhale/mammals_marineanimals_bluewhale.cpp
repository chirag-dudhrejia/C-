#include <iostream>
using namespace std;

class Mammals
{
protected:
    bool is_mammal;
public:
    Mammals(){}
    Mammals(bool a): is_mammal(a){}
    void print()
    {
        cout<<"I'm Mammal.\n";
    }
};

class Marine_animals
{
protected:
    bool is_marine;
public:
    Marine_animals(){}
    Marine_animals(bool a): is_marine(a){}
    void print()
    {
        cout<<"I'm Marine Animal.\n";
    }
};

class Blue_Whale: public Mammals, public Marine_animals
{
public:
    Blue_Whale(): Mammals(true), Marine_animals(true) {}
    void print()
    {
        if (is_mammal)
        {
            Mammals::print();
        }
        
        if (is_marine)
        {
            Marine_animals::print();
        }
        
        cout<<"I belong to both the categories: Mammals as well as Marine Animals.\n";
    }
};

int main()
{
    Blue_Whale bluewhale;
    Mammals mammal;
    Marine_animals marine;

    cout<<"Mammal object called.\n";
    mammal.print();
    cout<<"\nMarine object called.\n";
    marine.print();
    cout<<"\nBlueWhale object called.\n";
    bluewhale.print();


    return 0;
}