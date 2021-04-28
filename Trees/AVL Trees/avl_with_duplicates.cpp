#include<bits/stdc++.h>
using namespace std;

template <class T>

class avl{

        /****************************** STRUCTURE OF AVL TREENODE *************************************/

    struct TreeNode 
    { 
        T data; 
        int height;
        int count;
        int lc; int rc;
        struct TreeNode *left, *right; 
    };

    struct TreeNode *root = NULL;
    T nextgreater = {}; T nextsmaller = {}; 

    public: 

        /****************************** CREATE NEW NODE **********************************************/

        TreeNode* createTreeNode(T key) 
        { 
            TreeNode* newNode =  new TreeNode; 
            newNode->data = key; 
            newNode->left = newNode->right = NULL; 
            newNode->height = 0; newNode->lc = 0; newNode->rc = 0;
            newNode->count = 1;
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

        TreeNode* insert(TreeNode* node, T key) 
        { 
            if (node == NULL) return createTreeNode(key); 
            
            if(key == node->data){
                node->count = node->count + 1;
                return node;
            }

            if (key < node->data) 
                {node->lc++; node->left  = insert(node->left, key);}
            else if (key > node->data) 
                {node->rc++; node->right = insert(node->right, key);}    

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

        void insertKey(T key){
            root = insert(root, key);
        }

        /****************************** LEVEL ORDER TRAVERSAL ****************************************/

        void levelorder_helper(TreeNode* root){
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

        void levelOrder(){
            levelorder_helper(root);
        }

        /****************************** RETURN MIN VALUE OF AVL **************************************/

        TreeNode* minValue( TreeNode* root){
            if(!root) return root; 
            if(!root->left) return root;
            return minValue(root->left);
        }

        /****************************** DELETE NODE FROM AVL *****************************************/

        TreeNode* deleteNode(TreeNode* node, T key){
            if(!node) return NULL;

            if(key < node->data){
                node->left = deleteNode(node->left, key);
            }

            else if(key > node->data){
                node->right = deleteNode(node->right, key);
            }

            else{

                if(node->count > 1){
                    node->count = node->count - 1 ;
                    return node;
                }

                if(!node->left && !node->right){
                    return NULL;
                } 

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

        void deleteKey(T key){
            root = deleteNode(root, key);
        }

        /****************************** COUNT OCCURRANCES OF ELEMENT ********************************/

        int countOccurrance_helper(TreeNode* root, T key){
            if(!root) return 0;
        // cout<<endl<<"count out : "<<count<<endl;
            if(root->data == key){
                return root->count;
            //    cout<<endl<<"count in : "<<count<<endl;
            }

            if(root->data >= key) return countOccurrance_helper(root->left, key);

            return countOccurrance_helper(root->right, key);
        }

        int countOccurrance(T key){
            return countOccurrance_helper(root, key);
        }

        /****************************** SEARCH GIVEN DATA IN AVL *************************************/

        TreeNode* search(TreeNode* root, T key){
            if(!root) return NULL;

            if(root->data == key) return root;

            if(root->data > key) return search(root->left, key);

            return search(root->right, key);
        }

        bool searchKey(T key){
            TreeNode* node = search(root, key);
            if(!node) return false;
            return true;
        }

        /****************************** NEXT GREATER IN AVL *****************************************/
    
        void nextGreater(TreeNode* root, T key){
            if(!root) return;

            if(key < root->data){
                nextgreater = root->data;
                nextGreater(root->left, key);
            }
            else nextGreater(root->right, key);
        }

        /****************************** NEXT SMALLER IN AVL *****************************************/
    
        void nextSmaller(TreeNode* root, T key){
            if(!root) return;

            if(key > root->data){
                nextsmaller = root->data;
                //cout<<"nextS : "<<nextsmaller<<endl;
                nextSmaller(root->right, key);
            }
            else nextSmaller(root->left, key);
        }

        /****************************** LOWER BOUND OF GIVEN DATA IN AVL *****************************/

        T lowerBound(TreeNode* root, T key){
            TreeNode *node = search(root, key);
            if(node) return key;

            nextGreater(root, key);
            return nextgreater;
        }

        T lowerbound(T key){
            return lowerBound(root, key);
        }

        /****************************** UPPER BOUND OF GIVEN DATA IN AVL *****************************/

        T upperBound(TreeNode* root, T key){
            nextGreater(root, key);
            return nextgreater;
        }

        T upperbound(T key){
            return upperBound(root, key);
        }

        /**************************** CLOSEST ELEMENT OF GIVEN DATA IN AVL ***************************/

        T closest(T key){
            string typeTest;
            T n1 = lowerbound(key);
            nextSmaller(root, key);
            T n2 = nextsmaller;

            //cout << " n1 : "<<n1;
            //cout<<" n2 : "<<n2;
            if(typeid(key) != typeid(typeTest)){
                return key-n2 > n1-key ? n1 : n2;  
            }
            else{
                return n2;
            }

        }

};

/****************************** MAIN FUNCTION ***********************************************/

int main() 
{ 
    avl<int> t;

    t.insertKey(1.3);
    t.insertKey(2.4);
    t.insertKey(3.5);
    t.insertKey(4.6);
    t.insertKey(5.7);
    t.insertKey(6.8);
    t.insertKey(7.9);

    cout<<"\nLevelOrder after Insertion : "; t.levelOrder();
    cout<<endl;

    t.deleteKey(5.7);
    t.deleteKey(6.8);
    t.deleteKey(2.4);
    t.insertKey(1.3); 

    cout<<"\nLevelOrder after Insertion : "; t.levelOrder();
    cout<<endl;

    bool found = t.searchKey(1.3);
    if(found) cout<<endl<<endl<<"Node Found !";
    else cout<<endl<<endl<<"Node NOT Found !";

    int count = t.countOccurrance(1.3);
    cout<<endl<<endl<<"Count Occurances : "<<count;

    cout<<endl<<endl<<"Lower Bound : "<<t.lowerbound(5.7);
    cout<<endl<<endl<<"Upper Bound : "<<t.upperbound(5.7);

    cout<<endl<<endl<<"Closest Element : "<<t.closest(5.7);
   
    cout<<endl<<endl;
    return 0; 
} 