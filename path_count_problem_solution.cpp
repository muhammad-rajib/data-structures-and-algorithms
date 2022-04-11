/*
Path Count Problem Solution using C++ Program.
*/
#include <bits/stdc++.h> 
using namespace std; 
  
 
int pathCountSolve(int m_row, int n_col) 
{ 
    int dp[n_col] = { 1 }; 
    dp[0] = 1; 
  
    for (int i = 0; i < m_row; i++) { 
        for (int j = 1; j < n_col; j++) { 
            dp[j] += dp[j - 1]; 
        } 
    } 
  
    return dp[n_col - 1]; 
} 
  

int main() 
{
    int row, col;

    cout << "\nEnter Row: ";
    cin >> row;

    cout << "Enter Column: ";
    cin >> col;

    cout << "\nOutput: " << pathCountSolve(row, col) << "\n\n"; 
} 
