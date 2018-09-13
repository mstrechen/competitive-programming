var n, i, alternateN:longint;
	answer:qword=1;
BEGIN
read(n);
alternateN:=n;
if n<5 then write(n)
else begin
	while alternateN mod 3>0 do alternateN-=2;
	for i:=1 to (alternateN div 3) do answer*=3;
	for i:=1 to (n-alternateN) div 2 do answer*=2;
write(answer);
end;
END.