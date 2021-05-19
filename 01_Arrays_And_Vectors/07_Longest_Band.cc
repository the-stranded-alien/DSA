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

// Given an array containing N integers, find the length of longest band.
// A band is defined as a subsequence which can be reordered in such a 
// manner all elements appear consecutive (i.e. with absolute difference
// of 1 between neighbouring elements)
// A longest band is the band (subsequence) which contains maximum integers.

// 1. Sorting and forming bands : O(N Log N)
// 2. Find head/start then lookup using unordered_seT : O(Log N)


int largestBand(int n, vector<int> elements) {
    // Data inside a set
    unordered_set<int> s;
    for(int ele : elements) s.insert(ele);
    // Iterate over the array
    int largestLen = 1;
    for(auto element : s) {
        int parent = element - 1;
        if(s.find(parent) == s.end()) {
            // Find entire band / chain starting from element
            int next_no = element + 1;
            int cnt = 1;
            while(s.find(next_no) != s.end()) {
                next_no++;
                cnt++;
            }
            if(cnt > largestLen) largestLen = cnt;
        }
    }
    return largestLen;
}

int main() {
    FIO;
    int n; cin >> n;
    vector<int> elements;
    for(int i = 0; i < n; i++) {
        int ele; cin >> ele;
        elements.push_back(ele);
    }
    int largest = largestBand(n, elements);
    cout << largest << endl;
    return 0;
}