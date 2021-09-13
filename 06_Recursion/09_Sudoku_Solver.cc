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

// You are given a 9x9 2D array which is partially filled. Fill the grid from
// digits 1 to 9 such that every row, column, and subgrid of size 3x3 contains
// all digits from 1 to 9 exactly once.

bool canPlaceDigit(int i, int j, vector<vector<int> > board, int dig) {
    // Column & Row
    for(int x = 0; x < 9; x++) {
        if((board[x][j] == dig) || (board[i][x] == dig)) return false;
    }
    // SubGrid
    int rn = 3;
    int si = (i / rn) * rn;
    int sj = (j / rn) * rn;
    for(int x = si; x < (si + rn); x++) {
        for(int y = sj; y < (sj + rn); y++) {
            if(board[x][y] == dig) return false;
        }
    }
    return true;
}

bool sudokuSolver(vector<vector<int> > &input, int i, int j, int n) {
    // Base Case
    if(i == n) return true;
    // Recursive Case
    // Case for Row End
    if(j == n) return sudokuSolver(input, (i + 1), 0, n);
    // Case for Skipping the Prefilled Cells
    if(input[i][j] != 0) return sudokuSolver(input, i, (j + 1), n);
    // Fill The Current Cell With Possible Options
    for(int num = 1; num <= 9; num++) {
        if(canPlaceDigit(i, j, input, num)) {
            input[i][j] = num;
            bool couldWeSolve = sudokuSolver(input, i, (j + 1), n);
            if(couldWeSolve) return true;
        }
    }
    // Backtrack after trying all numbers
    input[i][j] = 0;
    return false;
}

vector<vector<int> > solveSudoku(vector<vector<int> > input){
    bool success = sudokuSolver(input, 0, 0, 9);
    return input;
}

int main() {
    FIO;
    vii input = {
        {0,3,0,0,0,0,9,0,0},
        {0,0,6,0,0,0,0,0,0},
        {0,0,0,2,4,1,0,3,0},
        {0,0,0,9,0,0,7,0,0},
        {0,0,0,0,0,2,0,0,4},
        {0,8,0,0,7,0,0,2,0},
        {8,5,0,0,0,0,0,0,0},
        {0,9,0,7,0,4,0,0,0},
        {0,0,0,0,0,6,0,0,1}
    };
    vii output = solveSudoku(input);
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) cout << output[i][j] << " ";
        cout << endl;
    }
    return 0;
}