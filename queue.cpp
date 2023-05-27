#include <iostream>

class Queue {
    private:
        int* arr;
        int length;
        int head;
        int tail;

        bool exceededCapacity() {
            return this->tail == (this->length - 1);
        }

        void resetQueue() {
            this->head      = -1;
            this->tail      = -1;
        }

    public: 
        Queue(int length) {
            this->arr       = new int[length];
            this->length    = length;
            resetQueue();
        }

        void enqueue(int num) {
            if (exceededCapacity()) {
                throw "Queue Overflow";
            } else {
                if (isEmpty()) this->head = 0;
                this->arr[++this->tail] = num;
            }
        }

        int dequeue() {
            if (isEmpty()) {
                throw "Queue is empty";
            } else {
                int value = this->arr[this->head];
                this->arr[this->head] = 0;
                this->head++;

                if (this->head == this->length) {
                    resetQueue();
                }

                return value;
            }
        }

        int peek() {
            if (isEmpty()) {
                throw "Queue is empty";
            } else {
                return this->arr[this->head];
            }
        }

        bool isEmpty() {
            return this->head == -1;
        }
};

int main() {
    Queue* queue = new Queue(5);
    try {
        std::cout << "dequeue: " << queue->dequeue() << std::endl;
    } catch (const char* msg) {
        std::cout << msg << std::endl;
    }
    

    queue->enqueue(1);
    queue->enqueue(2);
    queue->enqueue(3);
    queue->enqueue(4);
    queue->enqueue(5);

    std::cout << "dequeue: " << queue->dequeue() << std::endl;
    std::cout << "dequeue: " << queue->dequeue() << std::endl;
    std::cout << "peek: " << queue->peek() << std::endl;

    try {
        queue->enqueue(6);
    } catch(const char* msg) {
        std::cout << msg << std::endl;
    }
    std::cout << "dequeue: " << queue->dequeue() << std::endl;

    
    std::cout << "dequeue: " << queue->dequeue() << std::endl;
    std::cout << "dequeue: " << queue->dequeue() << std::endl;
    queue->enqueue(7);

    std::cout << "dequeue: " << queue->dequeue() << std::endl;
}