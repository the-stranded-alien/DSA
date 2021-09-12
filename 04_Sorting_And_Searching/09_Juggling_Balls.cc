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

vector<int> sortBalls(vector<int> balls) {
    int n = balls.size();
    int low = 0;
    int mid = 0;
    int high = (n - 1);
    while(mid <= high) {
        if(balls[mid] == 0) swap(balls[low++], balls[mid++]);
        else if(balls[mid] == 1) mid++;
        else swap(balls[mid], balls[high--]);
    }
    return balls;
}

int main() {
    FIO;
    vi balls = {0, 0, 1, 2, 0, 1, 2, 0};
    vi res = sortBalls(balls);
    for(auto b : res) cout << b << " ";   
    return 0;
}