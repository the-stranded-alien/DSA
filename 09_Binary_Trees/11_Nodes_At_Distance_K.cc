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

// Given a Binary Tree, and a Target Node 'T'. Find All Nodes at
// Distance 'K' from Given Node, Where K is Also an Integer Input.

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

void printAtLevelK(node *root, int k) {
    if(root == NULL) return;
    if(k == 0) {
        cout << root->data << " ";
        return;
    }
    printAtLevelK(root->left, k - 1);
    printAtLevelK(root->right, k - 1);
    return;
}

int printNodesAtDistanceK(node *root, node *target, int K) {
    // Base Case
    if(root == NULL) return -1;
    // Reach The Target Node
    if(root == target) {
        printAtLevelK(target, K);
        return 0;
    }
    // Other Case
    int DL = printNodesAtDistanceK(root->left, target, K);
    if(DL != -1) {
        // 2 Cases
        // Print The Current Node
        if(DL + 1 == K) cout << root->data << " ";
        // Or Print Some Nodes In The Right SubTree
        else printAtLevelK(root->right, (K - 2 - DL));
        return (1 + DL);
    }
    int DR = printNodesAtDistanceK(root->right, target, K);
    if(DR != -1) {
        // 2 Cases
        // Print The Current Node
        if(DR + 1 == K) cout << root->data << " ";
        // Or Print Some Nodes In The Left SubTree
        else printAtLevelK(root->left, (K - 2 - DR));
        return (1 + DR);
    }
    return -1;
}

int main() {
    FIO;
    node *root = levelOrderBuild();
    printLevelOrderTraversal(root);
    node *target = root->left->right;
    int k = 2;
    printNodesAtDistanceK(root, target, k);
    return 0;
}