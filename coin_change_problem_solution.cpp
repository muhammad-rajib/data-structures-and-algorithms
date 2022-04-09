/*
Coin Change Problem using C++ Program.
*/
#include <bits/stdc++.h>
using namespace std;


int coin_change_count_solve(int coins_arr[], int m, int n)
{
	int i, j, x, y;
	int table[n + 1][m];

	for (i = 0; i < m; i++)
		table[0][i] = 1;
	
	for (i = 1; i < n + 1; i++)
	{
		for (j = 0; j < m; j++)
		{
			x = (i - coins_arr[j] >= 0) ? table[i - coins_arr[j]][j] : 0;
			y = (j >= 1) ? table[i][j - 1] : 0;

			table[i][j] = x + y;
		}
	}
	return table[n][m - 1];
}


int main()
{
	// total change amount
	int totalChange;
	cout << "\nEnter Total Change Amount: ";
	cin >> totalChange;

	// total coins
	int total_coins;
	cout << "Enter Total Coins: ";
	cin >> total_coins;
	
	// coins array
	int arr[total_coins];
	
	cout << "Enter coins: ";
	for (int i = 0; i < total_coins; i++)
		cin >> arr[i];
	
	cout << "\nOutput: " << coin_change_count_solve(arr, total_coins, totalChange) << "\n\n";
	
	return 0;
}