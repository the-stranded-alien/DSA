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

// Given a Sorted Array, Construct a BST of Minimum Height !

class Node {
public:
    int key;
    Node *left;
    Node *right;

    Node(int key) {
        this->key = key;
        left = right = NULL;
    }
};

Node *sortedArrayToBST(vector<int> &arr, int start, int end) {
    // Return NULL If start > end, Because No Array Elements Are Left There
    if(start > end) return NULL;
    // Get The Middle Element And Make It Root
    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);
    // Create Left & Right Sub-Trees Recursively
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);
    return root;
}

void printInorderTraversalBST(Node *root) {
    if(root == NULL) return;
    printInorderTraversalBST(root->left);
    cout << root->key << " ";
    printInorderTraversalBST(root->right);
    return;
}

void printLevelOrderTraversal(Node *root) {
    queue<Node*> q; // Store a Pointer to The Node
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        Node *temp = q.front();
        if(temp ==  NULL) {
            cout << nl;
            q.pop();
            // Insert a New NULL for the Next Level
            if(!q.empty()) q.push(NULL);
        } else {
            q.pop();
            cout << temp->key << " ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    return;
}

int main() {
    FIO;
    vector<int> arr{1,2,3,4,5,6,7};
    Node *root = sortedArrayToBST(arr, 0, (arr.size() - 1));
    printInorderTraversalBST(root);
    cout << nl;   
    printLevelOrderTraversal(root);
    return 0;
}