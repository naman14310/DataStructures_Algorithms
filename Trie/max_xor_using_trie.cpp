#include<bits/stdc++.h>
using namespace std;

template <class T>

class trie{
    
    struct TrieNode{
        T data;
        bool endFlag;
        int freq;
        TrieNode * arr[2];
    };

    TrieNode* root = NULL;

    public:

    TrieNode* newNode(T data, bool endFlag, int freq){
        TrieNode* node = new TrieNode;
        node->data = data;
        node->endFlag = endFlag;
        node->freq = freq;
        for(int i=0; i<2; i++){
            node->arr[i] = NULL;
        }
        return node;
    };

    trie(){
        root = newNode('/', false, 0);
    }

    TrieNode* insertChar(TrieNode* start, char ch, bool eF){
        int pos = ch - '0';
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
            int pos = ch - '0';
            if(root->arr[pos]){ root = root->arr[pos];}
            else{return false;}
        }
        return root->endFlag;
    }

    bool search(string word){
        return search_helper(root, word);
    }

    long long int max_xor_helper(TrieNode* root, string num){
        int exp = 39;
        long long int ans = 0;
        for(int i=0; i<num.length(); i++){
            char ch = num[i];
            int pos = ch - '0' ? 0 : 1;
            if(root->arr[pos]){ 
                root = root->arr[pos];
                ans += pow(2,exp);
            }
            else root = root->arr[1-pos];
            exp--;
        }
        return ans;
    }

    long long int max_xor(string num){
        return max_xor_helper(root, num);
    }

};

string addPadding(string bin){
    int len = bin.length();
    string zeros = "";
    for(int i=0; i<40-bin.length(); i++)
        zeros.push_back('0');
    return zeros.append(bin);
}

string decimalToBinary(long long int dec){
    string binary = "";
    while(dec>0){
        char bit = dec&1 ? '1' : '0';
        binary.push_back(bit);
        dec>>=1;
    }
    reverse(binary.begin(), binary.end());
    return addPadding(binary);
}

int main(){
    trie<char> t;
    int n,q; cin>>n>>q;

    for(int i=0; i<n; i++){
        long long int decimal; cin>>decimal;
        string binary = decimalToBinary(decimal);
        t.insert(binary);
    } 
    
    while(q--){
        long long int num; cin>>num;
        string s = decimalToBinary(num);
        cout<<t.max_xor(s)<<endl;
    }

    return 0;
}