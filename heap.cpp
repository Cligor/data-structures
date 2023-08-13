#include <iostream>
using namespace std;

class Heap {
    private:
        int* heap;
        int size;
        int tail;

    public:
        Heap(int size) {
            this->size = size;
            this->tail = -1;
            this->heap[size] = {};
        }

        void add(int value) {
            if (++tail >= size) {
                cout << "Index Out of Bounds" << endl;
            }
            this->heap[++this->tail] = value;
        }

        int get(int i) {
            if (i > tail || i < 0) cout << "Index Out of Bounds" << endl;
            return this->heap[i];
        }
}

int main() {
    Heap heap = new Heap(1);
    heap->add(1);

    cout << heap->get(0);
    cout << heap->get(1);
    return 0;
}
