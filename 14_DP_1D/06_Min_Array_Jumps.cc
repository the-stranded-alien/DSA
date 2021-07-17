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

// Given an array of positive integers, where each element represents
// the maximum number of steps you can jump forward in the array.
// Find minimum jumps needed to reach the final index.

int minJumpsTD(vi arr, int n, vi dp, int i = 0) {
    // Base Case
    if(i == (n - 1)) return 0;
    if(i >= n) return INT_MAX;
    // Look-Up
    if(dp[i] != 0) return dp[i];
    // Recursive Case
    int steps = INT_MAX;
    int max_jump = arr[i];
    for(int jump = 1; jump <= max_jump; jump++) {
        int next_cell = i + jump;
        int subprob = minJumpsTD(arr, n, dp, next_cell);
        if(subprob != INT_MAX) steps = min(steps, subprob + 1);
    }
    return (dp[i] = steps);
}

int main() {
    FIO;
    vi arr = {3,4,2,1,2,3,7,1,1,3};
    int n = arr.size();
    vi dp(n+1, 0);
    cout << minJumpsTD(arr, n, dp, 0) << nl;
    return 0;
}