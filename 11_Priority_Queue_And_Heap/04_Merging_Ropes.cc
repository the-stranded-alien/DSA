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

// Given N Ropes Each Having a Different Size, Your Task is to Join the Ropes
// Together. The Cost of Joining 2 Ropes of Different Sizes X and Y is (X + Y).
// Find the Minimum Cost to Join All the Ropes Together.

// Min Heap Algorithm :
// 1. Add all the elements in min heap.
// 2. Pick the smallest pair of ropes, join them and add their cost.
// 3. Add the new rope in min heap.
// 4. Repeat until a single rope is left.

int minCostToMergeRopes(int ropes[], int n) {
    // Min Heap
    priority_queue<int, vector<int>, greater<int> > min_heap(ropes, ropes + n);
    // Logic
    int cost = 0;
    while(min_heap.size() > 1) {
        int A = min_heap.top();
        min_heap.pop();
        int B = min_heap.top();
        min_heap.pop();
        int new_rope = (A + B);
        cost += new_rope;
        min_heap.push(new_rope);
    }
    return cost;
}

int main() {
    FIO;
    int N = 4;
    int ropes[] = {4, 3, 2, 6};
    cout << minCostToMergeRopes(ropes, N) << nl;
    return 0;
}