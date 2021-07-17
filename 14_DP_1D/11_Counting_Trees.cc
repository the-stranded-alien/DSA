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

// Count the No. of Binary Search Trees that can be Formed using 'N' Nodes,
// numbered from 1 to N.

// Catalan Numbers

// Exponential
int countBSTRec(int n) {
    if(n == 0 || n == 1) return 1;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int x = countBSTRec(i - 1);
        int y = countBSTRec(n - i);
        ans += (x * y);
    }
    return ans;
}

// O(N^2) Time
int countBSTTopDown(int n, int dp[]) {
    if(n == 0 || n == 1) return 1;
    if(dp[n] != 0) return dp[n];
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int x = countBSTTopDown(i - 1, dp);
        int y = countBSTTopDown(n - i, dp);
        ans += (x * y);
    }
    return (dp[n] = ans);
}

int countBSTBottomUp(int N) {
    vi dp((N+1), 0);
    dp[0] = dp[1] = 1; // Base Case Assignment
    for(int n = 2; n <= N; n++) {
        for(int i = 1; i <= n; i++) {
            dp[n] += (dp[i - 1] * dp[n - i]);
        }
    }
    return dp[N];
}

int main() {
    FIO;
    int n = 6;
    cout << "Recursive : " << countBSTRec(n) << nl;
    int dp[n + 1] = {0};
    cout << "Top Down DP : " << countBSTTopDown(n, dp) << nl;
    cout << "Bottom Up DP : " << countBSTBottomUp(n) << nl;
    return 0;
}