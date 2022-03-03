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

void deleteNode(Node* &root, int target) {

    Node* tarParAdd = searchPar(root, target);

    // Case 1
    if ( tarParAdd->left!=nullptr and tarParAdd->left->data == target ) {
        // LEFT CHILD
        if ( tarParAdd->left->left==nullptr and tarParAdd->left->right==nullptr ) {
            tarParAdd->left = nullptr;
        }
    }

    // Case 1
    if ( tarParAdd->right!=nullptr and tarParAdd->right->data == target ) {
        // RIGHT CHILD
        if ( tarParAdd->right->left==nullptr and tarParAdd->right->right==nullptr ) {
            tarParAdd->right = nullptr;
        }
    }



    // Case 2
    if ( tarParAdd->left!=nullptr and tarParAdd->left->data == target ) {
        if ( tarParAdd->left->left==nullptr and tarParAdd->left->right!=nullptr ) {
            tarParAdd->left = tarParAdd->left->right;
        }
        if ( tarParAdd->left->left!=nullptr and tarParAdd->left->right==nullptr ) {
            tarParAdd->left = tarParAdd->left->left;
        }
    }
    // Case 2
    if ( tarParAdd->right!=nullptr and tarParAdd->right->data == target ) {
        if ( tarParAdd->right->left==nullptr and tarParAdd->right->right!=nullptr ) {
            tarParAdd->right = tarParAdd->right->right;
        }
        if ( tarParAdd->right->left!=nullptr and tarParAdd->right->right==nullptr ) {
            tarParAdd->right = tarParAdd->right->left;
        }
    }
    
    // Case 3
    if ( tarParAdd->left!=nullptr and tarParAdd->left->data == target ) {
        
        Node* head = tarParAdd->left->left;
        
        // cout << head->data << endl;
        
        if ( head->right == nullptr ) {
            tarParAdd->left->left->right = tarParAdd->left->right;
            tarParAdd->left = tarParAdd->left->left;
        } else {
            while ( head->right!=nullptr and head->right->right!=nullptr ) {
                head = head->right;
            }
            
            tarParAdd->left->data = head->right->data;
            head->right = nullptr;
        }
    }
    // Case 3
    if ( tarParAdd->right!=nullptr and tarParAdd->right->data == target ) {

        Node* head = tarParAdd->right->left;
        
        if ( head->right == nullptr ) {
            tarParAdd->right->left->right = tarParAdd->right->right;
            tarParAdd->right = tarParAdd->right->left;
        } else {
            while ( head->right!=nullptr and head->right->right!=nullptr ) {
                cout << head->data << endl;
                head = head->right;
            }
            
            tarParAdd->right->data = head->right->data;
            head->right = nullptr;
        }
    }
    

}

void inOrder(Node* root) {

    if ( root == nullptr ) return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);

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


}
