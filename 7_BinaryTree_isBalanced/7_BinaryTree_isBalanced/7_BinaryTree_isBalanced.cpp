#include <iostream>
using namespace std;
class Node {
public:
    Node(int d) {
        left = nullptr;
        right = nullptr;
        data = d;
    }
    Node* left;
    Node* right;
    int data;
};
class Tree {
private:
    Node* root;
    void crawlPrint(Node* node, int level, int& branch) {
        cout << " " << "(" << node->data << ")";
        if (node->left != nullptr)
            cout << "L";
        if (node->right != nullptr)
            cout << "R";
        if (node->right == nullptr && node->left == nullptr)
            cout << "N";
        cout << "[" << branch << "]" << "{" << level << "}";
        if (node->left != nullptr) {
            branch++;
            crawlPrint(node->left, level + 1, branch);
        }
        if (node->right != nullptr) {
            branch++;
            crawlPrint(node->right, level + 1, branch);
        }
    }
    void crawlWeight(Node* node, int& weight) {
        if (node->left != nullptr) {
            weight++;
            crawlWeight(node->left, weight);
        }
        if (node->right != nullptr) {
            weight++;
            crawlWeight(node->right, weight);
        }
    }
    bool crawlIsBalanced(Node* node) {
        bool leftIsBalanced = true, rightIsBalanced = true;
        if (node->left != nullptr)
            leftIsBalanced = crawlIsBalanced(node->left);
        if (node->right != nullptr)
            rightIsBalanced = crawlIsBalanced(node->right);
        int wleft = 0, wright = 0;
        if (node->left != nullptr)
            crawlWeight(node->left, wleft);
        if (node->right != nullptr)
            crawlWeight(node->right, wright);
        if (abs(wleft - wright)<=1 && rightIsBalanced && leftIsBalanced)
            return true;  
        return false;
    }
public:
    Tree() {
        root = nullptr;
    }
    void print() {
        int level = 1, branch = 0;
        crawlPrint(root, level, branch);
    }
    bool isBalanced() {
        return crawlIsBalanced(root);
    }
    void insert(int data) {
        if (root == nullptr) {
            root = new Node(data);
        }
        else {
            bool stop = false;
            auto cur = root;
            while (!stop) {
                if (data < cur->data) {
                    if (cur->left == nullptr) {
                        cur->left = new Node(data);
                        stop = true;
                    }
                    else {
                        cur = cur->left;
                    }
                }
                if (data >= cur->data) {
                    if (cur->right == nullptr) {
                        cur->right = new Node(data);
                        stop = true;
                    }
                    else {
                        cur = cur->right;
                    }
                }
            }
        }
    }
};
int main()
{
    Tree t = Tree();
    t.insert(20);
    t.insert(10);
    t.insert(15);
    t.insert(30);
    t.insert(25);
    t.insert(40);
    
    t.print();
    cout <<endl<< "isBalanced: " << t.isBalanced() << endl;
}
//25 minutes
