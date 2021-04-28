#include<bits/stdc++.h>
using namespace std;

template <class T>

class trie{
    
    struct TrieNode{
        T data;
        bool endFlag;
        int freq;
        TrieNode * arr[26];
    };

    TrieNode* root = NULL;

    public:

    TrieNode* newNode(T data, bool endFlag, int freq){
        TrieNode* node = new TrieNode;
        node->data = data;
        node->endFlag = endFlag;
        node->freq = freq;
        for(int i=0; i<26; i++){
            node->arr[i] = NULL;
        }
        return node;
    };

    trie(){
        root = newNode('/', false, 0);
    }

    TrieNode* insertChar(TrieNode* start, char ch, bool eF){
        int pos = ch<97 ? ch-65 : ch-97;
        
        if(start->arr[pos]==NULL){
            start->arr[pos] = newNode(ch, eF, 1);
            start = start->arr[pos];
        }
        else{
            start = start->arr[pos];
            start->endFlag = eF;
            start->freq++;
        }
        return start;
    }

    void insert(string word){
        TrieNode* start = root;
        for(int i=0; i<word.length(); i++){
            char ch = word[i];
            bool eF = i==word.length()-1 ? true : false;
            start = insertChar(start, ch, eF);
        }
    }

    bool search_helper(TrieNode* root, string word){
        
        if(word.length()<1) return false;

        for(int i=0; i<word.length(); i++){
            char ch = word[i];
            //cout<<ch<<endl;
            int pos = ch<97 ? ch-65 : ch-97;
            //cout<<pos<<endl;
            if(root->arr[pos]){ root = root->arr[pos]; /*cout<<"in if"<<endl;*/}
            else{/*cout<<"in else"<<endl;*/ return false;}

        }

        return root->endFlag;
    }

    bool search(string word){
        return search_helper(root, word);
    }

    void displayAllStrings(){

    }


};

int main(){
    trie<char> t;
    t.insert("bat");
    t.search("bat")==true ? cout<<"\nWORD PRESENT\n" : cout<<"\nWORD NOT PRESENT!\n";
    t.insert("batman");
    t.search("batm")==true ? cout<<"\nWORD PRESENT\n" : cout<<"\nWORD NOT PRESENT!\n";

}