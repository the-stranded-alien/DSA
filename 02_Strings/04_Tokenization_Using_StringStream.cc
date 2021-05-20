#include<bits/stdc++.h>
#define ll long long int
#define ld long long double
#define pb push_back
#define F first
#define S second
#define P pair<int, int>
#define MOD 1000000007
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

// Tokenizing a string denotes splitting a string with respect to some delimiter(s).


int main() {
    FIO;
    string input;
    getline(cin, input);
    // Create a string stream object
    stringstream ss(input);
    // >> and << operators
    string token;
    vector<string> tokens;
    while(getline(ss, token, ' ')) {
        tokens.pb(token);
    }
    // Print all tokens
    for(auto token : tokens) {
        cout << token << ", ";
    }
    return 0;
}