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

// Given a String, Find the Smallest Window (Substring) which Contains All
// Distinct Characters of the given input string.
const int MAX_CHARS = 256;

string smallestWindow(string str) {
    int n = str.length();
    if(n <= 1) return str;
    int distinctChars = 0;
    bool visited[MAX_CHARS] = { false };
    for(int i = 0; i < n; i++) {
        if(!visited[str[i]]) {
            visited[str[i]] = true;
            distinctChars++;
        }
    }
    int startIdx = -1;
    int start = 0;
    int minLength = INT_MAX;
    int count = 0;
    int currChar[MAX_CHARS] = { 0 };
    for(int j = 0; j < n; j++) {
        currChar[str[j]]++;
        if(currChar[str[j]] == 1) count++;
        if(count == distinctChars) {
            while(currChar[str[start]] > 1) {
                if(currChar[str[start]] > 1) currChar[str[start]]--;
                start++;
            }
            int lenWindow = j - start + 1;
            if(minLength > lenWindow) {
                minLength = lenWindow;
                startIdx = start;
            }
        }
    }
    return str.substr(startIdx, minLength);
}

int main() {
    FIO;
    string s = "aabcbcdbcaaad";
    cout << smallestWindow(s);
    return 0;
}