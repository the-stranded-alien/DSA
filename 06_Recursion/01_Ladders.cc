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
#define vii vector< vector<int> >
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

// Recursion is the process of defining a problem in terms of (a simpler version) itself.
// Recursion => Principal of Mathematical Induction
// 1. Figure out the smallest case
// 2. Always assume the subproblem can be solved
// 3. Solve the current problem assuming subproblem solution exists

// Climbing Ladder : Given a ladder containing N steps, you can take a jump
// of 1, 2, or 3 at each step. Find the number of ways to climb the ladder.

// O(3^N) Time (Exponential Complexity)
int climbLadder(int n) {
    // Base Case
    if(n < 0) return 0;
    if(n == 0) return 1;
    // Recursive Case
    else return (climbLadder(n-1) + climbLadder(n-2) + climbLadder(n-3));
}

int main() {
    FIO;
    int n; cin >> n;
    cout << climbLadder(n) << nl; 
    return 0;
}