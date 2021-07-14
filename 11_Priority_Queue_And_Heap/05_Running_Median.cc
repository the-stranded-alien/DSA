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

// You Are Given a Running Stream of Integers. Write an Efficient Algorithm to
// Output Median of Numbers Read So Far After Every Input.
// Median -> Middle Most Values !

// Observing How Median Shifts, It Will Either Stay Same Or Go To 
// Next Larger Number or Previous Smaller Number.

// For All The Elements to The Left Of Median (SMALLER) Maintain a MAX Heap.
// For All The Elements to The Right Of Median (LARGER) Maintain a MIN Heap.

// 1. If We Have 'N' Number Of Elements In Both The Heaps Then
// Median is Average of Both The Roots.
// 2. If We Have 'N+1' Elements in One Heap And 'N' Elements in The Other
// Heap Then Median is Root of Heap With 'N+1' Elements.
// 3. We Maintain Equal Heap Size At All Times.

// Time : O(log N) for One Insertion, O(1) For One Query => Total : O(N log N)

int main() {
    FIO;
    priority_queue<int> leftHeap; // Max-Heap
    priority_queue<int, vector<int>, greater<int> > rightHeap; // Min-Heap
    int d;
    cin >> d;
    leftHeap.push(d);
    float med = d;
    cout << med << " ";
    cin >> d;
    while(d != -1) {
        // 1. Left Heap Is Bigger
        if(leftHeap.size() > rightHeap.size()) {
            if(d < med) { // Rebalancing
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
                leftHeap.push(d);
            } else rightHeap.push(d);
            med = (leftHeap.top() + rightHeap.top()) / 2.0;
        }
        // 2. Both Heaps Are Same Size
        else if(leftHeap.size() == rightHeap.size()) {
            if(d < med) {
                leftHeap.push(d);
                med = leftHeap.top();
            } else {
                rightHeap.push(d);
                med = rightHeap.top();
            }
        } 
        // 3. Right Heap Is Bigger 
        else {
            if(d < med) leftHeap.push(d);
            else { // Rebalancing
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
                rightHeap.push(d);
            }
            med = (leftHeap.top() + rightHeap.top()) / 2.0;
        }
        cout << med << " ";
        cin >> d;
    }
    return 0;
}