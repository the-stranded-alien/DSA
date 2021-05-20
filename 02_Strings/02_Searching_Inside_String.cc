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
    string para = "We are learning about STL strings. STL string class is quite powerful";
    string word;
    getline(cin, word);   
    // Find function
    int index = para.find(word);
    if(index == -1) cout << "String not found !\n";
    else {
        cout << "First Occurence : " << index << endl;
    }
    index = para.find(word, index + 1);
    if(index != -1) cout << "Second Occurence : " << index << endl;
    return 0;
}