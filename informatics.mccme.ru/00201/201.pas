var n,i:longint;
        f1,f2,f3:longint;
BEGIN
        assign(input,'input.txt');
        reset(input);
        read(n);
        f1:=1;
        f2:=1;
        for i:=3 to n do
                begin
                f3:=f1+f2;

                f1:=f2;
                f2:=f3;
                end;
        close(input);
        assign(output,'output.txt');
        rewrite(output);
        write(f2);
        close(output);
END.