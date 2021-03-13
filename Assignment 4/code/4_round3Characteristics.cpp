#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> Key(8,-1);
vector<int> charkey;

int gen_input_sbox(int n)
{
	vector<int>v(6,0);
	for(int i=5;i>=0;i--)
	{
		if(n&1)
		{
			v[i]=1;
		}
		else
		{
			v[i]=0;
		}
		n>>=1;
	}
	v[0]*=(1<<5);
	v[1]*=(1<<3);
	v[2]*=(1<<2);
	v[3]*=(1<<1);
	v[4]*=(1<<0);
	v[5]*=(1<<4);
	return  v[0]+v[1]+v[2]+v[3]+v[4]+v[5];
}
void bit_encoding(string s,int v[])
{
	for(int i=0;i<s.length();i++)
	{
		int temp=s[i]-'f';
		for(int j=4*i+3;j>=4*i;j--)
		{
			if(temp&1)
			{
				v[j]=1;
			}
			else
			{
				v[j]=0;
			}
			temp>>=1;
		}
	}
	return;
}

int 	   permutate_box[]={39,7,47,15,55,23,63,31,38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25,32,0,40,8,48,16,56,24};
int pbox[]={16 ,7 ,20 ,21 ,29 ,12 ,28 ,17, 1 ,15 ,23 ,26 ,5 ,18 ,31 ,10, 2 ,8 ,24 ,14 ,32 ,27 ,3 ,9, 19 ,13 ,30 ,6 ,22 ,11 ,4 ,25};

	int S[][64] = {
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

int expansion[] =  {
    32, 1, 2, 3, 4, 5,
    4, 5, 6, 7, 8, 9,
    8, 9, 10, 11, 12, 13,
    12, 13, 14, 15, 16, 17,
    16, 17, 18, 19, 20, 21,
    20, 21, 22, 23, 24, 25,
    24, 25, 26, 27, 28, 29,
    28, 29, 30, 31, 32, 1 };
void input_forward(int x[],int l[],int r[])
{
	for(int i=0;i<64;i++)
	{
		int index=permutate_box[i];
		if(index<32)
			l[index]=x[i];
		else
			r[index-32]=x[i];
	}
	return;
}
void generate_freq(ifstream &f1,ifstream &f2,int c[])
{
	string s1,s2; 
	int v1[64],l1[32],r1[32],l2[32],r2[32],temp[32];
	int dp[8][64]={0};
	while(f1&&f2)
	{
		getline(f1,s1);
		getline(f2,s2);
		
		bit_encoding(s1,v1);
		
		input_forward(v1,l1,r1);
		
		bit_encoding(s2,v1);

		input_forward(v1,l2,r2);

		for (int i = 0; i < 32; ++i)	
		{
			temp[pbox[i]-1]=l1[i]^l2[i]^c[i];	
		}
		
		for (int s = 0; s < 8; ++s)	
		{
			for (int n = 0; n < 64; ++n)
			{	
				int k1=0,k2=0,k3=0;
				for (int i = 0; i < 6; ++i)
				{
					k1+=((r1[expansion[6*s+i]-1]^r2[expansion[6*s+i]-1])*(1<<(5-i)));  
					k2+=(r1[expansion[6*s+i]-1])*(1<<(5-i));
					if(i<4)
						k3+=(temp[4*s + i]*(1<<(3-i))); 
				}
				k1^=n;
				k2^=n;
				if(((S[s][gen_input_sbox(n)] ^ S[s][gen_input_sbox(k1)])^k3)==0) 
				{
					dp[s][k2]+=1;		
				}

			}

		} 
				
	}
	for(int i=0;i<8;i++)
	{
		int max_freq=INT_MIN,val;
		for(int j=0;j<64;j++)
		{
			if(max_freq<dp[i][j])
			{
				max_freq=dp[i][j];
				val=j;
			}
		}
		cout<<val<<" ";
		charkey.push_back(val);
	}
	cout<<endl;
	return;
}
		
string tobinary(int n){
	if(n<0) return "XXXXXX";
    string ans ="";
    while(n>0){
        ans = to_string(n%2) + ans;
        n = n/2;
    }
    while(ans.size()<6) ans = '0' + ans; 
    return ans;
}

		
int main()
{
	ifstream f1 ("new_output1.txt");
	ifstream f2 ("new_output2.txt");
	int c1[]={0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	cout<<"result of 1st characteristics:-only key bits corresponding to s2,s5,s6,s7,s8 is of concerned to us"<<endl;
	generate_freq(f1,f2,c1);
	vector<int> arr = {2,5,6,7,8};
	for(auto i: arr){
		Key[i-1] = charkey[i-1];
	}
	charkey.clear();
	arr.clear();
	ifstream f3 ("new_output3.txt");
	ifstream f4 ("new_output4.txt");
	int c2[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0};
	cout<<"result of 2nd characteristics:-only key bits corresponding to s1,s2,s4,s5,s6 is of concerned to us"<<endl;
	generate_freq(f3,f4,c2);
	arr = {1,4};
	for(auto i: arr){
		Key[i-1] = charkey[i-1];
	}	
	cout<<"\nKey K6 values: ";
	for(auto i: Key) cout<<tobinary(i)<<" ";
	cout<<endl;
	return 0;
}
