#include <iostream>

class Stack {
    private:
        int* arr;
        int length;
        int head;
        int tail;

        bool exceededCapacity() {
            return this->tail == (this->length - 1);
        }

        void resetStack() {
            this->head      = -1;
            this->tail      = -1;
        }

    public: 
        Stack(int length) {
            this->arr       = new int[length];
            this->length    = length;
            resetStack();
        }

        void push(int num) {
            if (exceededCapacity()) {
                throw "Stack Overflow";
            } else {
                if (isEmpty()) this->head = 0;
                this->arr[++this->tail] = num;
            }
        }

        int pop() {
            if (isEmpty()) {
                throw "Stack is empty";
            } else {
                int value = this->arr[this->tail];
                this->arr[this->tail] = 0;
                this->tail--;

                if (this->head == this->length) {
                    resetStack();
                }

                return value;
            }
        }

        bool isEmpty() {
            return this->tail == -1;
        }
};

int main() {
    Stack* stack = new Stack(5);
    try {
        std::cout << "pop: " << stack->pop() << std::endl;
    } catch (const char* msg) {
        std::cout << msg << std::endl;
    }
    

    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    stack->push(5);

    std::cout << "pop: " << stack->pop() << std::endl;
    std::cout << "pop: " << stack->pop() << std::endl;
    std::cout << "pop: " << stack->pop() << std::endl;

    try {
        stack->push(6);
    } catch(const char* msg) {
        std::cout << msg << std::endl;
    }
    std::cout << "pop: " << stack->pop() << std::endl;

    
    std::cout << "pop: " << stack->pop() << std::endl;
    stack->push(7);

    std::cout << "pop: " << stack->pop() << std::endl;
    std::cout << "pop: " << stack->pop() << std::endl;
    try {
        std::cout << "pop: " << stack->pop() << std::endl;
    } catch(const char* msg) {
        std::cout << msg << std::endl;
    }
}