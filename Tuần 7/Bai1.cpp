#include <iostream>
#include <vector>

using namespace std;

int binarySearchRecursive(const vector<int>& arr, int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] > target)
            return binarySearchRecursive(arr, left, mid - 1, target);
        return binarySearchRecursive(arr, mid + 1, right, target);
    }
    return -1;
}

int main() {
    vector<int> arr = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = arr.size();
    int target = 12;

    int result = binarySearchRecursive(arr, 0, n - 1, target);

    if (result != -1)
        cout << target << " " << result << endl;
    else
        return -1;

    return 0;
}
