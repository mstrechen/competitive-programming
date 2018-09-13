var s,sTmp,sNum,sWords:ansistring;
	k,i:longint;
	a:array[1..100005] of longint;
	from,howMuch:longint;
	countWords:longint=0;
	countNums:longint=0;
function isNum(var s:ansistring):boolean;
	var i:longint;
	begin
		isNum:=true;
		if(length(s)=0) then isNum:=false
		else if (length(s)=1) and  (s[1]='0') then isNum:=true
		else if s[1]='0' then isNum:=false
		else for i:=1 to length(s) do 
			if (ord(s[i])<48) or (ord(s[i])>57) then isNum:=false;			
	end;
BEGIN
sNum:='';
sWords:='';
readln(s);
s:=','+s+',';
k:=1;
for i:=1 to length(s) do
	if (s[i]=',') or(s[i]=';') then begin a[k]:=i; k+=1; end;
for i:=2 to k-1 do
		begin
			from:=a[i-1]+1;
			howMuch:= a[i]-a[i-1]-1;
			sTmp:=copy(s,from,howMuch);
			
			if isNum(sTmp) then 
			begin
				if (countNums>0) then  sNum:=sNum+#44+sTmp
				else sNum:=sTmp;
				countNums+=1;	
			end
			else
			begin
				
				if(countWords>0) then  sWords:=sWords+#44+sTmp
				else sWords:=sTmp;
				countWords+=1;
			end;
		end;
if length(sNum)>0 then 
writeln(#34,sNum,#34)
else writeln(#45);
if length(sWords)>0  then
writeln(#34,sWords,#34)
else if(length(sNum)>0) then writeln(#45);
END.