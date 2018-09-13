var m,n, p,q:qword;
	currentX:qword=0;
	currentY:qword=0;
	summOfCrosses:qword=0;
	
function nsd(a,b:qword):qword;
	begin
		while a*b>0 do 
			if a>b then a:=a mod b
			else b:=b mod a;
		nsd:=a+b;
	end;

procedure minimize(var a,b:qword);
	var nsdOfab:qword;
	begin
		nsdOfab:=nsd(a,b);
		a:=a div nsdOfab;
		b:=b div nsdOfab;
	end;

BEGIN
read(m,n,p,q);
if p*q=0 then write(0) else 
	begin
			minimize(p,q);	
			repeat
				currentX+=q;
				currentY+=p;
				summOfCrosses+=currentX div m;
				summOfCrosses+=currentY div n;
				currentX:=currentX mod m;
				currentY:=currentY mod n;
			until currentX+currentY=0;
		write(summOfCrosses-2);
	end;

END.