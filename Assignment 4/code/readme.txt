This project breaks the DES 6 round to obtain its key.

Note: You need to have a network connection to perform the chosen plaintext attack. 

Programs Glossary
------------------
=> 0_run.sh - master script to run the entire program at once. 

=> 1_plaintextGenerator.cpp - It generates the plaintexts according the two round 3 characteristics.

=> 2_cypherGenerator.sh - It generates the ciphertexts corresponding to the plaintexts genereated by the last program from the game.

=> 3_cleanCipher.py - It reformats the ciphertext generated so that they can be taken as inputs in next program.

=> 4_round3Characteristics.cpp - It applies the two round 3 characteristics to generate the 42 key bits.

=> 5_key_bruteforce.cpp - It generates all possible key values in "key_out.txt" file by bruteforcing all possible values for 14 unknown bits of the key.

=> 6_DES_bruteforce.cpp - It encrypts the plaintext with all possible key values present in "key_out.txt" and then matches the returned cipher with original cipher to identify the original key.

=> 7_decryptDES.cpp - It decrypts the encrypted password message.


