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

// Given a vector of strings strs, your task is to group the anagrams together.
// An Anagram is a word or phrase formed by rearranging the letters of a different
// word or phrase, typically using all the original letters exactly once.

vector<vector<string> > groupAnagrams(vector<string> strs){
    unordered_map<string, vector<string> > groupMap;
    for(auto str : strs) {
        string copy = str;
        sort(str.begin(), str.end());
        groupMap[str].push_back(copy);
    }
    vector<vector<string> > out;
    for(auto vec : groupMap) {
        out.push_back(vec.second);
    }
    return out;
}

int main() {
    FIO;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string> > out = groupAnagrams(strs);
    for(auto vec : out) {
        for(auto ele : vec) cout << ele << " ";
        cout << nl;
    }
    return 0;
}