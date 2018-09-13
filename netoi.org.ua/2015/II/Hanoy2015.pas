var disks:array[1..64] of qword;
		wasSwaped:boolean;
		n,i:qword;
		j:longint;
		countOfDifferentDisks,lastDisk:qword;
		answer:qword;
procedure swap(var a,b:qword);
	var tmp:qword;
	begin
		tmp:=a;
		a:=b;
		b:=tmp;
	end;
	
BEGIN
	
	read(n);
	for j:=1 to n do read(disks[j]);
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
	for j:=1 to n do
		begin
			if disks[j]<>lastDisk then begin countOfDifferentDisks+=1; lastDisk:=disks[j]; disks[countOfDifferentDisks]:=1 end
			else disks[countOfDifferentDisks]+=1;
		end;
	answer:=0;
	for j:=1 to countOfDifferentDisks do
		answer+=disks[j] << (countOfDifferentDisks-j);
	write(answer);
END.