var x1,x2,y1,y2:longint;
r,r1,r2:real;
begin
assign(input,'input.txt');
reset(input);
read(x1,y1,r1,x2,y2,r2);
r:=sqrt(sqr(x1-x2)+sqr(y1-y2));
close(input);
assign(output,'output.txt');
rewrite(output);
if (r1+r2>=r) and (r+r2>=r1) and (r+r1>=r2) then write('YES') else write('NO');
close(input);
end.
