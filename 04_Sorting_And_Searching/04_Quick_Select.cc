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

// Write a function that takes input an array of distinct integers, and
// return kth smallest in the array.

int partition(vi &arr, int s, int e) {
    int pivot = arr[e];
    int i = s - 1;
    for(int j = s; j < e; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[e]);
    return (i + 1);
}

int quickSelect(vi &arr, int s, int e, int k) {
    int p = partition(arr, s, e);
    if(p == k) return arr[p];
    else if (k < p) return quickSelect(arr, s, p - 1, k);
    else return quickSelect(arr, p + 1, e, k);
}

int main() {
    FIO;
    int n; cin >> n;
    int tmp;
    vi arr;
    FOR(i, n) {
        cin >> tmp;
        arr.PB(tmp);
    }
    int k; cin >> k; // 0 based indexing
    cout << quickSelect(arr, 0, n - 1, k);
    return 0;
}