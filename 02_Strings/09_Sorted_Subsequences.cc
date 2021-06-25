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

// Given a string you need to print all subsequences of the string sorted by length 
// and lexicographic sorted order if length is same.

void subsequence(string s, string o, vs &v) {
    // Base case
    if(s.size() == 0) {
        v.PB(o);
        return;
    }
    // Recursive case
    char ch = s[0];
    string reducedInp = s.substr(1);
    // Include the current char
    subsequence(reducedInp, o + ch, v);
    // Exclude the current char
    subsequence(reducedInp, o, v);
}

bool compare(string s1, string s2) {
    if(s1.length() == s2.length()) return (s1 < s2);
    else return (s1.length() < s2.length());
}

int main() {
    FIO;
    string str;
    cin >> str;
    string output = "";
    vs v;
    subsequence(str, output, v);
    sort(v.begin(), v.end(), compare);
    for(string s : v) cout << s << ", ";
    return 0;
}