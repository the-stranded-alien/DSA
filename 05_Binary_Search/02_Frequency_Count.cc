#include<iostream>
#include<string>
#include<limits>
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
#define vii vector< vector<int> >
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

// Given a sorted array which can contain repeated elements, and an element K,
// we need to find the frequency of a given element.

// Find lower_bound & upper_bound using binary search and
// output = upper_bound - lower_bound + 1

// arr[mid] == key : Don't stop !! => ans = mid & binarySearch(left) !

int lower_bound(vi arr, int key) {
    int s = 0;
    int e = arr.size() - 1;
    int ans = -1;
    while(s <= e) {
        int mid = (s + e) / 2;
        if(arr[mid] == key) {
            ans = mid;
            e = mid - 1;
        }
        else if(arr[mid] > key) e = mid - 1;
        else s = mid + 1;
    }
    return ans;
}

int upper_bound(vi arr, int key) {
    int s = 0;
    int e = arr.size() - 1;
    int ans = -1;
    while(s <= e) {
        int mid = (s + e) / 2;
        if(arr[mid] == key) {
            ans = mid;
            s = mid + 1;
        }
        else if(arr[mid] > key) e = mid - 1;
        else s = mid + 1;
    }
    return ans;
}

int main() {
    FIO;
    vi arr = {0, 1, 1, 2, 3, 3, 3, 3, 3, 4, 5, 5, 5, 10};
    int n = arr.size();
    int low = lower_bound(arr, 3);
    int up = upper_bound(arr, 3);
    cout << (up - low + 1) << nl;
    // STL
    cout << upper_bound(arr.begin(), arr.end(), 3) - lower_bound(arr.begin(), arr.end(), 3);
    return 0;
}