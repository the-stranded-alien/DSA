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

// Find the Largest Sum of a Subset of Nodes in a Binary Tree,
// Such That if a Node is Included in The Sum Then Its Parent
// And Children Must Not Be Included in the Subset Sum.

// Base => root == NULL : return 0
// include = root->data + L.exclude + R.exclude
// exclude = max(L.include, L.exclude) + max(R.include, R.exclude)

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

class Pair {
public:
    int inc;
    int exc;
};

// O(N) Time
Pair maxSubsetSum(node *root) {
    Pair p;
    if(root == NULL) {
        p.inc = p.exc = 0;
        return p;
    }
    Pair Left = maxSubsetSum(root->left);
    Pair Right = maxSubsetSum(root->right);

    p.inc = (root->data + Left.exc + Right.exc);
    p.exc = max(Left.inc, Left.exc) + max(Right.inc, Right.exc);
    return p;
}

int main() {
    FIO;
    node *root = levelOrderBuild();
    Pair result = maxSubsetSum(root);
    cout << "Max-Subset-Sum = " << max(result.inc, result.exc) << nl;
    return 0;
}