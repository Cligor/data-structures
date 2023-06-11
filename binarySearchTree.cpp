#include <iostream>

class Node {
    public:
        int value;
        Node* right;
        Node* left;
};

class BinarySearchTree {
    private:
        Node* root;

        Node* search(Node* node, int value) {
            if (value > node->value) {
                return search(node->right, value);
            } else if (value < node->value) {
                return search(node->left, value);
            }

            return node;
        }

        void inorder_traversal(Node* node) {
            if (node) {
                inorder_traversal(node->left);
                std::cout << node->value << "-";
                inorder_traversal(node->right);
            }
        }

    public:
        BinarySearchTree() {
            this->root = NULL;
        }

        Node* getRoot() {
            return this->root;
        }

        bool insert(int value) {
            Node *temp = new Node();

            temp->value = value;
            temp->left = NULL;
            temp->right = NULL;

            if (root == NULL) {
                root = temp;
                return true;
            } 
            Node *current = this->root;
            Node *parent = NULL;

            while(true) {
                parent = current;
                if (value < parent->value) {
                    current = current->left;

                    if (current == NULL) {
                        parent->left = temp;
                        return true;
                    }
                } else {
                    current = current->right;

                    if (current == NULL) {
                        parent->right = temp;
                        return true;
                    }
                }
            }

            return true;
        }

        void inorder_traversal() {
            this->inorder_traversal(this->root);
        }

        Node* search(int value) {
            return this->search(this->root, value);
        }
};

int main() {
    int array[11] = {22,8,32,1,10,30,43,5,20,31,49};
    BinarySearchTree* bstree = new BinarySearchTree();

    for (int i = 0; i < 11; i++) {
        bstree->insert(array[i]);
    }
    bstree->inorder_traversal();

    Node* test = bstree->search(43);
    if (test) 
        std::cout << "Encontrado o valor: " << test->value << std::endl;
    else 
        std::cout << "Não encontrado";

    return 0;
}