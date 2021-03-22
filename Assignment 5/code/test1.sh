filename=plaintext.txt
ssh -tt student@65.0.124.36 <<ENDSSH
Toddlers
Mohit9638@
5
go
wave
dive
go
read
`while read -r line;
do
echo $line
echo 'c'
done <$filename`
back
exit
