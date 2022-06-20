#include <iostream>
#include<list>
using namespace std;
class Node {
public:
    Node(char d) {
        right = nullptr;
        left = nullptr;
        data = d;
    }
    Node* right;
    Node* left;
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
    void crawlEven(Node* node, list<char>& evenNodes) {
        if (node->left != nullptr) {
            if (node->left->data % 2 == 0) {
                evenNodes.push_back(node->left->data);
            }
            crawlEven(node->left, evenNodes);
        }
        if (node->right != nullptr) {
            if (node->right->data % 2 == 0) {
                evenNodes.push_back(node->right->data);
            }
            crawlEven(node->right, evenNodes);
        }
    }
    void moreEven(Node* node) {
        int evenLeft = 0, evenRight = 0;
        list<char>evenLeftList, evenRightList;
        if (node->left != nullptr) {
            crawlEven(node->left, evenLeftList);
        }
        if (node->right != nullptr) {
            crawlEven(node->right, evenRightList);
        }
        cout << "Node: " << node->data << endl;
        cout << "LeftEvenList > RightEvenList: " << (evenLeftList.size() > evenRightList.size()) << endl;
        cout << "\t" << "Left:" << endl;
        for (auto i = begin(evenLeftList); i != end(evenLeftList); i++)
        {
            cout << "\t\t" << *i << endl;
        }
        cout << "\t" << "Right:" << endl;
        for (auto i = begin(evenRightList); i != end(evenRightList); i++)
        {
            cout << "\t\t" << *i << endl;
        }
        if (node->left != nullptr) {
            moreEven(node->left);
        }
        if (node->right != nullptr) {
            moreEven(node->right);
        }
            
    }
public:
    Tree() {
        root = nullptr;
    }
    void print() {
        if (root != nullptr) {
            int level = 1, branch = 0;
            crawlPrint(root, level, branch);
        }
        else
            cout << "Empty";
    }
    void printMoreEven() {
        moreEven(root);
    }
    void insert(char data) {
        if (root == nullptr)
            root = new Node(data);
        else {
            bool stop = false;
            Node* cur = root;
            while (!stop) {
                if (data < cur->data) {
                    if (cur->left == nullptr) {
                        cur->left = new Node(data);
                        stop = true;
                    }
                    else
                        cur = cur->left;
                }
                if (data > cur->data) {
                    if (cur->right == nullptr) {
                        cur->right = new Node(data);
                        stop = true;
                    }
                    else
                        cur = cur->right;
                }
                if (data == cur->data) {
                    stop = true;
                }
            }
        }
    }
};
int main()
{
    Tree t = Tree();
    string s = "";
    cout << "Enter string: ";
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        t.insert(s[i]);
    }
    t.print();
    cout << endl << endl;
    t.printMoreEven();
}
