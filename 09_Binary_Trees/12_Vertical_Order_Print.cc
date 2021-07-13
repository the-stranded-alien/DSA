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

// Given a Binary Tree, We Need to Print it Vertically !

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

void traverseTree(node *root, int d, map<int, vector<int> > &m) {
    if(root == NULL) return;
    m[d].push_back(root->data);
    traverseTree(root->left, d - 1, m);
    traverseTree(root->right, d + 1, m);
    return;
}

void verticalOrderPrint(node *root) {
    map<int, vector<int> > m;
    int d = 0;
    traverseTree(root, d, m);
    // Keys Are Sorted in The Map
    for(auto pair : m) {
        int key = pair.first;
        vector<int> line = pair.second;
        for(auto data : line) cout << data << " ";
        cout << nl;
    }
}

int main() {
    FIO;
    node *root = levelOrderBuild();
    verticalOrderPrint(root);
    return 0;
}