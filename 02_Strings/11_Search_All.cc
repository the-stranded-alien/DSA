#include<iostream>
#include<string>
#include<climits>
#include<algorithm>
#include<array>
#include<bitset>
#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<deque>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<vector>
#define ll long long int
#define ld long long double
#define PB push_back
#define POB pop_back
#define MP make_pair
#define F first
#define S second
#define nl '\n'
#define tab '\t'
#define pi pair<int, int>
#define vi vector<int>
#define vs vector<string>
#define vb vector<bool>
#define vii vector< vector<int> >
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

// Implement a function that returns a list of all occurences of a given substring
// inside a big string. Return empty vector if smaller string is not present inside
// bigger string

vector<int> stringSearch(string big, string small) {
    vector<int> result = {};
    int sizeBig = big.size();
    int sizeSmall = small.size();
    for(int i = 0; i < sizeBig; i++) {
        bool match = true;
        int itr = i;
        for(int j = 0; j < sizeSmall; j++) {
            if(big[itr++] != small[j]) {
                match = false;
                break;
            }
        }
        if(match) result.push_back(i);
    }
    return result;
}

vector<int> stringSearchOpt(string big, string small) {
    vector<int> result;
    int index = big.find(small);
    while(index != -1) {
        result.push_back(index);
        index = big.find(small, index + 1);
    }
    return result;
}

int main() {
    FIO;
    string bigString = "I liked the movie, acting in movie was great!";
    string smallString = "movie";
    vi res = stringSearch(bigString, smallString);
    for(auto x : res) cout << x << " ";   
    return 0;
}