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

// Given a Binary Tree, Check if it is Height Balanced.
// A Non-Empty Binary Tree 'T' is Balanced if :
// 1. Left Subtree of T is Balanced
// 2. Right Subtree of T is Balanced
// 3. The Difference Between Heights of Left Subtree and Right Subtree is NOT MORE THAN 1.

class node {
public:
    int data;
    node *left;
    node *right;

    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *levelOrderBuild() {
    int d;
    cin >> d;
    node *root = new node(d);
    queue<node*> q;
    q.push(root);
    while(!q.empty()) {
        node *current = q.front();
        q.pop();
        int c1, c2;
        cin >> c1 >> c2;
        if(c1 != -1) {
            current->left = new node(c1);
            q.push(current->left);
        }
        if(c2 != -1) {
            current->right = new node(c2);
            q.push(current->right);
        }
    }
    return root;
}

// Post Order / Bottom-Up Approach

pair<int, bool> isHeightBalanced(node *root) {
    pair<int, bool> p;
    // Base Case
    if(root == NULL) return make_pair(0, true); // Height & IsBalanced
    // Recursive Case
    pair<int, bool> Left = isHeightBalanced(root->left);
    pair<int, bool> Right = isHeightBalanced(root->right);
    int height = (1 + max(Left.first, Right.first));
    if((abs(Left.first - Right.first) <= 1) && Left.second && Right.second) return make_pair(height, true);
    else return make_pair(height, false);
}

int main() {
    FIO;
    node *root = levelOrderBuild();
    pair<int, bool> p = isHeightBalanced(root);
    if(p.second) cout << "Yes, Tree Is Height Balanced !\n";
    else cout << "Not a Height Balanced Tree !\n";
    return 0;
}