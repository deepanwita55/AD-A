#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int knapsack (int n, int capacity, vector<int>&profit, vector<int>&weight, vector<int>&chosen)
{
    vector<vector<int>> KS(n+1, vector<int>(capacity+1,0));
    for(int i=1; i<=n; i++)
    {
        for(int c=1; c<=capacity; c++)
        {
            if(weight[i-1]<=c)
            {
                KS[i][c]=max(KS[i-1][c],profit[i-1]+KS[i-1][c-weight[i-1]]);
            }
            else
            {
                KS[i][c]=KS[i-1][c];
            }
        }
    }
    return KS[n][capacity];
}
int main()
{
    int n;
    cout << "Enter the no of items: ";
    cin >> n;
    vector<int>profit(n),weight(n);
    for(int i=0; i<n; i++)
    {
        cout << "Enter the profit of item "<<i+1<<" :";
        cin >> profit[i];
        cout << "Enter the weight of item "<<i+1<<" :";
        cin >> weight[i];
    }
    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    vector<int>chosen;
    int max_profit = 0;
    max_profit = knapsack(n,capacity,profit,weight,chosen);
    cout <<"Maximum profit: "<<max_profit<<"\n";

}
