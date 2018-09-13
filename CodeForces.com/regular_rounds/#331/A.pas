type point=record 
			x,y:longint;
			end;
	
var a:array[1..4] of point;
	i,n:longint;
function max(a,b:longint):longint;
	begin
		if a>=b then max:=a
		else max:=b;
	end;
function min(a,b:longint):longint;
	begin
		if a<=b then min:=a
		else min:=b;
	end;
function max3(a,b,c:longint):longint;
	begin
		max3:=max(max(a,b),c);
	end;
function max4(a,b,c,d:longint):longint;
	begin
		max4:=max(max3(a,b,c),d);
	end;
function min3(a,b,c:longint):longint;
	begin
		min3:=min(min(a,b),c);
	end;
function min4(a,b,c,d:longint):longint;
	begin
		min4:=min(min3(a,b,c),d);
	end;
BEGIN
read(n);
for i:=1 to n do read(a[i].x,a[i].y);
if n=1 then write(-1);
if n=2 then 
	begin
		if (max(a[1].x,a[2].x)<>min(a[1].x,a[2].x)) and (max(a[1].y,a[2].y)<>min(a[1].y,a[2].y)) then begin
				write((max(a[1].x,a[2].x)-min(a[1].x,a[2].x))*((max(a[1].y,a[2].y)-min(a[1].y,a[2].y))));
			end
			else write(-1);
	end;
if n=3 then
	begin
		write((max3(a[1].x,a[2].x,a[3].x)-min3(a[1].x,a[2].x,a[3].x))*(max3(a[1].y,a[2].y,a[3].y)-min3(a[1].y,a[2].y,a[3].y)));
	end;
if n=4 then
	begin
		write((max4(a[1].x,a[2].x,a[3].x,a[4].x)-min4(a[1].x,a[2].x,a[3].x,a[4].x))*((max4(a[1].y,a[2].y,a[3].y,a[4].y)-min4(a[1].y,a[2].y,a[3].y,a[4].y))))
	end;
END.