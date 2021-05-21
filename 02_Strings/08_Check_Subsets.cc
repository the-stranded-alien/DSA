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

// Given two non-empty string, determine whether the second string 
// is subsequence of first one.

bool isSubset(string s1, string s2) {
    int i = s1.length() - 1;
    int j = s2.length() - 1;
    while((i >= 0) && (j >= 0)) {
        if(s2[j] == s1[i]) {
            i--;
            j--;
        } else i--;
    }
    if(j == -1) return true;
    else false;
}

int main() {
    FIO;
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    bool result = isSubset(s1, s2);
    if(result) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}