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

// There are N stones, for each 'i' (1 <= i <= N), the height of Stone 'i' is h[i].
// There is a frog who is initially on Stone 1. He will repeat the following action
// some number of times to reach stone N.
// If the frog is currently on Stone 'i', jump to one of the following stone (i + 1),
// (i + 2), ......, (i + K). Here, a cost of |hi - hj| is incurred, where j is the stone
// to land on. Find the minimum possible total cost incurred before the frog reaches stone N.

int frogMinCost(vi stones, int K) {
    int n = stones.size();
    vi dp((n + 1), 0);
    // Base Case Assignment
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        dp[i] = INT_MAX;
        for(int k = 1; k <= K; k++) {
            int cur_ans = (i < k) ? INT_MAX : (abs(stones[i] - stones[i - k]) + dp[i - k]);
            dp[i] = min(dp[i], cur_ans); 
        }
    }
    return dp[n - 1];
}

int main() {
    FIO;
    int K = 3;
    vi stones({10, 30, 40, 50, 20});
    cout << frogMinCost(stones, K); 
    return 0;
}