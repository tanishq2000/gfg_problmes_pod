# include<iostream>
# include<vector>
#include<stack>

using namespace std;

vector<int> nextGreaterElements(vector<int> &arr){
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for(int i=0; i < 2*n; i++){
        int num = arr[i % n];

        while(!st.empty() && arr[st.top()] < num){
            ans[st.top()] = num;
            st.pop();
        }
        
        if(i<n){ 
            st.push(i);
        }
    }

    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of circular array: ";
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    vector<int> res = nextGreaterElements(arr);
    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}