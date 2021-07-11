#include<iostream>
#include<string>
#include <sstream>
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

// Stack

string simplifyPath(string path) {
    // 1. Tokenization & Filtering
    istringstream iss(path);
    vs tokens;
    string token;
    while(getline(iss, token, '/')) {
        if(token == "" || token == ".") continue;
        else tokens.PB(token);
    }
    // 2. Handle '..'
    vector<string> stack; // Using Vector as a Stack
    if(path[0] == '/') {
        // Denotes That Path is an Absolute Path w.r.t. Root Directory
        stack.push_back("");
    }
    for(string token : tokens) {
        if(token == "..") {
            // Absolute Path & Relative Path
            if(stack.size() == 0 || stack[stack.size() - 1] == "..") stack.push_back("..");
            else if(stack[stack.size() - 1] != "") stack.pop_back();
        } else {
            stack.push_back(token);
        }
    }
    // Single Element
    if(stack.size() == 1 && stack[0] == "") return "/";
    // Combine All Elements in Stack to Get the Answer
    ostringstream oss;
    int i = 0;
    for(auto token : stack) {
        if(i != 0) oss << "/";
        i++;
        oss << token;
    }
    return oss.str();
}

int main() {
    FIO;
    string path = "/../x/y/../z/././w/a///../../c/./"; // Output : /x/z/c
    cout << simplifyPath(path) << nl;
    return 0;
}