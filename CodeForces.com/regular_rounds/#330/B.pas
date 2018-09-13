const what=1000000007;
var k,l,i,n,tmp:longint;
		a:array[1..100000] of longint;
		numberOfVariants: int64=1;
		numberOfNumbers:longint;
function pow(n:longint):longint;
	var i:longint;
	begin
		pow:=1;
		for i:=1 to n do pow*=10;
	end;
function howMuch(n,p,k:longint):longint;
	begin
		if p=0 then howMuch:=(pow(k) div n)-(pow(k-1) div n)
		else howMuch:=((pow(k)+1) div n)+(((pow(k-1))*p+1) div n)-((pow(k-1)*(p+1)+1) div n) + 1;
	end;
BEGIN
	read(n,k);
	numberOfNumbers:=pow(k);
	for i:=1 to (n div k) do
		read(a[i]);
	for i:=1 to (n div k) do
		begin
			read(tmp);
			numberOfVariants:=numberOfVariants*howMuch(a[i],tmp,k) mod what;
		end;
	write(numberOfVariants);
END.