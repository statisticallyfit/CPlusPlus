#include <iostream>
using namespace std;




class Sales
{
private:
    const static int numPassedMonths = 3;
    float publicationSales[numPassedMonths]; // sales over last n months

public:
    Sales() {
        for (int i = 0; i < numPassedMonths; i++){
            publicationSales[i] = 0;
        }
    }

    Sales(float s[]){
        for(int i = 0; i < numPassedMonths; i++){
            publicationSales[i] = s[i];
        }
    }

    void getData() {
        //cout << endl;
        for (int i = 0; i < numPassedMonths; i++){
            cout << "\tEnter dollar sale for month #" << i + 1
                    << ": "; cin >> publicationSales[i];
        }
    }

    void putData() const {
        for (int i = 0; i < numPassedMonths; i++){
            cout << "\n\tSale #" << i + 1 << ": " << publicationSales[i];
        }
    }
};



class Publication
{
private:
    string title;
    float price;

public:
    Publication() : title(""), price(0)
    { }
    Publication(string t, float p) : title(t), price(p)
    { }

    void getData() {
        cout << "\n\tEnter a title: "; cin >> title;
        cout << "\tEnter a price: "; cin >> price;
    }

    void putData() const {
        cout << "\n\tTitle: " << title;
        cout << "\n\tPrice: " << price;
    }
};



class Book : public Publication, public Sales
{
private:
    int pageCount;

public:
    Book() : Publication(), Sales(), pageCount(0)
    { }
    Book(string t,
         float p,
         int c,
         float s[]) : Publication(t, p),
                      Sales(s),
                      pageCount(c)
    { }

    void getData() {
        Publication::getData();
        cout << "\tEnter number of pages: "; cin >> pageCount;
        Sales::getData();
    }

    void putData() const {
        Publication::putData();
        cout << "\n\tNumber of pages: " << pageCount;
        Sales::putData();
    }
};




class Tape : public Publication, public Sales
{
private:
    float playingTimeMinutes;

public:
    Tape() : Publication(),
             Sales(),
             playingTimeMinutes(0)
    { }
    Tape(string t,
         float p,
         float time,
         float s[]) : Publication(t, p),
                      Sales(s),
                      playingTimeMinutes(time)
    { }

    void getData() {
        Publication::getData();
        cout << "\tEnter minutes of playing time: "; cin >> playingTimeMinutes;
        Sales::getData();
    }

    void putData() const {
        Publication::putData();
        cout << "\n\tMinutes of playing time: " << playingTimeMinutes;
        Sales::putData();
    }
};



enum TYPE { CD, DVD};

class Disk : public Publication, public Sales
{
private:
    TYPE diskType;

public:
    Disk() : Publication(), Sales(), diskType{CD}
    { }
    Disk(string t,
         float p,
         float s[],
         TYPE type=CD) : Publication(t, p),
                         Sales(s),
                         diskType(type)
    { }

    void getData() {
        char cDiskType;
        Publication::getData();
        cout << "\tEnter disk type: "; cin >> cDiskType;
        diskType = (cDiskType == 'c') ? CD : DVD;
        Sales::getData();
    }

    void putData() const {
        char cDiskType = (diskType == CD) ? 'c' : 'd';
        Publication::putData();
        cout << "\n\tDisk type: " << cDiskType;
        Sales::putData();
    }
};




int main()
{
    float arr1[] = {90.1, 88.45, 33.34};
    float arr2[] = {77, 55.5, 65.23};
    float arr3[] = {10, 20.3, 40.45};

    Publication p1, p2;
    Sales s1, s2;
    Book b1, b2;
    Tape t1, t2;
    Disk d1, d2;

    Publication p3 ("The Seeker", 45.20);
    Sales s3(arr3);
    Book b3 ("Inkheart", 100.50, 780, arr1);
    Tape t3 ("The Musical", 10.11, 90.5, arr2);
    Disk d3 ("Disk title", 89, arr3, DVD);

    cout << endl;
    cout << "\nEnter data for publication 1";
    p1.getData();
    cout << "\nEnter data for publication 2";
    p2.getData();
    cout << "\nEnter data for book 1";
    b1.getData();
    cout << "\nEnter data for book 2";
    b2.getData();
    cout << "\nEnter data for tape 1";
    t1.getData();
    cout << "\nEnter data for tape 2";
    t2.getData();
    cout << "\nEnter data for sales 1";
    s1.getData();
    cout << "\nEnter data for sales 2";
    s2.getData();
    cout << "\nEnter data for disk 1";
    d1.getData();
    cout << "\nEnter data for disk 2";
    d2.getData();

    //display data
    cout << "\nData on publication 1";
    p1.putData();
    cout << "\nData on publication 2";
    p1.putData();
    cout << "\nData on book 1";
    b1.putData();
    cout << "\nData on book 2";
    b2.putData();
    cout << "\nData on tape 1";
    t1.putData();
    cout << "\nData on tape 2";
    t2.putData();
    cout << "\nData on sales 1";
    s1.putData();
    cout << "\nData on sales 2";
    s2.putData();
    cout << "\nData on disk 1";
    d1.putData();
    cout << "\nData on disk 2";
    d2.putData();
    cout << endl;

    cout << "\nDisplaying object 3 data";
    p3.putData(); cout << endl;
    b3.putData(); cout << endl;
    t3.putData(); cout << endl;
    s3.putData(); cout << endl;
    d3.putData(); cout << endl;

    return 0;
}