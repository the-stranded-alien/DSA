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

// Divide & Conquer Algorithm
// 1. Divide array in two parts
// 2. MergeSort(Left) & MergeSort(Right)
// 3. Merge(Left + Right)

// Helper Method
void merge(vi &array, int s, int e) {
    int i = s;
    int m = (s + e) / 2;
    int j = m + 1;
    vi temp;
    while(i <= m and j <= e) {
        if(array[i] < array[j]) {
            temp.PB(array[i]);
            i++;
        } else {
            temp.PB(array[j]);
            j++;
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
    return;
}

// Sorting Method
void mergeSort(vi &array, int s, int e) {
    // Base case
    if(s >= e) return;
    // Recursive Case
    int mid = (s + e) / 2;
    mergeSort(array, s, mid);
    mergeSort(array, mid + 1, e);
    return merge(array, s, e);
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
    mergeSort(arr, s, e);
    for(int x : arr) cout << x << " ";
    return 0;
}