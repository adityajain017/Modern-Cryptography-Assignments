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

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string cipher = "wsamiepjoysgtmeyipbya.Paxgniphayy,meysywahgmewhrgtwhmysyamwhmeyiepjoys.Agjygtmeykpmysiepjoysavwkkoyjgsywhmysyamwhrmephmewaghy!Meyiguynayutgsmewajyaaprywapawjfkyanoamwmnmwghiwfeyswhvewieuwrwmaepbyoyyhaewtmyuox8fkpiya.MeyfpaavgsuwamxSrN03uwddvwmegnmmeydngmya.Mewawameyt";
unordered_map<char,char> sbstn; //substitution hash map

void show_message(){
    char k;
    for(int i=0; i<cipher.length();i++){
        char c = tolower(cipher[i]);
        if(sbstn.find(c)!=sbstn.end()){
            printf("\033[1;31m");
            if(cipher[i]<'a' and cipher[i]>='A') {
                k = sbstn[c];
                k = toupper(k);
                cout<<k;
            }
            else printf("%c",sbstn[c]);
            printf("\033[0m");
        }
        else {
            if(cipher[i]<'a' and cipher[i]>='A') {
                k = toupper(c);
                cout<<k;
            }
            cout<<c;
        }
    }
    cout<<endl;
}


int main(){
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
    cout<<"Frequency Analysis:\n";
    for(auto it=freq.begin();it!=freq.end();it++){
        cout<<it->second<<" - "<<it->first<<"%"<<endl;
    }

	//step 1 . y is highest frequency replace it with 'e'. 'm' and 'e' are substiuted for 'the'.
    cout<<"\nStep 1\n"<<"-----------------\n";
    sbstn['y']= 'e';
    sbstn['m'] = 't';
    sbstn['e'] = 'h';

    show_message();
    cipher = "wsamiepjoysgt mey ipbya.Paxgniphayy, mey sywahgmewhrgtwhmysyamwh mey iepjoys.Agjygt mey kpmysiepjoysavwkkoyjgsywhmysyamwhrmephmewaghy! Mey iguynayutgsmewajyaaprywapawjfkyanoamwmnmwghiwfeyswhvewieuwrwmaepbyoyyhaewtmyuox8fkpiya. Mey fpaavgsuwamxSrN03uwddvwmegnm mey dngmya.Mewawa mey t";    
    cout<<"\nAfter adding space around 'the':\n";
    show_message();

	//step 2. In english language , in middle sentence if 'the' is present . some preposition 
	//	  like 'on','of','at','in' etc . follows 'the'. In given cipher 'gt' follows 'the'. 
	//        By brute force , we find out 'o' -> 'g' and 'f' -> 't'.
    sbstn['g'] = 'o';
    sbstn['t'] = 'f';   
    
	// step 2.2 by looking at last two word 'thw awathef' .break it by 'the'. we get 'thw awa the f'. w can not be 'e'. Since a preposition precedes the word "the" we broke it into 'thwa wa the f'.
	//by looking at the word generated by th_ _ (length 4). we find out 'w' -> i and 'a' -> 's' as it satisfyies with the preopsition -"is" precedig the word "the".
    cout<<"\nStep 2\n"<<"-----------------\n";
    sbstn['w'] = 'i';
    sbstn['a'] = 's';
    // This leads to the generation of the word "this" from the cipher text "mewa".
    cipher = "wsamiepjoys gt mey ipbya.Paxgniphayy, mey sy wa hgmewhr gt whmysyamwh mey iepjoys.Agjy gt mey kpmysiepjoysavwkkoyjgsywhmysyamwhrmeph mewa ghy! Mey iguynayutgs mewa jyaapry wa pawjfkyanoamwmnmwghiwfeyswhvewieuwrwmaepbyoyyhaewtmyuox8fkpiya. Mey fpaavgsu wa mxSrN03uwddvwmegnm mey dngmya. Mewa wa mey t";
    cout<<"\nAfter adding space around 'of', 'this' and 'is':\n";
    show_message();

    // step 3.1  We have 'i_te_esti_ the' in our message. Since a preopsition precedes the word 'the' "ih" seems to be "in". so 'n' -> 'h'
    sbstn['h'] = 'n';
    
    // step 3.2 by looking at 'of inte_est' ,we can say the word is 'interest'. 'r' -> 's'.
    sbstn['s'] = 'r';
    cipher = "wsamiepjoys gt mey ipbya.Paxgniphayy, mey sy wa hgmewhr gt whmysyam wh mey iepjoys.Agjy gt mey kpmysiepjoysavwkkoyjgsy whmysyam whrmeph mewa ghy! Mey iguynayutgs mewa jyaapry wa pawjfkyanoamwmnmwghiwfeyswhvewieuwrwmaepbyoyyhaewtmyuox8fkpiya. Mey fpaavgsu wa mxSrN03uwddvwmegnm mey dngmya. Mewa wa mey t";
    cout<<"\nStep 3\n"<<"-----------------\n";
    cout<<"\nAfter adding space around 'interest':\n";
    show_message();

    //step 4. by looking at 'the re is not hin_ of interest', the actual sentence is read by us as 'there is nothinr of interest'. 'nothinr' looks like 'nothing', So, 'g' -> 'r'.
    sbstn['r'] = 'g'; 
    // Making some more space correction.
    cipher = "wsamiepjoys gt mey ipbya.Paxgniphayy, meysy wa hgmewhr gt whmysyam wh mey iepjoys.Agjy gt mey kpmysiepjoysavwkkoyjgsy whmysyamwhr meph mewa ghy! Mey iguynayu tgs mewa jyaapry wa pawjfkyanoamwmnmwghiwfeyswhvewieuwrwmaepbyoyyhaewtmyuox8fkpiya. Mey fpaavgsu wa mxSrN03uwddvwmegnm mey dngmya. Mewa wa mey t";
    cout<<"\nStep 4\n"<<"-----------------\n";
    cout<<"\nAfter correcting the place of spaces :\n";
    show_message();

    //step 5.1 by looking at 'interesting th_n this one!'. the actual sentence is read by us as 'interesting than this one!'. 'thpn' looks like 'than'. 'a' -> 'p'.
    sbstn['p'] = 'a';
    //step 5.2 by looking at 'so_e of the _ater". the actual sentence is read by us as 'some of the later'. soje looks 'some' and 'kater' like 'later'. 'j' -> 'm' and 'k' -> 'l'.
    sbstn['j'] = 'm';
    sbstn['k'] = 'l';   
    //step 5.3 by looking at '_e more interesting' it looks like 'be more interesting'.  'o' -> 'b'. 
    sbstn['o'] = 'b';
    
    cipher = "wsamiepjoys gt mey ipbya.Paxgniphayy, meysy wa hgmewhr gt whmysyam wh mey iepjoys.Agjy gt mey kpmys iepjoysavwkk oy jgsy whmysyamwhr meph mewa ghy! Mey iguynayu tgs mewa jyaapry wa pawjfkyanoamwmnmwghiwfeyswhvewieuwr wma epby oyyh aewtmyuox8fkpiya. Mey fpaavgsu wa mxSrN03uwddvwmegnm mey dngmya. Mewa wa mey t";
    cout<<"\nStep 5\n"<<"-----------------\n";
    cout<<"\nAfter substituting p,j,k,o, and b and positioning spaces :\n";
    show_message();

    //step 6.1 by looking at 'ha_e been sh ifte u'. it looks like 'have been shifted' . 'b' -> 'v' and 'u' -> 'd'.
    sbstn['b'] = 'v';
    sbstn['u'] = 'd'; 
    //step 6.2. by looking at '_hamber of the _aves '. It looks like 'chamber of the caves'. 'i' -> 'c'.  
    sbstn['i'] = 'c';
    //step 6.3 by looking at 'chamers _ill be more' It looks like 'chamber will be more'. 'v' -> 'w'.
    sbstn['v'] = 'w'; 
     
    cipher = "wsam iepjoys gt mey ipbya. Paxgn iph ayy, meysy wa hgmewhr gt whmysyam wh mey iepjoys. Agjy gt mey kpmys iepjoysa vwkk oy jgsy whmysyamwhr meph mewa ghy! Mey iguy nayu tgs mewa jyaapry wa pawjfkyanoamwmnmwghiwfeys wh vewie uwrwma epby oyyh aewtmyu ox8fkpiya. Mey fpaavgsu wa mxSrN03uwddvwmegnm mey dngmya. Mewa wa mey t";
    cout<<"\nStep 6\n"<<"-----------------\n";
    cout<<"\nAfter substituting b,u,i,v and positioning spaces :\n";
    show_message();

    //step 7.1 - by looking at 'the code _sed for this message'. It looks like 'the code used for this message'. Hence 'n' -> 'u'.
    sbstn['n'] = 'u'; 
    //step 7.2 - by looking at 'as_o_ can see'. It looks like 'as you can see'. 'x' -> 'y'.
    sbstn['x'] = 'y';
    //step 7.3 - by looking at 'flaces' and 'duotes' individually . '_assword' is 'password' and '_uotes' is 'quotes'. So, 'f' -> 'p' and 'd' -> 'q'.
    sbstn['f'] = 'p';  
    sbstn['d'] = 'q';
    cipher = "wsam iepjoys gt mey ipbya. Pa xgn iph ayy, meysy wa hgmewhr gt whmysyam wh mey iepjoys. Agjy gt mey kpmys iepjoysa vwkk oy jgsy whmysyamwhr meph mewa ghy! Mey iguy nayu tgs mewa jyaapry wa p awjfky anoamwmnmwgh iwfeys wh vewie uwrwma epby oyyh aewtmyu ox 8 fkpiya. Mey fpaavgsu wa mxSrN03uwdd vwmegnm mey dngmya. Mewa wa mey t";
    cout<<"\nStep 7\n"<<"-----------------\n";
    cout<<"\nAfter substituting n,x,f,d and positioning spaces :\n";
    show_message();

    // Step 8 - Last incomplete sentence "This is the f" seems that it is the part of the 1st sentence. So rearranging it.
    cipher = "Mewa wa mey twsam iepjoys gt mey ipbya. Pa xgn iph ayy, meysy wa hgmewhr gt whmysyam wh mey iepjoys. Agjy gt mey kpmys iepjoysa vwkk oy jgsy whmysyamwhr meph mewa ghy! Mey iguy nayu tgs mewa jyaapry wa p awjfky anoamwmnmwgh iwfeys wh vewie uwrwma epby oyyh aewtmyu ox 8 fkpiya. Mey fpaavgsu wa mxSrN03uwdd vwmegnm mey dngmya.";
    cout<<"\nStep 8\n"<<"-----------------\n";
    cout<<"\nDecrypted Plain Text :\n";
    show_message();
//so final decrypted text is 
/*This is the first chamber of the caves.As you can see,there is nothing of interest in the chamber.Some of the later chambers will be more interesting than this one!the code used for this message is a simple substitution cipher in which digits have been shiftedby 8 places. the password is tyrgu03diqq without the quotes. */
    
    
    


    return 0;
}