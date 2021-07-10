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

// Given an expression string, write a program to 
// check all the pairs of parenthesis are valid.

bool isBalanced(string input) {
    stack<char> s;
    for(auto ch : input) {
        switch(ch) {
            case '(':
            case '[':
            case '{': s.push(ch);
                        break;
            case ')': if(!s.empty() && s.top() == '(') s.pop();
                      else return false;
                      break;
            case ']': if(!s.empty() && s.top() == '[') s.pop();
                      else return false;
                      break;
            case '}': if(!s.empty() && s.top() == '{') s.pop();
                      else return false;
                      break;
            default: continue;
        }
    }
    if(s.empty() == true) return true;
    else return false;
}

int main() {
    FIO;
    string s = "((a+b+c)+[d])";
    if(isBalanced(s)) cout << "Balanced !" << nl;
    else cout << "Not Balanced\n";    
    return 0;
}