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

// The K-Way Merge Problem Consists of Merging K-Sorted Arrays to Produce
// A Single Sorted Array With The Same Elements. K-Way Merge Are Used in
// External Sorting Procedures. External Sorting Algorithms are a Class of
// Sorting Algorithms That Can Handle Massive Amounts Of Data. 

// Given K-Sorted Arrays of Different Sizes, Produce a Single Sorted Array.

// Min Heap of K Elements. Time : O(N K log N)

vector<int> mergeKArrays(vector< vector<int> > arrays) {
    int k = arrays.size();
    // Triplet -> Element, Array Index, Element Index (Min Heap)
    priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pq;
    vector<int> output;
    // Init the Heap
    for(int i = 0; i < k; i++) {
        int element = arrays[i][0];
        pq.push({element, i, 0});
    }
    // Start Popping & Pushing More Elements
    while(!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int element = top[0];
        int arrIdx = top[1];
        int eleIdx = top[2];
        output.push_back(element);
        if((eleIdx + 1) < arrays[arrIdx].size()) {
            int next_element = arrays[arrIdx][eleIdx + 1];
            pq.push({next_element, arrIdx, (eleIdx + 1)});
        }
    }
    return output;
}

int main() {
    FIO;
    vector< vector<int> > arr = {{10,15,20,30},{2,5,8,14,24},{0,11,60,90}};
    vector<int> result = mergeKArrays(arr);
    for(auto x : result) cout << x << " ";
    return 0;
}