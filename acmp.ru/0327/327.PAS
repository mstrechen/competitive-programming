var a:array[-100..100] of longint;
        i,i1,k:longint;
		tmp:shortint;

BEGIN
assign(input, 'INPUT.TXT');reset(input);
read(k);
for i:=1 to k do begin read(tmp); inc(a[tmp]); end;close(input);
assign(output, 'OUTPUT.TXT'); rewrite(output);

for i:=-100 to 100 do 
	for i1:=1 to a[i] do write(i,' ');
close(output);

END.
