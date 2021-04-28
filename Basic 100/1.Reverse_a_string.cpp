#include<bits/stdc++.h>

using namespace std;


int main()
{
    string s1;
    cout<<"Enter string : ";
    cin>>s1;
    string s2="";
    for(int i=s1.length()-1;i>=0;i--)
        s2+=s1[i];
    cout<<s2;
} 

