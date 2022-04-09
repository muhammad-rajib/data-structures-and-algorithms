/*
Subset Sum Problem using C++ Program.
*/
#include<bits/stdc++.h>

using namespace std;


bool subsetSumSolve(int set[], int arr_size, int totalSum)
{
	bool subset[arr_size + 1][totalSum + 1];

	for (int i = 0; i <= arr_size; i++)
		subset[i][0] = true;

	for (int i = 1; i <= totalSum; i++)
		subset[0][i] = false;

	for (int i = 1; i <= arr_size; i++) {
		for (int j = 1; j <= totalSum; j++) {
			if (j < set[i - 1])
				subset[i][j] = subset[i - 1][j];
			if (j >= set[i - 1])
				subset[i][j] = subset[i - 1][j]
							|| subset[i - 1][j - set[i - 1]];
		}
	}

    cout << "\nsubset Table: " << endl;
	for (int i = 0; i <= arr_size; i++)
	{
	    for (int j = 0; j <= totalSum; j++)
		    cout<<"  "<<subset[i][j];
	    cout <<"\n";
	}

	if(subset[arr_size][totalSum] == true)
        return true;
    else
		return false;
}


int main() {

    // subset array
    int total_set_element;
    cout << "\nEnter number of set elements: ";
    cin >> total_set_element;

    int set_arr[total_set_element];

    cout << "Enter set elements: ";
    for (int i=0; i<total_set_element; i++)
        cin >> set_arr[i];

    // total Sum
    int total_totalSum;
    cout << "Enter Total Sum: ";
    cin >> total_totalSum;
    
    if (subsetSumSolve(set_arr, total_set_element, total_totalSum))
        cout << "\nOutput: True\n\n";
    else
        cout << "\nOutput: False\n\n";

    return 0;
}