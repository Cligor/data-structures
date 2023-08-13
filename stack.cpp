#include <iostream>
using namespace std;

class MinHeap {
    private:
        int* heap;
        int size;
        int tail;
        int head;

        void heapify(int insertionIndex) {
            if (insertionIndex <= this->head) return;

            int parentIndex = (insertionIndex)/2;

            if (this->heap[insertionIndex] < this->heap[parentIndex]) {
                int aux = this->heap[parentIndex];
                this->heap[parentIndex] = this->heap[insertionIndex];
                this->heap[insertionIndex] = aux;
            }

            this->heapify(parentIndex);
        }

    public:
        MinHeap(int size) {
            this->size = size;
            this->tail = -1;
            this->head = -1;
            this->heap = new int[size];
        }

        void add(int value) {
            if (++tail >= size) {
                cout << "Index Out of Bounds" << endl;
            }

            this->heap[this->tail] = value;
            
            if (this->head == -1) this->head++;

            this->heapify(this->tail);
        }

        int get(int i) {
            if (i > tail || i < 0) cout << "Index Out of Bounds" << endl;
            return this->heap[i];
        }

        void print() {
            cout << "|";
            for(int i = 0; i <= this->tail; i++) {
                cout << this->heap[i] << "|";
            }

            cout << endl;
        }

        int pop() {
            // this->tail--;
            int value = this->heap[0];
            
            this->heap[0] = this->heap[tail];
            
            this->heapify(--this->tail);
            return value;
        }
};

int main() {
    MinHeap* heap = new MinHeap(4);
    heap->add(4);
    heap->add(5);
    heap->print();
    heap->add(2);
    heap->print();
    heap->add(1);
    heap->print();
    heap->pop();
    heap->print();
    heap->pop();
    heap->print();
    heap->add(4);
    heap->add(1);
    heap->print();
    heap->pop();
    heap->print();
    
    return 0;
}