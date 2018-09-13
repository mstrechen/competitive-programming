type oneRecord=record
		k,d,m,y,absol:longint;
		end;
		allRecords=array[1..1500] of oneRecord;
var a:allRecords;
	n:longint;
	i:longint;
procedure swap(var a,b:oneRecord);
	var tmp:oneRecord;
	begin
		tmp:=a;
		a:=b;
		b:=tmp;
	end;
procedure heapSort(var m:allRecords; n:longint);
	var i:longint;
	procedure restoreHeap(father,count:longint);
	var maxson:longint;
	begin
		while father<=count div 2 do
			begin
				if 2*father=count
					then maxson:=count
				else
					if M[2*father].absol>M[2*father+1].absol then maxson:=2*father else maxson:=2*father+1;
				if M[father].absol<M[maxson].absol then
					begin
							swap(M[father], M[maxson]);
							father:=maxson;
					end
					else father:=count;
			end;
	end;
		Begin
			for i:=1 to n do	
				restoreHeap(i,n);
			for i:=n downto 2 do
			begin
				swap(M[1],M[i]);
				restoreHeap(1,i-1);
			end;
		End;
BEGIN
read(n);
for i:=1 to n do
	begin 
		read(a[i].k, a[i].d, a[i].m, a[i].y);
		a[i].absol:=a[i].d+32*(a[i].m+13*a[i].y);
	end;
	HeapSort(a, n);
for i:=1 to n do 
	writeln(a[i].k,' ',a[i].d,' ', a[i].m, ' ', a[i].y);
END.