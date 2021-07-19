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

// Given Weights and Prices of 'n' Items, We Need to Put a Subset of Items
// in a Bag of Capacity W such that We get the Maximum Total Value in the Bag,
// Also Known as Knapsack.

int knapsackRec(vi wts, vi prices, int N, int W) {
    // Base Case
    if(N == 0 || W == 0) return 0;
    // Recursive Case
    int inc = 0, exc = 0;
    if(wts[N - 1] <= W) inc = prices[N - 1] + knapsackRec(wts, prices, N - 1, W - wts[N - 1]); 
    exc = knapsackRec(wts, prices, N - 1, W);
    return max(inc, exc);
}

int knapsackTopDown(vi wts, vi prices, int N, int W, vii &dp) {
    // Base Case
    if(N == 0 || W == 0) return 0;
    // Look-Up
    if(dp[N][W] != 0) return dp[N][W];
    // Recursive Case
    int inc = 0, exc = 0;
    if(wts[N - 1] <= W) inc = prices[N - 1] + knapsackRec(wts, prices, N - 1, W - wts[N - 1]); 
    exc = knapsackRec(wts, prices, N - 1, W);
    return (dp[N][W] = max(inc, exc));
}

// Time : O(N * W)
int knapsackBottomUp(vi wts, vi prices, int N, int W) {
    vector<vector<int> > dp((N + 1), vector<int>((W + 1), 0));
    for(int n = 1; n <= N; n++) {
        for(int w = 1; w <= W; w++) {
            int inc = 0, exc = 0;
            if(wts[n - 1] <= w) inc = prices[n - 1] + dp[n - 1][w - wts[n - 1]];
            exc = dp[n - 1][w];
            dp[n][w] = max(inc, exc);
        }
    }
    return dp[N][W];
}

// Space Complexity Can Be Reduced from (N+1 * W+1) to (2 * W+1).

int main() {
    FIO;
    int N = 4;
    int W = 11;
    vi weights({2, 7, 3, 4});
    vi prices({5, 20, 20, 10});
    cout << "Recursion : " << knapsackRec(weights, prices, N, W) << nl;
    vector<vector<int> > dp((N + 1), vector<int>((W + 1), 0));
    cout << "Top Down DP : " << knapsackTopDown(weights, prices, N, W, dp) << nl;
    cout << "Bottom Up DP : " << knapsackBottomUp(weights, prices, N, W) << nl;
    return 0;
}