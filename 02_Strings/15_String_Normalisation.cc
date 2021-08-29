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

// Given a sentence with words separated by spaces, return a copy of the sentence
// where all the words, start with a capital letter & the rest of the letters
// are lower case.

// string normalize(const string &sentence) {
//     string copy = sentence;
//     bool shouldMakeCapital = true;
//     for(int i = 0; i < copy.length(); i++) {
//         if(shouldMakeCapital) {
//             copy[i] = toupper(copy[i]);
//             shouldMakeCapital = false;
//         } else copy[i] = tolower(copy[i]);
//         if(copy[i] == ' ') shouldMakeCapital = true;
//     }
//     return copy;
// }

int skipWhiteSpace(const string &sentence, int idx) {
    while(idx < sentence.length() && sentence[idx] == ' ') idx += 1;
    return idx;
}

int normalize_word(string &sentence, int idx) {
    if(idx < sentence.length() && sentence[idx] != ' ') {
        sentence[idx] = toupper(sentence[idx]);
        idx += 1;
    }
    while(idx < sentence.length() && sentence[idx] != ' ') {
        sentence[idx] = tolower(sentence[idx]);
        idx += 1;
    }
    return idx;
}

string normalize(const string &sentence) {
    string copy = sentence;
    int idx = 0;
    while(idx < copy.length()) {
        idx = skipWhiteSpace(copy, idx);
        idx = normalize_word(copy, idx);
    }
    return copy;
}

int main() {
    FIO;
    string sentence = "This is SO MUCH FUN!";
    cout << normalize(sentence);
    return 0;
}