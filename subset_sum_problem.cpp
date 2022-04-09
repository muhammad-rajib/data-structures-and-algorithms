/*
Subset Sum Problem using C++ Program.
*/
#include<bits/stdc++.h>

using namespace std;


bool subsetSum(int A[], int n, int k)
{
    if (k == 0) {
        return true;
    }

    if (n < 0 || k < 0) {
        return false;
    }

    bool include = subsetSum(A, n - 1, k - A[n]);

    bool exclude = subsetSum(A, n - 1, k);

    return include || exclude;
}


int main() {

    // subset array
    int total_set_element;
    cout << "Enter number of set elements: ";
    cin >> total_set_element;

    int set_arr[total_set_element];

    for (int i=0; i<total_set_element; i++) {
        int set_element;
        cout << i+1 << " element: ";
        cin >> set_element;
        set_arr[i] = set_element;
    }

    // total sum
    int total_sum;
    cout << "Enter Total Sum: ";
    cin >> total_sum;
    
    if (subsetSum(set_arr, total_set_element - 1, total_sum)) {
        cout << "Output: True";
    }
    else {
        cout << "Output: False";
    }

    return 0;
}