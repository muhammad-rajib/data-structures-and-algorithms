#include <iostream>
using namespace std;


void createTbl(int *tps, int size, string patt) {

    int i = 0; 
    tps[0] = 0;

    int j = 1;
    while (j < size) {

        if (patt[i] == patt[j]) {
            i++;
            tps[j] = i;
            j++;
        }
        else {
            if (i != 0) {
                i = tps[i-1];
            }
            else {
                tps[j] = 0;
                j++;
            }
        }
    }
}


int main() {
    string text;
    string patt;
    
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern: ";
    getline(cin, patt);

    int patt_size = patt.size();
    int tps[patt_size];
    int *tpsTbl = tps;
    createTbl(tpsTbl, patt_size, patt);

    // length of text & pattern
    cout << "Length of text is: " << text.size() << endl;
    cout << "Length of pattern is: " << patt_size << endl;

    // print tps table
    for (int i=0; i<patt_size; i++) {
        cout << tps[i] << " ";
    }
    cout << endl;

    return 0;
}
