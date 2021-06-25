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

// Along one side of a road there is a sequence of vacant plots of land.
// Each plot has a differnt area (non zero). So, the areas form a sequence
// A[1], A[2], .... A[N]. You want to buy K acres of land to build a house.
// You want to find all segments of continguous plots(i.e., a subsection in the
// sequence) of whose sum is exactly K.

// O(N^3) => Brute Force
// O(N^2) => Prefix Sum + Brute Force
// O(N log N) => Prefix Sum + Binary Search on Non Decreasing Sequence
// O(N) => Sliding Window (Two Pointer) 


// Expand towards right contract from left !
// Each element entered the window once and would leave once.

void housing(int *arr, int n, int k) {
    
    int i = 0;
    int j = 0;
    int cs = 0;

    while(j < n) {
        // Expand to Right
        cs += arr[j];
        j++;
        // Remove elements from the left till cs > sum and i < j
        while((cs > k) and (i < j)) {
            cs = cs - arr[i];
            i++;
        }
        // Check if any given point
        if(cs == k) {
            // Print that window
            cout << i << " - " << (j - 1) << nl;
        }
    }
    return;
}

int main() {
    FIO;
    int plots[1000];
    int n; cin >> n;
    FOR(i, n) cin >> plots[i];
    int k; cin >> k;
    housing(plots, n, k);
    return 0;
}