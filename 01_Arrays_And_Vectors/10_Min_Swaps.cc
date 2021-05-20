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

// Given an array of size N, find the minimum number of swaps needed to make the array as sorted.

// We should know the correct location of each element (Sorting : O(log N))
// Cycle containing N elements would need N-1 swaps

int countMinSwaps(int n, vector<int> elements) {
    int ans = 0;
    // Know the actual positions of elements (sorting)
    P ap[n];
    for(int i = 0; i < n; i++) {
        ap[i].F = elements[i];
        ap[i].S = i;
    }
    // Sorting based on value
    sort(ap, ap + n);
    // Main Logic
    vector<bool> visited(n, false);
    for(int i = 0; i < n; i++) {
        // If element is already visited or element is already in the right position
        int old_position = ap[i].S;
        if(visited[i] == true || old_position == i) continue;
        // Visiting the element (index) for the first time
        int node = i;
        int cycle = 0;
        while(!visited[node]) {
            visited[node] = true;
            int next_node = ap[node].S;
            node = next_node;
            cycle += 1;
        }
        ans += (cycle - 1);
    }
    return ans;
}

int main() {
    FIO;
    int n; cin >> n;
    vector<int> elements;
    for(int i = 0; i < n; i++) {
        int ele; cin >> ele;
        elements.pb(ele);
    }
    cout << countMinSwaps(n, elements) << endl;
    return 0;
}