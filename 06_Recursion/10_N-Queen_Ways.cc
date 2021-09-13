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

// Find number of ways to place N queens on NxN board, such that no two queens
// can kill each other in one move. A queen can move horizontally, vertically & diagonally.


bool canPlace(int n, int board[][10], int x, int y) {
    // Column
    for(int k = 0; k < x; k++) {
        if(board[k][y] == 1) return false;
    }
    // Left Diagonal
    int i = x;
    int j = y;
    while((i >= 0) && (j >= 0)) {
        if(board[i][j] == 1) return false;
        i--;
        j--;
    }
    // Right Diagonal
    i = x;
    j = y;
    while((i >= 0) && (j < n)) {
        if(board[i][j] == 1) return false;
        i--;
        j++;
    }
    return true;
}

int ways = 0;

bool solveNQueen(int n, int board[][10], int i) {
    // Base Case
    if(i == n) {
        ways++;
        return false;
    } 
    // Recursive Case
    // Try to Place a Queen in Every Row
    for(int j = 0; j < n; j++) {
        // Whether the Current (i, j) is Safe or Not !
        if(canPlace(n, board, i, j)) {
            board[i][j] = 1;
            bool success = solveNQueen(n, board, i + 1);
            if(success) return true;
            // Backtrack
            board[i][j] = 0; 
        }
    }
    return false;
}

int nQueen(int n) {
    int board[10][10] = {0};
    solveNQueen(n, board, 0);
    return ways;
}

int main() {
    FIO;
    cout << nQueen(8);
    return 0;
}