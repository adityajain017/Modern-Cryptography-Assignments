#define BYTE unsigned char
#define INT unsigned int
#include <bits/stdc++.h>
using namespace std;

INT S[8][64]=
{
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


INT PC1[] = {
  57, 49, 41, 33, 25, 17, 9,
  1, 58, 50, 42, 34, 26, 18,
  10,  2, 59, 51, 43, 35, 27,
  19, 11,  3, 60, 52, 44, 36,
  63, 55, 47, 39, 31, 23, 15,
  7, 62, 54, 46, 38, 30, 22,
  14,  6, 61, 53, 45, 37, 29,
  21, 13,  5, 28, 20, 12,  4
};


unsigned short shifts[] = {
1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1
};


INT PC2[] = {
  14, 17, 11, 24,  1, 5,
  3, 28 ,15,  6, 21, 10,
  23, 19, 12,  4, 26, 8,
  16,  7, 27, 20, 13, 2,
  41, 52, 31, 37, 47, 55,
  30, 40, 51, 45, 33, 48,
  44, 49, 39, 56, 34, 53,
  46, 42, 50, 36, 29, 32
};

INT IP[] = {
  58,50,42, 34,26,18,10,2,
  60,52,44,36,28,20,12,4,
  62,54, 46, 38, 30, 22, 14,6,
  64, 56, 48, 40,32,24, 16, 8,
  57, 49, 41, 33,25,17, 9,1,
  59, 51,43,35,27,19,11,3,
  61,53,45,37,29,21,13, 5,
  63,55, 47,39,31,23,15,7
};



INT RFP[] = {
  8,40,16,48,24,56,32,64,
  7, 39,15,47,23,55,31,63,
  6,38,14,46,22,54,30,62,
  5,37,13,45, 21,53,29,61,
  4,36,12,44,20,52,28,60,
  3, 35, 11,43,19,51,27,59,
  2, 34, 10, 42,18, 50,26,58,
  1,33,9,41, 17, 49, 25,57,
};



INT E[] = {
  32, 1, 2, 3, 4, 5,
  4, 5,6, 7, 8, 9,
  8, 9, 10, 11, 12, 13,
  12, 13, 14, 15, 16, 17,
  16, 17, 18, 19, 20, 21,
  20, 21, 22, 23, 24, 25,
  24, 25, 26, 27, 28, 29,
  28, 29, 30, 31, 32, 1
};


INT P[] = {
  16, 7, 20, 21,
  29, 12, 28, 17,
  1, 15, 23, 26,
  5, 18, 31,10,
  2, 8, 24, 14,
  32, 27, 3, 9,
  19, 13, 30, 6,
  22, 11, 4, 25,
};


INT INV_P[] = {
  9, 17, 23, 31,
  13, 28, 2, 18,
  24, 16, 30, 6,
  26, 20, 10, 1,
  8, 14, 25, 3,
  4, 29, 11, 19,
  32, 12, 22, 7,
  5, 27, 15, 21,
};

BYTE KS[16][48];

void unpack8(BYTE *packed,BYTE *binary)

{
  register INT i, j, k;

  for (i=0; i<8; i++) {
    k = *packed++;
    for (j=0; j<8;j++) *binary++ = (k>>(7-j)) &01 ;
  }
}

void pack8(BYTE *packed,BYTE *binary)
 
{
  register INT i, j, k;

  for (i=0; i<8; i++) {
    k = 0;
    for (j=0; j<8;j++) k  = (k<<1)+ *binary++;
    *packed++ = k;
  }
}

void des(BYTE *in,BYTE *out,INT r,char flag)
{
  register INT i, j, k, t;
  static BYTE block[64]; 
  static BYTE LR[64], f[32], preS[48];
  int z;
  unpack8(in, block);
  for (j =0; j<64 ; j++)
        {
                LR[j] = block[IP[j] -1];
        }
        for (i=0; i<r; i++) 
        { 
          for( j=0; j<48; j++) 
          {
             preS[j] = LR[E[j] +31]^KS[i][j];
          }

          for (j=0; j<8; j++) 
          {
           k= 6*j;
            t= preS[k];
            t = (t<<1) | preS[k+5];
            t = (t<<1)| preS[k+1];
            t = (t<<1)| preS[k+2];
            t = (t<<1)| preS[k+3];
            t = (t<<1)| preS[k+4];

            t = S[j][t];

            k= 4*j;
            f[k] = (t>>3)&1;
            f[k+1] = (t >> 2) & 1;
            f[k+2] = (t >> 1) & 1;            
            f[k+3] = t &1;
          }

          for (j=0; j <32; j++) 
          {
            t = LR[j+32];

          if (flag == 'N')
              LR[j+32] = LR[j]^f[P[j] -1];
          else
              LR[j+32] = LR[j]^f[INV_P[j] -1];

             LR[j] =t;
          }

        }
        for (j=0; j < 64; j++) block [j] = LR[RFP[j]-1];

    pack8(out, block);
    out[9] = '\0';
}

void set_the_key(int sw1,BYTE *CD,int r)
{
  register INT i, j, k, t1, t2;
  int z;
  for ( i=0; i<r; i++) 
  { 
    for (j =0; j <shifts[i]; j++) 
    {
      t1 = CD[0];
      t2 = CD[28];
      for ( k=0; k<27; k++) 
      {
        CD[k] = CD[k+1];
        CD[k+28] = CD[k+29];
      }
      CD[27] = t1;
      CD[55] = t2;
    }  
    j = sw1 ? r-1-i :i ;  
    for (k=0; k< 48 ; k++)  
        KS[j][k] = CD[PC2[k] -1];
  }
  return;
}

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


int main(){
  int sw1=0;
  BYTE key[56],key2[56];
  int r =6;
  BYTE cipher2[9];
  char flag='N';
  int i,m;
  string str1;
  ifstream ifile1;
  ifile1.open("key_out.txt");
  key[56]={2};
  BYTE plain[9]={0,0,0,0,0,0,0,0,'\0'};
  string ciphertext = "qfpouphsgqnmkfkg"; //qfpouphsgqnmkfkg was the output with ffffffffffffffff as input
  BYTE cipher1[9]; //output that we got from server for input ffffffffffffffff. But it is in numeric form (i.e. 8 bits changed to number 0-255)
  int k=0;
  for(int i=0; i<ciphertext.size();i=i+2){
      char c = ciphertext[i];
      char d = ciphertext[i+1];
      int i1 = c -'f';
      int i2 = d -'f';
      string out = tobinary(i1) + tobinary(i2);
      cipher1[k] = todecimal(out);
      k++;
  }  
  cipher1[9] = '\0';
  

  for(int j = 0; j < 16384; j++)  {
    string str1;
    int flag1=0;
    ifile1>>str1;
        
    for(i=0;i<56;i++){
      key[i]=str1[i]-48;
      key2[i]=key[i];
    }
    
    set_the_key(sw1,key,r);
    des(plain,cipher2,r,flag);

    for(i=0;i<8;i++){
      if(int(cipher1[i])!=int(cipher2[i]))
        flag1=1;
    }
  
    if(!flag1)
        break;
  }

  cout<<"Key: ";
  for(i=0;i<56;i++)
    cout<<int(key2[i]);
  cout<<endl;
    return 0;
}


