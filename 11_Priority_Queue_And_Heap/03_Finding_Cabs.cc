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

// Given N Cartesian Points in a 2D Plane Each Represents the Location of the Cab.
// You Are Standing At Origin, You Want to Know The Names of Nearest K Cabs.

// Method 1 : Sorting => O(N log N + K) 
// Method 2 : Min Heap of Size N (Key -> Distance) => O(N + K log N)
// Method 3 : Max Heap of Size K (Key -> Distance) => O(K + (N - K) * log K)

class Car {
public:
    string id;
    int x, y;
    Car(string id, int x, int y) {
        this->id = id;
        this->x = x;
        this->y = y;
    }
    int dist() const {
        return ((x * x) + (y * y)); // Square of the Distance
    }
};

class CarCompare {
public:
    bool operator() (const Car A, const Car B) {
        return (A.dist() < B.dist()); // '<' For Max Heap & '>' For Min Heap
    }
};

void printKNearestCars(vector<Car> cars, int k) {
    // Create a Max-Heap of Size 'K'
    priority_queue<Car, vector<Car>, CarCompare> max_heap(cars.begin(), cars.begin() + k);
    // Iterate Over Remaining Cars
    for(int i = k; i < cars.size(); i++) {
        auto car = cars[i];
        if(car.dist() < max_heap.top().dist()) {
            max_heap.pop(); // Remove The Root Node / Largest One
            max_heap.push(car);
        }
    }
    // Print All The Cars Inside The Heap, They Will Be The Smallest
    vector<Car> output;
    while(!max_heap.empty()) {
        output.push_back(max_heap.top());
        max_heap.pop();
    }
    // Vector of K Nearest Cars
    reverse(output.begin(), output.end());
    for(auto car : output) {
        cout << car.id << nl;
    }
    return;
}

int main() {
    FIO;
    int N, K;
    cin >> N >> K;
    string id;
    int x, y;
    vector<Car> cars;
    for(int i = 0; i < N; i++) {
        cin >> id >> x >> y;
        Car car(id, x, y);
        cars.push_back(car);
    }
    printKNearestCars(cars, K);
    return 0;
}