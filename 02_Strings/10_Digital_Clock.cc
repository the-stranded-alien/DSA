#include<iostream>
#include<string>
#include<limits>
#include<algorithm>
#include<array>
#include<bitset>
#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
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
#define pi pair<int, int>
#define vi vector<int>
#define vs vector<string>
#define vii vector< vector<int> >
#define mod 1e9 + 7
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

string convert_to_digital_time(int minutes){
    string out = "";
    int hrs = (minutes / 60);
    int min = (minutes % 60);
    out += to_string(hrs);
    out += ":";
    if(min < 10) out += "0";
    out += to_string(min);
    out += "\0";
    return out;
}

int main() {
    FIO;
    int min; cin >> min;
    cout << convert_to_digital_time(min);
    return 0;
}