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

// Efficient Searching Algorithm to find the index of element in a given sorted array !!

int binarySearch(int arr[], int n, int key) {
    int s = 0;
    int e = n - 1;
    while(s <= e) {
        int mid = (s + e) / 2;
        if(arr[mid] == key) return mid;
        else if(arr[mid] > key) e = mid - 1;
        else s = mid + 1;
    }
    return -1;
}

int main() {
    FIO;
    int arr[] = {1,2,3,4,5,6,7,8,9};
    cout << binarySearch(arr, 9, 5);
    return 0;
}