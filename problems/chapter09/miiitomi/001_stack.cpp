#include <iostream>
#include <list>
using namespace std;

struct Stack {
    int size;
    list<int> data;

    Stack() {
        size = 0;
    }

    bool isEmpty() {
        return (size == 0);
    }

    void push(int x) {
        data.push_back(x);
        size++;
    }

    int pop() {
        if (isEmpty()) {
            cout << "error: stack is empty." << endl;
            return -1;
        } else {
            int output = data.back();
            data.pop_back();
            size--;
            return output;
        }
    }
};

int main() {
    Stack S;
    S.push(3);
    S.push(5);
    S.push(7);

    cout << S.pop() << endl;
    S.push(9);
    cout << S.pop() << endl;
    cout << S.pop() << endl;
}
