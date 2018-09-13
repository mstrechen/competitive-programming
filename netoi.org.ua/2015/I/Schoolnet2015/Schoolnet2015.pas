var i, n,tmp:longint;
	maxn:longint=1;
	max:longint; 
BEGIN
	read(n);
	read(tmp);
	max:=tmp;
	for i:=2 to n do 
		begin
			read(tmp);
			if tmp>max then begin max:=tmp; maxn:=i; end;
		end;
	write(max+1,' ', maxn);
END.