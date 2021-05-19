#include<bits/stdc++.h>
#define ll long long int
#define ld long long double
#define pb push_back
#define F first
#define S second
#define P pair<int, int>
#define MOD 1000000007
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

// Given n non-negative integers representing an elevation map where the width
// of each bar is 1, compute how much water it can trap after raining.

// Water tapped at a particular position (block) O(N)
// => minimum(highest bar on left, highest bar on right) - height of bar at current position
// Maintain two arrays for finding maximum length bar (left and right)

int rainWaterTrapped(int n, vector<int> heights) {   
    if (n <= 2) return 0;
    // Left max & right max
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    left[0] = heights[0];
    right[n-1] = heights[n-1];
    for(int i = 1; i < n; i++) {
        left[i] = max(left[i-1], heights[i]);
        right[n-i-1] = max(right[n-i], heights[n-i-1]);
    }
    // Water Trapped
    int water = 0;
    for(int i = 0; i < n; i++) {
        water += min(left[i], right[i]) - heights[i];
    }
    return water;
}

int main() {
    FIO;
    int n; cin >> n;
    vector<int> heights;
    for(int i = 0; i < n; i++) {
        int ele; cin >> ele;
        heights.pb(ele);
    }
    int water = rainWaterTrapped(n, heights);
    cout << water << endl;
    return 0;
}