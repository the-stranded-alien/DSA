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

bool compare(string x, string y) {
    string xy = x.append(y);
    string yx = y.append(x);
    return (xy.compare(yx) > 0 ? 1 : 0);
}

string concatenate(vector<int> numbers) {
    vector<string> numStr;
    for(auto num : numbers) numStr.push_back(to_string(num));
    sort(numStr.begin(), numStr.end(), compare);
    string res = "";
    for(auto cur : numStr) res += cur;
    return res;
}

int main() {
    FIO;
    vi numbers = {45, 40, 4, 96, 98, 9, 400, 50};    
    string res = concatenate(numbers);
    cout << res;
    return 0;
}