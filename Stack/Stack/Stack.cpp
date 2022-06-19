#include <iostream>
#include<string>
using namespace std;

template<typename T>
class Node {
public:
    Node(T data) {
        this->left = nullptr;
        this->right = nullptr;
        this->data = data;
    }
    Node* left;
    Node* right;
    T data;
};
template<typename T>
class Stack {
private:
    Node<T>* top;
public:
    Stack() {
        this->top = nullptr;
    }
    void Push(T data) {
        if (this->top == nullptr) {
            this->top = new Node<T>(data);
        }
        else {
            Node<T>* node = new Node<T>(data);
            node->left = this->top;
            this->top = node;
        }
    }
    T Pop() {
        T data = this->top->data;
        Node<T>* node = this->top;
        this->top = this->top->left;
        delete node;
        return data;
    }
    T Top() {
        return this->top->data;
    }
    bool IsEmpty() {
        return this->top == nullptr;
    }
    ~Stack() {
        Node<T>* current = this->top;

        while (current != nullptr) {
            Node<T>* tmp = current->left;
            delete current;
            current = tmp;
        }
    }
};
int main() {
    Stack<int> st = Stack<int>();
    for (int i = 0; i < 10; i++)
    {
        st.Push(i);
        cout << st.Top() << endl;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << st.Top() << endl;
        st.Pop();  
    }
}