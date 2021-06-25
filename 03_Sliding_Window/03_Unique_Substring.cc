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
#define nl '\n'
#define tab '\t'
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

// Given a string, write a function to find the largest substring 
// with unique characters (no duplicates) #Hashing
// aabcb -> abc

// Optimise : Storing the last occurence of current char
// Lookup: unordered_map, Start a new window, Expand your current window.

string unique_substring(string str) {
    int firstPtr = 0;
    int secondPtr = 0;
    int window_len = 0;
    int max_window_len = 0;
    int start_window = -1;
    unordered_map<char, int> lookupMap;
    while(secondPtr < str.length()) {
        char ch = str[secondPtr];
        // If it is inside hashmap & its index >= start of the current window.
        if(lookupMap.count(ch) and lookupMap[ch] >= firstPtr) {
            firstPtr = lookupMap[ch] + 1;
            window_len = secondPtr - firstPtr; // Updated remaining window length excluding current char
        }
        // Update the last occurence
        lookupMap[ch] = secondPtr;
        window_len++;
        secondPtr++;
        // Update max_window length at every step
        if(window_len > max_window_len) {
            max_window_len = window_len;
            start_window = firstPtr;
        }
    }
    return str.substr(start_window, max_window_len);
}

int main() {
    FIO;
    string input; cin >> input;
    cout << unique_substring(input);
    return 0;
}