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

// Given a partially filled Sudoku Matrix of 9 x 9,
// write a function to fill the matrix using Sudoku rules.

bool isSafe(int mat[][9], int i, int j, int no, int n) {
    // Check for Row & Column
    for(int k = 0; k < n; k++) {
        if(mat[k][j] == no || mat[i][k] == no) {
            return false;
        }
    }
    // Check for Sub-Grid
    int sx = (i / 3) * 3;
    int sy = (j / 3) * 3;
    for(int x = sx; x < (sx + 3); x++) {
        for(int y = sy; y < (sy + 3); y++) {
            if(mat[x][y] == no) return false;
        }
    }
    return true;
}

bool sudokuSolver(int mat[][9], int i, int j, int n) {
    // Base Case
    if(i == n) {
        // Print The Solution
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << mat[i][j] << " ";
            }
            cout << nl;
        }
        return true;
    }
    // Recursive Case
    // Jump to Next Row
    if(j == n) return sudokuSolver(mat, i + 1, 0, n);
    // Skip The Prefilled Cell
    if(mat[i][j] != 0) return sudokuSolver(mat, i, j + 1, n);
    // Cell to be Filled
    // Try Out All Possibilities
    for(int no = 1; no <= n; no++) {
        // Whether it is safe to place the number or not
        if(isSafe(mat, i, j, no, n)) {
            mat[i][j] = no;
            bool solveSubproblem = sudokuSolver(mat, i, j + 1, n);
            if(solveSubproblem == true) return true;
        }
    }
    // If No Options Works : Backtrack
    mat[i][j] = 0;
    return false;
}

int main() {
    FIO;
    int n = 9;
    int mat[9][9] =
        {{5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}};
    if(!sudokuSolver(mat, 0, 0, n)) {
        cout << "No Solution Exists !";
    }
    return 0;
}