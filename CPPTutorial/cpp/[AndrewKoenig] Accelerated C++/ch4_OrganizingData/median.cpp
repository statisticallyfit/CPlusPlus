// source file for median function

#include <algorithm>    // to get declaration of sort
#include <stdexcept>    // to get declaration of domain_error
#include <vector>       // to get declaration of vector
#include "median.h"

using std::domain_error;
using std::sort;
using std::vector;

/*
 * Compute median of a vector<double>
 * Calling this function copies the entire argument vector
 */
double median(vector<double> vec) {
    typedef vector<double>::size_type vecSize;
    vecSize size = vec.size();

    if(size == 0){
        throw domain_error("Median of an empty vector");
    }
    sort(vec.begin(), vec.end());

    vecSize mid = size / 2;

    return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}