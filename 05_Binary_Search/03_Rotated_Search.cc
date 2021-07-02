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

// Write a function that take input an sorted array of
// distinct integers, which is rotated about a pivot
// point and finds the index of any given element.

int rotatedSearch(vi a, int key) {
    int n = a.size();
    int s = 0;
    int e = n - 1;
    while(s <= e) {
        int mid = (s + e) / 2;
        if(a[mid] == key) return mid;
        // Two Cases
        if(a[s] <= a[mid]) {
            // Left
            if(key >= a[s] && key <= a[mid]) e = mid - 1;
            else s = mid + 1;
        }
        else {
            // Right
            if(key >= a[mid] && key <= a[e]) s = mid + 1;
            else e = mid - 1;           
        }
    }
    return -1;
}

int main() {
    FIO;
    vi a{4, 5, 6, 7, 0, 1, 2, 3};
    int key; cin >> key;
    cout << rotatedSearch(a, key) << nl;
    return 0;
}