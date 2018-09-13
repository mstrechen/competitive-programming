const ArraySize=1000000;
type SomeArray=array[1..ArraySize] of longint;
var a,b:SomeArray;
	n,i,j:longint;
BEGIN
read(n);
a[1]:=1;
for i:=1 to 2*n+1 do
	begin
		b[1]:=1;
		b[i]:=1;
		for j:=2 to i-1 do b[j]:=(a[j-1]+a[j]) mod 1000000007;
		
		a:=b;
	end;
write(a[n+1]-1);
END.