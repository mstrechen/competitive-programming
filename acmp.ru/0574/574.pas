var a:array[1..20,1..20] of longint;
        n,m,i1,i2:longint;
BEGIN
assign(input,'INPUT.TXT');
reset(input);
read(n,m);
for i1:=1 to n do
for i2:=1 to m do read(a[i1,i2]);
     close(input);
for i1:=2 to m do inc(a[1,i1],a[1,i1-1]);
for i1:=2 to n do inc(a[i1,1],a[i1-1,1]);
for i1:=2 to n do
        for i2:=2 to m do begin
            if a[i1,i2-1]<a[i1-1,i2] then inc(a[i1,i2],a[i1,i2-1])
            else inc(a[i1,i2],a[i1-1,i2]);

        end;            assign(output,'OUTPUT.TXT'); rewrite(output);
        writeln(a[n,m]);                                             close(output);
END.
