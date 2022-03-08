#include <bits/stdc++.h>
using namespace std;

class Node{
public:

    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        this->left = this->right = nullptr;
    }
    Node(int data, Node *left, Node *right) {
        this->data = data;
        this->left = left;
        this->right = right;
    }

};

void insert(Node* &root, int data) {

    if ( root == nullptr ) {
        root = new Node(data);
        return;
    }

    if ( data < root->data ) {
        insert(root->left,data);
    } else if ( root->data < data ) {
        insert(root->right,data);
    }

    return;
}

Node* search( Node* root, int target ) {

    if ( root == nullptr ) {
        return root;
    }

    if ( target < root->data ) {
        return search(root->left,target);
    } else if ( root->data < target ) {
        return search(root->right,target);
    }
    
    // VAL HAS BEEN FOUND!!!!
    return root;
}


Node* search1( Node* root, int target ) {

    if ( root == nullptr ) {
        return root;
    }

    if ( target != root->data ) {
        return 
        
        (Node*)
        (search1(root->left,target) 
        || 
        search1(root->right,target));


    } else {
        // VAL HAS BEEN FOUND!!!!
        return root;
    }
    
}


Node* searchPar( Node* root, int target ) {

    if ( root == nullptr ) {
        return root;
    }

    if ( root->left!=nullptr and root->left->data == target ) {

        return root;

    }
    if ( root->right!=nullptr and root->right->data == target ) {

        return root;

    }


    if ( target < root->data ) {
        return searchPar(root->left,target);
    } else if ( root->data < target ) {
        return searchPar(root->right,target);
    }
    

}


Node* deleteNode(Node* root, int target) {

    if ( root== nullptr)
        return nullptr;

    
    if ( root->data == target ){
        // delete

        // Case 1 - Leaf Node
        if ( root->left==nullptr and root->right==nullptr ) {
            return nullptr;
        }

        // Case 2 - ONLY L/R child

        if ( root->left!=nullptr and root->right==nullptr ) {
            return root->left;
        }
        if ( root->left==nullptr and root->right!=nullptr ) {
            return root->right;
        }

        // Case 3 - Both L&R Child

        Node* head = root->left;
        while ( head!=nullptr and head->right!=nullptr ) {
            head = head->right;
        }

        swap(head->data,root->data);

        root->left = deleteNode(root->left,target);


    } else if ( root->data > target) {
        root->left = deleteNode(root->left,target);
    } else {
        root->right = deleteNode(root->right,target);
    }

    return root;

}



void inOrder(Node* root) {

    if ( root == nullptr ) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);

}
void preOrder(Node* root) {

    if ( root == nullptr ) return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);

}

int main() {

    Node* bst = nullptr;

    insert(bst,24);
    insert(bst,1);
    insert(bst,11);
    insert(bst,15);
    insert(bst,7);
    insert(bst,36);
    insert(bst,50);
    insert(bst,44);
    insert(bst,38);
    insert(bst,53);

    inOrder(bst); cout << endl;

    if (search(bst,28)!=nullptr) {
        cout << "Found 28\n";
    } else {
        cout << "NOT Found 28!!\n";
    }

    if (search(bst,7)!=nullptr) {
        cout << "Found 7\n";
    } else {
        cout << "NOT Found 7!!\n";
    }

    if (search(bst,15)!=nullptr) {
        cout << "Found 15\n";
    } else {
        cout << "NOT Found 15!!\n";
    }

    // deleteNode(bst,24);
    // inOrder(bst); cout << endl;

    deleteNode(bst,50);
    inOrder(bst); cout << endl;
    
    deleteNode(bst,11);
    inOrder(bst); cout << endl;
    
    deleteNode(bst,44);
    inOrder(bst); cout << endl;
    preOrder(bst); cout << endl;


}
