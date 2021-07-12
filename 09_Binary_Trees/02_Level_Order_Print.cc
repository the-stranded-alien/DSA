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

// Print a Binary Tree Using A Level Order Traversal

class node {
public:
    int data;
    node *left;
    node *right;

    node (int d) {
        data = d;
        left = NULL;
        right = NULL; 
    }
};

node *buildTree() {
    int d;
    cin >> d;
    if(d == -1) return NULL;
    node *n = new node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

void printLevelOrderTraversal(node *root) {
    queue<node*> q; // Store a Pointer to The Node
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        node *temp = q.front();
        if(temp ==  NULL) {
            cout << nl;
            q.pop();
            // Insert a New NULL for the Next Level
            if(!q.empty()) q.push(NULL);
        } else {
            q.pop();
            cout << temp->data << " ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    return;
}

int main() {
    FIO;
    node *root = buildTree();
    printLevelOrderTraversal(root);   
    return 0;
}