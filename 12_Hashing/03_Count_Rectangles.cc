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

// Given N Cartesian Points in a 2D Plane, Find the Number of
// Axis Parallel Rectangles That Can Be Formed.

// Brute Force : O(N^4)

// Optimization 1 : P1(x1, y1), P2(x2, y2), P3(x2, y1), P4(x1, y2) : O(N^2) 
// Optimization 2 : Use Set/Map to LookUp If Points Exist in List. 
// Double Counting Would Happen So Return Answer / 2, Because Each Rectangle
// Would be Detected From Both Diagonals.

class Point {
public:
    int x;
    int y;
    Point() {

    }
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

class Compare {
public: 
    bool operator()(const Point p1, const Point p2) {
        if(p1.x == p2.x) return (p1.y < p2.y);
        return (p1.x < p2.x);
    }
};

int count_rectangles(vector<Point> points) {
    // 1. Insert All Points in the Set
    set<Point, Compare> s;
    for(Point p : points) s.insert(p);
    int ans = 0;
    // 2. Logic : Brute Force Two Points + LookUp for Other Two Points.
    for(auto it = s.begin(); it != prev(s.end()); it++) {
        for(auto jt = next(it); jt != s.end(); jt++) {
            Point p1 = *it;
            Point p2 = *jt;
            // Small Checks That We Need To Make
            if((p2.x == p1.x) || (p2.y == p1.y)) continue;
            // Create Points P3 & P4 From P1 & P2
            Point p3(p1.x, p2.y);
            Point p4(p2.x, p1.y);
            if((s.find(p3) != s.end()) && (s.find(p4) != s.end())) ans += 1;
        }
    }
    return (ans / 2);
}

int main() {
    FIO;
    int N;
    cin >> N;
    int x, y;
    vector<Point> points;
    for(int i = 0; i < N; i++) {
        cin >> x >> y;
        Point p(x, y);
        points.push_back(p);
    }    
    cout << count_rectangles(points) << nl;
    return 0;
}