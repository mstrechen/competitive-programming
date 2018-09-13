var n,m:longint;
	tmp1,tmp2:longint;
	count:longint=0;
	i,j:longint;
BEGIN
read(n,m);
for i:=1 to n do
	for j:=1 to m do
		begin
			read(tmp1);
			read(tmp2);
			if tmp1+tmp2>0 then inc(count);
		end;
write(count);
END.