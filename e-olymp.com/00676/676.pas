const sizeOfArray=100;
type vector=record
					x,y: shortint;
					end;
var vectors		: 	array[0..sizeOfArray+1,0..sizeOfArray+1] of vector;
		visited		:	array[0..sizeOfArray+1,0..sizeOfArray+1] of longint;
		n,m,i,j		:	longint;
	tempVector	:	vector = (x:0; y:0);	
countOfCycles: longint = 0;
CurrentBranch: longint = 0;
currX,currY		: longint;
AcurrX,AcurrY		: longint;

BEGIN
	{	x : 1..m
		y : 1..n
	}
	read(n,m);
	for i:=1 to n do
		for j:=1 to m do
			read(vectors[i,j].x, vectors[i,j].y);
	
	for i:=0 to m+1 do 
		begin
			vectors[0,i]:=tempVector;
			vectors[n+1,i]:=tempVector;
		end;
	for i:=0 to n+1 do 
		begin
			vectors[i,0]:=tempVector;
			vectors[i,m+1]:=tempVector;
		end;
	for i:=0 to n+1 do for j:=0 to m+1 do visited[i,j]:=0;
	for i:=1 to n do	
		for j:=1 to m do
			if (visited[i,j]=0) then
				begin
					inc(currentBranch);
					currX:=j;
					currY:=i;
					while (visited[currY,currX]=0) and not ((currX=0) or (currY=0) or (currX=m+1) or (currY=n+1)) do
						begin
							visited[currY,currX]:=currentBranch;
							AcurrX:=currX+vectors[currY,currX].X;
							AcurrY:=currY+vectors[currY,currX].Y;
							currX:=AcurrX;
							currY:=AcurrY;
						end;
					if(visited[currY,currX]=currentBranch) then inc(countOfCycles);
					
				end;
	write(countOfCycles);
END.