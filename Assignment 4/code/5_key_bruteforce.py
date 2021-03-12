pc2 = [                 #Permutation matrix 2 for key schedule
  14, 17, 11, 24,  1, 5,
  3, 28 ,15,  6, 21, 10,
  23, 19, 12,  4, 26, 8,
  16,  7, 27, 20, 13, 2,
  41, 52, 31, 37, 47, 55,
  30, 40, 51, 45, 33, 48,
  44, 49, 39, 56, 34, 53,
  46, 42, 50, 36, 29, 32
]
#s="011001101101010110XXXXXX110110000010XXXXXX111110"  #Key guessed from sbox 
s="010101010001XXXXXX010011110010000101010011000100"
#s="101101110011XXXXXX000111010101010110001100111110"
new=['X']*56
for i in range(len(s)):
    new[pc2[i]-1]=s[i]       #Applying inverse of permutation 2
y="".join(new)               
shifts=[1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1]     
for i in range(6):           #Shifting the key and generating 56 bit key
    for j in range(shifts[i]):
        a=new[55]
        b=new[27]
        k=27
        while(k>=1):
            new[k]=new[k-1]
            new[k+28]=new[k+27]
            k-=1
        new[0]=b
        new[28]=a
print("".join(new))

key_out_file=open("key_out.txt",'w')
for i in range(2**14):
    key_out_file.write(str(i//8192%2) +'11'+ str(i//4096%2) + str(i//2048%2)+ '1'+ str(i//1024%2) + str(i//512%2)+'01011' + str(i//256%2)  + '100' +  str(i//128%2) + str(i//64%2)+'11' +  str(i//32%2)+ '11000' + str(i//16%2) + '0001010'+str(i//8%2) + '11100010' + str(i//4%2) + '11'+str(i//2%2) + '1101'+str(i%2)  + '011\n')
key_out_file.close()