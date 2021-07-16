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

// You Are Given an Array and You Need to Count Number of
// Triplets with Indices (i, j, k) Such That the Elements
// at Those Indices are in Geometric Progression for a Given
// Common Ratio 'r' and 'i' (i < j < k).

// Sliding Hashing Algorithm

int count_triplets(vector<int> arr, int r) {
    int n = arr.size();
    unordered_map<long, long> rightMap, leftMap;
    // Init the Right Map With Freq, Left Map = 0
    for(auto x : arr) {
        rightMap[x]++;
        leftMap[x] = 0;
    }
    // Compute by Iterating Left to Right
    int ans = 0;
    for(int i = 0; i < n; i++) {
        rightMap[arr[i]]--;
        if(arr[i] % r == 0) {
            long b = arr[i];
            long a = arr[i] / r;
            long c = arr[i] * r;
            ans += leftMap[a] * rightMap[c];
        }
        leftMap[arr[i]]++;
    }
    return ans;
}

int main() {
    FIO;
    int n, r;
    cin >> n >> r;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << count_triplets(arr, r) << nl;
    return 0;
}