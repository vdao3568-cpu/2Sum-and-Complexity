// Stolen from code given by professor: twoSum then renamed to twoSumHash, main then modified to impliment twoSumBruteForce and test cases
// Grok 4.5 used to check if documentation is correct for twoSumHash 9/6
// Grok 4.5 continuation: figured out that you have to use first and second instead of indexes for pair<int, int>


#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>          // for std::pair
using namespace std;

std::pair<int, int> twoSumBruteForce(const std::vector<int>& nums, int target) { // have to use .first and .second with pair as opposed to indexes

    for (int i = 0; i < nums.size(); ++i) { // Loops through each value i

        for (int j = i + 1; j < nums.size(); ++j) { // Checks the next value j

            if (nums[i] + nums[j] == target) { // Checks each value i and j (i < j) and returns first pair that equals target observed IF i + j == target

                return { i, j }; 

            }
        }
    }

    return {-1, -1}; // No solution found, so that [0, 0] (standard pair) doesn't work

}

std::pair<int, int> twoSumHash(const std::vector<int>& nums, int target) {
    unordered_map<int, int> index;

    for (int i = 0; i < nums.size(); ++i) {
        int needed = target - nums[i]; // Computes the number that would result in nums[i] + any other number == target (complement needed)

        if (index.count(needed)) { // Only works if needed number has been observed
            return {index[needed], i}; // returns index of complemennt and current number nums[i]
        }

        index[nums[i]] = i; // puts current number location into index
    }

    return {-1, -1}; // No solution found, so that [0, 0] (standard pair) doesn't work
}

void printResult(const pair<int, int>& brute, const pair<int, int>& hash) { // Helper that receives results and prints them

    if (brute.first != -1) { //adjusted from .empty cause pair does not utilize .empty
        cout << "Brute Force Indices: [" << brute.first // first in the pair
             << ", " << brute.second << "]\n";
    } else {
        cout << "Brute Force no solution\n";
    }

    if (hash.first != -1) {
        cout << "Hash Indices: [" << hash.first
            << ", " << hash.second << "]\n";
    }
    else {
        cout << "Hash no solution\n";
    }
}

void runTests() {

    vector<int> test1 = {15, 4, 18, 8, 19, 22, 24, 59, 20, 18, 12, 36, 42, 9};
    int target1 = 24;

    printResult(twoSumBruteForce(test1, target1), twoSumHash(test1, target1));

    vector<int> test2 = {1, 2, 3, 4};
    int target2 = 56;

    printResult(twoSumBruteForce(test2, target2), twoSumHash(test2, target2));

    vector<int> test3 = {10, 9, 5, 14};
    int target3 = 19;

    printResult(twoSumBruteForce(test3, target3), twoSumHash(test3, target3));

    vector<int> test4 = {5, 5};
    int target4 = 10;

    printResult(twoSumBruteForce(test4, target4), twoSumHash(test4, target4));

    vector<int> test5 = {1, 2, 3, -4, 5, 6};
    int target5 = 2;

    printResult(twoSumBruteForce(test5, target5), twoSumHash(test5, target5));

    vector<int> test6 {0, 2, 4};
    int target6 = 2;

    printResult(twoSumBruteForce(test6, target6), twoSumHash(test6, target6));
}

int main() {

    runTests();
    
}
