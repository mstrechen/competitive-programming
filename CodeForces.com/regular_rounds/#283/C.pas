type star=array[1..100] of string;
     hsar=array[1..100] of boolean;
var n,m:longint;
    a:star;
    b:hsar;
    i,j:longint;
    num:longint;
function ok(a:star; b:hsar; k,n:longint):boolean;
        var lol:boolean;
        i:longint;
begin
        i:=2;
        lol:=true;
        while (i<=n) and lol do   begin
                if (a[i][k]<a[i-1][k]) and b[i] then lol:=false; inc(i); end;
        ok:=lol;
end;
procedure mkhs(a:star; n,k:longint; var b:hsar);
        var i:longint;
        begin
                for i:=2 to n do if a[i][k]=a[i-1][k] then b[i]:=true
                                                      else b[i]:=false;
        end;

BEGIN
fillchar(b, sizeof(b),true);
num:=0;
readln(n,m);
for i:=1 to n do readln(a[i]);
i:=1;
while i<=m do
        begin
              if not ok(a,b,i,n) then
                      inc(num)
                   else
                      mkhs(a,n,i,b);
              inc(i);
        end;
write(num);
END.