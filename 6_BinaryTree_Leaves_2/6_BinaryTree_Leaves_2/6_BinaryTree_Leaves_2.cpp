#include <iostream>
#include<list>
using namespace std;
class Node {
public:
    Node(char data) {
        left = nullptr;
        right = nullptr;
        this->data = data;
    }
    Node* left;
    Node* right;
    char data;
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
        if (node->left == nullptr && node->right == nullptr)
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
    void crawlLeaves(Node* node, list<char>& leaves) {
        if (node->left == nullptr && node->right == nullptr)
            leaves.push_back(node->data);
        if (node->left != nullptr) {
            crawlLeaves(node->left, leaves);
        }
        if (node->right != nullptr) {
            crawlLeaves(node->right, leaves);
        }
    }
public:
    Tree() {
        this->root = nullptr;
    }
    list<char> getLeaves() {
        list<char>leaves;
        crawlLeaves(root, leaves);
        leaves.sort();
        return leaves;
    }
    void insert(char data) {
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
    void print() {
        int level = 1, branch = 0;
        crawlPrint(root, level, branch);
    }
};
int main()
{
    Tree t = Tree();
    for (int i = 0; i < 10; i++)
    {
        t.insert(rand()%20+50);
    }
    t.print();
    list<char>leaves = t.getLeaves();
    cout <<endl<< "Leaves: " << endl;
    for (auto i = begin(leaves); i !=end(leaves); i++)
    {
        cout << *i << endl;
    }
    return 0;
}
//12 minutes
