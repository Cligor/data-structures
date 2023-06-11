#include <iostream>

class Node {
    public:
        int value;
        int color; // 0 - black; 1 - red;
        Node* right;
        Node* left;
        Node* parent;
};

class RBTree {
    private:
        Node* root;

        Node* search(Node* Node, int value) {
            if (value > Node->value) {
                return search(Node->right, value);
            } else if (value < Node->value) {
                return search(Node->left, value);
            }

            return Node;
        }

        void inorderTraversal(Node* Node) {
            if (Node) {
                inorderTraversal(Node->left);
                std::cout << Node->value << "-";
                inorderTraversal(Node->right);
            }
        }

    public:
        RBTree() {
            this->root = NULL;
        }

        Node* getRoot() {
            return this->root;
        }

        bool applyRbRules(Node* currentNode) {
            Node* temp;
            if(this->root==currentNode) {
                currentNode->color=0;
                return true;
            }
            while(currentNode->parent!=NULL&&currentNode->parent->color==1) {
                Node* grandParent=currentNode->parent->parent;
                if(grandParent->left==currentNode->parent) {
                    if(grandParent->right!=NULL) {
                        temp=grandParent->right;
                        if(temp->color==1) {
                            currentNode->parent->color=0;
                            temp->color=0;
                            grandParent->color=1;
                            currentNode=grandParent;
                        }
                    } else {
                        if(currentNode->parent->right==currentNode) {
                            currentNode=currentNode->parent;
                            leftRotate(currentNode);
                        }
                        currentNode->parent->color=0;
                        grandParent->color=1;
                        rightRotate(grandParent);
                    }
                } else {
                    if(grandParent->left!=NULL) {
                        temp=grandParent->left;
                        if(temp->color==1) {
                            currentNode->parent->color=0;
                            temp->color=0;
                            grandParent->color=1;
                            currentNode=grandParent;
                        }
                    }
                    else {
                        if(currentNode->parent->left==currentNode) {
                            currentNode=currentNode->parent;
                            rightRotate(currentNode);
                        }
                        currentNode->parent->color=0;
                        grandParent->color=1;
                        leftRotate(grandParent);
                    }
                }
                this->root->color=0;
            }

            return true;
        }

        void leftRotate(Node* x) {
            if(x->right == NULL) return;
            else {
                Node* temp = x->right;
                if (temp->left) {
                    x->right = temp->left;
                    temp->left->parent = x;
                } else {
                    x->right=NULL;
                }

                if (x->parent) {
                    temp->parent = x->parent;
                } 
                
                if (!x->parent) {
                    this->root = temp;
                } else {
                    if (x == temp->parent->right) {
                        x->parent->right = temp;
                    } else {
                        x->parent->left = temp;
                    }
                }

                temp->left = x;
                x->parent = temp;
            }
        }

        void rightRotate(Node* x) {
            if(x->left == NULL) return;
            else {
                Node* temp = x->left;
                if (temp->right) {
                    x->left = temp->right;
                    temp->right->parent = x;
                } else {
                    x->left=NULL;
                }

                if (x->parent) {
                    temp->parent = x->parent;
                } 
                
                if (!x->parent) {
                    this->root = temp;
                } else {
                    if (x == temp->parent->left) {
                        x->parent->left = temp;
                    } else {
                        x->parent->right = temp;
                    }
                }

                temp->right = x;
                x->parent = temp;
            }
        }

        bool insert(int value) {
            Node *temp = new Node();
            temp->value = value;
            temp->left = NULL;
            temp->right = NULL;
            temp->parent = NULL;
            temp->color = 1; // todo Node adicionado entra como vermelho

            if (root == NULL) {
                temp->color = 0;
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
                        temp->parent = parent;
                        parent->left = temp;
                        break;
                    }
                } else {
                    current = current->right;

                    if (current == NULL) {
                        temp->parent = parent;
                        parent->right = temp;
                        break;
                    }
                }
            }

            return this->applyRbRules(temp);
        }

        void inorderTraversal() {
            this->inorderTraversal(this->root);
        }

        Node* search(int value) {
            return this->search(this->root, value);
        }
};

std::string getColor(int color) {
    if (color == 0)
        return "preta";

    return "vermelha";
}


int main() {
    int arrayLength = 5;
    int array[arrayLength] = {34, 15, 84, 0, 2};
    RBTree* rbTree = new RBTree();

    for (int i = 0; i < arrayLength; i++) {
        rbTree->insert(array[i]);
    }
    rbTree->inorderTraversal();

    Node* test = rbTree->search(0);
    if (test) {
        std::string cor = getColor(test->color);
        
        std::cout << std::endl << "Encontrado o valor " << test->value << " com a cor " << cor << std::endl;
    } else {
        std::cout << "Não encontrado";
    }

    return 0;
}