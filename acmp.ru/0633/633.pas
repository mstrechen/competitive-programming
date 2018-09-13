var s1,s2,s3,s4:string;
procedure swapIf(var s1,s2:string);
	var stmp:string;
	begin
		if s1>s2 then
			begin
				stmp:=s1;
				s1:=s2;
				s2:=stmp;
			end;
	end;
BEGIN
{
	assign(input,'output.txt');
	assign(output,'output.txt');
	reset(input);
	rewrite(output);}
	readln(s1);
	readln(s2);
	readln(s3);
	readln(s4);
	swapIf(s2,s3);
	swapIf(s3,s4);
	swapIf(s2,s3);
	writeln(s1,': ',s2,', ',s3,', ',s4)
	{close(input);
	close(output);}
END.