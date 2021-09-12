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

// N-Queen is the problem of placing N Chess Queens on an N x N
// chessboard so that no two queens attack each other.
// Possible Variations : Print One Configurations, Print All Configurations,
// Count All Possible Configurations.

void printBoard(int n, int board[][20]) {
    for(int i = 0; i < n; i++) cout << "---";
    cout << endl;
    for(int i = 0; i < n; i++) {
        cout << "| ";
        for(int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << " |";
        cout << endl;
    }
    for(int i = 0; i < n; i++) cout << "---";
    cout << endl;
}

bool canPlace(int n, int board[][20], int x, int y) {
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

bool solveNQueen(int n, int board[][20], int i) {
    // Base Case
    if(i == n) {
        // Print the Board
        printBoard(n, board);
        return true;
        // Return False if you want to Print All Configurations
        // return false;
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

int main() {
    FIO;
    int board[20][20] = {0};
    int n;
    cin >> n;
    bool can = solveNQueen(n, board, 0);
    if(can) cout << "We Can Place Queens !";
    return 0;
}