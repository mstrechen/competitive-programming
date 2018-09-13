var n,i,l,h:longint;
	summ:qword=0;
	tmp:longint;
BEGIN
	read(n,l,h);
	for i:=1 to n do
		begin
			read(tmp);
			summ+=((n-i)*L+h)*tmp;
		end;
	write(summ*10);
END.