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

// Given the start and end times of N activities return the maximum number of 
// activities you can do given you can be involved in only one activity at a time.

bool compare(pair<int, int> a, pair<int, int> b) {
    return (a.second < b.second);
}

int countActivities(vector<pair<int, int> > activities) {
    sort(activities.begin(), activities.end(), compare);
    int maxAct = 0;
    int lastFinishTime = 0;
    for(auto act : activities) {
        if((act.first >= lastFinishTime) ) {
            maxAct++;
            lastFinishTime = act.second;
        }
    }
    return maxAct;
}

int main() {
    FIO;
    vector<pair<int, int> > act = {{7, 9}, {0, 10}, {4, 5}, {8, 9}, {4, 10}, {5, 7}};
    cout << countActivities(act) << nl;
    return 0;
}