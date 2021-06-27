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

// Given a sorted array of strings that is interspersed with empty strings,
// write a method to find the location of a given string.

// Linear Search: O(N)
// Binary Seach: X
// Modified Binary Search: Better than O(N)
// If mid is empty then traverse to nearest non-empty string by
// traversing lineraly in both direction

int sparseSearch(string arr[], int n, string key) {
    int s = 0;
    int e = n - 1;
    while(s <= e) {
        int mid = (s + e) / 2;
        int mid_left = mid - 1;
        int mid_right = mid + 1;
        if(arr[mid] == "") {
            // Update our mid to point to a nearest non-empty string
            while(1) {
                if(mid_left < s and mid_right > e) return -1;
                else if(mid_right <= e && arr[mid_right] != "") {
                    mid = mid_right;
                    break;
                }
                else if(mid_left >= s && arr[mid_left] != "") {
                    mid = mid_left;
                    break;
                }
                mid_left--;
                mid_right++;
            }
        } 
        if(arr[mid] == key) return mid;
        else if(arr[mid] > key) e = mid - 1;
        else s = mid + 1;
    }
    return -1;
}

int main() {
    FIO;
    string arr[] = {"ai", "", "", "bat", "", "", "car", "cat", "", "", "dog", "e"};
    int n = 12;
    string str; cin >> str;
    cout << sparseSearch(arr, n, str) << nl;
    return 0;
}