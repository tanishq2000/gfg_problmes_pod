#include <iostream>
#include <vector>

using namespace std;

int maxWater(vector<int>& arr){
    int maxWater = 0;
    int n = arr.size();
    int left = 0, right = n-1;

    while(left < right){
        int width = right-left;
        int height = min(arr[left], arr[right]);
        int area = width * height;
        maxWater = max(maxWater, area);
        
        if(arr[left] < arr[right]){
            left++;
        }
        else{
            right--;
        }
    }

    return maxWater;
}

int main(){
    
    vector<int> arr = {2, 1, 6, 6, 8, 8};
    
    cout<< "The Max water that can be contained is: " << maxWater(arr)<< endl;

    return 0;
}