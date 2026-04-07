#include <iostream>
using namespace std;

int n, target;
int weights[20];
int x[20]; // solution vector

void sumOfSubsets(int k, int currentSum, int remainingSum) {
    x[k] = 1;

    // Include current element
    if (currentSum + weights[k] == target) {
        cout << "Subset: ";
        for (int i = 0; i <= k; i++) {
            if (x[i] == 1)
                cout << weights[i] << " ";
        }
        cout << endl;
    }
    else if (currentSum + weights[k] + weights[k+1] <= target) {
        sumOfSubsets(k + 1, currentSum + weights[k], remainingSum - weights[k]);
    }

    // Exclude current element
    if ((currentSum + remainingSum - weights[k] >= target) &&
        (currentSum + weights[k+1] <= target)) {
        x[k] = 0;
        sumOfSubsets(k + 1, currentSum, remainingSum - weights[k]);
    }
}

int main() {
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements in increasing order:\n";
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
        totalSum += weights[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    sumOfSubsets(0, 0, totalSum);

    return 0;
}
