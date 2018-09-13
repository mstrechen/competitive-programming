var n,i,tmp,count,max:longint;
	a:array[1..1000001] of longint;
	
BEGIN
read(n);
for i:=1 to n do
	begin
		read(tmp);
		a[tmp]:=i;
	end;
a[n+1]:=-1;
count:=1;
max:=1;
for i:=1 to n do
	begin
		if a[i]<a[i+1] then count+=1
		else
			begin
				if count>max then max:=count;
				count:=1;
			end;
	end;
write(n-max);
END.