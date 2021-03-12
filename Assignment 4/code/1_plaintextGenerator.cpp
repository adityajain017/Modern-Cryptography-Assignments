#include <bits/stdc++.h>
using namespace std;

int hexCharToInt(char a){	//change 0-f to 0-15
    if(a>='0' && a<='9')
        return(a-48);
    else if(a>='A' && a<='Z')
        return(a-55);
    else
        return(a-87);
}

char IntToChar(int a)	//change 0-15 to 0-f
{
	if(a>-1 && a<10) return (char)(a+48);
	else return ('a'-10+a);
}

int main()
{

	long long int rand_no,j=0;
	string inputdiff1="0000801000004000";
	string inputdiff2="0000080101000400";
	ofstream myfile1 ("i1xor.txt");
	ofstream myfile2 ("i2xor.txt");

	char a[16];
	char b[16]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
	FILE *fr1;
	FILE *fr2;
	fr1 = fopen("i1.txt","w+");
	fr2 = fopen("i2.txt","w+");


	while(j < 1000)
	{
		std::stringstream XORString;

		for (int i = 0; i < 16; i++)
		  {
		    rand_no = rand()%16;
		    a[i] = b[rand_no];
		  }
		for (int i = 0; i < 16; i++)
		    fprintf(fr1, "%c",(hexCharToInt(a[i])+'f'));
			
		fprintf(fr1, "\n");

		for(int i=0;i<16;i++)
			{
				myfile1<<char('f'+(hexCharToInt(a[i])^hexCharToInt(inputdiff1[i]))) ; 
			}
			myfile1<<'\n';

		j++;
	}
	myfile1.close();

	j=0;

	while(j < 1000)
	{
	std::stringstream XORString;

	for (int i = 0; i < 16; i++)
	  {
	    rand_no = rand()%16;
	    a[i] = b[rand_no];
	  }
	for (int i = 0; i < 16; i++)
	    fprintf(fr2, "%c",(hexCharToInt(a[i])+'f'));
		
	fprintf(fr2, "\n");

	for(int i=0;i<16;i++)
	{
			myfile2<<char('f'+(hexCharToInt(a[i])^hexCharToInt(inputdiff1[i]))) ;    
	}
		myfile2<<'\n';

	j++;
	}
	myfile2.close();

fclose(fr1);
fclose(fr2);

return 0;
}
