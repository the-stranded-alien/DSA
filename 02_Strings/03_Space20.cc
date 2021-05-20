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

// Given a string write a function to replace all spaces in a string with '%20'.
// It is given that the string has sufficient space at the end to hold the additional characters. 

void replace_space(char *str) {
    // 1. Calculate Spaces
    int spaces = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if(str[i] == ' ') spaces++;
    }
    int idx = strlen(str) + (2 * spaces);
    str[idx] = '\0';
    for(int i = strlen(str) - 1; i >= 0; i--) {
        if(str[i] == ' ') {
            str[idx-1] = '0';
            str[idx-2] = '2';
            str[idx-3] = '%';
            idx -= 3;
        } else {
            str[idx-1] = str[i];
            idx--;
        }
    }
}

int main() {
    FIO;
    char str[10000];
    cin.getline(str, 10000);
    replace_space(str);
    cout << str << endl;
    return 0;
}