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

// We are given a array of boxes. Each box is represented using 3 integers 
// denoting height, width, and depth of the box. Our goal is to stack up the
// boxes and maximise the total height of the stack. You can't rotate any box 
// i.e. integers in each box must represent [width, depth, height] at all times.
// A box must have strictly smaller width, depth, and height than any other box below it.

bool compareBoxes(vi b1, vi b2) {
    return (b1[2] > b2[2]);
}

bool canPlace(vi b1, vi b2) {
    if((b1[0] > b2[0]) and (b1[1] > b2[1]) and (b1[2] > b2[2])) return true;
    else return false;
}

int boxStacking(vii boxes) {
    // 1. Sorting Based on Height
    sort(boxes.begin(), boxes.end(), compareBoxes);
    // 2. DP
    int n = boxes.size();
    vi dp(n+1, 0);
    for(int i = 0; i < n; i++) dp[i] = boxes[i][2]; // Height of 'i'th box.
    for(int i = 1; i < n; i++) {
        // Check for all boxes whose index is less than 'i'
        for(int j = 0; j < i; j++) {
            if(canPlace(boxes[j], boxes[i])) {
                int current_height = boxes[i][2];
                if(dp[j] + current_height > dp[i]) {
                    dp[i] = dp[j] + current_height;
                }
            }
        }
    }
    int max_height = 0;
    for(int i = 0; i < n; i++) {
        cout << dp[i] << ", ";
        max_height = max(max_height, dp[i]);
    }
    return max_height;
}

int main() {
    FIO;
    vii boxes = {
        {2, 1, 2},
        {3, 2, 3},
        {2, 2, 8},
        {2, 3, 4},
        {2, 2, 1},
        {4, 4, 5}   
    }; 
    int height = boxStacking(boxes);
    cout << "\nMax Height : " << height << nl;
    return 0;
}