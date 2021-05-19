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

// Given an array containing N integers, and an number S denoting a target sum.
// Find all distinct integers that can add up to form target sum.
// The numbers in each triplet should be ordered in ascending order, and triplets
// should be ordered too. Return empty array if no such triplet exists.

// 1. Brute Force : O(N^3)
// 2. Using Pair Sum : O(N^2)
// 3. Sorting + Two Pointer : O(N log N) + O(N^2) = O(N^2)

vector< vector<int> > tripletSum(int n, vector<int> elements, int targetSum) {
    vector< vector<int> > result;
    sort(elements.begin(), elements.end());
    // Pick every a[i], pair sum for remaining part
    for(int i = 0; i <= n - 3; i++) {
        int j = i + 1;
        int k = n - 1;
        // Two Pointer Approach
        while(j < k) {
            int current_sum = elements[i];
            current_sum += elements[j];
            current_sum += elements[k];
            if(current_sum == targetSum) {
                result.push_back({elements[i], elements[j], elements[k]});
                j++; k--;
            } else if (current_sum > targetSum) k--;
            else j++;
        }
    }   
    return result;
}

int main() {
    FIO;
    int n; 
    cin >> n;
    vector<int> elements;
    for(int i = 0; i < n; i++) {
        int num; cin >> num;
        elements.push_back(num);
    }
    int sum; 
    cin >> sum;
    auto triplets = tripletSum(n, elements, sum);
        for(vector<int> triplet : triplets) {
            cout << triplet[0] << " " << triplet[1] << " " << triplet[2] << endl;
        }
    return 0;
}