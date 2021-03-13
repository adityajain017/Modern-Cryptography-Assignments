#include <bits/stdc++.h>
using namespace std;

int main(){

    unordered_map<char, int> m1 = 
	{
	    {'0', 0}, {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5}, {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9},
        {'a', 10}, {'b', 11}, {'c', 12}, {'d', 13}, {'e', 14}, {'f', 15}
    };

    unordered_map<int, char> m2 = 
    {
        {0, '0'}, {1, '1'}, {2, '2'}, {3, '3'}, {4, '4'}, {5, '5'}, {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'},
        {10, 'a'}, {11, 'b'}, {12, 'c'}, {13, 'd'}, {14, 'e'}, {15, 'f'}
    };

    string diff1 = "0000801000004000";
    int mydiff1[16];
    for(int i = 0; i < 16; i++){
    	mydiff1[i] = m1[diff1[i]];
	}
    string diff2 = "0000080101000400";
    int mydiff2[16];
    for(int i = 0; i < 16; i++){
    	mydiff2[i] = m1[diff2[i]];
	}

    ofstream fp1("new_output1.txt");
    ofstream fp2("new_output2.txt");
    ofstream fp3("new_output3.txt");
    ofstream fp4("new_output4.txt");


    for(int i = 0; i < 1000; i++){
	    string str = "";
	    for(int j = 0; j < 16; j++){
	        str.push_back(m2[(rand() % 16)] );
	    }
	    
	    int myArray[16];
	    for(int j = 0; j < 16; j++){
	    	myArray[j] = m1[str[j]];
	    }
		
	    string p1 = "";
	    for(int j = 0; j < 16; j++){
		    p1.push_back('f' + myArray[j]);
	    }
	
	    string p2 = "";
	    for(int j = 0; j < 16; j++){
	        p2.push_back('f' + (myArray[j] ^ mydiff1[j]));
	    }
	    
	    fp1 << p1 << endl;
	    fp2 << p2 << endl;
    }


    for(int i = 0; i < 1000; i++){
	    string str = "";
	    for(int j = 0; j < 16; j++){
	        str.push_back(m2[(rand() % 16)] );
	    }
	    
	    int myArray[16];
	    for(int j = 0; j < 16; j++){
	    	myArray[j] = m1[str[j]];
	    }
		
	    string p1 = "";
	    for(int j = 0; j < 16; j++){
		    p1.push_back('f' + myArray[j]);
	    }
	
	    string p2 = "";
	    for(int j = 0; j < 16; j++){
	        p2.push_back('f' + (myArray[j] ^ mydiff2[j]));
	    }
	    
	    fp3 << p1 << endl;
	    fp4 << p2 << endl;
    }


    fp1.close();
    fp2.close();
    fp3.close();
    fp4.close();
    return 0;
}
