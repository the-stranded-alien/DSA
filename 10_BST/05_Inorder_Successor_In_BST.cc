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

// Given a BST, Find The Inorder Successor of a Given Target Node.

// Case 1 : When We Have Right SubTree
// 1. Look for The Right SubTree.
// 2. Then Go To The Extreme Left.
// Case 2 : When We Don't Have Right SubTree
// 1. Everytime node->data > Target => Store & Update Successor.
// (Root To Leaf Traversal)

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

Node *nextInorderSuccessor(Node *root, Node *target) {
    // Case 1 : If Right SubTree Exists
    if(target->right != NULL) {
        Node *temp = target->right;
        while(temp->left != NULL) temp = temp->left;
        return temp;
    }
    // Case 2 : If Right SubTree Doesn't Exist
    else {
        Node *temp = root;
        Node *succ = NULL;
        while(temp != NULL) {
            if(temp->key > target->key) {
                succ = temp;
                temp = temp->left;
            } 
            else if(temp->key < target->key) temp = temp->right;
            else break;
        }
        return succ;
    }
}

int main() {
    FIO;
    Node *root = NULL;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    for(int x : arr) {
        root = insertIntoBST(root, x);
    }
    Node *t1 = root->left->right->right;
    Node *t2 = root->right;
    cout << "Inorder Successor of 7 is : " << nextInorderSuccessor(root, t1)->key << nl;
    cout << "Inorder Successor of 10 is : " << nextInorderSuccessor(root, t2)->key << nl;
    return 0;
}