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

// Given an array containing integers, you need to count the total number of inversions.
// Inversion: Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j !

// Brute Force : O(N^2)
// How many inversions each element will form !
// Divide and Conquer : Merge Sort
// C1 -> Inversions in Part 1
// C2 -> Inversions in Part 2
// Ci -> Cross Inversions
// Inversions = C1 + C2 + Ci
// O(N log N) time 

// Helper Method
int merge(vi &array, int s, int e) {
    int i = s;
    int m = (s + e) / 2;
    int j = m + 1;
    vi temp;
    int cnt = 0;
    while(i <= m and j <= e) {
        if(array[i] < array[j]) temp.PB(array[i++]);
        else { 
            cnt += (m - i + 1);
            temp.PB(array[j++]);
        }
    }
    // Copy remaining of elements from first array
    while(i <= m) temp.PB(array[i++]);
    // Or Copy remaining of elements from second array
    while(j <= e) temp.PB(array[j++]);
    // Copy back the elements from temp to original array
    int k = 0;
    for(int idx = s; idx <= e; idx++) {
        array[idx] = temp[k++];
    }
    return cnt;
}

// Sorting Method
int inversionCount(vi &array, int s, int e) {
    // Base case
    if(s >= e) return 0;
    // Recursive Case
    int mid = (s + e) / 2;
    int C1 = inversionCount(array, s, mid);
    int C2 = inversionCount(array, mid + 1, e);
    int CI = merge(array, s, e);
    return (C1 + C2 + CI);
}

int main() {
    FIO;
    int n; cin >> n;
    vi arr;
    FOR(i, n) {
        int temp; cin >> temp;
        arr.PB(temp);
    }
    int s = 0;
    int e = arr.size() - 1;
    cout << inversionCount(arr, s, e);
    return 0;
}