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

// Given a number N and a modern phone keypad. Find out all possible
// strings generated using that number.

string keypad[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void printKeypadOutput(string input, string output, int i = 0) {
    // Base Case
    if(input[i] == '\0') {
        cout << output << endl;
        return;
    }
    // Recursive Case
    int current_digit = input[i] - '0';
    if(current_digit == 0 || current_digit == 1) printKeypadOutput(input, output, i + 1);
    // Keypad
    for(int k = 0; k < keypad[current_digit].size(); k++) {
        printKeypadOutput(input, output + keypad[current_digit][k], i + 1);
    }
    return;
}

int main() {
    FIO;
    string input;
    cin >> input;
    string output;
    printKeypadOutput(input, output);
    return 0;
}