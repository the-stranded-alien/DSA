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

// Little Cute Kitten Loves to Write Stories in a GitHub Readme Document.
// One Day She is Given a List of Words, You Want to Help Her to Check if
// Each of These Words Are Present in The Readme File.

// Sample Input
// document = "little cute cat loves to code in c++, java & python"
// words = ["cute cat", "ttle", "cutest", "cat", "quick", "big"]
// Output -> Yes, Yes, No, Yes, No, No

// D -> Length of Document
// N -> No. of Words
// W -> Average / Largest Word Length

// Brute Force : O(D * W * N)
// Suffix Trie (Of Entire Document) : O(D^2 + (W * N))
// Trie of Words : O((N * W) + (D * W))

// Maintain history of characters encountered on each branch.

class Node {
public:
    char data;
    unordered_map<char, Node*> children;
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
            if(temp->children.count(ch) == 0) {
                Node *n = new Node(ch);
                temp->children[ch] = n;
            }
            temp = temp->children[ch]; // Go to the New / Next Node
        }
        temp->isTerminal = true; // Mark The Last Char Node As Terminal
    }
};

void SearchHelper(Trie t, string document, int i, unordered_map<string, bool> &m) {
    Node *temp = t.root;
    for(int j = i; j < document.length(); j++) {
        char ch = document[j];
        if(temp->children.count(ch) == 0) return;
        temp = temp->children[ch];
        if(temp->isTerminal) {
            // History Part
            string out = document.substr(i, (j - i + 1));
            m[out] = true;
        }
    }
    return;
}

void documentSearch(string document, vs words) {
    // 1. Create a Trie of Words
    Trie t;
    for(auto w : words) {
        t.insert(w);
    }
    // 2. Searching (Helper Function)
    unordered_map<string, bool> m;
    for(int i = 0; i < document.length(); i++) SearchHelper(t, document, i, m);
    // 3. You can check which words are marked as True inside HashMap
    for(auto w : words) {
        if(m[w]) cout << w << " : True" << nl;
        else cout << w << " : False" << nl;
    }
}

int main() {
    FIO;
    string document = "little cute cat loves to code in c++, java & python";
    vs words = {"cute cat", "ttle", "cat", "quick", "big"};
    documentSearch(document, words);
    return 0;
}