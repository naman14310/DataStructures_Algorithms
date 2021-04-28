#include<bits/stdc++.h>
using namespace std;

/****************************** STRUCTURE OF AVL TREENODE *************************************/

struct TreeNode 
{ 
    int data; 
    int height;
    struct TreeNode *left, *right; 
}; 

/****************************** CREATE NEW NODE **********************************************/

TreeNode* createTreeNode(int key) 
{ 
    TreeNode* newNode =  new TreeNode; 
    newNode->data = key; 
    newNode->left = newNode->right = NULL; 
    newNode->height = 0;
    return newNode; 
}

/****************************** FUNCTION TO CALCULATE HEIGHT OF NODE **************************/

int height(TreeNode *node){
    if(!node) return -1;

    return node->height;
}

/****************************** ROTATE RIGHT FUNCTION  ****************************************/

TreeNode* rotateRight(TreeNode* root){
    //cout<<endl<<"=======INSIDE ROTATE RIGHT======="<<endl;
    TreeNode *pivot = root->left;
    root->left = pivot->right;
    pivot->right = root;
    root->height = max( height(root->left), height(root->right) ) + 1;
    pivot->height = max( height(pivot->left), height(pivot->right) ) + 1;
    return pivot;
}

/****************************** ROTATE LEFT FUNCTION ******************************************/

TreeNode* rotateLeft(TreeNode* root){
    //cout<<endl<<"=======INSIDE ROTATE LEFT======="<<endl;
    TreeNode *pivot = root->right;
    root->right = pivot->left;
    pivot->left = root;
    root->height = max( height(root->left), height(root->right) ) + 1;
    pivot->height = max( height(pivot->left), height(pivot->right) ) + 1;
    return pivot;
}

/****************************** INSERTION OF NODE IN AVL **************************************/

TreeNode* insert( TreeNode* node, int key) 
{ 
    if (node == NULL) return createTreeNode(key); 
  
    if (key <= node->data) 
        node->left  = insert(node->left, key); 
    else if (key > node->data) 
        node->right = insert(node->right, key);    

    int heightDifference = height(node->left) - height(node->right);

    if (heightDifference < -1){
        if(height(node->right->right) >= height(node->right->left)){
            return rotateLeft(node);
        }
        else{
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }

    else if(heightDifference > 1){
        if(height(node->left->left) >= height(node->left->right)){
            return rotateRight(node);
        }
        else{
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }

    node->height = max(height(node->left), height(node->right)) + 1;
    return node; 
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

/****************************** RETURN MIN VALUE OF AVL **************************************/

TreeNode* minValue( TreeNode* root){
    if(!root) return root; 
    if(!root->left) return root;
    return minValue(root->left);
}

/****************************** DELETE NODE FROM AVL *****************************************/

TreeNode* deleteNode(TreeNode* node, int key){
    if(!node) return NULL;

    if(key < node->data){
        node->left = deleteNode(node->left, key);
    }

    else if(key > node->data){
        node->right = deleteNode(node->right, key);
    }

    else{

        if(!node->left && !node->right) return NULL;

        if(!node->left){
            TreeNode* temp = node->right;
            delete(node);
            return temp;
        }

        if(!node->right){
            TreeNode* temp = node->left;
            delete(node);
            return temp;
        }

        else{
            TreeNode* temp = minValue(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, node->data);
        }
    }

    int heightDifference = height(node->left) - height(node->right);

    if (heightDifference < -1){
        if(height(node->right->right) >= height(node->right->left)){
            return rotateLeft(node);
        }
        else{
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }

    else if(heightDifference > 1){
        if(height(node->left->left) >= height(node->left->right)){
            return rotateRight(node);
        }
        else{
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }

    node->height = max(height(node->left), height(node->right)) + 1;
    
    return node;
}

/****************************** COUNT OCCURRANCES OF ELEMENT ********************************/

void countOccurrance(TreeNode* root, int key, int & count){
    if(!root) return;
   // cout<<endl<<"count out : "<<count<<endl;
    if(root->data == key){
        count++;
    //    cout<<endl<<"count in : "<<count<<endl;
    }

    if(root->data >= key) countOccurrance(root->left, key, count);

    countOccurrance(root->right, key, count);
}

/****************************** SEARCH GIVEN DATA IN AVL *************************************/

TreeNode* search(TreeNode* root, int key){
    if(!root) return NULL;

    if(root->data == key) return root;

    if(root->data > key) return search(root->left, key);

    return search(root->right, key);
}

/****************************** MAIN FUNCTION ***********************************************/

int main() 
{ 
 
    struct TreeNode *root = NULL; 
    root = insert(root, 50); 
   // cout<<endl<<"root : "<<root->data<<endl;
    root = insert(root, 30); 
    root = insert(root, 30); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80); 

    cout<<"\nLevelOrder after Insertion : "; levelorder(root);
    cout<<endl;

    root = deleteNode(root, 80);
    root = deleteNode(root, 60);
    root = deleteNode(root, 70);

    cout<<"\nLevelOrder after Deletion : "; levelorder(root);

    TreeNode *searchedNode = search(root, 70);
    if(searchedNode) cout<<endl<<endl<<"Node Found !";
    else cout<<endl<<endl<<"Node NOT Found !";

    int count = 0;
    countOccurrance(root, 30, count);
    cout<<endl<<endl<<"Count Occurances : "<<count;
   
    cout<<endl<<endl;
    return 0; 
} 