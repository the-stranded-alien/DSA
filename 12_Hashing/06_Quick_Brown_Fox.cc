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

// Given A String Without Spaces And a List of Words. Write a Function
// That Finds The Minimum Bars to be Added to The String, So That All
// Resulting Words Are Found In The List.

// Recursion + Hashing + Dynamic Programming

// Main Logic
int min_bars_helper(string s, vs &words, int idx, unordered_set<string> &m) {
    // Base Case
    if(s[idx] == '\0') return 0;
    // Recursive Case
    int ans = INT_MAX;
    string current_string = "";
    for(int j = idx; s[j] != '\0'; j++) {
        current_string += s[j];
        // At Every Step You Can Check Whether This Prefix is Present In Set or Not
        if(m.find(current_string) != m.end()) {
            int remaining_ans = min_bars_helper(s, words, j + 1, m);
            if(remaining_ans != -1) {
                ans = min(ans, 1 + remaining_ans);
            }
        }
    }
    if(ans == INT_MAX) return -1;
    else return ans;
}

int min_bars(string str, vs words) {
    unordered_set<string> m;
    for(string w : words) m.insert(w);
    // Recursive Helper Function
    int output = min_bars_helper(str, words, 0, m);
    return (output - 1);
}

int main() {
    FIO;
    string s = "thequickbrownfoxjumpsoverthehighbridge";
    vector<string> words = {"the", "fox", "thequickbrownfox", "jumps", "lazy", "lazyfox", "highbridge",
                        "the", "over", "bridge", "high", "tall", "quick", "brown"};
    cout << min_bars(s, words) << nl;
    return 0;
}