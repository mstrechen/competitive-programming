var s:string;
function variants(c:char):longint;
        var a:longint;
        Begin
                case c of
                        '1': a:=7;
                        '0': a:=2;
                        '2': a:=2;
                        '3': a:=3;
                        '4': a:=3;
                        '5': a:=4;
                        '6': a:=2;
                        '7': a:=5;
                        '8': a:=1;
                        '9': a:=2;
                        end;
        variants:=a;
        end;
BEGIN
readln(s);
write(variants(s[1])*variants(s[2]));

END.