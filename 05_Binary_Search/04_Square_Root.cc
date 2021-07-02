#include<iostream>
#include<string>
#include<limits>
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

// Given an integer N and an integer P, you need to find the
// square root of number N upto P places without library functions.

// Monotonic Search Space !!

// Binary Search + Linear Search : O(log N + qp)

float sqrRoot(int n, int p) {
    int s = 0;
    int e = n;
    float ans = 0;
    // Binary Search for Integer Part (Search Space 0 ........ N)
    while(s <= e) {
        int mid = (s + e) / 2;
        if((mid * mid) == n) return mid;
        else if((mid * mid) < n) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    // Linear Search For Each Place (for Floating Part)
    float inc = 0.1;
    for(int place = 1; place <= p; place++) {
        // Do Linear Search
        while((ans * ans) <= n) ans += inc;
        ans = ans - inc;
        inc = (inc / 10.0);
    }
    return ans;
}

int main() {
    FIO;
    int n, p;
    cin >> n >> p;
    cout << sqrRoot(n, p) << nl;
    return 0;
}