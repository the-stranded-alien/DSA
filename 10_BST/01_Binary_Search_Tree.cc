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

Node *insertIntoBST(Node *root, int key) {
    if(root == NULL) return new Node(key);
    // Recursive Case
    if(key < root->key) root->left = insertIntoBST(root->left, key);
    else root->right = insertIntoBST(root->right, key);    
    return root;
}

void printInorderTraversalBST(Node *root) {
    if(root == NULL) return;
    printInorderTraversalBST(root->left);
    cout << root->key << " ";
    printInorderTraversalBST(root->right);
    return;
}

bool searchInBST(Node *root, int key) {
    if(root == NULL) return false;
    if(root->key == key) return true;
    if(root->key > key) searchInBST(root->left, key);
    else searchInBST(root->right, key);
}

int main() {
    FIO;
    Node *root = NULL;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    for(int x : arr) {
        root = insertIntoBST(root, x);
    }
    printInorderTraversalBST(root);
    if(searchInBST(root, 11)) cout << "\nNode Is Present In The BST !" << nl;
    else cout << "\nNode Is Not Present In The BST !" << nl;
    return 0;
}