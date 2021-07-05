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

// Given a string S, find all permutations of the string.
// No of Permutations for String With Length 'N' = N!

// Restore our original array while going back : Backtracking !

void printPermutations(string input, int idx = 0) {
    // Base Case
    if(input[idx] == '\0') {
        cout << input << nl;
        return;
    }
    // Recursive Case
    for(int itr = idx; input[itr] != '\0'; itr++) {
        swap(input[idx], input[itr]);
        printPermutations(input, idx + 1);
        swap(input[idx], input[itr]); // Backtracking to Restore Original Array
    }   
    return;
}

int main() {
    FIO;
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}