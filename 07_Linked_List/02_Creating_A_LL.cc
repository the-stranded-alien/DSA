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

class node {
public:
    int data;
    node *next;

    node(int data) {
        this->data = data;
        next = NULL;
    }
};
//-------------------Linked List---------------------//
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
    printLL(head);
    insertAtHead(head, 3);
    printLL(head);
    insertAtHead(head, 2);
    printLL(head);
    insertAtHead(head, 1);
    printLL(head);    
    insertAtHead(head, 0);
    printLL(head);
    return 0;
}