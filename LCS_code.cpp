#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void LCS(string x, string y, int a, int b){
    vector<vector<int>> lcs(a+1, vector<int>(b+1, 0));

    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            if(x[i-1] == y[j-1]){
                lcs[i][j] = lcs[i-1][j-1] + 1;
            }
            else if(x[i-1] != y[j-1] && lcs[i-1][j] == lcs[i][j-1]){
                lcs[i][j] = lcs[i-1][j];
            }
            else{
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }

        }
    }

    string sequence = "";
    int i = a, j = b;
    while (i > 0 && j > 0){
        if(x[i-1] == y[j-1]){
            sequence = x[i-1] + sequence;
            i--;
            j--;
        }
        else if(lcs[i-1][j] > lcs[i][j-1]){
            i--;
        }
        else{
            j--;
        }

    }

    cout << "Length of LCS = " << lcs[a][b] << endl;
    cout << "LCS = " << sequence << endl;

}

int main()
{
    string x,y;
    cout << "Enter the first string: " << endl;
    cin >> x;
    cout << "Enter the second string: " << endl;
    cin >> y;

    int a = x.length();
    int b = y.length();

    LCS(x,y,a,b);

}