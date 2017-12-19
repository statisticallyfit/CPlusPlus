#include <iostream>
#include <string>

using namespace std;


class Line {

private:
    double length;

public:
    Line(double len) {
        length = len;
    }

    void setLength(double len) {
        length = len;
    }

    double getLength() {
        return length;
    }
};



int main() {

    Line line(10.0);

    cout << "Length of line: " << line.getLength() << endl;
    line.setLength(6.3);
    cout << "Length of line: " << line.getLength() << endl;

    return 0;
}