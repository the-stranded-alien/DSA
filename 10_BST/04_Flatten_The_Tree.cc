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

// Given a BST, Convert it to a Sorted Linked List, Right Pointer Should Behave
// As Next Pointer For The Linked List.

// 4 Cases
// 1. Both Left & Right SubTree Exist.
// 2. A Single Node Which Doesn't Have Anything on Left Or Right.
// 3. Left SubTree Exist But Right SubTree Doesn't Exist.
// 4. Right SubTree Exist But Left SubTree Doesn't Exist.

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

// BST to Sorted Linked List

class LinkedList {
public:
    Node *head;
    Node *tail;
};

// Post Order Traversal !
// O(N) Time

LinkedList tree2LL(Node *root) {
    LinkedList list;
    // Base Case
    if(root == NULL) {
        list.head = list.tail = NULL;
        return list;
    }
    // 4 Cases
    if(root->left == NULL && root->right == NULL) {
        list.head = list.tail = root;
        return list;
    } 
    else if(root->left != NULL && root->right == NULL) {
        LinkedList leftLL = tree2LL(root->left);
        leftLL.tail->right = root;
        list.head = leftLL.head;
        list.tail = root;
    }
    else if(root->left == NULL && root->right != NULL) {
        LinkedList rightLL = tree2LL(root->right);
        root->right = rightLL.head;
        list.head = root;
        list.tail = rightLL.tail;
    } 
    else {
        LinkedList leftLL = tree2LL(root->left);
        LinkedList rightLL = tree2LL(root->right);
        leftLL.tail->right = root;
        root->right = rightLL.head;
        list.head = leftLL.head;
        list.tail = rightLL.tail;
    }
    return list;
}

int main() {
    FIO;
    Node *root = NULL;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    for(int x : arr) {
        root = insertIntoBST(root, x);
    }
    // printInorderTraversalBST(root);
    LinkedList list = tree2LL(root);
    Node *temp = list.head;
    while(temp != NULL) {
        cout << temp->key << " --> ";
        temp = temp->right;
    }
    return 0;
}