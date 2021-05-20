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
    char input[1000];
    cin.getline(input, 1000);
    // strtok()
    // internally maintains the state of the string
    // you passed in the last fn call using a static variable
    // cout << strtok(input, " ") << endl;
    char *token = strtok(input, " ");
    while(token != NULL) {
        cout << token << ", ";
        token = strtok(NULL, " ");
    }
    return 0;
}