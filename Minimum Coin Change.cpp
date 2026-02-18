#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int CoinChange(int n, vector <int> &coins, int amount)
{
    vector<vector<int> > CC(n+1, vector <int> (amount+1, INT_MAX-1));
    for (int i=1; i<=n; i++)
    {
        CC[i][0] = 0;
    }
    for (int i=1; i<=n; i++)
    {
        for (int a=1; a<=amount; a++)
        {
            if(coins[i-1] <=a)
            {
                CC[i][a] = min(CC[i-1][a], 1+CC[i][a-coins[i-1]]);
            }
            else
            {
                CC[i][a] = CC[i-1][a];
            }
        }
    }
    return CC[n][amount];
}
int main()
{
    int n;
    cout << "Enter the number of coins: " <<"\n";
    cin >> n;

    vector <int> coins(n);
    for(int i=0; i<n; i++)
    {
        cout << "Enter the value of coin " << i+1 << ": ";
        cin >> coins[i];
    }
    int amount;
    cout << "Enter the total amount: ";
    cin >> amount;
    int min_coins = 0;
    min_coins = CoinChange(n,coins,amount);

    cout << "Minimum number of coins: " << min_coins << "\n";

}
