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

// Given a set of non-negative integers, and a value sum,
// determine if there is a subset of the given set with
// sum equal to given sum. If yes, how many such subsets are there.

int countSubsets(vi arr, int n, int i, int X) {
    // Base Case
    if(i == n) {
        if(X == 0) return 1;
        else return 0;
    }
    // Recursive Case
    int inc = countSubsets(arr, n, (i+1), X - arr[i]);
    int exc = countSubsets(arr, n, (i+1), X);
    return (inc + exc);
}

int main() {
    FIO;
    vi arr{1,2,3,4,5};
    int X = 10;
    cout << countSubsets(arr, arr.size(), 0, X);
    return 0;
}