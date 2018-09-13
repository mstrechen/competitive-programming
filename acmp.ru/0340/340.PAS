var a1,b1,c1,a2,b2,c2,tmp: longint;

BEGIN assign(input, 'INPUT.TXT');reset(input);
read(a1,b1,c1,a2,b2,c2);
close(input);
if           (a1>b1) then begin
tmp:=a1;
a1:=b1;
b1:=tmp;
end;
if(b1>c1) then begin
tmp:=b1;
b1:=c1;
c1:=tmp;
end;
if           (a1>b1) then begin
tmp:=a1;
a1:=b1;
b1:=tmp;
end;
if(a2>b2) then begin
tmp:=a2;
a2:=b2;
b2:=tmp;
end;
if(b2>c2) then begin
tmp:=b2;
b2:=c2;
c2:=tmp;
end;
if(a2>b2) then begin
tmp:=a2;
a2:=b2;
b2:=tmp;
end;

assign(output, 'OUTPUT.TXT');rewrite(output);
if(a1=a2) and (b1=b2) and (c1=c2) then write('Boxes are equal')
else if(a1>=a2) and (b1>=b2) and(c1>=c2) then write('The first box is larger than the second one')
else if(a2>=a1) and(b2>=b1) and (c2>=c1) then  write('The first box is smaller than the second one')
else write('Boxes are incomparable');
close(output);

END.