#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;             // <iostream>
using std::cout;            // <iostream>
using std::endl;            // <iostream>
using std::setprecision;    // <iomanip>
using std::sort;            // <algorithm>
using std::streamsize;      // <ios>
using std::string;          // <string>
using std::vector;          // <string>

int main()
{
    // display header message
    cout << "***************************************************************\n"
            "*** This program computes quartiles given a list of numbers ***\n"
            "***************************************************************\n";
    cout << endl;

    // ask for a list of numbers and store the list as a vector
    cout << "Enter all a list of numbers: ";
    vector<double> v;
    double x;
    while (cin >> x)
        v.push_back(x);

    // check vector size and action accordingly
    cout << endl;
    typedef vector<double>::size_type vecSize;
    vecSize N = v.size();
    if (N ==0 )
    {
        cout << "You must enter some numbers! " << endl;
        return 1;
    }

    else if (N ==1 )
    {
        cout << " Only 1 number supplied. Q1, Q2, and Q3 all equate to " << v[0] << endl;
        return 0;
    }

    else
    {
        // sort the homework grades;
        sort(v.begin(),v.end());

        // declare new variables
        vecSize NMod4 = (N % 4);  // identification of 1 of the 4 known datum distribution profiles
        string datumDistr = "";   // datum distribution profile
        vecSize M, ML, MU;        // core vector indices for quartile computation
        double m, ml, mu;         // quartile values are store here

        // compute quartiles for the 4 known patterns
        if ( NMod4 == 0 )
        {
            // Q1-Q3 datum distribution: [0 0 0]
            datumDistr = "[0 0 0]";
            M = N / 2;
            ML = M / 2;
            MU = M + ML;

            // grab quartile values
            ml= (v[ML] + v[ML-1]) / 2;     // datum: 0
            m = (v[M] + v[M-1]) / 2;       // datum: 0
            mu = (v[MU] + v[MU-1]) / 2;    // datum: 0
        }

        else if ( NMod4 == 1 )
        {
            // Q1-Q3 datum distribution: [0 1 0]
            datumDistr = "[0 1 0]";
            M = N / 2;
            ML = M / 2;
            MU = M + ML + 1;

            // grab quartile values
            datumDistr = "[0 0 0]";
            ml= (v[ML] + v[ML-1]) / 2;      // datum: 0
            m = v[M];                       // datum: 1
            mu = (v[MU] + v[MU-1]) / 2;     // datum: 0
        }

        else if ( NMod4 == 2 )
        {
            // Q1-Q3 datum distribution: [1 0 1]
            datumDistr = "[1 0 1]";
            M = N / 2;
            ML = M / 2;
            MU = M + ML;

            // grab quartile values
            ml= v[ML];                    // datum: 1
            m = (v[M] + v[M-1]) / 2;     // datum: 0
            mu = v[MU];                   // datum: 1
        }

        else if ( NMod4 == 3 )
        {
            // Q1-Q3 datum distribution: [1 1 1]
            datumDistr = "[1 1 1]";
            M = N / 2;
            ML = M / 2;
            MU = M + ML + 1;

            // grab quartile values
            ml= v[ML];                    // datum: 1
            m = v[M];                     // datum: 0
            mu = v[MU];                   // datum: 1
        }

        else
        {
            cout << "Unknown pattern discovered - new algorithm may be required.";
        }

        // Display results
        streamsize prec = cout.precision();
        cout << "Display the sorted (non-descending) vector below." << endl;
        cout << "Index: Number" << endl;
        for (vecSize i = 0; i !=  N; ++i)
        {
            cout << i << ": " << v[i] << endl;
        }
        cout << endl;
        cout << "Vector size: " << N << endl;
        cout << "Datum Distribution: " << datumDistr << endl;
        cout << setprecision(3) << endl
        << " Q1: " << ml << endl
        << " Q2: " << m << endl
        << " Q3: " << mu << endl
        << setprecision(prec);
    }
}