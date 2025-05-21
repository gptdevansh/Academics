#include <iostream>
using namespace std;

bool isSubsetSum(const *set, int n, int targetSum) {
    // If the target sum is 0, return true (empty subset is valid)
    if (targetSum == 0) {
        return true;
    }

    // If no more elements to consider and target sum is not 0
    if (n == 0 && targetSum != 0) {
        return false;
    }

    // If last element is greater than target sum, ignore it
    if (set[n - 1] > targetSum) {
        return isSubsetSum(set, n - 1, targetSum);
    }

    // Check if sum can be obtained by including or excluding the last element
    return isSubsetSum(set, n - 1, targetSum) ||
           isSubsetSum(set, n - 1, targetSum - set[n - 1]);
}

int main() {
    int n, targetSum;
    cout << "Enter number of elements in the set: ";
    cin >> n;

    int set[n];
    cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; i++) {
        cin >> set[i];
    }

    cout << "Enter the target sum: ";
    cin >> targetSum;

    if (isSubsetSum(set, n, targetSum)) {
        cout << "There is a subset with the targetSum.\n";
    } else {
        cout << "No subset with the targetSum.\n";
    }

    return 0;
}
