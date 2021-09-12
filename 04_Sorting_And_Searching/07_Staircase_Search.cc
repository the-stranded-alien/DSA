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

// Given a M x N matrix which is row wise and column wise sorted, search the index of
// a given integer K in the matrix.

pair<int, int> search(int m, int n, vector<vector<int> > v, int k) {
    int i = 0;
    int j = n - 1;
    pair<int, int> res = {-1, -1};
    while(((i >= 0) && (i < m)) && ((j >= 0) && (j < n))) {
        if(k > v[i][j]) i++;
        else if(k < v[i][j]) j--;
        else {
            res = {i, j};
            break;
        }
    }
    return res;
}

int main() {
    FIO;
    int m = 3;
    int n = 3;
    vii v = {{1, 4, 9}, {2, 5, 10}, {6, 7, 11}};
    int k = 10;
    pair<int, int> res = search(m, n, v, k);  
    cout << res.first << " " << res.second << nl;
    return 0;
}