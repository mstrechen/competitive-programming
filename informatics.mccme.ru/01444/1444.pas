var a:array[0..33,0..33] of byte;
	n,m,k,i,j:longint;
	x,y:longint;
BEGIN
read(n,m,k);
for i:=0 to n+1 do
	for j:=0 to m+1 do
		a[i,j]:=0;
for i:=1 to k do 
	begin
		read(x,y);
		a[x,y]:=1;
	end;
for i:=1 to n do
	begin
	for j:=1 to m do
		if(a[i,j]=1) then
		begin
			write('* ');
		end
		else
		begin
			write(a[i-1,j-1]+a[i-1,j+1]+a[i+1,j-1]+a[i+1,j+1]+a[i,j-1]+a[i,j+1]+a[i-1,j]+a[i+1,j],' ');
		end;
	writeln();
	end;
END.