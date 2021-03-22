#include<bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]){
    int k = atoi(argv[1])+2;
    string chars = "fghijklmnopqrstu";
    string cipher = "gskohgkokritmqjfikfhffgiltjlisfr";
    ifstream if1,if2;
    if1.open("ciphertext1.txt");
    if2.open("plaintext.txt");
    ofstream of1;
    of1.open("password.txt");

    for(int i=1;i<=160;i++){
        string s1,s2;
        if1>>s1;
        if(s1.substr(0,k) == cipher.substr(0,k)){
            for(int j =1; j<=i;j++) if2>>s2;
            s2 = s2.substr(0,k);
            cout<<"\n\nDecrypted Text: "<<s2<<endl;
            of1<<s2;
            break;
        }
    }
    if1.close();
    if2.close();
    of1.close();
    return 0;
}

