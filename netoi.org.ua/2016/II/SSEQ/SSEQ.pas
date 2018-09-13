var n,t,x,i: longint;
    s1 : longint = 0;
    s2 : longint = 0;
    s3 : longint = 0;
BEGIN
    read(n,t);
    for i:= 1 to n do
    begin
        read(x);
        if(x=t+1) then
            s3+=1;
        if(x=t) then
        begin
            if s3>0 then s3-=1;
            s2+=1
        end;
        if(x=t-1) then
        begin
            if s2>0 then s2-=1
            else if s3>0 then s3-=1;
            s1+=1
        end;
    end;
    
    write(s1+s2+s3);
END.