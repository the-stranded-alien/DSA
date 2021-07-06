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

// Array is continuous memory but Linked List is not continuous memory.
// You can add nodes dynamically to the Linked List
// Basic Operations : Insertion, Searching, Deletion,
// Creating a LL, Deleting a LL, Printing a LL.

template<typename T>
class Node {
    T data;
    Node<T> *next;
public:
    Node(T data) {
        this->data = data;
        next = NULL;
    }
    int getData() {
        return this->data;
    }
};

int main() {
    FIO;
    Node<int> *node = new Node<int>(10);  
    cout << node->getData() << nl;
    return 0;
}