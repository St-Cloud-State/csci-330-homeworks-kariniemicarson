#include <iostream>
#include <vector>
#include <stack> //need this for non-recursive quicksort

using namespace std;

//partition function
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // if the element is smaller than the pivot, swap
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Iterative QuickSort using stack
void quickSortIterative(vector<int>& arr) {
    int low = 0, high = arr.size() - 1; // getting highs and lows, partition function will use it
    stack<pair<int, int>> s;

    s.push({low, high}); // push initial array onto the stack

    while (!s.empty()) {
        // Get the subarray range from stack
        auto [low, high] = s.top();
        s.pop();

        // partition
        int pivot = partition(arr, low, high);

        // push left subarray if needed
        if (pivot - 1 > low) {
            s.push({low, pivot - 1});
        }

        // push right subarray if needed
        if (pivot + 1 < high) {
            s.push({pivot + 1, high});
        }
    }
}

int main() {
    vector<int> arr = {1, 13, 32, 43, 2, 5, 7, 11, 23, 69, 33};

    cout << "Original array: "; //display original array
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    quickSortIterative(arr);

    cout << "Sorted array: "; //display sorted array
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}