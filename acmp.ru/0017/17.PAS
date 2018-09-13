var  i,i1,i3,max,k:longint;

BEGIN
assign(input, 'INPUT.TXT');reset(input);
read(i1);
max:=0;
i3:=0;
for i:=1 to i1 do begin
read(k);
if(k>0)then inc(i3)
else if (i3>max) then begin
max:=i3;
i3:=0;
end else i3:=0;
end;
if(i3>max) then max:=i3;
close(input);
assign(output, 'OUTPUT.TXT');rewrite(output);

write(max);
close(output);

END.
