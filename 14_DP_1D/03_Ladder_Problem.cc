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

// Given a Ladder of Size N, and an Integer K, Write a Function to Compute
// Number of Ways to Climb the Ladder if you can Take a Jump of Atmost K 
// at Every Step.

// General Recurrence : 
// f(N) = f(N - 1) + f(N - 2) + f(N - 3) + ..... + f(N - K)

// Recursive Approach : O(K ^ N) Time
int ladderProblemRecursion(int n, int k) {
    // Base Case
    if(n == 0) return 1;
    if(n < 0) return 0;
    // Recursive Case
    int ans = 0;
    for(int jump = 1; jump <= k; jump++) {
        ans += ladderProblemRecursion(n - jump, k);
    }
    return ans;
}

// Approach 1 : Top Down DP : O(N * K) Time
int ladderProblemTopDown(int n, int k, int dp[]) {
    // Base Case
    if(n == 0) return 1;
    if(n < 0) return 0;
    // Look-Up (Check if State is Already Computed)
    if(dp[n] != 0) return dp[n];
    // Recursive Case
    int ans = 0;
    for(int jump = 1; jump <= k; jump++) {
        ans += ladderProblemTopDown(n - jump, k, dp);
    }
    return (dp[n] =  ans);
}

// Approach 2 : Bottom Up DP
// O(N * K) Time & O(N) Space
int ladderProblemBottomUp(int n, int k) {
    vector<int> dp((n + 1), 0);
    // Base Case (Assignment)
    dp[0] = 1;
    // Iterative Approach
    for(int i = 1; i <= n; i++) {
        for(int jump = 1; jump <= k; jump++) {
            if((i - jump) >= 0) dp[i] += dp[i - jump];
        }
    }
    return dp[n];
}

// Approach 3 : Optimise The Recurrence
// dp(N) = dp(N - 1) - dp(N - (K + 1)) + dp(N - 1)
// dp(N) = 2 * dp(N - 1) - dp(N - K - 1) => O(1) Time for Each Cell
// O(N) Time & O(N) Space
int ladderProblemBottomUpOptimized(int n, int k) {
    vector<int> dp((n + 1), 0);
    // Base Case (Assignment)
    dp[0] = dp[1] = 1;
    // Iterative Approach
    for(int i = 2; i <= k; i++) {
        dp[i] = 2 * dp[i - 1]; 
    }
    for(int i = (k + 1) ; i <= n; i++) {
        dp[i] += (2 * dp[i - 1]) - dp[i - k - 1];
    }
    return dp[n];
}

int main() {
    FIO;
    int n, k;
    cin >> n >> k;
    cout << "Recursion : " << ladderProblemRecursion(n, k) << nl;
    int dp[n + 1] = {0};
    cout << "Top Down DP : " << ladderProblemTopDown(n, k, dp) << nl;
    cout << "Bottom Up DP : " << ladderProblemBottomUp(n, k) << nl;
    cout << "Bottom Up DP Optimized Recurrence : " << ladderProblemBottomUpOptimized(n, k) << nl;
    return 0;
}