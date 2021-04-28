#include<bits/stdc++.h>
#define SIZE 100000
#define prime 19
using namespace std;

template <class T1, class T2>

class unorderedMap{

    struct node{
        T1 key; T2 val;
        node *next;
    };

    node *arr[SIZE]; int factor;

    public:

    long long int hashKey(T1 KEY){
        ostringstream ss; ss << KEY; string key = ss.str();
        factor = 1; long long int sum = 0;
        for(int i=0; i<key.length(); i++){
            sum += (key[i] * factor);
            sum = sum % SIZE;
            factor *= prime;
        }
        //cout<<"sum : "<<sum<<endl;
        return sum;
    }

    int hash(T1 key){
        long long int hashkey = hashKey(key);
        //cout<<"hashkey : "<<hashkey<<endl;
        return (hashkey % SIZE);
    }

    node* createNode(T1 key, T2 val){
        node* newNode = new node;
        newNode->key = key; newNode->val = val; newNode->next = NULL; 
        return newNode;
    }

    void insert(T1 key, T2 val){
        int index = hash(key);
        //cout<<"index : "<<index<<endl;
        node* head = arr[index];

        if(!head){
            node *newNode = createNode(key, val);
            arr[index] = newNode;
            return;
        }

        else if(!head->next){
            if(head->key == key)return;
            else{
                node *newNode = createNode(key, val);
                head->next = newNode;return;
            }
        }

        else{
            node* itr = head;
            while(itr->next){            
                if(itr->key == key)return;
                else itr = itr->next;
            }
            node *newNode = createNode(key, val);
            itr->next = newNode;return;
        }
    }

    void erase(T1 key){
        int index = hash(key);

        node* head = arr[index];

        if(!head) return;
    
        else if(!head->next){
            if(head->key == key){
                delete(head);
                arr[index] = NULL;return;
            } else return;
        }

        else{
            node* prev = head;
            node* itr = prev->next;
            if(prev->key == key){
                arr[index] = itr;
                delete(prev);return;
            }
            while(itr){
                if(itr->key == key){
                    prev->next = itr->next;
                    delete(itr);return;
                }
            }
        }
    }

    pair<bool,T2> find_helper(T1 key){
        int index = hash(key);

        node* itr = arr[index];
        while(itr){
            if(itr->key == key){
                return {true,itr->val};
            }
        }
        T2 t2 = {};
        return {false,t2};
    }

    bool find(T1 key){
        pair<bool, T2> p = find_helper(key);
        return p.first;
    }

    T2 operator[](T1 key){

        pair<bool, T2> found = find_helper(key);
        if(!found.first){
            cout<<"value doesn't exist"<<endl;
            T2 t2 = {};
            insert(key, t2);
            return t2;
        }
        else return found.second;
                  
    } 

};

int main(){

    unorderedMap<float, float> ump1; 
    unorderedMap<string, string> ump2;
    unorderedMap<char, int> ump3;
    unorderedMap<float, string> ump4;
    unorderedMap<int, int> ump5;

    ump1.insert(34.123, 3424.12);
    ump1.insert(31.3, 1);
    ump1.insert(13.3, 422);
    cout<<endl<<"ump1[34.213] : "<<ump1[34.123]<<endl<<endl;
    ump1.erase(34.123);
     ump1.insert(1.23, 3545);
    cout<<endl<<ump1[34.123]<<endl<<endl;

    ump2.insert("naman", "jain");
    ump2.insert("31.3", "1");
    ump2.insert("13.3", "422");
    cout<<endl<<ump2["naman"]<<endl<<endl;
    ump2.insert("jain", "iam");
    cout<<endl<<ump2.find("31.3")<<endl<<endl;
    ump2.erase("31.3");
    cout<<endl<<ump2.find("jain")<<endl<<endl;
    cout<<endl<<ump2.find("13.3")<<endl<<endl;
    cout<<"ump[13.3] : "<<ump2["13.3"]<<endl<<endl;

    ump3.insert('a', 1);
    ump3.insert('q', 5543);
    ump3.insert('e', 0);
    ump3.insert('y', 6437);
    cout<<"ump[a] : "<<ump3['a']<<endl<<endl;
    cout<<"ump[q] : "<<ump3['q']<<endl<<endl;
    cout<<"ump[e] : "<<ump3['e']<<endl<<endl;
    cout<<"ump[y] : "<<ump3['y']<<endl<<endl;
    ump3.erase('q'); 
    ump3.erase('e');
    cout<<endl<<ump3.find('a')<<endl;
    cout<<endl<<ump3.find('e')<<endl;

    ump4.insert(4.21, "1");
    ump4.insert(0, "5543");
    ump4.insert(0.2, "0");
    ump4.insert(0.5, "43");
    cout<<"ump[4.21] : "<<ump4[4.21]<<endl<<endl;
    cout<<"ump[0] : "<<ump4[0]<<endl<<endl;
    cout<<"ump[0.2] : "<<ump4[0.2]<<endl<<endl;
    cout<<"ump[0.5] : "<<ump4[0.5]<<endl<<endl;
    ump4.erase(0); 
    ump4.erase(0.5);
    cout<<"hello : "<<endl;
    cout<<endl<<ump4.find(0.5)<<endl;
    cout<<endl<<ump4.find(4.21)<<endl;




    
    return 0;
}