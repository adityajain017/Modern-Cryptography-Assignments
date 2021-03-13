#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int pc[48] = {
    14, 17, 11, 24, 1, 5,
    3, 28, 15, 6, 21, 10,
    23, 19, 12, 4, 26, 8,
    16, 7, 27, 20, 13, 2,
    41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32
	};
	
	string str1 = "010101010001XXXXXX010011110010000101010011000100";
	string str2 = "";
	for(int i = 0; i < 56; i++){
		str2.push_back('X');
	}
	
	for(int i = 0; i < 48; i++){
		str2[pc[i] - 1] = str1[i];
	}
	
	int shift[] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
	
	for(int i = 0; i < 6; i++){
		int x = shift[i];
		while(x--){
			char a = str2[27];
			char b = str2[55];
                       for(int j = 27; j >= 1; j--){
            	             str2[j] = str2[j - 1];
			}
			for(int j = 55; j >= 29; j--){
            	             str2[j] = str2[j - 1];
			}
			str2[0] = a;
                       str2[28] = b;
		}
	}
	
	ofstream fp1("key_out.txt");
	for(int i = 0; i < 16384; i++){
		stringstream ss;
        ss << to_string(i/8192 % 2) << "11" << to_string(i/4096 % 2) << to_string(i/2048 % 2) << "1" << to_string(i/1024 % 2) << to_string(i/512 % 2) << "01011" << to_string(i/256 % 2) << "100" << to_string(i/128 % 2) << to_string(i/64 % 2) << "11" <<  to_string(i/32 % 2) << "11000" << to_string(i/16 % 2) << "0001010" << to_string(i/8 % 2) << "11100010" << to_string(i/4 % 2) << "11" << to_string(i/2 % 2) << "1101" << to_string(i % 2) << "011";
        string s = ss.str();
		fp1 << s << endl;
	}
	fp1.close();
	return 0;
}
