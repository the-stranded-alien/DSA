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

// Given an Array of Coin Denominations, and Integer M Representing Target Money.
// We Need to Find the Minimum Coins Required to Make The Change.

int minNumberOfCoinsForChangeTopDown(int m, vi denoms, vi dp) {
    // Base Case
    if(m == 0) return 0;
    // Look-Up
    if(dp[m] != -1) return dp[m];
    // Recursive Case
    int result = INT_MAX;
    for(int i = 0; i < denoms.size(); i++) {
        if(denoms[i] <= m) {
            int sub_result = 1 + minNumberOfCoinsForChangeTopDown(m - denoms[i], denoms, dp);
            if(sub_result < result) result = sub_result;
        }
    }
    return (dp[m] = result);
}

int minNumberOfCoinsForChangeBottomUp(int m, vi denoms) {
    vi dp((m + 1), 0);
    dp[0] = 0; // Base Case Assignment
    for(int i = 1; i <= m; i++) {
        dp[i] = INT_MAX;
        for(int c : denoms) {
            if(((i - c) >= 0) && (dp[i - c] != INT_MAX)) {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }
    return (dp[m] == INT_MAX ? -1 : dp[m]);
}

int main() {
    FIO;
    vi denoms = {1,3,7,10};
    int money = 15;
    vi dp((money + 1), -1);
    cout << "Top Down DP : " << minNumberOfCoinsForChangeTopDown(money, denoms, dp) << nl;
    cout << "Bottom Up DP : " << minNumberOfCoinsForChangeBottomUp(money, denoms) << nl;
    return 0;
}