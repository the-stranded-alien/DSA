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

// Given two strings, one big string and one small string, find the
// 'smallest window' in the big string that contains all characters
// of the small string. Window can have additional characters than required.
// If small string has duplicates, then those duplicates must be present
// with same or higher count in window.

// Sliding Window -> Expand on one side and contract on the other side !!

// 1. Build frequency map for small string / pattern.
// 2. Maintain hashmap of current window on big string / input.

// Expand, Contract and Maintain Window Size

string find_window(string s, string p) {
    // Array as frequency map or can use unordered_map
    int FP[256] = {0};
    int FS[256] = {0};
    for(int i = 0; i < p.length(); i++) FP[p[i]]++;
    // Sliding window algorithm
    int cnt = 0;
    int start = 0; // left contraction
    int start_idx = -1; // Start index for best window
    int min_so_far = INT_MAX;
    int window_size;
    for(int i = 0; i < s.length(); i++) {
        // Expand the window by including current character
        char ch = s[i];
        FS[ch]++;
        // Count how many characters have been matched till now (string and pattern)
        if((FP[ch] != 0) and (FS[ch] <= FP[ch])) cnt += 1;
        // Another thing, if all characters of the pattern are found in the
        // current window, then start contracting
        if(cnt == p.length()) {
            // Start contracting from the left to remove unwanted characters,
            // i.e those characters which are not present in pattern
            // or frequency is higher than required.
            while((FP[s[start]] == 0) or (FS[s[start]] > FP[s[start]])) {
                FS[s[start]]--;
                start++;
            }
            // Note the window size
            window_size = i - start + 1;
            if(window_size < min_so_far) {
                min_so_far = window_size;
                start_idx = start;
            }
        }
    }
    if(start_idx == -1) return "No Window Found !";
    else return s.substr(start_idx, min_so_far);
}

int main() {
    FIO;
    string s, p;
    cin >> s >> p;
    cout << find_window(s, p) << nl;    
    return 0;
}