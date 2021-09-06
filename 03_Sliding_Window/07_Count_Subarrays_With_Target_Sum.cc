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

// Given an Unsorted Array of Integers, find the Number of Subarrays having Sum
// Exactly Equal to a given Number 'K'.

int cntSubarrays(vector<int> arr, int k) {
    int n = arr.size();
    unordered_map<int, int> prevSum;
    int result = 0;
    int currentSum = 0;
    for(int i = 0; i < n; i++) {
        currentSum += arr[i];
        if(currentSum == k) result++;
        if(prevSum.find(currentSum - k) != prevSum.end()) {
            result += (prevSum[currentSum - k]);
        }
        prevSum[currentSum]++;
    }
    return result;
}

int main() {
    FIO;
    vi arr = {10, 2, -2, -20, 10};
    int k = -10;
    cout << cntSubarrays(arr, k) << nl;
    return 0;
}