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

// Implement a function that prints the maximum subarray sum that can be formed.
// A subarray is defined as consecutive segment of the array.

int maxSubarraySum(vector<int> arr){
    //Complete this function, your function should return the maximum subarray sum
    int n = arr.size();
    vector<int> temp(n, 0);
    int maxSum = INT_MIN;
    temp[0] = arr[0];
    for(int i = 1; i < n; i++) {
        temp[i] = max(arr[i], arr[i] + temp[i-1]);
    }
    for(int i = 0; i < n; i++) {
        maxSum = max(maxSum, temp[i]);
    }
    if(maxSum < 0) return 0;
    else return maxSum;
}

int main() {
    FIO;
    vector<int> vec({-1, -7, -3, -4, -5, -2});
    cout << maxSubarraySum(vec) << endl;   
    return 0;
}