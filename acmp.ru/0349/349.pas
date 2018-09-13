type myType=0..1;
var isAllOk: bitpacked array[2..1000000] of myType;
		i,j,n,m:longint;
BEGIN
fillchar(isAllOk,sizeof(isAllOk),0);
read(m,n);
for i:=2 to n do
	begin
		if isAllOk[i]=0 then 
		for j:=2 to n div i do
			isAllOk[j*i]:=1;
	end;
j:=0;
for i:=m to n do 
	begin
		if isAllOk[i]=0 then begin writeln(i); j+=1; end;
	end;
if j=0 then writeln('Absent');
END.