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

// Given a Palindromic string of lowercase English letters, replace exactly one
// character with any lowercase English letter so that the resulting string is not
// a palindrome and that is the lexicographically smallest one possible.
// Return the resulting string, if there is no way to replace a character to make
// it not a palindrome, return an empty string.

string breakPalindrome(string palindrome) {
    string palindromeCopy = palindrome;
    // Impossible to Perform the Replacement if Length = 1
    if(palindrome.length() == 1) return "";
    // Step 1. Change the first non 'a' character to 'a'.
    for(int i = 0; i < palindrome.length(); i++) {
        if(palindrome[i] != 'a') {
            palindrome[i] = 'a';
            break;
        }
    }
    // Step 2. If String has only 'a', Change last character to 'b'.
    bool allA = true;
    for(int i = 0; i < palindrome.length(); i++) {
        if(palindrome[i] != 'a') {
            allA = false;
            break;
        }
    }
    if(allA) {
        palindrome = palindromeCopy;
        palindrome[palindromeCopy.length() - 1] = 'b';
    }
    return palindrome;
}

int main() {
    FIO;
    string palindrome = "aba";
    cout << breakPalindrome(palindrome);
    return 0;
}