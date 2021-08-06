#include <iostream>
#include <list>
using namespace std;

struct Queue {
    int size;
    list<int> data;

    Queue() {
        size = 0;
    }

    bool isEmpty() {
        return (size == 0);
    }

    void enqueue(int x) {
        data.push_back(x);
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "error: queue is empty." << endl;
            return -1;
        } else {
            int output = data.front();
            data.pop_front();
            size--;
            return output;
        }
    }
};

int main() {
    Queue Q;
    Q.enqueue(3);
    Q.enqueue(5);
    Q.enqueue(7);

    cout << Q.dequeue() << endl;
    cout << Q.dequeue() << endl;

    Q.enqueue(9);
    cout << Q.dequeue() << endl;
}
