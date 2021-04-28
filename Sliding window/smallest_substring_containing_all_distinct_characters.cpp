#include<bits/stdc++.h>
using namespace std;


int smallestWindow(string s){

    unordered_map<char, bool> mp;
    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        if(mp.find(ch)==mp.end()){
            mp[ch] = true;
        }
    }

    int distinctCount = mp.size();

    vector<int> freq (256, 0); 

    int i=0, j=0;
    int count = 0;
    int ans = s.length();
    string sub = "";

    while(i<s.length()){
        if(count == distinctCount){
            ans = min(ans, j-i);
            freq[s[i]] -= 1;
            if(freq[s[i]]==0) count--;
            i++;

        }
        else{
            if(freq[s[j]]==0)
                count++;
            
            freq[s[j]] += 1;
            
            j++;
        }
        if(j==s.length() && count<distinctCount) break;
     
    }

    return ans;
}

int main(){

    string s = "abcaaa";

    cout<<"Smallest window : "<<smallestWindow(s)<<endl;

}