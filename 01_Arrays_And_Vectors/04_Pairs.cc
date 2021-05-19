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

// Given an array containing N integers, and an number S denoting a target sum.
// Find two distinct integers that can pair up to form target sum.
// Let us assume there will be only one such pair.

// 1. Brute Force : O(N^2)
// 2. Sorting & Binary Search : O(N log N)
// 3. DS - Unordered Set : O(N)

vector<int> pairSum(vector<int> elements, int sum) {
    vector<int> pair;
    unordered_set<int> bag;
    for(int element : elements) {
        int x = sum - element;
        if(bag.count(x)) {
            pair.push_back(min(element, x));
            pair.push_back(max(element, x));
            return pair;
        } else bag.insert(element);
    }
    return pair;
}

int main() {
    FIO;
    int n; cin >> n;
    vector<int> elements(10000);
    for(int i = 0; i < n; i++) cin >> elements[i];
    int sum; cin >> sum;

    auto pair = pairSum(elements, sum);

    if(pair.size() == 0) cout << "No Such Pair";
    else {
        cout << pair[0] << " " << pair[1] << endl;
    }

    return 0;
}