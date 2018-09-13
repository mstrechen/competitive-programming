var disks:array[1..64] of longint;
		wasSwaped:boolean;
		n,i,j:longint;
		countOfDifferentDisks,lastDisk:longint;
		answer:qword;
procedure swap(var a,b:longint);
	var tmp:longint;
	begin
		tmp:=a;
		a:=b;
		b:=tmp;
	end;
	
BEGIN
	
	read(n);
	for i:=1 to n do read(disks[i]);
	wasSwaped:=true;
	i:=n-1;
	while (i>2) and wasSwaped do
		begin
			wasSwaped:=false;
			for j:=1 to i do 
				if disks[j]>disks[j+1] then
					begin swap(disks[j],disks[j+1]); wasSwaped:=true; end;
		end;
	lastDisk:=0;
	countOfDifferentDisks:=0;
	for i:=1 to n do
		begin
			if disks[i]<>lastDisk then begin countOfDifferentDisks+=1; lastDisk:=disks[i]; disks[countOfDifferentDisks]:=1 end
			else disks[countOfDifferentDisks]+=1;
		end;
	answer:=0;
	for i:=1 to countOfDifferentDisks do
		answer+=disks[i] << (countOfDifferentDisks-i);
	write(answer);
END.