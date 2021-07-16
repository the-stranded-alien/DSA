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

// Two Strings are Anagrams of Each Other If The Letters of One String Can Be
// Rearranged To Form The Other String. Given a String, Find The Number of Pairs
// of Substrings of The String That Are Anagrams of Each Other.

// Brute Force : O(N^5)
// Check If Two Strings Are Anagram in Constant Time.
// Club Anagrams With Same Hash Value In Buckets For Efficient Counting.

// Step 1. Generate All The Substrings.
// Step 2. Generate Hash Values Corresponding To Each Of The Substrings.
// Step 3. Put The Hash Values Generated Above in a Hashtable Along With Frequencies. 
// Or in Other Words, Hash the 'Hash' Values to Club All Anagrams in Single Bucket,
// To Get Their Frequency Count.
// Step 4. Find No. Of Anagrams Using The Frequency Count.

vector<int> getHashValue(string s, int i, int j) {
    vector<int> freq(26, 0);
    // Iterate Over The Original String From i To j To Fill This Vector
    for(int k = i; k <= j; k++) {
        char ch = s[k];
        freq[ch - 'a']++;
    }
    return freq;
}

// O(N^3 + N^2) => O(N^3) Time

int anagrams_substrings(string s) {
    // Maps Can Automatically Handle Complex Vector Keys But Unordered_Map Can't.
    map<vector<int>, int> m;
    // No Need to Generate and Store Substrings
    for(int i = 0; i < s.length(); i++) {
        for(int j = i; j < s.length(); j++) {
            // Substring s[i...j]
            vector<int> h = getHashValue(s, i, j);
            // Put It Inside a Map
            m[h]++;
        }
    }
    int ans = 0;
    for(auto p : m) {
        int freq = p.second;
        if(freq >= 2) ans += (freq) * (freq - 1)/2; 
    }
    return ans;
}

int main() {
    FIO;
    string s;
    cin >> s;
    cout << anagrams_substrings(s) << nl;
    return 0;
}