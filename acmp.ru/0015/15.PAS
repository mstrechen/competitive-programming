var a,x,y,i1,i,n1,k1,     d,k:longint;

begin
assign(input,'input.txt');
reset(input);
             read(n1,k1);

close(input);
assign(output,'output.txt');
rewrite(output);
write(((n1-1) div 2) +1);

end.
