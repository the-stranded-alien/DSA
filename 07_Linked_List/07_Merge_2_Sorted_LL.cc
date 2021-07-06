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

// Given two sorted linked lists, merge them into a new linked list.

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

// Time : O(N + M)
// Space : O(N + M) -> Call Stack of Recursion

node * merge2SortedLL(node *a, node *b) {
    // Base Case
    if(a == NULL) return b;
    if(b == NULL) return a;
    // Recursive Case
    node *c;
    if(a->data < b->data) {
        c = a;
        c->next = merge2SortedLL(a->next, b);
    } else {
        c = b;
        c->next = merge2SortedLL(a, b->next);
    }
    return c;
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
    node * head1 = NULL;   
    insertAtHead(head1, 10);
    insertAtHead(head1, 7);
    insertAtHead(head1, 5);
    insertAtHead(head1, 1);
    node * head2 = NULL;
    insertAtHead(head2, 6);
    insertAtHead(head2, 3);
    insertAtHead(head2, 2);
    printLL(head1);
    printLL(head2);
    node *head = merge2SortedLL(head1, head2);
    printLL(head);
    return 0;
}