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

// Given an array of integers and an integer K, return a vector containing maximum 
// for each and every contiguous subarray of size k.

vector<int> maxInWindow(vector<int> input, int k) {
    int n = input.size();
    vector<int> output;
    deque<int> deck(k);
    for(int i = 0; i < k; i++) {
        while((!deck.empty()) && (input[i] >= input[deck.back()])) deck.pop_back();
        deck.push_back(i);        
    }
    for(int i = k; i < n; i++) {
        output.push_back(input[deck.front()]);
        while((!deck.empty()) && (deck.front() <= (i - k))) deck.pop_front();
        while((!deck.empty()) && (input[i] >= input[deck.back()])) deck.pop_back();
        deck.push_back(i);
    }
    output.push_back(input[deck.front()]);
    return output;
}

int main() {
    FIO;
    vi input = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 3;
    vi output = maxInWindow(input, k);
    for(auto x : output) cout << x << " ";
    return 0;
}