#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int array_triangle(vector<int>& arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int count = 0;
    for(int k = n-1; k >= 2; k--){
        int i = 0; 
        int j = k-1;

        while (i<j)
        {
            /* code */
            if(arr[i]+arr[j] > arr[k]){
                count += j-i;
                j--;
            }
            else{
                i++;
            }
        }
        
    }
    return count;
}

int main(){
    vector<int> arr = {4, 6, 3, 7};
    cout << array_triangle(arr) << endl; // Output: 3
    return 0;
}