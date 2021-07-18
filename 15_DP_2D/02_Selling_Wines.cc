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

// There is a collection of N wines placed linearly on shelf, the price of
// the 'i'th wine is pi. Since wines get better every year, suppose today is
// the year 1, on the year y the price of the 'i'th wine would be (y * pi) i.e.
// y-times the value that current year have.
// You want to sell all the wines you have, but you want to sell exactly one wine
// per year, starting this year. One more constraint - on each year you can sell 
// either the leftmost or the rightmost wine without re-ordering. Find the maximum
// profit you can get if you sell all the wines in the optimal order.

int winesTopDown(vii &dp, vi &prices, int leftIdx, int rightIdx, int year) {
    // Base Case
    if(leftIdx > rightIdx) return 0;
    // Look-Up if a State is Already Calculated
    if(dp[leftIdx][rightIdx] != 0) return dp[leftIdx][rightIdx];
    // Recursive Case
    int pick_left = (year * prices[leftIdx]) + winesTopDown(dp, prices, (leftIdx + 1), rightIdx, (year + 1));
    int pick_right = (year * prices[rightIdx]) + winesTopDown(dp, prices, leftIdx, (rightIdx - 1), (year + 1));
    return (dp[leftIdx][rightIdx] = max(pick_left, pick_right));
}

int winesBottomUp(vi &prices, int n) {
    vector<vector<int> > dp((n + 1), vector<int>((n + 1), 0));
    for(int i = (n - 1); i >= 0; i--) {
        // Bottom Row to Top Row
        for(int j = 0; j < n; j++) {
            // Left to Right
            if(i == j) dp[i][j] = (n * prices[i]); // Filling Diagonal
            else if(i < j) {
                int year = n - (j - i);
                int pick_left = ((prices[i] * year) + dp[i + 1][j]);
                int pick_right = ((prices[j] * year) + dp[i][j - 1]);
                dp[i][j] = max(pick_left, pick_right);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    FIO;
    vi prices({2, 3, 5, 1, 4});
    int n = prices.size();
    vii dp((n + 1), vector<int>((n + 1), 0));
    cout << "Top Down DP : " << winesTopDown(dp, prices, 0, (n - 1), 1) << nl;
    cout << "Bottom Up DP : " << winesBottomUp(prices, n) << nl;
    return 0;
}