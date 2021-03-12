g++ 1_plaintextGenerator.cpp -o 1_plaintextGenerator
./1_plaintextGenerator

./2_cypherGenerator.sh

python3 3_cleanCipher.py

rm output1.txt output2.txt output3.txt output4.txt

g++ 4_round3Characteristics.cpp -o 4_round3Characteristics
./4_round3Characteristics

python3 5_key_bruteforce.py

g++ 6_DES_bruteforce.cpp -o 6_DES_bruteforce
./6_DES_bruteforce

g++ 7_decryptDES.cpp -o 7_decryptDES
./7_decryptDES
