#include <iostream>
#include <vector>
using namespace std;

struct Heap {
    vector<int> heap;
    Heap() {}

    void push(int x) {
        heap.push_back(x);
        int i = (int)heap.size() - 1;
        while (i > 0) {
            int p = (i - 1) / 2;
            if (heap[p] >= x) break;
            heap[i] = heap[p];
            i = p;
        }
        heap[i] = x;
    }

    int top() {
        if (!heap.empty()) return heap[0];
        else return -1;
    }

    void pop() {
        if (heap.empty()) return;
        int x = heap.back();
        heap.pop_back();
        int i = 0;
        while (i * 2 + 1 < (int)heap.size()) {
            int child1 = i * 2 + 1;
            int child2 = i * 2 + 2;
            if (child2 < (int)heap.size() && heap[child2] > heap[child1]) {
                child1 = child2;
            }
            if (heap[child1] <= x) break;
            heap[i] = heap[child1];
            i = child1;
        }
        heap[i] = x;
    }

    void show() {
        if (heap.empty()) return;
        for (int i = 0; i < (int)heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap H;
    vector<int> v = {5, 6, 1, 2, 7, 3, 4};
    for (int i = 0; i < (int)v.size(); i++) {
        H.push(v[i]);
        H.show();
    }
}
