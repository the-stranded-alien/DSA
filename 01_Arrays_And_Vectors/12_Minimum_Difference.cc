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

// Take in two non-empty arrays of integers, and find the pair of numbers (one from each array)
// whose absolute difference is closest to zero, and return a pair containing these 2 numbers.
// Only one such pair will exist for the test. 

pair<int,int> minDifference(vector<int> a,vector<int> b){
    //Complete this method
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int f = 0;
    int s = 0;
    int s1 = a.size();
    int s2 = b.size();
    int fe, se;
    int minDif = INT_MAX;
    while(f < s1 && s < s2) {
        if(minDif > abs(a[f] - b[s])) {
            minDif = abs(a[f] - b[s]);
            fe = a[f];
            se = b[s];
        }
        if(a[f] < b[s]) f++;
        else s++;
    }
    return {fe, se};
}

int main() {
    FIO;
    vector<int> a({23, 5, 10, 17, 30});
    vector<int> b({26, 134, 135, 14, 19});
    pair<int, int> result = minDifference(a, b);
    cout << result.F << " " << result.S << endl;
    return 0;
}