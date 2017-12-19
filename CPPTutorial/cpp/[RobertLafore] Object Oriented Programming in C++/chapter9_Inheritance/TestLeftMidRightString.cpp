#include "../../../include/String.h"




int main()
{
    String s1 = "winged bird";
    s1.left(3).print();
    s1.right(4).print();

    String s2 = "the bright stars twinkled";
    s2.mid(11, 5).print();

    return 0;
}