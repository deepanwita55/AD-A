#include<iostream>
using namespace std;
struct Item
{
    int weight;
    int profit;
    double Ratio;
    char name[10];
};
int main()
{
    int n;
    cout<<"Enter the no of items: ";
    cin>>n;

    Item item[n];

    for(int i=0; i<n; i++)
    {
        cout<<"Enter the name of item "<<i+1<<" : ";
        cin>>item[i].name;
        cout<<"Enter the weight of item "<<i+1<<" : ";
        cin>>item[i].weight;
        cout<<"Enter the profit of item "<<i+1<<" : ";
        cin>>item[i].profit;
        item[i].Ratio = (double)item[i].profit / item[i].weight;
    }


    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(item[i].Ratio<item[j].Ratio)
            {
                Item temp = item[i];
                item[i] =  item[j];
                item[j] = temp;
            }
        }
    }

    cout << "Sorted Items: "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Item " <<i+1 << " Name:" << item[i].name
                 << " Ratio: " << item[i].Ratio
                 << ", Profit: " << item[i].profit
                 << ", Weight: " << item[i].weight << endl;
    }

    int capacity;
    cout<<"Enter the knapsack capacity: ";
    cin>>capacity;

    cout<<endl;

    double profits = 0.0 ;
    int rem_capacity = capacity;
    for(int i=0; i<n; i++)
    {
        if(rem_capacity <= 0)break;
        else if(item[i].weight <= rem_capacity)
        {
            profits += item[i].profit;
            rem_capacity-= item[i].weight;
            cout << "Item taken ->" <<i+1
                 << " Name: " << item[i].name
                 << " Weight: " << item[i].weight
                 << ", Profit: " << item[i].profit
                 << ", Ratio: " << item[i].Ratio << endl;

        }
        else
        {
            profits += item[i].Ratio * rem_capacity;

            cout << "Fraction of item taken -> " << i+1
                 << " Name: " <<item[i].name
                 << " Weight: " << rem_capacity
                 << ", Profit added: " << item[i].Ratio * rem_capacity
                 << endl;

            rem_capacity = 0;
        }
    }

    cout<<"Total profit: "<<profits<<endl;
}

