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

// There are N stones given in the form of an array, each element in array
// represents the height of 'i'th stone. There is a frog who is initially on Stone 1.
// Frog will repeat the following action some number of times to reach stone N:
// If the frog is currently on Stone i, jump to Stone (i+1) or Stone (i+2). Here,
// a cost of |hi - hj| is incurred, where j is the stone to land on.
// Find the minimum possible total cost incurred before the 
// frog reaches to Stone N.

// Bottom Up Approach
int getMinCost(vi stones) {
    int n = stones.size();
    vi dp(n+1, 0);
    // Base Case Assignment
    dp[0] = 0;
    dp[1] = abs(stones[1] - stones[0]);
    for(int i = 2; i < n; i++) {
        int op1 = abs(stones[i] - stones[i-1]) + dp[i-1];
        int op2 = abs(stones[i] - stones[i-2]) + dp[i-2];
        dp[i] = min(op1, op2);
    }
    return dp[n-1];
}

int main() {
    FIO;
    int n;
    cin >> n;
    vi stones(n);
    for(int i = 0; i < n; i++) cin >> stones[i];
    cout << getMinCost(stones) << nl;
    return 0;
}