#include <iostream>
#include <vector>
using namespace std;


template <typename T>
int countSignChanges(const vector<T>& vec) {
    int changes = 0;
    for (size_t i = 1; i < vec.size(); ++i) {
        if ((vec[i] > 0 && vec[i - 1] < 0) || (vec[i] < 0 && vec[i - 1] > 0)) {
            changes++;
        }
    }
    return changes;
}


template <typename T>
int countInRange(const vector<T>& vec, T a, T b) {
    int count = 0;
    for (T val : vec) {
        if (val >= a && val <= b) {
            count++;
        }
    }
    return count;
}

int main() {
    vector<int> numbers(20);
    cout << "Enter 20 integers:\n";
    for (int i = 0; i < 20; ++i) {
        cin >> numbers[i];
    }

    int a, b;
    cout << "Enter range values (a and b): ";
    cin >> a >> b;

    int signChanges = countSignChanges(numbers);
    int inRangeCount = countInRange(numbers, a, b);

    cout << "Number of sign changes: " << signChanges << endl;
    cout << "Number of elements in range [" << a << ", " << b << "]: " << inRangeCount << endl;

    return 0;
}
