filename=i1xor.txt
ssh -tt student@65.0.124.36 <<ENDSSH
Toddlers
Mohit9638@
4
read
`while read -r line;
do
echo $line
echo 'c'
done <$filename`
back
exit
