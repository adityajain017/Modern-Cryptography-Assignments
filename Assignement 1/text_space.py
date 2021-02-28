
def text_space(cipher):
	cipher = cipher.split(' ');
	li = []
	for i in cipher:
		if i not in li:
			li.append(i)
			print(i,end=", ")	
		
	print("\n");

cipher = "Mewa wa mey twsam iepjoys gt mey ipbya. Pa xgn iph ayy, meysy wa hgmewhr gt whmysyam wh mey iepjoys. Agjy gt mey kpmys iepjoysa vwkk oy jgsy whmysyamwhr meph mewa ghy! Mey iguy nayu tgs mewa jyaapry wa p awjfky anoamwmnmwgh iwfeys wh vewie uwrwma epby oyyh aewtmyu ox 8 fkpiya. Mey fpaavgsu wa mxSrN03uwdd vwmegnm mey dngmya."

text_space(cipher)

plain = "This is the first chamber of the caves. As you can see, there is nothing of interest in the chamber. Some of the later chambers will be more interesting than this one! The code used for this message is a simple substitution cipher in which digits have been shifted by 8 places. The password is tyRgU03diqq without the quotes."

text_space(plain)
