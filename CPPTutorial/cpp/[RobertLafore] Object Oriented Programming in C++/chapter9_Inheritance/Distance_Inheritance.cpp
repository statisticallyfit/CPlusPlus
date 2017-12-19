#include <iostream>
using namespace std;


enum POSNEG { pos, neg};


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
        cout << "\nEnter feet: "; cin >> feet;
        cout << "Enter inches: "; cin >> inches;
    }

    void showDist() const
    {
        cout << feet << "\'-" << inches << '\"';
    }
};


class DistSigned : public Distance
{
private:
    POSNEG sign;
public:
    DistSigned() : Distance()
    {
        sign = pos;
    }
    DistSigned(int ft, float in, POSNEG sg=pos) :
            Distance(ft, in)
    {
        sign = sg;
    }

    void getDist()
    {
        Distance::getDist();
        char c;
        cout << "Enter sign (+ or -): "; cin >> c;
        sign = (c == '+') ? pos : neg;
    }

    void showDist() const
    {
        cout << ( (sign == pos) ? "(+)" : "(-)");
        Distance::showDist();
    }
};


int main()
{
    DistSigned alpha;
    alpha.getDist();

    DistSigned beta(11, 6.25);

    DistSigned gamma(100, 5.5, neg);

    cout << "\nalpha = "; alpha.showDist();
    cout << "\nbeta = "; beta.showDist();
    cout << "\ngamma = "; gamma.showDist();
    cout << endl;

    return 0;
}