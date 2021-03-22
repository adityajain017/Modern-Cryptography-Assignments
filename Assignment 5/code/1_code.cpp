#include<bits/stdc++.h>

using namespace std;

void decrypt(string r){
    string chars = "fghijklmnopqrstu";
    int n = chars.size();
    ofstream fp1("plaintext.txt");
    string s1 = "ffffffffffffff"; //14 f
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            string out =r;
            out+=  chars[i];
            out+=  chars[j];
            out+=  s1;
            fp1<<out<<endl;
        }
    }
    cout<<"Plaintext Generated"<<endl;
    fp1.close();
}

int main(int argc, char *argv[]){
    string r = "";
    if(argc>1) r = argv[1];
    decrypt(r);

    return 0;
}

