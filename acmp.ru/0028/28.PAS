var
	n,i,k,z:integer;
  x1,x2,y1,y2,x3,y3: longint;

BEGIN

assign(input,'INPUT.TXT');reset(input);
read(x1,y1,x2,y2,x3,y3);



                  close(input);


assign(output,'OUTPUT.TXT'); rewrite(output);


if(x1=x2) then
    write(2*x1-x3,' ',y3)

else
    write(x3,' ', 2*y1-y3);

END.