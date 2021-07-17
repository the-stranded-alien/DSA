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

int fibRec(int n) {
    if(n == 0 || n == 1) return n;
    else return (fibRec(n - 1) + fibRec(n - 2));
}

// Top Down DP : Recursion + Memoization
int fibTopDownDP(int n, int dp[]) {
    // Base Case
    if(n == 0 || n == 1) return n;
    // Check if the State is Already Computed
    if(dp[n] != 0) return dp[n];
    // Otherwise Compute the State & Store It.
    return dp[n] = (fibTopDownDP(n - 1, dp) + fibTopDownDP(n - 2, dp));
}

// Bottom Up DP : Iterative + Memoization
int fibBottomUpDP(int n) {
    int dp[n + 1] = {0};
    // Base Case => Assignment
    dp[0] = 0; 
    dp[1] = 1;
    // Bottom Up DP
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    } 
    return dp[n];
}

// Bottom Up DP With Constant Space
int fibBottomUpDPSpaceEfficient(int n) {
    // Base Case
    int num1 = 0;
    int num2 = 1;
    for(int i = 2; i <= n; i++) {
        int temp = num1 + num2;
        num1 = num2;
        num2 = temp;
    }
    return num2;
}

int main() {
    FIO;
    int n;
    cin >> n;
    int dp[n + 1] = {0};
    cout << "Recursion : " << fibRec(n) << nl;
    cout << "Top Down DP : " << fibTopDownDP(n, dp) << nl;
    cout << "Bottom Up DP : " << fibBottomUpDP(n) << nl;
    cout << "Bottom Up DP Constant Space : " << fibBottomUpDPSpaceEfficient(n) << nl;
    return 0;
}