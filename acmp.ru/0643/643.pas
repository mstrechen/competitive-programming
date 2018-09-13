var n,m,i,j,count,max:longint;	
	s:string;
BEGIN
{
	assign(input,'output.txt');
	assign(output,'output.txt');
	reset(input);
	rewrite(output);}
	readln(n,m);
	max:=1000;
	for i:=1 to n do
		begin
			count:=0;
			readln(s);
			for j:=1 to m do
				if s[j]='.' then inc(count);
			if count<max then max:=count;
		end;
	write(max);
	{close(input);
	close(output);}
END.