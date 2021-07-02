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
#define vii vector< vector<int> >
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

// Given two non-empty arrays, find the pair of numbers (one from each array)
// whose absolute difference is minimum. Print any one pair with the 
// smallest difference.

// O((M log M) + (N log M)) 

void min_pair(vi a1, vi a2) {
    // Sort One of The Array
    sort(a2.begin(), a2.end());
    int p1, p2;
    int diff = INT_MAX;
    // Iterate Over 1 Array And Look For Closest Elements in The Second Array
    for(int x : a1) {
        auto lb = lower_bound(a2.begin(), a2.end(), x) - a2.begin();
        // Left
        if(lb >= 1 && (x - a2[lb-1] < diff)) {
            diff = x - a2[lb-1];
            p1 = x;
            p2 = a2[lb-1];
        }
        // Greater / Right
        if(lb != a2.size() && (a2[lb] - x < diff)) {
            diff = a2[lb] - x;
            p1 = x;
            p2 = a2[lb];
        }
    }
    cout << "Min Pair : " << p1 << " and " << p2 << nl;
}

int main() {
    FIO;
    vi a1{-1,5,10,20,3};
    vi a2{26,134,135,15,17};
    min_pair(a1, a2);
    return 0;
}