#include <iostream>
using namespace std;
class Node {
public:
    Node(char d) {
        left = nullptr;
        right = nullptr;
        data = d;
        dubs = 1;
    }
    Node* right;
    Node* left;
    char data;
    int dubs;
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
    Node* eraseNode(Node* node, char data) {
        if (data < node->data)
            node->left = eraseNode(node->left, data);
        else if (data > node->data)
            node->right = eraseNode(node->right, data);
        else {
            Node* tmp = nullptr;
            if (node->right == nullptr) {
                tmp = node->left;
            }
            else {
                Node* ptr = node->right;
                if (ptr->left == nullptr) {
                    tmp = ptr;
                    ptr->left = node->left;
                }
                else {
                    Node* pmin = ptr->left;
                    while (pmin->left != nullptr) {
                        ptr = pmin;
                        pmin = pmin->left;
                    }
                    ptr->left = pmin->right;
                    tmp = pmin;
                    pmin->left = node->left;
                    pmin->right = node->right;
                }
            }
            if (node == root) {
                root = tmp;
            }
            delete node;
            return tmp;
        }
        return node;
    }
    void crawlEraseDubs(Node* node) {
        if (node->left != nullptr) {
            crawlEraseDubs(node->left);
        }
        if (node->right != nullptr) {
            crawlEraseDubs(node->right);
        }
        if (node->dubs > 1)
            erase(node->data);
    }
public:
    Tree(){
        root = nullptr;
    }
    void erase(char data) {
        eraseNode(root, data);
    }
    void print() {
        int level = 1, branch = 0;
        crawlPrint(root, level, branch);
    }
    void eraseDubs() {
        crawlEraseDubs(root);
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
                    cur->dubs++;
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
    t.eraseDubs();
    t.print();

}
