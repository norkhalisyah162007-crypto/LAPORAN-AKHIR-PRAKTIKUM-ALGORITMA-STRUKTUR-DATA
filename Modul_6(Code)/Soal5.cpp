#include <iostream>
#include <sstream>
#include <string>
#include "RedBlackTree.h"
using namespace std;

void preorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nil,
              string& out, bool& first) {
    if (node->isNil) return;
    if (!first) out += " ";
    out += to_string(node->key);
    first = false;
    preorder(node->left,  nil, out, first);
    preorder(node->right, nil, out, first);
}

void inorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nil,
             string& out, bool& first) {
    if (node->isNil) return;
    inorder(node->left,  nil, out, first);
    if (!first) out += " ";
    out += to_string(node->key);
    first = false;
    inorder(node->right, nil, out, first);
}

void postorder(const RedBlackTree::Node* node, const RedBlackTree::Node* nil,
               string& out, bool& first) {
    if (node->isNil) return;
    postorder(node->left,  nil, out, first);
    postorder(node->right, nil, out, first);
    if (!first) out += " ";
    out += to_string(node->key);
    first = false;
}

string getPreorder(const RedBlackTree& rbt) {
    string out; bool first = true;
    preorder(rbt.root(), rbt.nil(), out, first);
    return out;
}

string getInorder(const RedBlackTree& rbt) {
    string out; bool first = true;
    inorder(rbt.root(), rbt.nil(), out, first);
    return out;
}

string getPostorder(const RedBlackTree& rbt) {
    string out; bool first = true;
    postorder(rbt.root(), rbt.nil(), out, first);
    return out;
}

int main() {
    int N;
    cin >> N;

    RedBlackTree rbt;
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        if (!rbt.contains(val)) {
            rbt.insert(val);
        }
    }

    int Q;
    cin >> Q;

    while (Q--) {
        string query;
        cin >> query;

        if (rbt.empty()) {
            cout << "Tree kosong. Tidak ada yang bisa ditampilkan." << endl;
            continue;
        }

        if (query == "PREORDER") {
            cout << "[Preorder]  : " << getPreorder(rbt) << endl;
        } else if (query == "INORDER") {
            cout << "[Inorder]   : " << getInorder(rbt) << endl;
        } else if (query == "POSTORDER") {
            cout << "[Postorder] : " << getPostorder(rbt) << endl;
        } else if (query == "ALL") {
            cout << "[Preorder]  : " << getPreorder(rbt)   << endl;
            cout << "[Inorder]   : " << getInorder(rbt)    << endl;
            cout << "[Postorder] : " << getPostorder(rbt)  << endl;
        }
    }
    return 0;
}