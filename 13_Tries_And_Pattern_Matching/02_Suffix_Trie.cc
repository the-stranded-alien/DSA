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

// Suffix Trie
// Insert All Suffixes of Words Into Trie.

// Simplified Suffix Tree
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

class SuffixTrie {
public:
    Node * root;
    
    SuffixTrie() {
        root = new Node('\0');
    }

    void insert_helper(string word) {
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

    void insert(string word) {
        // Pick All SubStrings From (i, eos) And Insert_helper
        for(int i = 0; word[i] != '\0'; i++) {
            // cout << "SubStr : " << word.substr(i) << nl;
            insert_helper(word.substr(i));
        }
    }
};

int main() {
    FIO;
    string input = "hello";
    string suffixes[] = {"lo", "ell", "hello"};
    SuffixTrie st;
    st.insert(input);
    for(auto sf : suffixes) {
        if(st.search(sf)) cout << "Yes" << nl;
        else cout << "No" << nl;
    }
    return 0;
}