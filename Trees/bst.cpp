#include<bits/stdc++.h>
using namespace std;

/********************************* Structure of TreeNode***************************************/

struct TreeNode 
{ 
    int data; 
    struct TreeNode *left, *right; 
}; 

/******************************** CREATE NEW NODE *********************************************/
   
TreeNode* createTreeNode(int key) 
{ 
    TreeNode* newNode =  new TreeNode; 
    newNode->data = key; 
    newNode->left = newNode->right = NULL; 
    return newNode; 
} 

/******************************* INORDER TREVERSAL ********************************************/
   
void inorder( TreeNode *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        cout<<root->data<<" "; 
        inorder(root->right); 
    } 
} 

/******************************* PREORDER TREVERSAL *******************************************/

void preorder( TreeNode *root) 
{ 
    if (root != NULL) 
    { 
        cout<<root->data<<" ";
        preorder(root->left); 
        preorder(root->right); 
    } 
} 

/******************************* POSTORDER TREVERSAL ******************************************/

void postorder( TreeNode *root) 
{ 
    if (root != NULL) 
    { 
        postorder(root->left); 
        postorder(root->right); 
        cout<<root->data<<" ";
    } 
} 

/****************************** LEVEL ORDER TRAVERSAL ****************************************/

void levelorder(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root); 

    while(!q.empty()){

        TreeNode* node = q.front();
        q.pop();

        cout<<node->data<<" ";

        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
}

/****************************** SEARCH GIVEN DATA IN BST *************************************/

TreeNode* find(TreeNode* root, int key){
    if(!root) return NULL;

    if(root->data == key) return root;

    if(root->data > key) return find(root->left, key);

    return find(root->right, key);
}

/****************************** RETURN MIN VALUE OF BST **************************************/

TreeNode* minValue( TreeNode* root){
    if(!root) return root; 
    if(!root->left) return root;
    return minValue(root->left);
}

/****************************** RETURN MAX VALUE OF BST **************************************/

TreeNode* maxValue( TreeNode* root){
    if(!root) return root;
    if(!root->right) return root;
    
    return maxValue(root->right);
}

/****************************** INORDER SUCCESSOR OF A GIVEN NODE ****************************/

int inorderSuccessor(TreeNode* root , int key){
    
    TreeNode* node = find(root, key);
    
    if(node->right)
    return minValue(node->right)->data;

    else{
        TreeNode* ancestor = root;
        TreeNode* successor = NULL;

        while(ancestor!=node){
            if(ancestor->data > node->data){
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else{
                ancestor = ancestor->right;
            }
        }

        return successor->data;
    }

}

/******************************* INORDER PREDECESSOR OF A GIVEN NODE *************************/

int inorderPredecessor(TreeNode* root, int key){
    
    TreeNode* node = find(root, key);

    if(node->left)
        return maxValue(node->left)->data;

    else{
        TreeNode* ancestor = root;
        TreeNode* predecesor = NULL;

        while(ancestor!=node){
            if(ancestor->data < node->data){
                predecesor = ancestor;
                ancestor = ancestor->right;
            }
            else{
                ancestor = ancestor ->left;
            }
        }

        return predecesor->data; 
    }

}

/******************************* INSERT GIVEN NODE IN BST ********************************/

TreeNode* insert( TreeNode* node, int key) 
{ 
    if (node == NULL) return createTreeNode(key); 
  
    if (key < node->data) 
        node->left  = insert(node->left, key); 
    else if (key > node->data) 
        node->right = insert(node->right, key);    
  
    return node; 
} 

/******************************* IS BST ****************************************************/

bool isBST(TreeNode* root, int low, int high){

    if(!root) return true;

    return low <= root->data && root->data <= high && isBST(root->left, low, root->data) && isBST(root->right, root->data, high) ;
}

/****************************** DELETE NODE ***********************************************/

TreeNode* deleteNode(TreeNode* root, int key){
    if(!root) return NULL;

    if(key < root->data){
        root->left = deleteNode(root->left, key);
    }

    else if(key > root->data){
        root->right = deleteNode(root->right, key);
    }

    else{

        if(!root->left && !root->right) return NULL;

        if(!root->left){
            TreeNode* temp = root->right;
            delete(root);
            return temp;
        }

        if(!root->right){
            TreeNode* temp = root->left;
            delete(root);
            return temp;
        }

        else{
            TreeNode* temp = minValue(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    
    return root;
}

/******************************* MAIN FUNCTION *********************************************/
   
int main() 
{ 
 
    struct TreeNode *root = NULL; 
    root = insert(root, 50); 
    cout<<endl<<"root : "<<root->data<<endl;
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
   
    cout<<endl<<"Inorder Traversal : "; inorder(root); cout<<endl;
    cout<<endl<<"Preorder Traversal : "; preorder(root); cout<<endl;
    cout<<endl<<"Postorder Traversal : "; postorder(root); cout<<endl;
    cout<<endl<<"Level order Traversal : "; levelorder(root); cout<<endl;

    cout<<endl<<"Inorder Successor : "<<inorderSuccessor(root, 40)<<endl;
    cout<<endl<<"Inorder Predecessor : "<<inorderPredecessor(root, 40)<<endl;

    cout<<endl<<"is BST : "<<isBST(root, INT_MIN, INT_MAX)<<endl;

    deleteNode(root, 40);
    cout<<endl<<"after delete : ";inorder(root); cout<<endl<<endl;
   
    return 0; 
} 