 const sizeOfArray=100000;
type someRecord= record
	money, friendly:longint;
	end;
	myArr=array[1..100000] of someRecord;
 var a:myArr;
 n,d,i:longint;
 currentFriendly, maxFriendly:int64;
 first,last:longint;
 
 procedure HeapSort(var m:myArr; n:longint);
	var i:longint;
		tmp1:someRecord;
	procedure RestoreHeap(father,count:longint);
		var maxson:longint;
			tmp:someRecord;
			BEGIN
				while father<=count div 2 do	
				begin
					if 2*father=count then maxson:=count
					else if M[2*father].money>M[2*father+1].money
						then maxson:=2*father
						else maxson:=2*father+1;
					if M[father].money<M[maxson].money then	
						begin
							tmp:=M[father];
							M[father]:=M[maxson];
							M[maxson]:=tmp;
							father:=maxson;
						end
					else father:=count;
				end;
			END;
	BEGIN
		for i:=n downto 1 do
			RestoreHeap(i,n);
		for i:=n downto 2 do
			begin
				tmp1:=M[1];
				M[1]:=M[i];
				M[i]:=tmp1;
				RestoreHeap(1,i-1)
			end;
	END;

BEGIN
read(n,d);
for i:=1 to n do read(a[i].money, a[i].friendly);
HeapSort(a,n);
maxFriendly:=a[1].friendly;
currentFriendly:=a[1].friendly;
first:=1;
last:=1;
while last<n do	
	begin
	inc(last);
	currentFriendly+=a[last].friendly;
		while (a[last].money-a[first].money>=d)  do
			begin
				currentFriendly-=a[first].friendly;
				first+=1;
			end;
		if currentFriendly>maxFriendly then maxFriendly:=currentFriendly;
	end;
writeln(maxFriendly);

END.