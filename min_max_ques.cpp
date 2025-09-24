#include<iostream>
#include<deque>
#include<queue>

using namespace std;

class SpecialQueue{
    queue<int> q;
    deque<int> minDeque, maxDeque;
public:
    void enqueue(int x){
        q.push(x);

        while(!minDeque.empty() && minDeque.back() > x){
            minDeque.pop_back();
        }
        minDeque.push_back(x);

        while(!maxDeque.empty() && maxDeque.back() < x){
            maxDeque.pop_back();
        }
        maxDeque.push_back(x);
    }
    void dequeue(){
        int val = q.front();
        q.pop();

        if(!minDeque.empty() && minDeque.front() == val){
            minDeque.pop_front();
        }
        if(!maxDeque.empty() && maxDeque.front() == val){
            maxDeque.pop_front();
        }
    }
    int getFront(){
        return q.front();
    }
    int getMin(){
        return minDeque.front();
    }
    int getMax(){
        return maxDeque.front();
    }
};

int main(){
    int Q;
    cin >> Q;
    SpecialQueue sq;

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x; cin >> x;
            sq.enqueue(x);
        } else if (type == 2) {
            sq.dequeue();
        } else if (type == 3) {
            cout << sq.getFront() << endl;
        } else if (type == 4) {
            cout << sq.getMin() << endl;
        } else if (type == 5) {
            cout << sq.getMax() << endl;
        }
    }
    
    return 0;
}