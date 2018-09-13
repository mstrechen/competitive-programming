var
	n,i,k,z:integer;
  s1:string;
  summ:longint;

BEGIN
                summ:=0;
assign(input,'INPUT.TXT');reset(input);
            readln(k);
            for i:=1 to k do begin
                        readln(s1);
                        if(s1[1]=s1[4]) then inc(summ);

            end;



                  close(input);


assign(output,'OUTPUT.TXT'); rewrite(output);
write(summ);


END.