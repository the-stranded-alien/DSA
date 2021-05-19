#include<bits/stdc++.h>
#define ll long long int
#define ld long long double
#define pb push_back
#define F first
#define S second
#define P pair<int, int>
#define MOD 1000000007
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;



int main() {
    FIO;
    // 2D Vector
    vector< vector<int> > arr = {
        {1,2,3},
        {4,5,6},
        {7,8,9,10},
        {11,12}
    };

    for(int i = 0; i < arr.size(); i++) {
        for(int number : arr[i]) {
            cout << number << " ";
        }
        cout << endl;
    }    

    for(vector<int> x : arr) {
        for(int num : x) {
            cout << num << ",";
        }
        cout << endl;
    }

    arr[0][0] += 10; // Update

    return 0;
}