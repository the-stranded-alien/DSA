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

// Given a list of 'n' strings a1, a2, a3, ....., an. Concatenate them together
// in some order such that the resulting string would be lexicographically smallest.
// Given the list of strings, output the lexicographically smallest concatenation.

bool compare(string x, string y) {
    return ((x + y) < (y + x));
}

int main() {
    FIO;
    vs arr;
    string temp;
    int n; cin >> n;
    FOR(i, n) {
        cin >> temp;
        arr.PB(temp);
    }
    sort(arr.begin(), arr.end(), compare);
    for(auto x : arr) cout << x;
    return 0;
}