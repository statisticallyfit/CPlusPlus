#include <iostream>
#include <string>
using namespace std;


class ScrollBar {

private:
    int size;               // related to constness
    mutable string owner;   // not relevant to constness

public:
    ScrollBar(int s, string o) : size(s), owner(o) {}

    void setSize(int s) { size = s; }
    void setOwner(string o) const { owner = o; }
    int getSize()           const { return size; }
    string getOwner()       const { return owner; }
};


int main() {

    // IMPORTANT: Object is declared const
    const ScrollBar bar(60, "Window1");

    //bar.setSize(100); // cannot do this to const obj
    bar.setOwner("Window2"); // this is ok since mutable

    cout << bar.getSize() << ", " << bar.getOwner() << endl;

    return 0;
}