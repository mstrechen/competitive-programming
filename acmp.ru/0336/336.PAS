var  i,cur,min,max,k:longint;
s:string;

BEGIN
	assign(input, 'INPUT.TXT');reset(input);
	readln(s);
	cur:=1;
	max:=1;
	min:=1;
	for i:=1 to length(s) do
	begin
	if(s[i]='1')then inc(cur)
	else dec(cur);

	if(cur>max)then inc(max)
	else if(cur<min) then dec(min);
	end;
	close(input);
	assign(output, 'OUTPUT.TXT');rewrite(output);

	write(max-min+1);
	close(output);

END.
