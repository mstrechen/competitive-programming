 var i,j,k,l,n:longint;
	summ:longint=0;
 BEGIN
read(n);
for i:=3 to n do
	for j:=2 to i do
		for k:=2 to j do
			for l:=1 to k do
				summ+=1;
END.