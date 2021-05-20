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

char *mystrtok(char *str, char delim) {
    static char *input = NULL;
    if(str != NULL) input = str;
    if(input == NULL) return NULL;
    // You can return dynamically created array but not a static one
    char *token = new char[strlen(input)+1];
    int i = 0;
    for( ; input[i] != '\0'; i++) {
        if(input[i] != delim) {
            token[i] = input[i];
        } else {
            token[i] = '\0';
            input = input + i + 1;
            return token;
        }
    }
    token[i] = '\0';
    // Reset the input as NULL
    input = NULL;
    return token;
}

int main() {
    FIO;
    char s[1000];
    cin.getline(s, 1000);
    char *token = mystrtok(s, ' ');
    while(token != NULL) {
        cout << token << ", ";
        token = mystrtok(NULL, ' ');
    }
    return 0;
}