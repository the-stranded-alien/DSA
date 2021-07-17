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

// Given a List of N Strings and Q Queries, Each Query Containing a Word,
// You Have to Tell Whether the Word is Contained in the List or Not.
// N -> No of Strings
// W -> Average Length of Each Word

// 1. Brute Force - O(N^2 * Q)
// 2. Binary Search Tree / Map - O(log N * Q)
// 3. Unordered Set / Unordered Map (Hashing)
// 4. Trie - O(W * Q) 

// Performance of Hash-Tables Degrades With Increasing No. of Elements But Trie's Doesn't.

// PREFIX TREE / TRIES
// -> generic tree like data structure
// -> efficient information retrieval data structure
// -> searches in optimal time O(key length) but uses extra storage
// -> Important Operations : Insert a new word & Search for a given word
// Insert : O(Key Length)
// Search : O(Key Length)

class Node {
public:
    char data;
    unordered_map<char, Node*> m; // Children
    bool isTerminal;

    Node(char d) {
        data = d;
        isTerminal = false;
    }
};

class Trie {
public:
    Node * root;
    
    Trie() {
        root = new Node('\0');
    }

    void insert(string word) {
        Node *temp = root;
        for(char ch : word) {
            if(temp->m.count(ch) == 0) {
                Node *n = new Node(ch);
                temp->m[ch] = n;
            }
            temp = temp->m[ch]; // Go to the New / Next Node
        }
        temp->isTerminal = true; // Mark The Last Char Node As Terminal
    }

    bool search(string word) {
        Node *temp = root;
        for(char ch : word) {
            if(temp->m.count(ch) == 0) return false;
            temp = temp->m[ch];
        }
        return temp->isTerminal;
    }
};

int main() {
    FIO;
    string words[] = {"apple", "ape", "no", "news", "not", "never"};
    Trie t;
    for(auto w : words) t.insert(w);
    int q;
    cin >> q;
    string search_word;
    while(q--) {
        cin >> search_word;
        if(t.search(search_word)) {
            cout << "Yes" << nl;
        } else cout << "No" << nl;
    }
    return 0;
}