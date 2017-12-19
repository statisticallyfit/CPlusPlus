#include <iostream>
using namespace std;





class Type
{
private:
    string dimensions;
    string grade;
public:
    Type() : dimensions("N/A"), grade("N/A")
    { }
    Type(string d, string g) : dimensions(d), grade(g)
    { }

    void getType() {
        cout << "\tEnter nominal dimensions (2x4 etc.): ";
        cin >> dimensions;
        cout << "\tEnter grade (rough, const, etc.): ";
        cin >> grade;
    }

    void showType() const {
        cout << "\n\tDimensions: " << dimensions;
        cout << "\n\tGrade: " << grade;
    }
};


class Distance
{
protected:
    int feet;
    float inches;
public:
    Distance() : feet(0), inches(0.0) { }
    Distance(int ft, float in) : feet(ft), inches(in) { }

    void getDist()
    {
        cout << "\tEnter feet: "; cin >> feet;
        cout << "\tEnter inches: "; cin >> inches;
    }

    void showDist() const
    {
        cout << feet << "\'-" << inches << '\"';
    }
};




class Lumber : public Type, public Distance
{
private:
    int quantity; //numpieces
    double price; // price of each piece

public:
    Lumber() : Type(), Distance(), quantity(0), price(0.0)
    { }
    Lumber(string d, string g, int ft, float in, int quant, float prc) :
            Type(d, g), Distance(ft, in), quantity(quant), price(prc)
    { }

    void getLumber(){
        Type::getType();
        Distance::getDist();
        cout << "\tEnter quantity: "; cin >> quantity;
        cout << "\tEnter price per piece: "; cin >> price;
    }

    void showLumber() const {
        Type::showType();
        cout << "\n\tLength: ";
        Distance::showDist();
        cout << "\n\tPrice for " << quantity <<
                " pieces: $" << price * quantity;
    }
};




int main()
{
    Lumber siding;

    cout << "\nSiding data:\n";
    siding.getLumber();

    Lumber studs("2x4", "const", 8, 0.0, 200, 4.45F);

    cout << "\nSiding"; siding.showLumber();
    cout << "\nStuds";  studs.showLumber();
    cout << endl;

    return 0;
}