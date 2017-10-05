#include "../Debug.h"

using namespace std;

/* a simple observation the result[i] = (product of elements before i) * (product of elements after i) 
 * in this case we can compute the result seperately using two walks
 * */
vector<int> ProductExceptSelf(const vector<int>& A) {
    int alen = A.size(), 
        prefix_product = 1, // Product of elements before the current element
        surfix_product = 1; // product of the elements after the current element

    vector<int> result(alen, 1);

    for (int i = 1; i < alen; ++i) {
        prefix_product *= A[i - 1];
        result[i] = prefix_product;
    }

    for (int i = alen - 2; i >= 0; --i) {
        surfix_product *= A[i + 1];
        result[i] *= surfix_product;
    }

    return result;
}
