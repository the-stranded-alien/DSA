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

// Given a string of balanced expression, find if it contains a
// redundant parenthesis.

bool checkRedundant(string str) {
    stack<char> s;
    for(char ch : str) {
        if(ch != ')') s.push(ch);
        else {
            bool operatorFound = false;
            while(!s.empty() && s.top() != '(') {
                char top = s.top();
                if(top == '+' || top == '-' || top == '*' || top == '/') {
                    operatorFound = true;
                }
                s.pop();
            }
            s.pop(); // Pop the opening bracket after the loop is over
            if(operatorFound == false) return true;
        }
    }
    return false;
}

int main() {
    FIO;
    string str = "(((a+b))+c)";
    if(checkRedundant(str)) cout << "Contains Redundant Parenthesis\n";
    else cout << "Doesn't Contain Redundant Parenthesis\n";    
    return 0;
}