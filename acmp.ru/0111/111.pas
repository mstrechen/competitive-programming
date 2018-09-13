var 	n,i:longint;
BEGIN
read(n);
if n<3 then write(0)
else begin
		i:=3;
		while (n mod i>0) and (i*i<=n)do i+=1;
			
			if n mod i = 0 then  write(i-1)
			else  if (n mod 2 = 0) and (n<>4) then write(n div 2 -1) else write(n-1);
	end;
END.