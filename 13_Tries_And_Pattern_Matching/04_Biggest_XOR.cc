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

// Given an Array, Find the Maximum XOR
// That You Can Form by Picking Two Numbers From The Array.

// Trie + Bitmasking
// O(N) Time

class node {
public:
    node *left; // 0
    node *right; // 1
};

class trie {
public:
    node *root;
    trie() {
        root = new node();
    }
    void insert(int n) {
        // Insert Bits of This Number In The Trie
        node *temp = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1;
            if(bit == 0) {
                if(temp->left == NULL) temp->left = new node();
                temp = temp->left;
            } else {
                if(temp->right == NULL) temp->right = new node();
                temp = temp->right;
            }
        }
    }
    int max_xor_helper(int value) {
        int current_ans = 0;
        node *temp = root;
        for(int j = 31; j >= 0; j--) {
            int bit = (value >> j) & 1;
            if(bit == 0) {
                // Find The Opposite Value
                if(temp->right != NULL) {
                    temp = temp->right;
                    current_ans += (1 << j);
                } else {
                    temp = temp->left;
                }
            } else {
                // Look for a Zero
                if(temp->left != NULL) {
                    temp = temp->left;
                    current_ans += (1 << j);
                } else {
                    temp = temp->right;
                }
            }
        }
        return current_ans;
    }
    int max_xor(int *input, int n) {
        int max_xor = 0;
        for(int i = 0; i < n; i++) {
            int value = input[i];
            insert(value);
            int current_xor = max_xor_helper(value);
            max_xor = max(max_xor, current_xor);
        }
        return max_xor;
    }
};

int main() {
    FIO;
    int input[] = {3,10,5,25,9,2};
    int n = sizeof(input) / sizeof(int);
    trie t;
    cout << t.max_xor(input, n) << nl;
    return 0;
}