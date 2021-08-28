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

// Function that returns a vector of same length where each element in the output
// array is equal to the product of every other number in the input array.
// Solve this problem without using divison operator.

vector<int> productArray(vector<int> arr) {
    int n = arr.size();
    vector<int> output(n, 1);
    vector<int> prodFromLeft(n, 1);
    vector<int> prodFromRight(n, 1);
    prodFromLeft[0] = arr[0];
    for(int i = 1; i < n; i++) {
        prodFromLeft[i] = prodFromLeft[i - 1] * arr[i];
    }
    prodFromRight[n - 1] = arr[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        prodFromRight[i] = prodFromRight[i + 1] * arr[i];
    }

    output[0] = prodFromRight[1];
    output[n - 1] = prodFromLeft[n - 2];
    for(int i = 1; i < n - 1; i++) {
        output[i] = prodFromRight[i + 1] * prodFromLeft[i - 1];
    }
    return output;
}

vector<int> productArrayOpt(vector<int> arr) {
    int n = arr.size();
    vector<int> output(n, 1);
    int temp = 1;
    for(int i = 0; i < n; i++) {
        output[i] = temp;
        temp *= arr[i]; 
    }
    temp = 1;
    for(int i = n - 1; i >= 0; i--) {
        output[i] *= temp;
        temp *= arr[i];
    }
    return output;
}

int main() {
    FIO;
    vi arr = {1, 2, 3, 4, 5};
    vi out = productArrayOpt(arr);
    for(auto x : out) cout << x << " ";
    return 0;
}