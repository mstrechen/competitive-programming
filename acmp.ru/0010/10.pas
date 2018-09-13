var a,b,c,d:int64;
	i:longint;
BEGIN
read(a,b,c,d);
for i:=-100 to 100 do
	begin
		if(i*i*i*a+i*i*b+i*c+d=0) then write(i,' ');
	end;я
END.