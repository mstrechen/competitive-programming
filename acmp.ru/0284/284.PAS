var  i,i1,n,k:longint;
a:array[1..1000] of int64;
b:array[1..100,1..2] of longint;

BEGIN
	assign(input, 'INPUT.TXT');reset(input);
	read(n);
		for i:=1 to n do read(a[i]);
	
	read(k);
	for i:=1 to k do read(b[i,1],b[i,2]);
	
	close(input);
	assign(output, 'OUTPUT.TXT');rewrite(output);
	for i:=1 to k do begin
		for i1:=b[i,1] to b[i,2] do write(a[i1],' ');
		end;
	close(output);

END.
