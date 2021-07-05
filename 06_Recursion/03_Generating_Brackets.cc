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
#define vb vector<bool>
#define vii vector< vector<int> >
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

// Write a function to generate all possible 'n' pairs
// of balanced parenthesis.

// Two independent conditions
// 1. close < open
// 2. open < N

void generateBrackets(string output, int n, int open, int close, int idx) {
    // Base case
    if(idx == (2 * n)) {
        cout << output << nl;
        return;
    }
    // Open
    if(open < n) generateBrackets(output + '(', n, open + 1, close, idx + 1);
    // Close 
    if(close < open) generateBrackets(output + ')', n, open, close + 1, idx + 1);
}

void generateBrackets2(string output, int n, int open, int close, int idx) {
    // Base case
    if(idx == (2 * n)) {
        cout << output << nl;
        return;
    }
    // Open
    if(open < n) {
        output += '(';
        generateBrackets2(output, n, open + 1, close, idx + 1);
        output.pop_back();
    }
    // Close 
    if(close < open) {
        output += ')';
        generateBrackets2(output, n, open, close + 1, idx + 1);
        output.pop_back();
    } 
}

int main() {
    FIO;
    int N; cin >> N;
    string output;
    generateBrackets(output, N, 0, 0, 0);
    return 0;
}