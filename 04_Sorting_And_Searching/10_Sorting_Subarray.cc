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

// Write a function that takes in an array and returns two integers, denoting
// starting and ending indices of the smallest subarray in the input array that needs
// to be sorted in place so that the entire input is sorted.

pair<int, int> subarraySorting(vector<int> a) {
    int n = a.size();
    int s = 0;
    int e = n - 1;
    int maximum, minimum;
    for(s = 0; s < (n - 1); s++) {
        if(a[s] > a[s + 1]) break;
    }
    if(s == n - 1) return make_pair(-1, -1);
    for(e = (n - 1); e > 0; e--) {
        if(a[e] < a[e - 1]) break;
    }
    maximum = minimum = a[s];
    for(int i = (s + 1); i <= e; i++) {
        if(a[i] > maximum) maximum = a[i];
        if(a[i] < minimum) minimum = a[i];
    }
    for(int i = 0; i < s; i++) {
        if(a[i] > minimum) {
            s = i;
            break;
        }
    }
    for(int i = (n - 1); i >= (e + 1); i--) {
        if(a[i] < maximum) {
            e = i;
            break;
        }
    }
    return make_pair(s, e);
}

int main() {
    FIO;
    vi a = {0, 2, 4, 7, 10, 11, 7, 12, 13, 14, 16, 19, 29};
    pair<int, int> res = subarraySorting(a);
    cout << res.first << " " << res.second << nl;
    return 0;
}