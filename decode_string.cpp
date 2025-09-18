#include <iostream>
#include <stack>
#include <string>

using namespace std;

string decodeString(string input_string){
    stack<string> st;
    stack<int> numSt;
    string curr = "";
    int num = 0;
    for(char ch: input_string){
        
        if(isdigit(ch)){
            num = num * 10 + (ch - '0');
        }
        else if(ch == '['){
            numSt.push(num);
            st.push(curr);
            num = 0;
            curr = "";
        }
        else if(ch == ']'){
            int times = numSt.top(); numSt.pop();
            string prev = st.top(); st.pop();
            
            string temp = "";
            for(int i = 0; i < times; i++){
                temp += curr;
            }
            curr = prev + temp;
        }
        else{
            curr += ch;
        }
    }
    return curr;
}


// string decodeString(string s) {
//     stack<string> st;   // to store strings
//     stack<int> numSt;   // to store numbers
//     string curr = "";   // current building string
//     int num = 0;        // current number

//     for (char ch : s) {
//         if (isdigit(ch)) {
//             // build the number (multi-digit possible)
//             num = num * 10 + (ch - '0');
//         } 
//         else if (ch == '[') {
//             // push current state and reset
//             numSt.push(num);
//             st.push(curr);
//             num = 0;
//             curr = "";
//         } 
//         else if (ch == ']') {
//             // expand substring
//             int times = numSt.top(); numSt.pop();
//             string prev = st.top(); st.pop();

//             string temp = "";
//             for (int i = 0; i < times; i++) {
//                 temp += curr;
//             }
//             curr = prev + temp;
//         } 
//         else {
//             // normal character
//             curr += ch;
//         }
//     }
//     return curr;
// }


int main()
{
    string input_string;
    cout << "Enter the coded string: ";
    cin >> input_string;
    cout << decodeString(input_string)<< endl;
    return 0;
}