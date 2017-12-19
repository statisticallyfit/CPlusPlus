#include <iostream>
using namespace std;

namespace foo {
    int value(){
        return 5;
    }
}

namespace bar {
    const double pi = 3.1416;
    double value() {
        return 2*pi;
    }
}

namespace foo {
    const int constant = 1010;
}

namespace other {
    double sigma = 6;
    double e = 2.71828;
}

namespace first {
    int x = 5;
}

namespace second {
    double x = 3.14159;
}


namespace aliasOne {
    int omega = 555;
}
namespace aliasTwo {
    int alpha = 444;
}

int main() {
    using foo::constant;
    using bar::value;
    using namespace other;

    cout << foo::value() << "\n";
    cout << bar::value() << "\n";
    cout << value() << "\n"; //bar's value()
    cout << bar::pi << "\n";
    cout << foo::constant << "\n";
    cout << constant << "\n";

    cout << sigma << "\n";
    cout << e << "\n";

    {
        using namespace first;
        cout << x << "\n";
    }
    {
        using namespace second;
        cout << x << "\n";
    }

    cout << aliasOne::omega << "\n";
    cout << aliasTwo::alpha << "\n";

    namespace newAliasOne = aliasOne;

    cout << newAliasOne::omega << "\n";

    return 0;
}