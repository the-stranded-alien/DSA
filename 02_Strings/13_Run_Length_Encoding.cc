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

// Perform basic string compression using the counts of repeated characters,
// also known as run length encoding.

string compressString(const string &str) {
    string compressedString = "";
    int curCharCount = 0;
    char curChar = str[0];
    for(char ch : str) {
        if(ch == curChar) curCharCount++;
        else {
            compressedString += curChar;
            compressedString += to_string(curCharCount);
            curChar = ch;
            curCharCount = 1;
        }
    }
    compressedString += curChar;
    compressedString += to_string(curCharCount);
    if(compressedString.length() < str.length()) return compressedString;
    else return str;
}

int main() {
    FIO;
    string text = "bbbaaaadexxxxxx";
    cout << compressString(text);
    return 0;
}