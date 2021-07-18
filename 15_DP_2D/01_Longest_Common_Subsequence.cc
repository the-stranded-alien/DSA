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

// Given two sequences, find the length of longest
// subsequence which is common to both of them.

int lcsRecursion(string s1, string s2, int i, int j) {
    // Base Case
    if(i == s1.length() || j == s2.length()) return 0;
    // Recursive Case
    if(s1[i] == s2[j]) return (1 + lcsRecursion(s1, s2, i + 1, j + 1));
    int op1 = lcsRecursion(s1, s2, i + 1, j);
    int op2 = lcsRecursion(s1, s2, i, j + 1);
    return max(op1, op2);    
}

int lcsTopDown(string s1, string s2, int i, int j, vii &dp) {
    // Base Case
    if(i == s1.length() || j == s2.length()) return 0;
    // Look-Up
    if(dp[i][j] != -1) return dp[i][j];
    // Recursive Case
    if(s1[i] == s2[j]) return (dp[i][j] = (1 + lcsTopDown(s1, s2, i + 1, j + 1, dp)));
    int op1 = lcsTopDown(s1, s2, i + 1, j, dp);
    int op2 = lcsTopDown(s1, s2, i, j + 1, dp);
    return (dp[i][j] = max(op1, op2)); 
}

int lcsBottomUp(string s1, string s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int> > dp((n1 + 1), vector<int>((n2 + 1), 0));
    for(int i = 1; i <= n1; i++) {
        for(int j = 1; j <= n2; j++) {
            if(s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else {
                int op1 = dp[i - 1][j];
                int op2 = dp[i][j - 1];
                dp[i][j] = max(op1, op2);
            }
        }
    }
    // cout << nl;
    // FOR(i, n1 + 1) {
    //     FOR(j, n2 + 1) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << nl;
    // }    
    vector<char> result;
    int i = n1;
    int j = n2;
    while(i != 0 && j != 0) {
        if(dp[i][j] == dp[i][j - 1]) j--;
        else if(dp[i][j] == dp[i - 1][j]) i--;
        else {
            result.push_back(s1[i - 1]);
            i--;
            j--;
        }
    }
    reverse(result.begin(), result.end());
    cout << "LCS : ";
    for(char x : result) cout << x << " ";
    cout << nl;
    return dp[n1][n2];
}

int main() {
    FIO;
    string s1 = "ABCD";
    string s2 = "ABEDG";
    int n1 = s1.length();
    int n2 = s2.length();
    cout << "Recursion : " << lcsRecursion(s1, s2, 0, 0) << nl;
    vector<vector<int> > dp(n1, vector<int>(n2, -1)); // Vector of Size (n1 x n2)
    cout << "Top Down DP : " << lcsTopDown(s1, s2, 0, 0, dp) << nl;
    // FOR(i, n1) {
    //     FOR(j, n2) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << nl;
    // }
    cout << "Bottom Up : " << lcsBottomUp(s1, s2) << nl;
    return 0;
}