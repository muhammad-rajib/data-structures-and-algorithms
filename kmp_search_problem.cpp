/*
KMP Search Problem Solution using C++.
*/
#include<iostream>
#include<string>
using namespace std;


void createLPSTbl(string pat, int M, int* lpsTbl);

void KMPSearchPattern(string pat, string txt)
{
    int M = pat.size();
    int N = txt.size();
    cout << "Length of the Text: " << N << endl;
    cout << "Length of the Pattern: " << M << "\n\n";

    int lpsTbl[M];
  
    // prepare LPS table 
    createLPSTbl(pat, M, lpsTbl);

    // print LPS table
    int arrSize = sizeof(lpsTbl)/sizeof(lpsTbl[0]);
    cout << "LPS Table of " << pat << " is: ";
    for (int i=0; i<arrSize; i++) {
         cout << lpsTbl[i] << " "; 
    }
    cout << endl;
  
    int i = 0;  
    int j = 0;  
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            printf("Found pattern at index %d \n", i - j);
            j = lpsTbl[j - 1];
        } 
        else if (i < N && pat[j] != txt[i]) 
        {       
            if (j != 0)
                j = lpsTbl[j - 1];
            else
                i = i + 1;
        }
    }
}
  
 
void createLPSTbl(string pat, int M, int* lpsTbl)
{
    int len = 0;
    lpsTbl[0] = 0;
  
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lpsTbl[i] = len;
            i++;
        }
        else  
        { 
            if (len != 0) {
                len = lpsTbl[len - 1];        
            }
            else  
            {
                lpsTbl[i] = 0;
                i++;
            }
        }
    }
}
  

int main() {
    string text;
    string pattern;
    
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern: ";
    getline(cin, pattern);

    KMPSearchPattern(pattern, text);

    return 0;
}
