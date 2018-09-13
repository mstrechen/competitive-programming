type bit=0..1;
var hash:bitpacked array[0..100000] of bit;	
	  hash1:bitpacked array[0..100000] of bit;	
	n,m,i,tmp:longint;
BEGIN
fillchar(hash,sizeof(hash),0);
read(n,m);
for i:=1 to n do 
	begin
		read(tmp);
		hash[tmp]:=1;
	end;
for i:=1 to m do 
	begin
		read(tmp);
		hash1[tmp]:=1;
	end;
for i:=0 to 100000 do if hash[i]*hash1[i]=1 then write(i,' ');
END.