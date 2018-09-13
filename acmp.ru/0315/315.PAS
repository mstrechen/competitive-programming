
var a:array[0..255] of boolean;
	n,i:longint;
  s:string;
  impos:boolean;
  sysem: longint;
BEGIN
assign(input,'INPUT.TXT');reset(input);
readln(s);
impos:=false;
close(input);
for i:=1 to length(s) do begin
    a[ord(s[i])]:=true;
    if ((ord(s[i]))<48) or ((ord(s[i]))>90) then impos:=true;
end;


assign(output,'OUTPUT.TXT'); rewrite(output);
for i:=48 to 57 do if(a[i]) then sysem:=i-47;
for i:=65 to 90 do if(a[i]) then sysem:=i-54;
if (sysem=1) then write(2) else
if impos or (s='')  then
   write(-1)
 else write(sysem);


END.