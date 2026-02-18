#include <iostream>
#include <algorithm>
using namespace std;

struct Activity {
    int start;
    int finish;
};


bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int n;
    cout << "Number of activities: ";
    cin >> n;

    Activity arr[n];

    cout << "Enter start and finish time:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i].start >> arr[i].finish;
    }


    sort(arr, arr + n, compare);


    cout << "\nSelected Activities:\n";
    int lastFinish = arr[0].finish;
    cout << arr[0].start << " " << arr[0].finish << endl;


    for(int i = 1; i < n; i++) {
        if(arr[i].start >= lastFinish) {
            cout << arr[i].start << " " << arr[i].finish << endl;
            lastFinish = arr[i].finish;
        }
    }

    return 0;
}

