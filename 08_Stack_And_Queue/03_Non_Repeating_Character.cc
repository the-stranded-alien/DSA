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

// Given a running stream of characters, output the first non-repeating character
// in the string formed so far after every new character you get in the input.
// Output -1 if such a character doesn't exist.

int main() {
    FIO;
    queue<char> q;
    int freq[27] = {0};
    char ch;
    cin >> ch;
    while(ch != '.') {
        q.push(ch);
        freq[ch - 'a']++;
        // Query -> Remove all chars from front of queue till you get a char with freq 1
        while(!q.empty()) {
            int idx = q.front() - 'a';
            if(freq[idx] > 1) q.pop();
            else {
                cout << q.front() << nl;
                break;
            }
        }
        if(q.empty()) cout << "-1" << nl;
        cin >> ch;
    }
    return 0;
}