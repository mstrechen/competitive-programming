var x,y,i,x0,y0, summ:longint;
	s:ansistring;
	hash:array[1..500,1..500] of byte;
	
function min(a,b:longint):longint;
	begin
		if a>b then min:=b else min:=a;
	end;
function max(a,b:longint):longint;
	begin
		if a>b then max:=a else max:=b;
	end;

function retX(c:char):longint;
	begin
		case c of
			'U': retX:=-1;
			'D':retX:=1
			else retX:=0;
		end;
	end;
function retY(c:char):longint;
	begin
		case c of
			'R': retY:=1;
			'L':retY:=-1
			else retY:=0;
		end;
	end;
BEGIN
summ:=0;
fillchar(hash,sizeof(hash),0);
readln(x,y,x0,y0);
readln(s);
write(1,' ');
hash[x0,y0]:=1;
for i:=1 to length(s)-1 do
	begin
		x0+=retX(s[i]);
		y0+=retY(s[i]);
		x0:=min(max(1,x0),x);
		y0:=min(max(1,y0),y);
		if hash[x0,y0]=0 then begin write(1,' '); summ+=1; hash[x0,y0]:=1; end
		else write(0,' ');
	end;
write(x*y-summ-1);
END.