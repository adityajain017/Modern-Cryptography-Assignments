#include <bits/stdc++.h>
using namespace std;

int hexCharToInt(char a){	//0-f to 0-15
    if(a>='0' && a<='9')
        return(a-48);
    else if(a>='A' && a<='Z')
        return(a-55);
    else
        return(a-87);
}

char IntToChar(int a)	//0-15 to 0-f
{
	if(a>-1 && a<10) return (char)(a+48);
	else return ('a'-10+a);
}

int feedintobox(int n)
{
	int a=n; // preparing 'n' to feed into S box as 'z'
	int x[6]={0};
	for (int i = 0; i < 6; ++i)
	{
		x[5-i]=a%2;
		a/=2;
	}
	int z=32*x[0] + 8*x[1] + 4*x[2] + 2*x[3] + x[4] + 16*x[5];
	return z;
}

int freq[2][8][64]={0}; // stores candidate's frequency for both input characteristics to identify the key bits

void func()
{
	int ic=0;

	string line1,line2; 

	ifstream myfile1 ("new_output1.txt");
	ifstream myfile2 ("new_output2.txt");
	ifstream myfile3 ("new_output3.txt");
	ifstream myfile4 ("new_output4.txt");

  	int pbox[32]={16 ,7 ,20 ,21 ,29 ,12 ,28 ,17, 1 ,15 ,23 ,26 ,5 ,18 ,31 ,10, 2 ,8 ,24 ,14 ,32 ,27 ,3 ,9, 19 ,13 ,30 ,6 ,22 ,11 ,4 ,25};

	int S[8][64] = {
    14, 4, 13, 1, 2, 15, 11, 8, 3 , 10, 6, 12, 5, 9, 0, 7,
    0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
    4, 1 , 14, 8, 13, 6, 2, 11, 15, 12, 9, 7,3, 10, 5, 0,
    15, 12, 8,2,4, 9, 1,7 , 5, 11, 3, 14, 10, 0, 6, 13 ,
  
    15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0,5, 10,
    3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
    0, 14, 7, 11, 10, 4, 13, 1, 5, 8,12, 6, 9, 3, 2, 15,
    13, 8, 10, 1, 3, 15, 4, 2,11,6, 7, 12, 0,5, 14, 9,
  
    10, 0, 9,14,6,3,15,5, 1, 13, 12, 7, 11, 4,2,8,
    13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
    13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12,5, 10, 14, 7,
    1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12,
  
    7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
    13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
    10, 6, 9, 0, 12, 11, 7, 13, 15, 1 , 3, 14, 5, 2, 8, 4, 
    3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14,
  
    2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9, 
    14, 11,2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6, 
    4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14, 
    11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3, 

    12, 1, 10, 15, 9, 2, 6,8, 0, 13, 3, 4, 14, 7, 5, 11, 
    10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8, 
    9, 14, 15, 5, 2,8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6, 
    4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13, 
  
    4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
    13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
    1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2, 
    6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12,
  
    13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12,7, 
    1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2, 
    7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8, 
    2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 };

	int expansion[48] =  {
    32, 1, 2, 3, 4, 5,
    4, 5, 6, 7, 8, 9,
    8, 9, 10, 11, 12, 13,
    12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21,
    20, 21, 22, 23, 24, 25,
    24, 25, 26, 27, 28, 29,
    28, 29, 30, 31, 32, 1 };

	if (myfile1.is_open()&& myfile2.is_open())
	{	ic=0;
	while ( getline (myfile1,line1) && getline (myfile2,line2))
	{
	 	if((line1!="")&&(line2!=""))
		{	
			int temp1[64],temp2[64],temp[64],l1[32],r1[32],l2[32],r2[32],p,q,pos,arr[6]={4,1,2,3,4,5};
			int k1=0,k2=0,k3=0,alpha[48]={0},beta[48]={0},thetha[32]={0},gamma[48]={0},flag[8]={0},tempfreq[8][64]={0}, charboxes[2][5]={1,4,5,6,7,0,1,3,4,5},success=1,count=1;
			
			for(int i=0;i<line1.length();i++) //got 64 bit encoding of output for i1o before applying reverse final permutation
			{
					int s=line1[i]-'f';
			    	temp1[4*i+3]=s%2;
			    	s/=2;
			    	temp1[4*i+2]=s%2;
			    	s/=2;
			    	temp1[4*i+1]=s%2;
			    	s/=2;
			    	temp1[4*i]=s%2;			       
	    	}
	    	for(int i=0;i<line2.length();i++) //got 64 bit encoding of output for i1xoro before applying reverse final permutation
			{
					int s=line2[i]-'f';
			    	temp2[4*i+3]=s%2;
			    	s/=2;
			    	temp2[4*i+2]=s%2;
			    	s/=2;
			    	temp2[4*i+1]=s%2;
			    	s/=2;
			    	temp2[4*i]=s%2;			       
	    	}

			for(int i=0;i<64;i++)     		//permutinng the array "temp1" into array "temp" 
				{	if(i%2==0) 
						{p=4+ ((i+8)/2)%4;}
					else 
						p=((i-1)/2)%4;
					q=7-(i/8);
					pos=8*p + q;
					temp[pos]=temp1[i];
				}

				for (int i = 0; i < 32; ++i)	//storing temp into l1 and r1
				{
					l1[i]=temp[i];
					r1[i]=temp[i+32];
				}

				for(int i=0;i<64;i++)     		//permutinng the array "temp2" into array "temp" 
				{	if(i%2==0) 
						{p=4+ ((i+8)/2)%4;}
					else 
						p=((i-1)/2)%4;
					q=7-(i/8);
					pos=8*p + q;
					temp[pos]=temp2[i];
				}

				for (int i = 0; i < 32; ++i)		//storing temp into l2 and r2
				{
					l2[i]=temp[i];
					r2[i]=temp[i+32];
				}

				for(int i=0;i<48;i++)	//applied expansion on 32bit to make it 48bit and store in alpha (input1)
				{	
					alpha[i]=r1[expansion[i]-1];
				}
				
				for(int i=0;i<48;i++)		//applied expansion on 32bit to make it 48bit and store in beta (input2)
				{	
					beta[i]=r2[expansion[i]-1];
				}

				for (int i = 0; i < 48; ++i)
				{
					gamma[i]=alpha[i]^beta[i]; //XOR before s-boxes (48 bits) stored in gamma
				}

				int c[32]={0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
				for (int i = 0; i < 32; ++i) //preparing target after sboxes
				{
					temp[i]=l1[i]^l2[i]^c[i]; //----------------------------IMPORTANT--------------------- Here 'c' is input characteristic dependant
				}  

				for (int i = 0; i < 32; ++i) //applying inverse p box 
				{
					thetha[pbox[i]-1]=temp[i];
				}

				for (int s = 0; s < 8; ++s)	//analysis part if input xors and output xors are fixed for s boxes, then find candidate bits for key
				{
					for (int n = 0; n < 64; ++n)
					{	
						k1=0;
						for (int i = 0; i < 6; ++i)
						{
							k1+=gamma[6*s + i]* pow(2,5-i); //here 'k1' is value of XOR (in integer) before particular 's' box 
						}

						k2=0;
						for (int i = 0; i < 6; ++i)
						{
							k2+=alpha[6*s + i]* pow(2,5-i);//here 'k2' is value 1 (in integer) before particular 's' box before xoring with the key 6 bit
						}

						k3=0;
						for (int i = 0; i < 4; ++i)
						{
							k3+=thetha[4*s + i]* pow(2,3-i); //here 'k3' is value (in integer) after particular 's' box
						}

						if((S[s][feedintobox(n)] ^ S[s][feedintobox(k1^n)])==k3) 
						{
							freq[ic][s][n^k2]+=1;		// updating the key candidate database, if valid
						}

					}

				}
	}
	}
	myfile1.close();
	myfile2.close();
	 
	}

	else cout << "Unable to open file"; 


	if (myfile3.is_open()&& myfile4.is_open())	// above same program for input characteristic 2
		{	ic=1;
		while ( getline (myfile3,line1) && getline (myfile4,line2))
		{
		 	if((line1!="")&&(line2!=""))
			{	
				int temp1[64],temp2[64],temp[64],l1[32],r1[32],l2[32],r2[32],p,q,pos,arr[6]={4,1,2,3,4,5};
				int k1=0,k2=0,k3=0,alpha[48]={0},beta[48]={0},thetha[32]={0},gamma[48]={0},flag[8]={0},tempfreq[8][64]={0}, charboxes[2][5]={1,4,5,6,7,0,1,3,4,5},success=1,count=1;
				
				for(int i=0;i<line1.length();i++) //got 64 bit encoding of output for i2o before applying reverse final permutation
				{
						int s=line1[i]-'f';
				    	temp1[4*i+3]=s%2;
				    	s/=2;
				    	temp1[4*i+2]=s%2;
				    	s/=2;
				    	temp1[4*i+1]=s%2;
				    	s/=2;
				    	temp1[4*i]=s%2;			       
		    	}
		    	for(int i=0;i<line2.length();i++)	//got 64 bit encoding of output for i2xoro before applying reverse final permutation
				{
						int s=line2[i]-'f';
				    	temp2[4*i+3]=s%2;
				    	s/=2;
				    	temp2[4*i+2]=s%2;
				    	s/=2;
				    	temp2[4*i+1]=s%2;
				    	s/=2;
				    	temp2[4*i]=s%2;			       
		    	}

				for(int i=0;i<64;i++)     		//permutinng the array "temp1" into array "temp" 
					{	if(i%2==0) 
							{p=4+ ((i+8)/2)%4;}
						else 
							p=((i-1)/2)%4;
						q=7-(i/8);
						pos=8*p + q;
						temp[pos]=temp1[i];
					}

					for (int i = 0; i < 32; ++i) 		//storing temp into l1 and r1
					{
						l1[i]=temp[i];
						r1[i]=temp[i+32];
					}

					for(int i=0;i<64;i++)     		//permutinng the array "temp2" into array "temp"  
					{	if(i%2==0) 
							{p=4+ ((i+8)/2)%4;}
						else 
							p=((i-1)/2)%4;
						q=7-(i/8);
						pos=8*p + q;
						temp[pos]=temp2[i];
					}

					for (int i = 0; i < 32; ++i)		////storing temp into l2 and r2
					{
						l2[i]=temp[i];
						r2[i]=temp[i+32];
					}

					for(int i=0;i<48;i++)
					{	
						alpha[i]=r1[expansion[i]-1];		//applied expansion on 32bit to make it 48bit and store in alpha (input1)
					}
					
					for(int i=0;i<48;i++)				//applied expansion on 32bit to make it 48bit and store in alpha (input2)
					{	
						beta[i]=r2[expansion[i]-1];
					}

					for (int i = 0; i < 48; ++i)
					{
						gamma[i]=alpha[i]^beta[i]; 		//XOR before s-boxes (48 bits) stored in gamma
					}
					
					int c[32]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0};
					for (int i = 0; i < 32; ++i) //preparing target after sboxes
					{
						temp[i]=l1[i]^l2[i]^c[i]; //----------------------------IMPORTANT--------------------- Here 'c' is input characteristic dependant
					}
					  
					for (int i = 0; i < 32; ++i) //applying inverse p box
					{
						thetha[pbox[i]-1]=temp[i];
					}

					for (int s = 0; s < 8; ++s)			//analysis part if input xors and output xors are fixed for s boxes, then find candidate bits for key
					{
						for (int n = 0; n < 64; ++n)
						{	
							k1=0;
							for (int i = 0; i < 6; ++i)
							{
								k1+=gamma[6*s + i]* pow(2,5-i); //here 'k1' is value of XOR (in integer) before particular 's' box
							}

							k2=0;
							for (int i = 0; i < 6; ++i)
							{
								k2+=alpha[6*s + i]* pow(2,5-i); //here 'k2' is value 1 (in integer) before particular 's' box before xoring with the key 6 bit
							}

							k3=0;
							for (int i = 0; i < 4; ++i)
							{
								k3+=thetha[4*s + i]* pow(2,3-i); //here 'k3' is value (in integer) after particular 's' box 
							}

							if((S[s][feedintobox(n)]^S[s][feedintobox(k1^n)])==k3) 
							{
								freq[ic][s][n^k2]+=1; // updating the key candidate database, if valid
							}

						}

					}

		}
		}
		myfile1.close();
		myfile2.close();
		 
		}

		else cout << "Unable to open file"; 

}

int main()
{	
	func();

	int count,max,max2;

	for (int i = 0; i < 2; ++i)			// printing the analysis part for both input characteristics. 
	{	cout<<"\nInput characteristic "<<i+1<<" results:\n\n"	;								//Note: only obeserve s2,s5,s6,s7,s8 for first characteristics
		for(int j=0;j<8;j++)					//and s1,s2,s4,s5,s6 for second characteristics
		{	
			count=0; max=0; max2=0;
			
			for (int k = 0; k < 64; ++k)
			{	
				count+=freq[i][j][k];
				
				if((freq[i][j][k]>freq[i][j][max])&&(freq[i][j][k]>freq[i][j][max2])) {	
					max2=max;
					max=k; }
				else if((freq[i][j][k]<freq[i][j][max])&&(freq[i][j][k]>freq[i][j][max2]))
				{
					max2=k;
				}

			}
			
			cout<<"  "<<max<<"(value)"<<"  "<<freq[i][j][max]<<"(freq.)"<<"  "<<freq[i][j][max2]<<"(second highest freq.)"<<"  "<<(count/64)<<"(avg.freq.)";
			if((freq[i][j][max]-freq[i][j][max2])>50) cout<<"\t\tGood candidate";
			cout<<endl;
		}
		cout<<endl<<endl;
	}

	return 0;
}
