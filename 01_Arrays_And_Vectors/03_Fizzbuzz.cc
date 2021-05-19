#include<vector>
#include<string>
using namespace std;

vector<string> fizzbuzz(int n) {
    vector<string> result(n);
    result.clear();
    for(int i = 1; i <= n; i++) {
        string cur = "";
        if(i % 15 == 0) cur += "FizzBuzz";
        else if(i % 3 == 0) cur += "Fizz";
        else if(i % 5 == 0) cur += "Buzz";
        else cur += to_string(i);
        result.push_back(cur);
    }
    return result;
}