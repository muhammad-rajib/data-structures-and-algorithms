/*
Coin Change Problem using C++ Program.
*/
#include<bits/stdc++.h>

using namespace std;

int coin_change_count( int S[], int m, int n )
{
	int i, j, x, y;

	int table[n + 1][m];
	
	for (i = 0; i < m; i++)
		table[0][i] = 1;

	for (i = 1; i < n + 1; i++)
	{
		for (j = 0; j < m; j++)
		{
			// Count of solutions including S[j]
			x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0;

			// Count of solutions excluding S[j]
			y = (j >= 1) ? table[i][j - 1] : 0;

			// total count
			table[i][j] = x + y;
		}
	}
	return table[n][m - 1];
}


int main()
{
    // total amount
	int n;
    cout << "Enter Total Change Amount: ";
    cin >> n; 
	
	// coins array
	int total_coins;
	cout << "Enter Total Coins: ";
	cin >> total_coins;

	int arr[total_coins];

	for (int i=0; i<total_coins; i++) {
		int coins;
		cout << "coin " << i+1 << ": ";
		cin >> coins;
		arr[i] = coins;
	}

    cout << "Output: " << coin_change_count(arr, total_coins, n);
	return 0;
}
