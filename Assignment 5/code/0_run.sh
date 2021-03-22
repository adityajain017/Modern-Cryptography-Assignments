k=0;
s="";

g++ 1_code.cpp -o 1_code
g++ 4_check.cpp -o 4_check

for i in {1..16}
do
    ./1_code $s

    ./2_cypherGenerator.sh

    python3 3_cleanCipher.py

    rm output1.txt 

    ./4_check $k
    k=$((k+2))
    s=$(<password.txt)  
done

g++ 5_decode.cpp -o 5_decode
./5_decode