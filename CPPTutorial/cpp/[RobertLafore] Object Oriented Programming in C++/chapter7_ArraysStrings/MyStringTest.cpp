#include "../../../include/String.h"



int main()
{
    String s1 = "sandy";
    String s2 = " beach";

    cout << "Test '+': ";
    String s3 = s1 + s2;
    s3.print();

    cout << "Test concat: ";
    s1.concat(s2);
    s1.print();
    s1 = "sandy";
    s1.print();

    String container = "majestic queen swooped down and grabbed it";
    //container.print();
    cout << "Find 1: " << container.find(" ") << endl;
    cout << "Find 2: " << container.find("queen") << endl;
    cout << "Find 3: " << container.find("t") << endl;
    cout << "Find 4: " << container.find("m") << endl;
    cout << "Find 'z': " << container.find("z") << endl;

    cout << endl;
    String c2 = container;
    c2.print();
    c2.remove(9, 14); //startIndex, numChars
    c2.print();

    String c3 = container;
    c3.replaceAll("t", "T");
    c3.replaceAll("m", "M");
    c3.replace("queen", "hawk");
    c3.print();

    cout << endl;
    String c4 = c3;
    c3.toUppercase();
    c3.print();
    c4.toLowercase();
    c4.print();

    return 0;
}
