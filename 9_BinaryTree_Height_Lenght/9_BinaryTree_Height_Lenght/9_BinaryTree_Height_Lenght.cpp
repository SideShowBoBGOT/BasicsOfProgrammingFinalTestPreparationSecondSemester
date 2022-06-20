#include <iostream>
using namespace std;
class Node {
public:
    Node(char d) {
        left = nullptr;
        right = nullptr;
        data = d;
    }
    Node* left;
    Node* right;
    char data;
};
class Tree {
private:
    Node* root;
    void crawlPrint(Node* node, int level, int&branch){
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
    void crawlHeight(Node* node, int level, int&height) {
        height = max(level, height);
        if (node->left != nullptr) {
            crawlHeight(node->left, level + 1, height);
        }
        if (node->right != nullptr) {
            crawlHeight(node->right, level + 1, height);
        }
    }
    void crawlGetLengthPath(Node* node, char data, int level, int&lenght) {
        if (node->data == data) {
            lenght = level;
            return;
        }
        if (node->left != nullptr)
            crawlGetLengthPath(node->left, data, level + 1, lenght);
        if (node->right != nullptr)
            crawlGetLengthPath(node->right, data, level + 1, lenght);
    }
public:
    Tree() {
        root = nullptr;
    }
    int getHeight() {
        int height = 0;
        if (root != nullptr) {
            height++;
            crawlHeight(root, 1, height);
        }
        return height;
    }
    int getLenghtPath(char data) {
        int lenght = 0;
        if (root != nullptr) {
            crawlGetLengthPath(root, data, 1, lenght);
        }
        else {
            throw "Tree is empty";
        }
        return lenght;
    }
    void print() {
        int level = 1, branch = 0;
        if (root != nullptr) {
            crawlPrint(root, level, branch);
        }
        else {
            throw "Tree is empty";
        }

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
                        stop = true;
                        cur->left = new Node(data);
                    }
                    else
                        cur = cur->left;
                }
                if (data > cur->data) {
                    if (cur->right == nullptr) {
                        stop = true;
                        cur->right = new Node(data);
                    }
                    else
                        cur = cur->right;
                }
                if (data == cur->data) {
                    stop = true;
                    // тут можа було викликати чну ситуацію, але навіщо
                }
            }
        }
    }
};
int main()
{
    Tree t = Tree();
    string s = "";
    cin >> s;
    cout << endl<<endl;
    for (int i = 0; i < s.length(); i++)
    {
        t.insert(s[i]);
    }
    t.print();
    cout << endl << endl;
    cout << "Height: " << t.getHeight() << endl;
    cout << "Symbol: ";
    char symb;
    cin >> symb;
    cout << "Length: " << t.getLenghtPath(symb)<<endl<<endl;

}
