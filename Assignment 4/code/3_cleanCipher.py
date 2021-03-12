for j in range(1,5):
	f1=open("output"+str(j)+".txt","r")
	f2=open("new_output"+str(j)+".txt","w")
	i=0
	s=""
	while i < 2000:
    		s=f1.readline()
    		s=s.strip()
    		f2.write(s)
    		f2.write("\n")
    		i+=1
	f1.close()
	f2.close()
