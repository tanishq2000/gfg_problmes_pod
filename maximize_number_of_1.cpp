#include <iostream>
#include <vector>
using namespace std;

int longestOnes(vector<int>& arr, int k) {
    int left = 0, right = 0;
    int zeros = 0, maxLen = 0;

    for (right = 0; right < arr.size(); right++) {
        if (arr[right] == 0) zeros++;

        while (zeros > k) {
            if (arr[left] == 0) zeros--;
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    vector<int> arr = {1,0,0,1,1,0,1};
    int k = 2;
    cout << longestOnes(arr, k) << endl; // Output: 5
}
