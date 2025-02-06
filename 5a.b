#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* buildTree(int preorder[], int inorder[], int start, int end, unordered_map<int, int>& inMap, int& preorderIndex) {
    if (start > end) {
        return nullptr;
    }

    int curr = preorder[preorderIndex++];
    Node* node = new Node(curr);
    
    if (start == end) {
        return node;
    }

    int inorderIndex = inMap[curr];

    node->left = buildTree(preorder, inorder, start, inorderIndex - 1, inMap, preorderIndex);
    node->right = buildTree(preorder, inorder, inorderIndex + 1, end, inMap, preorderIndex);

    return node;
}

Node* constructTree(int preorder[], int inorder[], int n) {
    unordered_map<int, int> inMap;
    for (int i = 0; i < n; i++) {
        inMap[inorder[i]] = i;
    }

    int preorderIndex = 0;
    return buildTree(preorder, inorder, 0, n - 1, inMap, preorderIndex);
}

void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    int n = sizeof(preorder) / sizeof(preorder[0]);

    Node* root = constructTree(preorder, inorder, n);

    cout << "Inorder traversal of constructed tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
