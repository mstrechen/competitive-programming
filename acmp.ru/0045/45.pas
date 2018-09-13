var n,i:longint;
	  s:ansistring;
	  a:array[1..9] of longint;
BEGIN
fillchar(a,sizeof(a),0);
i:=2;
s:='';
read(n);
if n=1 then write(1)
else if n=0 then write(10)
else 
	begin
		for i:=9 downto 2 do
			begin
				while (n mod i=0) and (n>1) do
					begin
						n:=n div i;
						a[i]+=1;
					end;
			end;
		if n>1 then writeln(-1)
		else for i:=1 to 9 do
			for n:=1 to a[i] do write(i);
	end;
END.