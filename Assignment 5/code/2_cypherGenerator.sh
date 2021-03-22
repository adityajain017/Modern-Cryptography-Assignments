./test1.sh |tee raw_output1.txt

cat raw_output1.txt | grep -A 1 "Slowly, a new text starts appearing on the screen. It reads ..." > raw_output2.txt
cat raw_output2.txt | grep -v "Slowly, a new text starts appearing on the screen. It reads ...\|--" > output1.txt
rm raw_output1.txt raw_output2.txt

# ./test2.sh |tee raw_output1.txt

# cat raw_output1.txt | grep -A 1 "Slowly, a new text starts appearing on the screen. It reads ..." > raw_output2.txt
# cat raw_output2.txt | grep -v "Slowly, a new text starts appearing on the screen. It reads ...\|--" > output2.txt
# rm raw_output1.txt raw_output2.txt

# ./test3.sh |tee raw_output1.txt

# cat raw_output1.txt | grep -A 1 "Slowly, a new text starts appearing on the screen. It reads ..." > raw_output2.txt
# cat raw_output2.txt | grep -v "Slowly, a new text starts appearing on the screen. It reads ...\|--" > output3.txt
# rm raw_output1.txt raw_output2.txt

# ./test4.sh |tee raw_output1.txt

# cat raw_output1.txt | grep -A 1 "Slowly, a new text starts appearing on the screen. It reads ..." > raw_output2.txt
# cat raw_output2.txt | grep -v "Slowly, a new text starts appearing on the screen. It reads ...\|--" > output4.txt
# rm raw_output1.txt raw_output2.txt
