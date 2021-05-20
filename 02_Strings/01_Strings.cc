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



int main() {
    FIO;
    // char s[1000] = {'1', 'a', 'b', 'c', '\0'}; // Not recommended
    
    string s = "hello world";
    cout << s << endl;

    string s2("hello world");
    cout << s2 << endl;

    string s3;
    getline(cin, s3, '.');
    cout << s3 << endl;

    vector<string> vec;
    int n = 5;
    string temp;
    while(n--) {
        getline(cin, temp);
        vec.pb(temp);
    }
    for(string sx : vec) {
        cout << sx << endl;
    }
    for(char ch : s3) {
        cout << ch << "," << endl;
    }
    return 0;
}