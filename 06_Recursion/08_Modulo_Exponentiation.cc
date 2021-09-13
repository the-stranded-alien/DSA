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

// Compute a raised to the power b. As this value could be large compute it to Modulo 1e9 + 7

const long long int M = 1e9 + 7;

long long int powerModulo(int a, int b) {
    if(a == 0) return 0;
    if(b == 0) return 1;
    return (((a % M) * (powerModulo(a, (b - 1)) % M)) % M);
}

// Optimized Recursive Function
// Property 1 : (a * b) % p = ((a % p) * (b % p)) % p
// Property 2 : if b is even : (a ^ b) % c = ((a ^ b/2) * (a ^ b/2)) % c
// Property 3 : if b is odd : (a ^ b) % c = (a * (a ^ (b-1))) % c
long long int powerModuloOpt(int a, int b) {
    // Base Cases
    if(a == 0) return 0;
    if(b == 0) return 1;
    // Recursive Cases
    // If b is even
    long long int ans;
    if(b % 2 == 0) {
        ans = powerModuloOpt(a, (b / 2));
        ans = (ans * ans) % M;
    } else { // If b is odd
        ans = a % M;
        ans = (ans * (powerModuloOpt(a, (b - 1)) % M)) % M;
    }
    return (int)((ans + M) % M);
}

int main() {
    FIO;
    int a = 5;
    int b = 3;
    cout << powerModulo(a, b) << nl;
    cout << powerModuloOpt(a, b) << nl;
    return 0;
}