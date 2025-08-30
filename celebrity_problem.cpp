#include <iostream>
#include <vector>

using namespace std;

int celebrity(vector<vector<int>>& mat){
    int candidate = 0;
    int n = mat.size();
    int a = 0, b = n-1;

    while(a<b){
        if(mat[a][b] == 1){
            a++;
        }
        else{
            b--;
        }
    }
    candidate = a;

    for(int i = 0; i<n; i++){
        if(i!= candidate){
            if(mat[candidate][i] == 1 || mat[i][candidate] == 0){
                return -1;
            }
        }
    }
    return candidate;
}

int main(){
    vector<vector<int>> arr = {{1, 1, 0}, {0, 1, 0}, {0, 1, 1}};
    cout<< celebrity(arr) << endl;
    return 0;
}