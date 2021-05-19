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

// Write a function that takes input an array of distinct integers,
// and returns the length of the highest mountain.
// A mountain is defined as adjacent integers that are strictly
// increasing until they reach a peak, at which they become strictly decreasing.
// At least 3 numbers are required to form a mountain.

// 1. Identify Peaks
// 2. For each peak look at previous peak (X) and move forward (Y) and add X + Y
// Time : Less than O(2N) : O(N)

int highestMountain(int n, vector<int> elements) {
    int largest = 0;
    for(int i = 1; i <= (n - 2);) { // From second to second last element
        // Check elements[i] is peak or not
        if(elements[i] > elements[i - 1] && elements[i] > elements[i + 1]) {
            // Do some work
            int cnt = 1;
            int j = i;
            // Count backwards (left)
            while(j >= 1 && elements[j] > elements[j - 1]) {
                j--;
                cnt++;
            }
            // Count forwards (right)
            while(i <= n - 2 && elements[i] > elements[i + 1]) {
                i++;
                cnt++;
            }
            largest = max(largest, cnt);
        } else i++;
    }   
    return largest;
}

int main() {
    FIO;
    vector<int> elements;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int ele; cin >> ele;
        elements.push_back(ele);
    }
    int highestMount = highestMountain(n, elements);
    cout << highestMount << endl;
    return 0;
}