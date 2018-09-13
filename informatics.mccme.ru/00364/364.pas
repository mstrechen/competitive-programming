var n,m,i,j,k,c:longint;
	a:array[1..1000,1..1000] of longint;
	
BEGIN
read(n,m);
c:=0;
for k:=2 to n+m do
	begin
		for i:=1 to n do
			if(k-i>0) and (k-i<=m) then
			begin
				a[i,k-i] := c;
				c:=c+1;
			end;
	end;



for i:=1 to n do
	begin
	for j:=1 to m do
		write(a[i,j],' ');
	writeln();
	end;
END.