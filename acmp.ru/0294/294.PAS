var  i,i1,n,k:longint;
k1,n1, l1, m1, k2,n2,  l2, m2:longint;

BEGIN
	assign(input, 'INPUT.TXT');reset(input);
		read(k1, l1, m1);
		read(k2, l2, m2);
	close(input);
	n1:=k1-((k1*l1) div 100);
	n2:=k2-((k2*l2) div 100);
	k1:=(k1*l1) div 100;
	k2:=(k2*l2) div 100;
	if(n2>n1) then inc(k2,n2-n1)
	else inc(k1,n1-n2);
	assign(output, 'OUTPUT.TXT');rewrite(output);
	write(k1*m1+k2*m2);
	close(output);

END.
