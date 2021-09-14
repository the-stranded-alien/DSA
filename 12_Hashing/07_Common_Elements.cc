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

// Given two vectors, find the common elements between them. (In sorted order)
// All elements in one vector are unique among themselves.

vector<int> commonElements(vector<int> v1, vector<int> v2) {
    int n1 = v1.size();
    int n2 = v2.size();
    if(n1 > n2) {
        unordered_set<int> ele2(v2.begin(), v2.end());
        vector<int> out;
        for(auto e : v1) {
            if(ele2.count(e) >= 1) out.push_back(e);
        }
        sort(out.begin(), out.end());
        return out;
    } else {
        unordered_set<int> ele1(v1.begin(), v1.end());
        vector<int> out;
        for(auto e : v2) {
            if(ele1.count(e) >= 1) out.push_back(e);
        }
        sort(out.begin(), out.end());
        return out;
    }
}

int main() {
    FIO;
    vi v1 = {1, 45, 54, 71, 76, 12};
    vi v2 = {1, 7, 5, 4, 6, 12};
    vi out = commonElements(v1, v2);
    for(auto e : out) cout << e << " ";
    return 0;
}