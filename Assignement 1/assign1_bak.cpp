// Color Codes
// [0;31m	Red
// [1;31m	Bold Red
// [0;32m	Green
// [1;32m	Bold Green
// [0;33m	Yellow
// [01;33m	Bold Yellow
// [0;34m	Blue
// [1;34m	Bold Blue
// [0;35m	Magenta
// [1;35m	Bold Magenta
// [0;36m	Cyan
// [1;36m	Bold Cyan
// [0m	Reset

#include<bits/stdc++.h>
// #include<graphics.h>
using namespace std;


int main(){
    string cipher = "wsam ie pjo ysgtm eyipbya .P axg niphay y, mey syw ahgm ewhrg tw hmysyam wh meyiepjo ys .Ag jygtmeyk pmys ie pjo ysavw kkoyjgsy whmy sy amwh rmephmewagh y!Me yigu ynay utg smew ajya apr ywap awjfkya no a mwmnmw ghiwfeyswhve wieuwr wm aepby oyyhae wtmy uox8 fkpiya. Me y fpaavgs uwa mxSrN03u wd dvwmegnmmey dngmya. Mew awameyt";
    unordered_map<char,double> hash;
    map<double,char,greater<double>> freq; //stores frequency
    int totl_letters=0;
    for(int i=0; i<cipher.length();i++){
        char c = tolower(cipher[i]);
        if(isalpha(c)){
            totl_letters++;
            if(hash.find(c)==hash.end()) hash[c] = 1;
            else hash[c]++;
        }
    }
    for(auto it=hash.begin();it!=hash.end();it++){
        it->second = (it->second/totl_letters)*100;
        freq[it->second] = it->first;
    }
    for(auto it=freq.begin();it!=freq.end();it++){
        cout<<it->second<<" - "<<it->first<<endl;
    }

    unordered_map<char,char> sbstn; //substitution hash map
    // sbstn['p'] = 'a';
    sbstn['y'] = 'e';
    sbstn['m'] = 't';
    sbstn['e'] = 'h';
    sbstn['w'] = 'i';
    sbstn['a'] = 's';
    sbstn['p'] = 'a';
    sbstn['g'] = 'o';

    for(int i=0; i<cipher.length();i++){
        char c = tolower(cipher[i]);
        if(sbstn.find(c)!=sbstn.end()){
            printf("\033[1;31m");
            printf("%c",sbstn[c]);
            printf("\033[0m");
        }
        else cout<<c;
    }
    cout<<endl;


    return 0;
}