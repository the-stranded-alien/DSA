#include<iostream>
#include<string>
#include<climits>
#include<algorithm>
#include<array>
#include<bitset>
#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<deque>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#define ll long long int
#define ld long long double
#define PB push_back
#define POB pop_back
#define MP make_pair
#define F first
#define S second
#define nl '\n'
#define tab '\t'
#define pi pair<int, int>
#define vi vector<int>
#define vs vector<string>
#define vb vector<bool>
#define vii vector< vector<int> >
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

// Given an array and an integer k, find the maximum for each
// and every contiguous subarray of size k.

// Time : O(N)
void maxSubArrayK(vector<int> a, int k) {
    deque<int> Q(k);
    int i;
    int n = a.size();
    // 1. Process Only The First 'k' Elements
    for(i = 0; i < k; i++) {
        while(!Q.empty() && a[i] > a[Q.back()]) Q.pop_back();
        Q.push_back(i);
    }
    // 2. Process The Remaining Elements Of The Array
    for( ; i < n; i++) {
        cout << a[Q.front()] << " ";
        // Remove Elements From The Left
        // (Contraction When an Index Lies Outside The Current Window)
        while(!Q.empty() && Q.front() <= (i - k)) Q.pop_front();
        while(!Q.empty() && a[i] >= a[Q.back()]) Q.pop_back();
        Q.push_back(i); // Always
    }
}

int main() {
    FIO;
    vector<int> arr{1,2,3,1,4,5,2,3,5};
    int k = 3;
    maxSubArrayK(arr, k);
    return 0;
}