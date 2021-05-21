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

// Given a list of 'n' strings S0, S1, S2, S3, ...., Sn-1, each consisting of digits
// and spaces, the number of spaces is the same for each entry, the goal is to implement
// a variation of a sort command. None of the string contains consecutive spaces. Also,
// no string starts with a space nor ends with it. Spaces are used to divide string into
// columns, which can be used as keys in comparisons.
// Program has to support the required parameters:
// 1. Key : integer denoting the column used as a key in comparisons.
// The left most column is denoted by 1
// 2. Reversed : boolean variable indicating whether yo reverse the result of comparisons.
// 3. Comparison-type : either lexicographic or numeric 


// Logic : 1. Extract keys from every string (Tokenizaition)
// 2. Make key-value pairs for strings & keys and store them
// 3. Then sort using different type of comparators
// 4. Reverse if needed

string extractStringAtKey(string str, int key) {
    // String Tokeniser
    char *s = strtok( (char *)str.c_str(), " ");
    while(key > 1) {
        s = strtok(NULL, " ");
        key--;
    }
    return (string)s;
}

int convertToInt(string s) {
    int ans = 0;
    int p = 1;
    for(int i = s.length() - 1; i >= 0; i--) {
        ans += ((s[i] - '0') * p);
        p = p * 10;
    }
    return ans;
}

bool numericCompare(pair<string, string> s1, pair<string, string> s2) {
    string key1, key2;
    key1 = s1.S;
    key2 = s2.S;
    return (convertToInt(key1) < convertToInt(key2));
}

bool lexicoCompare(pair<string, string> s1, pair<string, string> s2) {
    string key1, key2;
    key1 = s1.S;
    key2 = s2.S;
    return (key1 < key2);
}

int main() {
    FIO;
    int n;
    cin >> n;
    cin.get(); // Consume the extra '\n'
    string temp;
    vector<string> vec;
    for(int i = 0; i < n; i++) {
        getline(cin, temp);
        vec.pb(temp);
    }
    int key;
    string reversal, ordering;
    cin >> key >> reversal >> ordering;
    
    // 1. To extract keys for comparison and store them 
    vector< pair<string, string> > vp;
    for(int i = 0; i < n; i++) {
        vp.pb({vec[i], extractStringAtKey(vec[i], key)});
    }
    // 2. Sorting
    if(ordering == "numeric") sort(vp.begin(), vp.end(), numericCompare);
    else sort(vp.begin(), vp.end(), lexicoCompare);
    // 3. Reversal
    if(reversal == "true") reverse(vp.begin(), vp.end());
    // 4. Output
    for(int i = 0; i < n; i++) {
        cout << vp[i].F << endl;
    }
    return 0;
}