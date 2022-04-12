/*
Minimum Cost Path Problem using Dynamic Programming in c++.
*/
#include <bits/stdc++.h>
#define row 3
#define col 4

using namespace std;

int minCostPath(int cost[row][col])
{
    int dp[row][col];
    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {
            if (i == row - 1 && j == col - 1)
                dp[i][j] = cost[i][j];
            else if (i == row - 1)
                dp[i][j] = cost[i][j] + dp[i][j + 1];
            else if (j == col - 1)
                dp[i][j] = cost[i][j] + dp[i + 1][j];
            else
            {
                int min = std::min(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = cost[i][j] + min;
            }
        }
    }
    return dp[0][0];
}

int main()
{
    int cost[row][col] = {
        {3, 5, 7, 10},
        {6, 4, 3, 9},
        {6, 5, 4, 5}
    };

    cout << "\nMinimum Cost Path: " << minCostPath(cost) << "\n\n";
    return 0;
}
