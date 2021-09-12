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

// Suppose that we have a ranklist. For each team compute the distance between
// their preferred place and their place in the ranklist. The sum of these distances
// will be called the badness of this ranklist. Given team names and their
// preferred placements find one ranklist with the minimal possible badness.

int badnessFunc(vector<pair<string, int> > teams) {
    vector<int> rankBucket(teams.size(), 0);
    for(auto team : teams) rankBucket[team.second - 1] += 1;
    vector<int> sortedRanks;
    for(int i = 0; i < rankBucket.size(); i++) {
        int cur = rankBucket[i];
        if(cur <= 0) continue;
        while(cur--) sortedRanks.push_back(i + 1);
    }
    int bad = 0;
    for(int i = 0; i < teams.size(); i++) {
        bad += abs(sortedRanks[i] - (i + 1));
    }
    return bad;
}

int main() {
    FIO;
    vector<pair<string, int> > teams;
    teams.push_back(make_pair("Win", 1));
    teams.push_back(make_pair("Ball", 2));
    teams.push_back(make_pair("Who", 2));
    teams.push_back(make_pair("Bhole", 1));
    teams.push_back(make_pair("DCE", 5));
    teams.push_back(make_pair("Strange", 7));
    teams.push_back(make_pair("Who", 7));
    int res = badnessFunc(teams);
    cout << res << nl;
    return 0;
}