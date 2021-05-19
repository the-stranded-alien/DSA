// Vectors are passed by value by default !!

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
    vector<int> arr = {1, 2, 10, 12, 15};
    cout << arr.size() << endl;   // Size of vector
    cout << arr.capacity() << endl; // Capacity of vector
    arr.pb(16); // push_back
    cout << arr.size() << endl;   // Size of vector
    cout << arr.capacity() << endl; // Capacity of vector
    for(int i = 0; i < arr.size(); i++) cout << arr[i] << endl; // Print all elements
    arr.pop_back(); // pop_back

    vector<int> fill(10, 7); // Fill constructor (No of elements, value)
    return 0;
}