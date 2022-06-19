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
class Queue {
private:
    Node<T>* head, * tail;
public:
    Queue() {
        this->head = nullptr;
        this->tail = nullptr;
    }
    void Push(T data) {
        if (this->head == nullptr) {
            this->head = new Node<T>(data);
            this->tail = this->head;
        }
        else {
            Node<T>* node = new Node<T>(data);
            this->tail->left = node;
            node->right = this->tail;
            this->tail = node;
        }
    }
    T Pop() {
        Node<T>* node = this->head;
        T data = node->data;
        if (this->tail == this->head) {
            this->tail = nullptr;
            this->head = nullptr;
        }
        else
            this->head = this->head->left;
        delete node;
        return data;
    }
    T Front() {
        return this->head->data;
    }
    T Back() {
        return this->tail->data;
    }

};