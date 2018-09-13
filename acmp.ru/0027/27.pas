var a					:	 array[0..100,0..100] of boolean;
	w,h,n,i,j,k,x1,x2,y1,y2	:	longint;
	res:longint;
BEGIN
fillchar(a,sizeof(a),0);
res:=0;

read(w,h,n);
for i:=1 to n do
	begin
		read(x1,y1,x2,y2);
		for j:=x1 to x2-1 do
			for k:= y1 to y2-1 do	
					a[j+1,k+1]:=true;
				
	end;
for i:=1 to w do begin
	for j:=1 to h do
		if(not a[i,j]) then res+=1; 
		end;
write(res);
END.
//
