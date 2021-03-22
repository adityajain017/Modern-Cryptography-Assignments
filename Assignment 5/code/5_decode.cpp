#include<bits/stdc++.h>

using namespace std;

string tobinary(int n){
    string ans ="";
    while(n>0){
        ans = to_string(n%2) + ans;
        n = n/2;
    }
    while(ans.size()<4) ans = '0' + ans; 
    return ans;
}

int todecimal(string s){
    int ans,count=0;
    while(count<s.size()){
        int temp = (s[s.size()-count-1] - '0');
        ans += pow(2,count) * temp;
        count++;
    }
    return ans;
}

int main(int argc, char *argv[]){
    ifstream if1;
    if1.open("password.txt");
    string s1;
    if1>>s1;
    cout<<"\nPassword for this level: ";
    for(int i=0; i<s1.size()-1;i+=2){
        string str;
        str = tobinary(s1[i] - 'f') + tobinary(s1[i+1] - 'f');
        char c = todecimal(str);
        cout<<c;
    }
    cout<<endl;
    return 0;
}

