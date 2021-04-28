/*
Program : B+ Trees for MultiIndexing Queries
Author : Naman Jain
Language Used : C++
*/


#include<bits/stdc++.h>
#include <fstream>
#define ORDER 3
using namespace std;

/*****************************************************************************************************************/

struct TreeNode{
    int count;
    vector<pair<int,int>> keys;
    vector<TreeNode *> ptrs;
};

TreeNode* root = NULL;
stack<pair<TreeNode*, int>> parents;

/*****************************************************************************************************************/

TreeNode* createTreeNode(){
    TreeNode* node = new TreeNode();
    vector<pair<int,int>> tempKeys (ORDER, {INT_MIN,0});
    vector<TreeNode* > tempPtr (ORDER+1, NULL);
    node->keys = tempKeys;
    node->ptrs = tempPtr;
    node->count = 0; 
    return node;
}

/*****************************************************************************************************************/

void check(TreeNode* temp){
    if(!temp) cout<<"ROOT IS NULL"<<endl;
    else{
        check(temp->ptrs[0]);
        for(int i=0; i<temp->count; i++){
            cout<<temp->keys[i].first<<" -> "<< temp->keys[i].second<<endl;   
            check(temp->ptrs[i+1]); 
        }
    }
}

/*****************************************************************************************************************/

bool isLeaf(TreeNode* temp){
    for(int i=0; i<ORDER-1; i++){
        if(temp->ptrs[i])
            return false;
    }
    return true;
}

/*****************************************************************************************************************/

int getInsertPos(TreeNode* node, int key, int count){
    int i=0;
    for (; i<count; i++)
        if(key<node->keys[i].first) return i;
    return i;
}

/*****************************************************************************************************************/

void split1(int mid, TreeNode* node){
    TreeNode* parent = createTreeNode();
    parent->keys[0] = node->keys[mid];
    parent->ptrs[1] = createTreeNode();
    parent->ptrs[0] = node;
    parent->count = 1;
    for (int i=0; i<ORDER-mid; i++){
        parent->ptrs[1]->keys[i] = node->keys[mid+i];
        node->keys[mid+i] = {INT_MIN,0};
    }
    root = parent;
    parent->ptrs[0]->count = mid;
    parent->ptrs[1]->count = ORDER-mid;
    parent->ptrs[0]->ptrs[ORDER-1] = parent->ptrs[1];
}

/*****************************************************************************************************************/

int insertionAtInternalNode(pair<int,int> val, TreeNode* node){
    int pos = getInsertPos(node, val.first, node->count);
    node->keys.insert(node->keys.begin() + pos, val);
    (node->count)++;
    return pos;
}

/*****************************************************************************************************************/

void split2(int mid, TreeNode* node){
    auto parent = parents.top();
    parents.pop();
    TreeNode* prnt = parent.first;
    int idx = parent.second;
    int pos = insertionAtInternalNode(node->keys[mid], prnt);
    TreeNode* newNode = createTreeNode();

    if(isLeaf(node)){
        for (int i=0; i<ORDER-mid; i++){
            newNode->keys[i] = node->keys[mid+i];
        }
        newNode->count = ORDER-mid;
        newNode->ptrs[ORDER-1] = node->ptrs[ORDER-1];
        node->ptrs[ORDER-1] = newNode;
    }
    else{
        int i=0;
        for (; i<ORDER-mid-1; i++){
            newNode->keys[i] = node->keys[mid+i+1];
            newNode->ptrs[i] = node->ptrs[mid+i+1];
        }
        newNode->ptrs[i] = node->ptrs[mid+i+1];
        newNode->count = ORDER-mid-1;
    }
    
    if(prnt->count < ORDER){
        prnt->ptrs[idx+1] = newNode;
        node->count = mid;
    }
    else{
        node->count = mid;
        prnt->count = mid;
        prnt->ptrs[pos] = node;
        prnt->ptrs.insert(prnt->ptrs.begin() + pos+1, newNode);

        if(parents.empty()){
            TreeNode* newRoot = createTreeNode();
            TreeNode* rightNode = createTreeNode();
            newRoot->keys[0] = prnt->keys[mid];
            newRoot->count = 1;
            rightNode->count = ORDER-mid-1;
            newRoot->ptrs[0] = prnt;
            newRoot->ptrs[1] = rightNode;
            int i=0;
            for (; i<ORDER-mid-1; i++){
                rightNode->keys[i] = prnt->keys[mid+i+1];
                rightNode->ptrs[i] = prnt->ptrs[mid+i+1];
            }            
            rightNode->ptrs[i] = prnt->ptrs[mid+i+1];
            prnt->count = mid;
            root = newRoot;
        }
        else{
            split2(mid, prnt);
        }
    }
}

/*****************************************************************************************************************/

void insertNode_helper(int key, TreeNode* tempRoot){
    int pos = 0;

    while(tempRoot){
        pos = getInsertPos(tempRoot, key, tempRoot->count);
        if(isLeaf(tempRoot)) break;
        if(tempRoot->ptrs[pos]){
            parents.push({tempRoot,pos});
            tempRoot = tempRoot->ptrs[pos];
        }
        else break;
    }

    if (tempRoot->keys[pos-1].first==key){
        int num = tempRoot->keys[pos-1].first;
        int cnt = tempRoot->keys[pos-1].second;
        tempRoot->keys[pos-1] = {num, cnt+1};         
    }
    else{
        tempRoot->keys.insert(tempRoot->keys.begin() + pos, {key,1});
        (tempRoot->count)++;
    }

    if(tempRoot->count == ORDER){
        int mid = ORDER/2;
        if(parents.empty())
            split1(mid, tempRoot);
        else{
            split2(mid, tempRoot);
        }
    }
}

/*****************************************************************************************************************/

void insert(int key){
    if(root==NULL)
        root = createTreeNode();
    insertNode_helper(key, root);
    
    while(!parents.empty())
        parents.pop();
}

/*****************************************************************************************************************/

TreeNode* find_helper(int key){
    TreeNode* itr = root;
    int pos = 0;
    while(itr){
        if(isLeaf(itr)) break;
        pos = getInsertPos(itr, key, itr->count);
        if(itr->ptrs[pos]) itr = itr->ptrs[pos];
        else break;
    }
    return itr;       
}

/*****************************************************************************************************************/

bool find(int key){
    TreeNode* itr = find_helper(key);
    int pos = getInsertPos(itr, key, itr->count); 
    if (itr->keys[pos-1].first==key) return true;       
    return false;
}

/*****************************************************************************************************************/

void range(int x, int y){
    TreeNode* itr1 = find_helper(x);
    TreeNode* itr = itr1;
    bool end = false;
    cout<<endl;
    while(itr){
        for(int i=0; i<itr->count; i++)
            if(itr->keys[i].first>=x && itr->keys[i].first<=y)
                for(int c=0; c<itr->keys[i].second; c++)
                    cout<<itr->keys[i].first<<" ";
            else if (itr->keys[i].first>y){
                end = true;
                break;
            }
        itr = itr->ptrs[ORDER-1];
        if(end) break;
    }
    cout<<endl<<endl;
}

/*****************************************************************************************************************/

void traverse(){
    TreeNode* itr = root;
    while(itr->ptrs[0]) itr = itr->ptrs[0];
    cout<<"TRAVERSE"<<endl;
    cout<<"---------"<<endl<<endl;
    while(itr){
        for(int i=0; i<itr->count; i++)
            for(int c=0; c<itr->keys[i].second; c++)
                cout<<itr->keys[i].first<<" ";
        itr = itr->ptrs[ORDER-1];
    }
    cout<<endl<<endl;
}

/*****************************************************************************************************************/

int fetchCount(int key){
    auto itr = find_helper(key);
    int pos = getInsertPos(itr, key, itr->count);
    if(itr->keys[pos-1].first == key) return itr->keys[pos-1].second;
    else return 0;
}

/*****************************************************************************************************************/

void executeCommand(string cmd){
    cout<<"QUERY : "<<cmd;
    istringstream ss(cmd); 
    string word;
    vector<string> tokens; 
    while (ss >> word) tokens.push_back(word);
    
    if(tokens[0]=="INSERT"){
        insert(stoi(tokens[1]));
        cout<<endl<<tokens[1]<<" inserted successfully!\n\n";
    }

    else if(tokens[0]=="FIND"){
        bool res = find(stoi(tokens[1]));
        if(res)
            cout<<endl<<tokens[1]<<" is present.\n\n";
        else
            cout<<endl<<tokens[1]<<" is not present.\n\n";
    }

    else if(tokens[0]=="COUNT")
        cout<<"\nCount = "<<fetchCount(stoi(tokens[1]))<<endl<<endl;

    else if(tokens[0]=="RANGE")
        range(stoi(tokens[1]), stoi(tokens[2]));

    else cout<<"\nInvalid Query!\n";
}

/*****************************************************************************************************************/

int main(int argc, char *argv[]){
   if(argc != 2) printf("\nPlease provide correct no. of argments!\n");
    string filename = argv[1];
    cout<<endl;
    ifstream file(filename);
    string cmd;
    while(getline(file, cmd))
        executeCommand(cmd);
    
    traverse();
    return 0;
}
