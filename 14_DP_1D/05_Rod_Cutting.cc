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

// Given a Rod of Length N and Prices for Each Possible Cuts of Size (1 To N)
// Find Max Possible Profit.

// Recursive Solution
int maxProfit(int *prices, int n) {
    // Base Case
    if(n <= 0) return 0;
    // Recursive Case
    int ans = INT_MIN;
    for(int i = 0; i < n; i++) {
        int cut = i + 1;
        int current_ans = prices[i] + maxProfit(prices, (n - cut));
        ans = max(ans, current_ans);
    }
    return ans;
}

// Top Down DP
int maxProfitTD(int *prices, int n, vi dp) {
    // Base Case
    if(n <= 0) return 0;
    // Look Up
    if(dp[n] != -1) return dp[n];
    // Recursive Case
    int ans = INT_MIN;
    for(int i = 0; i < n; i++) {
        int cut = i + 1;
        int current_ans = prices[i] + maxProfit(prices, (n - cut));
        ans = max(ans, current_ans);
    }
    return (dp[n] = ans);
}

// Bottom Up DP
int maxProfitBU(int *prices, int n) {
    vi dp((n + 1), -1);
    dp[0] = 0; // Base Case Assignment
    for(int len = 1; len <= n; len++) {
        int ans = INT_MIN;
        for(int i = 0; i < len; i++) {
            int cut = i + 1;
            int current_ans = prices[i] + dp[len - cut];
            ans = max(current_ans, ans);
        }
        dp[len] = ans;
    }
    return dp[n];
}

int main() {
    FIO;
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(prices) / sizeof(int);
    cout << "Recursive : " << maxProfit(prices, n) << nl;
    vi dp((n + 1), -1);
    cout << "Top Down DP : " << maxProfitTD(prices, n, dp) << nl;
    cout << "Bottom Up DP : " << maxProfitBU(prices, n) << nl;   
    return 0;
}