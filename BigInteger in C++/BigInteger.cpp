#include <bits/stdc++.h> 
using namespace std;

class BigInteger{

public:

    string addition(string s1, string s2){
        string small, large;
        int len1 = s1.length();
        int len2 = s2.length();
        int carry = 0, tempRes = 0;
        if(len1<len2){
            small = s1; large = s2;
        }
        else{ 
            small = s2; 
            large = s1;
        }
        string res = ""; int i;

        
        for(i=0; i<small.length(); i++){
            int digit1 = large[large.length()-1-i]-'0';
            int digit2 = (int)small[small.length()-1-i]-'0';
            tempRes = digit1+digit2+carry;
            carry = tempRes/10;
            char t = (tempRes%10)+'0';
            res.push_back(t);
        }

       while(i<large.length()){
            if(carry>0){
                tempRes = carry + large[large.length()-1-i]-'0';
                carry = tempRes/10;
                res.push_back((char)((tempRes%10)+'0'));
            }
            else {
                res.push_back(large[large.length()-1-i]);

            }
            i++;
        }

        if(carry>0){
            char c = carry+'0'; 
            res.push_back(c);
        }

        reverse(res.begin(), res.end());

        return res;

    }

    string multiply(string num1, string num2){

        string res = "0"; int count = 0; string ans;
        int len1 = num1.size(), len2 = num2.size();

        for(int i=len2-1; i>=0; i--){
            int digit2 = num2[i]-'0';
            int carry = 0, tempRes = 0;

            string temp = "";
            for(int j=len1-1; j>=0; j--){
                int digit1 = num1[j]-'0'; 
                tempRes = digit1*digit2+carry;
                carry = tempRes/10;  
                char t = (tempRes%10)+'0';
                temp.push_back(t);
            }

           if(carry>0){
            char c = carry+'0'; 
            temp.push_back(c);
            }

            reverse(temp.begin(), temp.end());
            for(int z=0; z<count; z++) temp.push_back('0');

            ans = addition(res, temp);
            res = ans;
            count++;
        }

        return res;
    }

    string factorial(int n){

        string ans = to_string(n);
        for(int i=n-1; i>1; i--){
            ans = multiply(ans, to_string(i));
        }

        return ans;
    }

    string subtract(string s1, string s2){

        string res = "";
        int len1 = s1.length(), len2 = s2.length(); 
        reverse(s1.begin(), s1.end()); 
        reverse(s2.begin(), s2.end()); 

        int carry = 0;
        int i;

        for (i=0; i<len2; i++) 
        { 
            int temp = (s1[i]-'0')-(s2[i]-'0')-carry; 

                if (temp >= 0)  carry = 0;
                else{
                    temp += 10;
                    carry = 1; 
                }
            res.push_back(temp + '0'); 
       } 
  
       while (i<len1) 
       { 
            int temp = ((s1[i]-'0') - carry); 
            
            if (temp >= 0)  carry = 0; 
           
            else{
                temp += 10; 
                carry = 1; 
            }
                
                
            res.push_back(temp + '0'); 
            i++;
        } 
  
      reverse(res.begin(), res.end()); 

      res.erase(0, min(res.find_first_not_of('0'), res.size()-1));
  
    return res; 
        
    }

    bool isGreater(string s1, string s2) 
    { 
        int len1 = s1.length(), len2 = s2.length(); 
    
        if (len1 > len2) {
        return true;
        }
        else if(len2>len1) {
            return false;
        }
        else if(len2=len1){
            for (int i=0; i<len1; i++){ 
                if (s1[i] > s2[i]) {
                    return true;
                }
              
                else if(s1[i] < s2[i]) {
                    return false;
                }
            } 
        }
 
        return true; 
    } 

    string divide(string dividend, string divisor){
        int len = divisor.length();
        if(len>18) return divide2(dividend, divisor);
        else return divide1(dividend, divisor);
    }

    string divide2(string val, string div){
        while(isGreater(val, div)){
            val = subtract(val, div);
         
        }
        return val;
    }

    string divide1(string dividend, string divisor){

        long long int div = stoll(divisor);
        int len = dividend.length();
        string res = "";
        long long int rem;

        int i=0;
        long long int val = dividend[i]-'0';
        i++;
        while(val<div){
            val = val*10 + dividend[i]-'0';
            i++;
        }

        while(i<=len){
            int tempRes = val/div;
            rem = val%div;
            val = rem*10 + dividend[i]-'0';
            char ch = tempRes + '0';
            res.push_back(ch);


            i++;
        }

        return to_string(rem);
    }

    string pow(string base, long long int exp){
        string res = "1";
        while(exp>0){
            if(exp&1) res = multiply(res, base);
            base = multiply(base, base);
            exp>>=1;
        }
        return res;
    }

    string gcd(string a, string b){
        if(isGreater(b,a)){
                swap(a,b);
            }
        if(b=="0") return a;
        else{
            string rem  = divide(a,b);
            return gcd(b,rem);
        }
    }


};

int main(){

BigInteger bi;

int Q;
cin>>Q;

for(int i=0; i<Q; i++){
    int num;
    cin>>num;

    if(num==1){
        string a; long long int b;
        cin>>a>>b;
        string ans = bi.pow(a,b);
        cout<<ans<<endl;
    }

    else if(num==2){
        string a, b;
        cin>>a>>b;
        string ans = bi.gcd(a,b);
        cout<<ans<<endl;
    }

    else if(num==3){
        int num;
        cin>>num;
        string ans = bi.factorial(num);
        cout<<ans<<endl;
    }
}

return 0;
}
