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

// Given N Cartesian Points in a 2D Plane, Find The Number of Right-Angled 
// Triangles Such That the Base or Perpendicular is Parallel to X or Y-axis.

// Brute Force : O(N^3)

// Try To Count All Triangles With Every Vertex Being The Vertex at
// Which Right Angle Is Getting Formed.

// Two Hashed Maps, unordered_map <x, cnt(X)> and unordered_map <y, cnt(Y)>

int count_triangles(vector<pair<int, int> > &points) {
    unordered_map<int, int> freq_x;
    unordered_map<int, int> freq_y;
    // Count the Frequency By Iterating Over All The Points
    for(auto p : points) {
        int x = p.first;
        int y = p.second;
        freq_x[x]++;
        freq_y[y]++;
    }
    // Count
    int count = 0;
    for(auto p : points) {
        int x = p.first;
        int y = p.second;
        int fx = freq_x[x];
        int fy = freq_y[y];
        if((fx >= 1) && (fy >= 1)) count += ((fx - 1) * (fy - 1));
    }
    return count;
}

int main() {
    FIO;
    int N; cin >> N;
    vector<pair<int, int> > points;
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
    cout << count_triangles(points);
    return 0;
}