var a,b,i,j:int64;
BEGIN
 read(a,b);
 j:=0;
 if (a-b=0) then write('infinity')
       else begin
                i:=1;
                while sqr(i)<=a-b do
                        begin
                                if ((a-b) mod i=0) and (i>b) then inc(j);
                                if ((a-b) mod i=0) and ((a-b) div i>b) and ((a-b) div i <>i) then inc(j);
                                inc(i);

                        end;
 write(j); end;
END.
