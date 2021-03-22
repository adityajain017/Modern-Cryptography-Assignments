This code repository is solution for Assignment 5 for the course CS641.

To run the program
-------------------
execute the following 0_run.sh bash script to obtain the password on the terminal screen and in the password.txt file:
$./0_run.sh

Program Files
--------------
=> 0_run.sh:  is the script file which executes the entire program to genereate the password. It executes the programs 1_code.cpp, 2_cypherGenerator.sh, 3_cleanCipher.py, and 4_check.cpp in loop for 16 time to generate the deciphered text corresponding to the given ciphered password. Then it executes the program 5 to decode this obtained deciphered text to get the password to reach the next level.

=> 1_code.cpp: It generates all the possible plaintexts for the given ciphertexts. It generates permutations for only one block of the plaintext. It is executed 16 times to obtain the result. 

=> 2_cypherGenerator.sh: It generates the ciphertexts corresponding the plaintexts present in the plaintext.txt in the file output1.txt. It uses the bash script test1.sh.

=> 3_cleanCipher.py: It removes the spaces from the file output1.txt and generates the file ciphertext1.txt.

=> 4_check.cpp: It matches all possible obtained combinations of ciphertext present in ciphertext1.txt with the given cipher text to obtain the corresponding plaintext. It gives result for one block of plaintext only and it written in the output file named - password.txt. It is executed 16 times to obtain the result.

=> 5_decode.cpp: It decodes the obtained deciphered text present in password.txt to obtain the password that clears the level of the game.
