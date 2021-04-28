#include<bits/stdc++.h>
using namespace std;

template <class T>

class avl{

        /****************************** STRUCTURE OF AVL TREENODE *************************************/

    struct TreeNode 
    { 
        T data; 
        int height;
        int count, lc, rc;
        struct TreeNode *left, *right; 
    };

    struct TreeNode *root = NULL;
    T nextgreater = {}; T nextsmaller = {};  
    int noOfElementsOutsideRange = 0;

    public:

        /****************************** RETURN MIN VALUE OF AVL **************************************/

        TreeNode* minValue( TreeNode* root){
            if(!root) return root; 
            if(!root->left) return root;
            return minValue(root->left);
        }

        /****************************** RETURN MAX VALUE OF AVL **************************************/

        TreeNode* maxValue( TreeNode* root){
            if(!root) return root; 
            if(!root->right) return root;
            return maxValue(root->right);
        }

        /************************************* INIT **************************************************/

        void init(){
            noOfElementsOutsideRange = 0;
            nextgreater = {};
            nextsmaller = {};
        } 

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
            root->left = pivot->right; root->lc = pivot->rc;
            pivot->right = root; pivot->rc = root->lc + root->rc + root->count;
            root->height = max( height(root->left), height(root->right) ) + 1;
            pivot->height = max( height(pivot->left), height(pivot->right) ) + 1;
            return pivot;
        }

        /****************************** ROTATE LEFT FUNCTION ******************************************/

        TreeNode* rotateLeft(TreeNode* root){
            //cout<<endl<<"=======INSIDE ROTATE LEFT======="<<endl;
            TreeNode *pivot = root->right; 
            root->right = pivot->left; root->rc = pivot->lc;
            pivot->left = root; pivot->lc = root->lc + root->rc + root->count;
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

                cout<<node->data<<"|"<<node->count<<"|"<<node->lc<<"|"<<node->rc<<"  ";

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        void levelOrder(){
            levelorder_helper(root);
        }

        /****************************** PRE ORDER TRAVERSAL ****************************************/

        void preorder_helper(TreeNode* root){
            if(root){
            cout<<root->data<<"|"<<root->count<<"|"<<root->lc<<"|"<<root->rc<<"  ";
            preorder_helper(root->left);
            preorder_helper(root->right);
            }
        }

        void preorder(){
            preorder_helper(root);
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

        /****************************** DELETE NODE FROM AVL *****************************************/

        TreeNode* recurrDelete(TreeNode* node, T key){
            if(!node) return NULL;

            if(key < node->data){
                node->lc--;
                node->left = recurrDelete(node->left, key);
            }

            else if(key > node->data){
                node->rc--;
                node->right = recurrDelete(node->right, key);
            }

            else{

                /*if(node->count > 1){
                    node->count = node->count - 1 ;
                    return node;
                }*/

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
                    node->count = temp->count;
                    node->right = recurrDelete(node->right, node->data);
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

        TreeNode* deleteNode(TreeNode* node, T key){
            if(!node) return NULL;

            if(key < node->data){
                node->lc--;
                node->left = deleteNode(node->left, key);
            }

            else if(key > node->data){
                node->rc--;
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
                    node->count = temp->count;
                    node->rc -= temp->count ;  
                    node->right = recurrDelete(node->right, node->data);
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
            TreeNode* nodeToBeDelete = search(root, key);
            if(!nodeToBeDelete){
                cout<<endl<<endl<<"Key "<<key<<" doesn't exist"<<endl<<endl;
                return;
            }
            else root = deleteNode(root, key);
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

            if(key >= root->data){
                nextsmaller = root->data;
                nextSmaller(root->right, key);
            }
            else nextSmaller(root->left, key);
        }

        /****************************** LOWER BOUND OF GIVEN DATA IN AVL *****************************/

        T lowerBound(TreeNode* root, T key){
            TreeNode *node = search(root, key);
            if(node){return key;}

            nextGreater(root, key);
            return nextgreater;
        }

        T lowerbound(T key){
            init();
            return lowerBound(root, key);
        }

        /****************************** UPPER BOUND OF GIVEN DATA IN AVL *****************************/

        T upperBound(TreeNode* root, T key){
            nextGreater(root, key);
            return nextgreater;
        }

        T upperbound(T key){
            init();
            return upperBound(root, key);
        }

        /**************************** CLOSEST ELEMENT OF GIVEN DATA IN AVL ***************************/

        T closest(T key){
            init();
            if(key<=minValue(root)->data) return minValue(root)->data;
            else if (key >= maxValue(root)->data){return maxValue(root)->data;}

            T n1 = lowerbound(key);
            nextSmaller(root, key);
            T n2 = nextsmaller;

            if(key-n2 > n1-key) return n1;
            else return n2;
        }

        /************************* Kth LARGEST ELEMENT IN LOG-N TIME IN AVL *************************/

        T klargest_helper(TreeNode* root, int k){
            if(root->rc >= k){
                return klargest_helper(root->right, k);
            }
            else if(root->rc + root->count >= k){
                return root->data;
            }
            return klargest_helper(root->left, k - root->rc - root->count);            
        }

        T klargest(int k){
            return klargest_helper(root, k);
        }

        /***************************** NO OF NODES IN A GIVEN RANGE *******************************/

        void rejectMin(TreeNode* root, T a){
            if(!root) return;
            if(root->data < a){
                noOfElementsOutsideRange += root->lc + root->count; 
                 //cout<<"ll : "<<noOfElementsOutsideRange<<endl;
                return rejectMin(root->right, a);
            }
            else if(root->data ==a){
                noOfElementsOutsideRange += root->lc;
                 //cout<<"ll : "<<noOfElementsOutsideRange<<endl;
                return rejectMin(root->right, a);
            }
            return rejectMin(root->left, a);
        }

        void rejectMax(TreeNode* root, T b){
            if(!root) return;
            if(root->data > b){
                noOfElementsOutsideRange += root->rc + root->count;
                  //cout<<"ll+rr : "<<noOfElementsOutsideRange<<endl;
                return rejectMax(root->left, b);
            }
            else if(root->data == b){
                noOfElementsOutsideRange += root->rc;
                  //cout<<"ll+rr : "<<noOfElementsOutsideRange<<endl;
                return rejectMax(root->left, b);
            }
            return rejectMax(root->right, b);
        }

        int range(T a, T b){
            if(a<minValue(root)->data && b<minValue(root)->data) return 0;

            else if(a>maxValue(root)->data && b>maxValue(root)->data) return 0;

            T left = lowerbound(a);
            nextSmaller(root, b);
            T right = nextsmaller;
            init(); rejectMin(root, a);rejectMax(root, b);
            int total = root->count + root->lc + root->rc;
            return total-noOfElementsOutsideRange;
        }

};

/****************************** MAIN FUNCTION ***********************************************/

int main() 
{   cout<<endl<<"**********************************************   WELCOME TO AVL WORLD   ********************************************"<<endl;


    /* 1.insertKey(T key)
       2.deleteKey(T key)
       3.searchKey(T key)
       3.countOccurrance(T key)
       4.lowerbound(T key)
       5.upperbound(T key)
       6.closest(T key) 
       7.klargest(int k)
       8.range(T a, T b)*/

    avl<int> tree1; 
    avl<float> tree2; 
    avl<string> tree3; 
    avl<char> tree4;

    cout<<endl<<endl<<"----------------------------------------- TEST CASE : 1 ---------------------------------------"<<endl<<endl;

    tree1.insertKey(5);
    tree1.insertKey(10);
    tree1.insertKey(32);
    tree1.insertKey(25);
    tree1.insertKey(32);
    tree1.insertKey(41);
    tree1.insertKey(50);
    tree1.insertKey(55);

    cout<<endl<<endl<<"******************************************************************"<<endl<<endl;
    cout<<endl<<"preorder : ";tree1.preorder();
    cout<<endl<<"levelorder : ";tree1.levelOrder();


    cout<<endl<<endl<<"search 32 : "<<tree1.searchKey(32)<<endl;
    cout<<"search 40 : "<<tree1.searchKey(40)<<endl;
    cout<<"search 55 : "<<tree1.searchKey(55)<<endl;
    cout<<"search 50 : "<<tree1.searchKey(50)<<endl;
    cout<<"search 64 : "<<tree1.searchKey(64)<<endl;

    cout<<endl<<endl<<"******************************************************************"<<endl<<endl;
    
    cout<<endl<<endl<<"lowerbound 32 : "<<tree1.lowerbound(32)<<endl;
    cout<<"lowerbound 40 : "<<tree1.lowerbound(40)<<endl;
    cout<<"lowerbound 56 : "<<tree1.lowerbound(56)<<endl;
    cout<<"lowerbound 50 : "<<tree1.lowerbound(50)<<endl;
    cout<<"lowerbound 64 : "<<tree1.lowerbound(64)<<endl;

    cout<<endl<<endl<<"******************************************************************"<<endl<<endl;

    cout<<endl<<endl<<"closest 32 : "<<tree1.closest(32)<<endl;
    cout<<"closest 40 : "<<tree1.closest(40)<<endl;
    cout<<"closest 56 : "<<tree1.closest(56)<<endl;
    cout<<"closest 50 : "<<tree1.closest(50)<<endl;
    cout<<"closest 0 : "<<tree1.closest(0)<<endl;

    cout<<endl<<endl<<"******************************************************************"<<endl<<endl;
    
    cout<<endl<<endl<<"upperbound 32 : "<<tree1.upperbound(32)<<endl;
    cout<<"upperbound 40 : "<<tree1.upperbound(40)<<endl;
    cout<<"upperbound 56 : "<<tree1.upperbound(56)<<endl;
    cout<<"upperbound 50 : "<<tree1.upperbound(50)<<endl;
    cout<<"upperbound 0 : "<<tree1.upperbound(0)<<endl;

    cout<<endl<<endl<<"******************************************************************"<<endl<<endl;
    
    cout<<endl<<endl<<"countOccurance 32 : "<<tree1.countOccurrance(32)<<endl;
    cout<<"countOccurance 40 : "<<tree1.countOccurrance(40)<<endl;
    cout<<"countOccurance 56 : "<<tree1.countOccurrance(56)<<endl;
    cout<<"countOccurance 50 : "<<tree1.countOccurrance(50)<<endl;
    cout<<"countOccurance 0 : "<<tree1.countOccurrance(0)<<endl;

    
    cout<<endl<<endl<<"******************************************************************"<<endl<<endl;
    
    cout<<endl<<endl<<"klargest 4 : "<<tree1.klargest(4)<<endl;
    cout<<"klargest 1 : "<<tree1.klargest(1)<<endl;

    cout<<endl<<endl<<"******************************************************************"<<endl<<endl;
    
    cout<<endl<<endl<<"range 5 50 : "<<tree1.range(5, 50)<<endl;
    cout<<"range 1 2 : "<<tree1.range(1, 2)<<endl;

    cout<<endl<<endl<<"--------------------------------------- TEST CASE : 2 --------------------------------------"<<endl<<endl;

    tree2.insertKey(5.34);
    tree2.insertKey(10.2);
    tree2.insertKey(32.2341);
    tree2.insertKey(25.55);
    tree2.insertKey(32.2341);

    cout<<endl<<endl<<"******************************************************************"<<endl<<endl;
    cout<<endl<<"preorder : ";tree2.preorder();
    cout<<endl<<"levelorder : ";tree2.levelOrder();


    cout<<endl<<endl<<"search 32.2341 : "<<tree2.searchKey(32.2341)<<endl;
    cout<<"search 10.2 : "<<tree2.searchKey(10.2)<<endl;

    cout<<endl<<endl<<"******************************************************************"<<endl<<endl;
    
    cout<<endl<<endl<<"lowerbound 32 : "<<tree2.lowerbound(32)<<endl;
    cout<<"lowerbound 10 : "<<tree2.lowerbound(10)<<endl;
    cout<<"lowerbound 16 : "<<tree2.lowerbound(16)<<endl;

    cout<<endl<<endl<<"******************************************************************"<<endl<<endl;

    cout<<endl<<endl<<"closest 32 : "<<tree2.closest(32)<<endl;
    cout<<"closest 20 : "<<tree2.closest(20)<<endl;

    cout<<endl<<endl<<"******************************************************************"<<endl<<endl;
    
    cout<<endl<<endl<<"upperbound 12 : "<<tree2.upperbound(12)<<endl;
    cout<<"upperbound 4: "<<tree2.upperbound(4)<<endl;

    cout<<endl<<endl<<"******************************************************************"<<endl<<endl;
    
    cout<<endl<<endl<<"countOccurance 32.2341 : "<<tree2.countOccurrance(32.2341)<<endl;
    cout<<"countOccurance 40 : "<<tree2.countOccurrance(40)<<endl;
    
    cout<<endl<<endl<<"******************************************************************"<<endl<<endl;
    
    cout<<endl<<endl<<"klargest 4 : "<<tree2.klargest(4)<<endl;
    cout<<"klargest 1 : "<<tree2.klargest(1)<<endl;

    cout<<endl<<endl<<"******************************************************************"<<endl<<endl;
    
    cout<<endl<<endl<<"range 5 50 : "<<tree2.range(5, 50)<<endl;
    cout<<"range 1 2 : "<<tree2.range(1, 2)<<endl;

    cout<<endl<<endl<<"--------------------------------------- TEST CASE : 3 --------------------------------------"<<endl<<endl;

    
    tree3.insertKey("na");
    tree3.insertKey("msd");
    tree3.insertKey("dc");
    tree3.insertKey("sd");
    tree3.insertKey("hello");

    cout<<endl<<endl<<"******************************************************************"<<endl<<endl;
    cout<<endl<<"preorder : ";tree3.preorder();
    cout<<endl<<"levelorder : ";tree3.levelOrder();


    cout<<endl<<endl<<"search hello : "<<tree3.searchKey("hello")<<endl;
    cout<<"search dc : "<<tree3.searchKey("dc")<<endl;

    cout<<endl<<endl<<"******************************************************************"<<endl<<endl;
    
    cout<<endl<<endl<<"lowerbound dc : "<<tree3.lowerbound("dc")<<endl;
    cout<<"lowerbound cd : "<<tree3.lowerbound("cd")<<endl;
    cout<<"lowerbound hi : "<<tree3.lowerbound("hi")<<endl;

    cout<<endl<<endl<<"******************************************************************"<<endl<<endl;
    
    cout<<endl<<endl<<"upperbound rt : "<<tree3.upperbound("rt")<<endl;
    cout<<"upperbound gg: "<<tree3.upperbound("gg")<<endl;
    
    cout<<endl<<endl<<"******************************************************************"<<endl<<endl;
    
    cout<<endl<<endl<<"klargest 4 : "<<tree3.klargest(4)<<endl;
    cout<<"klargest 1 : "<<tree3.klargest(1)<<endl;

    cout<<endl<<endl<<"******************************************************************"<<endl<<endl;
    
    cout<<endl<<endl<<"range a z : "<<tree3.range("a", "z")<<endl;
    cout<<"range bye hi : "<<tree3.range("bye", "hi")<<endl;

    cout<<endl<<endl<<"--------------------------------------- TEST CASE : 4 --------------------------------------"<<endl<<endl;

    tree4.insertKey('d');
    tree4.insertKey('a');
    tree4.insertKey('s');
    tree4.insertKey('a');
    tree4.insertKey('@');

    cout<<endl<<endl<<"******************************************************************"<<endl<<endl;
    cout<<endl<<"preorder : ";tree3.preorder();
    cout<<endl<<"levelorder : ";tree3.levelOrder();


    cout<<endl<<endl;
    return 0; 
} 