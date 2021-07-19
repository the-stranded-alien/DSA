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

// Given two strings, find the number of times the second string
// occurs as a subsequence in the first string.

int countSubRec(string a, string b, int m, int n) {
    // Base Case
    if(((m == -1) && (n == -1)) || (n == -1)) return 1;
    if(m == -1) return 0;
    // Recursive Case
    if(a[m] == b[n]) return countSubRec(a, b, (m - 1), (n - 1)) + countSubRec(a, b, (m - 1), n);
    else return countSubRec(a, b, (m - 1), n);   
}

int countSubTopDown(string a, string b, int m, int n, vii &dp) {
    // Base Case
    if(((m == -1) && (n == -1)) || (n == -1)) return 1;
    if(m == -1) return 0;
    // Look-Up
    if(dp[m][n] != -1) return dp[m][n];
    // Recursive Case
    if(a[m] == b[n]) {
        return (dp[m][n] = countSubRec(a, b, (m - 1), (n - 1)) + countSubRec(a, b, (m - 1), n));
    }
    else return (dp[m][n] = countSubRec(a, b, (m - 1), n)); 
}

int countSubBottomUp(string a, string b) {
    int m = a.length();
    int n = b.length();
    vector<vector<int> > dp((m + 1), vector<int>((n + 1), 0));
    // Fill First Column as 1 (Base Case Assignment)
    for(int i = 0; i <= m; i++) dp[i][0] = 1;
    // Fill the Table in Bottom Up Manner (1,1 ......... m,n)
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            // For Strings Indexing is 0 Based But For DP Table Indexing is 1 Based.
            if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            else dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[m][n];
}

int main() {
    FIO;
    string a = "ABCECDG";
    string b = "ABC";
    cout << "Recursion : " << countSubRec(a, b, a.length() - 1, b.length() - 1) << nl;
    vector<vector<int> > dp(a.length(), vector<int>(b.length(), -1));
    cout << "Top Down DP : " << countSubTopDown(a, b, a.length() - 1, b.length() - 1, dp) << nl;
    cout << "Bottom Up DP : " << countSubBottomUp(a, b) << nl;
    return 0;
}