var a:array[-100..100] of longint;
        i,i1,k:longint;
		tmp:shortint;
                max,min:longint;

BEGIN
assign(input, 'INPUT.TXT');reset(input);
read(k);
min:=k;
read(k);
max:=k;
i:=2;
while not eof(input) do
begin
inc(i);
    read(k);
    if(i mod 2 = 0) and(k>max) then max:=k
    else if(i mod 2=1) and(k<min) then min:=k;
end;   close(input);
assign(output, 'OUTPUT.TXT'); rewrite(output);
write(max+min);
close(output);

END.
