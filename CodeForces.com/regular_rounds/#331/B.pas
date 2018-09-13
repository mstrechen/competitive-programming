type point = record
		x,y:longint;
		end;
myArray=array[0..100001] of point;
var a,a1:myArray;
	i,n:longint;
	b,c,w:array[0..100001] of longint;
	x:array[-100000..100000] of longint;
	current:longint=1;
	max:longint;
function f(a,b:point):boolean;
	begin
		if a.x>b.x then f:=true
		else if a.x=b.x then f:=a.y>b.y else
		f:=false;
	end;

  procedure sort(var ar: myArray; low, high: longint);
  var i, j: longint;
      m, wsp: point;
  begin
      i:=low; j:=high; m:=ar[(i+j) div 2];
      repeat
        while not f(ar[i],m) do Inc(i);    
        while f(ar[j],m) do Dec(j);   
        if i<=j then begin
          wsp:=ar[i]; ar[i]:=ar[j]; ar[j]:=wsp;
          Inc(i); Dec(j);
        end;
      until i>j;
      if low<j then sort(ar, low, j);
      if i<high then sort(ar, i, high);
  end;
BEGIN
	read(n);
	for i:=1 to n do read(a[i].x,a[i].y);
	for i:=1 to n do read(w[i]);
	sort(a,1,n);
	for i:=1 to n do
		begin
			b[i]:=a[i].x-a[i].y;
			if (a[i].x<a[i+1].x) and (a[i].y<a[i+1].y) then 
				begin
					c[current]:=i;
					current+=1;
				end;
		end;
		c[0]:=0;
	for i:=1 to current
		begin
			fillchar(x,0,sizeof(x));
			max:=0;
			for i:=b[c[i-1]+1] to b[c[i]] do
				begin
					x[w[i]]+=1;
					if x[w[i]]>max then 
				end;
		end;
	
END.