var
	n,i,k,z:integer;
  impos:boolean;
  sysem: longint;
  summ:real;

BEGIN
assign(input,'INPUT.TXT');reset(input);
read(n);
read(z);
summ:=0;
for i:=2 to n do begin
read(k);
summ:=summ+z+(k-z)/2;
z:=k; end;

                  close(input);


assign(output,'OUTPUT.TXT'); rewrite(output);

   write((summ)/(n-1):10:10);
END.