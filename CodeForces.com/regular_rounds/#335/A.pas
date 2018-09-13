var a,b,c, x,y,z:longint;
		freeSpheres:longint;
function min(a,b:longint):longint;
	begin
		if a>b then min:=b else min:=a;
	end;
function max(a,b:longint):longint;
	begin
		if a>b then max:=a else max:=b;
	end;

BEGIN
 read(a,b,c,x,y,z);
 freeSpheres:=(max(a-x,0) div 2) + (max(b-y,0) div 2)+(max(c-z,0) div 2);
 if min(a-x,0)+min(b-y,0)+min(c-z,0)+freeSpheres>=0 then write('Yes')
 else write('No');
END.