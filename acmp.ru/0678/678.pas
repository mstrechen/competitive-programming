var a:array[1..3] of boolean;
    s:string;
    i:longint;
    c:boolean;
BEGIN
a[1]:=true;
a[2]:=false;
a[3]:=false;
assign(input,'INPUT.TXT');
reset(input);
readln(s);
close(input);

for i:=1 to length(s) do CASE s[i] of
         'A': begin c:=a[1]; a[1]:=a[2];a[2]:=c;  end;
         'B': begin c:=a[2]; a[2]:=a[3];a[3]:=c;  end;
         'C':begin c:=a[1]; a[1]:=a[3];a[3]:=c;  end;
        end;
assign(output,'OUTPUT.TXT');
rewrite(output);
        if a[1] then write(1)
        else if a[2] then write(2)
        else write(3);
                            close(output);
END.