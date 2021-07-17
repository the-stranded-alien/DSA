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

// Given an Array of Positive Integers, Find the Maximum Sum
// of Non Adjacent Elements in the Array.

// Recurrence : dp[i] = max(dp[i-1], (dp[i-2] + arr[i]))

int maxSubsetSumNonAdjacent(vi arr) {
    int n = arr.size();
    vi dp((n + 1), 0);
    // Corner Case
    if(n == 1) return max(arr[0], 0);
    else if(n == 2) return max(0, max(arr[0], arr[1]));
    // Bottom Up Logic
    // Base Case Assignment
    dp[0] = max(arr[0], 0);
    dp[1] = max(0, max(arr[0], arr[1]));
    for(int i = 2; i < n; i++) {
        int inc = arr[i] + dp[i - 2];
        int exc = dp[i - 1];
        dp[i] = max(inc, exc);
    }
    return dp[n - 1];
}

int main() {
    FIO;
    vi arr({6, 10, 12, 7, 9, 14});
    cout << maxSubsetSumNonAdjacent(arr) << nl;
    return 0;
}