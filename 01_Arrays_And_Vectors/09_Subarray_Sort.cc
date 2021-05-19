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

// Given an array of size at-least two, find the smallest subarray that needs to be sorted
// in place so that entire input array becomes sorted. If the input array is already sorted,
// the function should return [-1,-1], otherwise return the start & end index of smallest subarray.

// 1. Sort and Compare : O(N Log N)
// 2. Look for largest and smallest elements that are out of order (peak)
// and then find their correct location. : O(N) Time

P subarraySort_brute(int n, vector<int> elements) {
    // Brute : O(N Log N) Time & O(N) Space
    vector<int> copy(elements);
    sort(copy.begin(), copy.end());
    int i = 0;
    while(i < n && elements[i] == copy[i]) i++;
    int j = n-1;
    while(j >=0 && elements[j] == copy[j]) j--;
    if(i == n) return {-1, -1};
    else return {i, j};
}

bool outOfOrder(vector<int> elements, int idx) {
    int x = elements[idx];
    if(idx == 0) return (x > elements[1]);
    if(idx == elements.size() - 1) return (x < elements[idx-1]);
    return ((x > elements[idx+1]) || (x < elements[idx-1]));
}

P subarraySort(int n, vector<int> elements) { // O(N) Time
    int smallest = INT_MAX;
    int largest = INT_MIN;
    for(int i = 0; i < n; i++) {
        int x = elements[i];
        if(outOfOrder(elements, i)) {
            smallest = min(smallest, x);
            largest = max(largest, x);
        }
    }
    // Find the right index where smallest and largest should be present (subarray) for solution 
    if(smallest == INT_MAX) return {-1, -1};
    int left = 0;
    while(smallest >= elements[left]) left++;
    int right = elements.size() - 1;
    while(largest <= elements[right]) right--;
    return {left, right};
}

int main() {
    FIO;
    int n; cin >> n;
    vector<int> elements;
    for(int i = 0; i < n; i++) {
        int ele; cin >> ele;
        elements.pb(ele);
    }   
    P indexPair1 = subarraySort_brute(n, elements);
    cout << indexPair1.F << " " << indexPair1.S << endl;
    P indexPair2 = subarraySort(n, elements);
    cout << indexPair2.F << " " << indexPair2.S << endl;
    return 0;
}