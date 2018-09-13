const sizeOfArray=100000;
var a,b:array[1..sizeOfArray] of longint;
	max:longint;
	n,i:longint;
BEGIN
read(n);
b[1]:=1;
for i:=1 to n do read(a[i]);

for i:=2 to n do if a[i]>=a[i-1] then b[i]:=b[i-1]+1 else b[i]:=1;
max:=b[1];
for i:=2 to n do if b[i]>max then max:=b[i];

write(max);
 END.