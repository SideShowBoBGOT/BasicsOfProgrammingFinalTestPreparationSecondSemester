#include <iostream>
#include<vector>
#include<string>
using namespace std;
class Node {
public:
    Node(int d) {
        right = nullptr;
        left = nullptr;
        data = d;
    }
    Node* right;
    Node* left;
    int data;
};
class Tree {
private:
    Node* root;
    void crawlBuild(Node* node, int num) {
        node->left = new Node(num);
        node->right = new Node(num);
        if (num == 1)
            return;
        crawlBuild(node->left, num - 1);
        crawlBuild(node->right, num - 1);
    }
    void crawlPrint(Node* node, vector<pair<int, char>>&leftPos) {
        cout << node->data;
        if (node->left != nullptr)
            leftPos.push_back(pair<int, char>(to_string(node->data).length(), '|'));
        if (node->right != nullptr) {
            cout << " -> ";
            crawlPrint(node->right, leftPos);
        }
        if (node->left != nullptr) {
            leftPos[leftPos.size() - 1].second = ' ';
            cout << endl;
            for (int k = 0; k < 2; k++)
            {
                for (int i = 0; i < leftPos.size() - 1; i++)
                {
                    for (int j = 0; j < leftPos[i].first - 1; j++)
                    {
                        cout << " ";
                    }
                    cout << leftPos[i].second;
                    cout << "    ";
                }
                
                for (int j = 0; j < leftPos[leftPos.size() - 1].first - 1; j++)
                {
                    cout << " ";
                }
                cout << "|";
                if (k == 0)
                    cout << endl;
            }
            cout << " -> ";
     
            crawlPrint(node->left, leftPos);
            leftPos.pop_back();
        }
    }
public:
    void print() {
        if (root != nullptr) {
            vector<pair<int, char>>leftPos;
            crawlPrint(root, leftPos);
        }
        else {
            cout << "Empty";
        }

    }
    Tree(int number) {
        root = new Node(number);
        crawlBuild(root, number - 1);
    }
};
int main()
{

    Tree t = Tree(5);
    t.print();
}
