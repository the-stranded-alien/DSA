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

// Given a Linked List, write a function to reverse every K nodes.
// (Where K is an input to the function)

class node {
public:
    int data;
    node *next;
    node (int data) {
        this->data = data;
        next = NULL;
    }
};

void insertAtHead(node * &head, int data) {
    if(head == NULL) {
        head = new node(data);
        return;
    }
    // Otherwise
    node * n = new node(data);
    n->next = head;
    head = n;
}

node* kReverse(node * head, int k) {
    // Base Case
    if(head == NULL) return NULL;
    // Recursive Case
    // Reverse the First K Nodes
    node *prev = NULL;
    node *current = head;
    node *temp;
    int cnt = 1;
    while(current != NULL && cnt <= k) {
        // Store Next
        temp = current->next;
        // Update the Current
        current->next = prev;
        // Prev & Current
        prev = current;
        current = temp;
        cnt++;
    }
    if(temp != NULL) {
        head->next = kReverse(temp, k);
    }
    return prev;
}

void printLL(node * head) {
    while(head != NULL) {
        cout << head->data << " --> ";
        head = head->next;
    }
    cout << nl;
}

int main() {
    FIO;
    node * head = NULL;   
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    printLL(head);
    head = kReverse(head, 3);
    printLL(head);
    return 0;
}