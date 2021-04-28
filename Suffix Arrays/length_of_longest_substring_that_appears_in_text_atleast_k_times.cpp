#include<bits/stdc++.h>
using namespace std;

struct sfx{
    int index;
    string suffix;
    int rank;
    int nextRank;
};

void printSFX(sfx arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i].index<<"      "<<arr[i].suffix<<"        "<<arr[i].rank<<"      "<<arr[i].nextRank<<endl;
    }
    cout<<endl<<"-------------------------------------------------------------------------------------------------------"<<endl;
}

bool comparator(sfx s1, sfx s2){
    if(s1.rank < s2.rank) return true;
    if(s1.rank == s2.rank && s1.nextRank < s2.nextRank) return true;
    return false;
}

int main(){
    string s; int k;
    cin>>s>>k;

    string str = s;
    int len = str.length();

    sfx arr[len];

    for(int i=0; i<len; i++){
        arr[i].suffix = str.substr(i,len);
        arr[i].rank = arr[i].suffix[0] - (int)'a';
        arr[i].index = i; 
        arr[i].nextRank = i==len-1 ? -1 : arr[i].suffix[1] - (int)'a';
    }

    //printSFX(arr,len);
    sort(arr, arr+len, comparator);
    //printSFX(arr,len);
    for (int jump=4; jump<len; jump*=2) {
        int r = 0;
        pair<int, int> prev = {arr[0].rank, arr[0].nextRank};
        arr[0].rank = r;
        for(int i=1; i<len; i++){
            pair<int, int> current = {arr[i].rank, arr[i].nextRank};
            if(prev==current){
                arr[i].rank = r;
            }
            else{
                r += 1;
                arr[i].rank = r;
                prev = current; 
            }
        }
        //printSFX(arr,len);

        int pos[len];

        for(int i=0; i<len; i++){
            pos[arr[i].index] = i;
        }

        for(int i=0; i<len; i++){
            arr[i].nextRank = arr[i].index + jump/2 >= len ? -1 : arr[pos[arr[i].index+jump/2]].rank;
        }
        //printSFX(arr,len);
        sort(arr, arr+len, comparator);
    }

    string longest_common_prefix = "";
    for(int i=0; i<len-k+1; i++){
        string sfx1 = arr[i].suffix;
        string sfx2 = arr[i+k-1].suffix;

        int itr = 0;
        string common_prefix = "";
        while(itr<min(sfx1.length(), sfx2.length())){
            if(sfx1[itr]==sfx2[itr]){
                common_prefix.push_back(sfx1[itr++]);
            } 
            else break;
        }

        if(longest_common_prefix.length() < common_prefix.length()){
            longest_common_prefix = common_prefix;
        }
    }

    longest_common_prefix==""?cout<<-1:cout<<longest_common_prefix.length();
    cout<<endl;
    return 0;

}