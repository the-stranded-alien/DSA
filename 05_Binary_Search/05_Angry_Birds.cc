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
#define nl '\n'
#define tab '\t'
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

// There is a long wire along at straight line, which contains N bird nests at
// positions x1, x2, ......., xN. There are B (B <= N) birds, which become angry towards
// each other once put into a nest. To put the birds from hurting each other you 
// want to assign birds to nests such that minimum distance between any two birds
// is as large as possible. What is the largest minimum distance ?

// O(N log(xN - x0)) => O(N log(xN))

bool canPlaceBirds(int B, int N, vi nests, int sep) {
    int birds = 1;
    int location = nests[0];
    for(int i = 1; i <= (N - 1); i++) {
        int current_location = nests[i];
        if(current_location - location >= sep) {
            birds++;
            location = current_location;
            if(birds == B) return true;
        }
    }
    return false;
}

int main() {
    FIO;
    int B = 3;
    vi nests{1,2,4,8,9};
    // Sorting
    sort(nests.begin(), nests.end());
    int N = nests.size();
    // Binary Search
    int s = 0;
    int e = nests[N-1] - nests[0];
    int ans = -1;
    while(s <= e) {
        int mid = (s + e) / 2;
        bool canPlace = canPlaceBirds(B, N, nests, mid);
        if(canPlace) {
            ans = mid;
            s = mid + 1;
        }
        else e = mid - 1;
    }
    cout << ans << nl;
    return 0;
}