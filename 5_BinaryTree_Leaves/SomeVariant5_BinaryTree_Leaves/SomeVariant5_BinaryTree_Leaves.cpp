#include <iostream>
#include<list>
using namespace std;
class Node {
public:
    Node(double data){
        this->left = nullptr;
        this->right = nullptr;
        this->data = data;
    }
    Node* left;
    Node* right;
    double data;
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
        cout << "[" << level << "]" << "{" << branch << "}";
        if (node->left != nullptr) {
            branch++;
            crawlPrint(node->left, level + 1, branch);
        }
        if (node->right != nullptr) {
            branch++;
            crawlPrint(node->right, level + 1, branch);
        }
    }
    void crawlLeaves(Node* node, list<int>& leaves) {
        if (node->left == nullptr && node->right == nullptr)
            leaves.push_back(node->data);
        if (node->left != nullptr)
            crawlLeaves(node->left, leaves);
        if (node->right != nullptr)
            crawlLeaves(node->right, leaves);
    }
public:
    Tree() {
        this->root = nullptr;
    }
    
    void insert(double data) {
        if (root == nullptr) {
            root = new Node(data);
        }
        else {
            bool stop = false;
            auto current = root;
            while (!stop) {
                if (data < current->data) {
                    if (current->left == nullptr) {
                        stop = true;
                        current->left = new Node(data);
                    }
                    else {
                        current = current->left;
                    }
                }
                if (data >= current->data) {
                    if (current->right == nullptr) {
                        stop = true;
                        current->right = new Node(data);
                    }
                    else {
                        current = current->right;
                    }
                }
            }
        }
    }
    list<int> getLeaves() {
        list<int>leaves;
        crawlLeaves(root, leaves);
        leaves.sort();
        return leaves;
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
        t.insert(rand() % 30);
    }
    t.print();
    list<int> leaves = t.getLeaves();
    cout << endl << "Leaves: " << endl;
    double avg = 0;
    for (auto i = begin(leaves); i != end(leaves); i++)
    {
        cout << *i << endl;
        avg += *i;
    }
    avg /= leaves.size();
    cout << "AVERAGE: " << avg << endl;

}
//16 minutes, guys
