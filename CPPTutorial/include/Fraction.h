#ifndef FRACTION_CLASS_H
#define FRACTION_CLASS_H


#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;


class Fraction {

private:
    int num;
    int denom;

    int GCD(int a, int b) const
    {
        a = abs(a); b = abs(b);
        if (b == 0)
            return a;
        return GCD(b, a % b);
    }

    int LCM(int a, int b) const
    {
        a = abs(a); b = abs(b);
        int c = a * b;
        while (a != b) {
            if (a > b)
                a -= b;
            else
                b -= a;
        }
        return (c / a);
    }

public:
    /** Constructor */
    Fraction() : num(0), denom(0)
    {}
    Fraction(int n, int d)
    {
        num = n;
        denom = d;
    }
    void setNum(int n) { num = n; }
    void setDenom(int d) {denom = d; }
    void setFraction(int n, int d) { num = n; denom = d; }
    int getNum() const { return num; }
    int getDenom() const { return denom; }

    string toString(){
        string n = to_string(getNum());
        string d = to_string(getDenom());
        string fracStr = n;
        fracStr.append("/");
        fracStr.append(d);
        return fracStr;
    }

    Fraction simplify() const
    {
        int n = getNum();
        int d = getDenom();

        int gcd = GCD(n, d);
        Fraction fraction(n / gcd, d / gcd);

        return fraction;
    }

    Fraction add(Fraction other, bool print) const
    {
        // convert to same denominator
        int lcm = LCM(getDenom(), other.getDenom());
        int m1 = lcm / getDenom();
        int m2 = lcm / other.getDenom();

        if (print)
            write(m1, getNum(), m2, other.getNum(), getDenom(), other.getDenom(), lcm, true);
        Fraction answer(m1 * getNum() + m2 * other.getNum(), lcm);

        return answer.simplify();
    }

    void addAcumulatively(Fraction other)
    {
        // convert to same denominator
        int lcm = LCM(getDenom(), other.getDenom());
        int m1 = lcm / getDenom();
        int m2 = lcm / other.getDenom();

        num = m1 * getNum() + m2 * other.getNum();
        denom = lcm;
    }

    Fraction subtract(Fraction other) const
    {
        // convert to same denominator
        int lcm = LCM(getDenom(), other.getDenom());
        int m1 = lcm / getDenom();
        int m2 = lcm / other.getDenom();

        write(m1, getNum(), m2, other.getNum(), getDenom(), other.getDenom(), lcm, false);
        Fraction answer(m1 * getNum() - m2 * other.getNum(), lcm);

        return answer.simplify();
    }

    Fraction multiply(Fraction other, bool print) const
    {
        int newNum = getNum() * other.getNum();
        int newDenom = getDenom() * other.getDenom();

        if (print)
            write(getNum(), other.getNum(), getDenom(), other.getDenom(), true);
        Fraction answer(newNum, newDenom);

        return answer.simplify();
    }

    Fraction divide(Fraction other) const
    {
        int newNum = getNum() * other.getDenom();
        int newDenom = getDenom() * other.getNum();

        write(getNum(), other.getNum(), getDenom(), other.getDenom(), false);
        Fraction answer(newNum, newDenom);

        return answer.simplify();
    }

    Fraction divide(int number) const
    {
        Fraction other(number, 1);

        int newNum = getNum() * other.getDenom();
        int newDenom = getDenom() * other.getNum();

        //write(getNum(), other.getNum(), getDenom(), other.getDenom(), false);
        Fraction answer(newNum, newDenom);

        return answer.simplify();
    }


    /** Pretty print add and subtract */
    void write(int m1, int n1, int m2, int n2, int d1, int d2, int lcm, bool add) const
    {
        string sign = (add) ? " + " : " - ";

        cout << "\n\t = " << n1 << "/" << d1 << sign << n2 << "/" << d2;
        cout << "\n\t = [" << m1 << "(" << n1 << ")"
        << sign << m2 << "(" << n2 << ")" << "]"
        << " / " << lcm;
        cout << "\n\t = " << "(" << m1 * n1 << sign << m2 * n2
        << ") / " << lcm
        << "\n\t = ";
    }

    /** Pretty print multiply and divide */
    void write(int n1, int n2, int d1, int d2, bool multiply) const
    {
        if (multiply){
            cout << "\n\t = (" << n1 << "/" << d1 << ") * ("
            << n2 << "/" << d2 << ")";
            cout << "\n\t = (" << n1 << "*" << n2 << ") / ("
            << d1 << "*" << d2 << ")";
            cout << "\n\t = ";
        } else {
            cout << "\n\t = (" << n1 << "/" << d1 << ") / ("
            << n2 << "/" << d2 << ")";
            cout << "\n\t = (" << n1 << "*" << d2 << ") / ("
            << d1 << "*" << n2 << ")";
            cout << "\n\t = ";
        }
    }

    void show() const
    {
        if (getNum() == 0)
            cout << "0" << endl;
        else if (getDenom() == 1)
            cout << getNum() << endl;
        else
            cout << getNum() << "/" << getDenom() << endl;
    }
};


#endif // FRACTION_CLASS_H