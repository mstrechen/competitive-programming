var s:string;
    i,lt,rg,sp: longint;
function check(s:string; lt,rg,sp: longint):boolean;
        var lt1,rg1,sp1:longint;
                lol:boolean;
        begin
        lt1:=0;
        rg1:=0;
        sp1:=0;
        lol:=true;
             for i:=1 to length(s) do begin
                   Case s[i] of
                        '(':inc(lt1);
                        '#':inc(sp1);
                        ')':inc(rg1);
                        end;

              if(sp1<sp) then begin  if(lt1<rg1+sp1) then lol:=false;   end
              else begin if(lt1<lt-rg+rg1) then lol:=false end;

                end;

          check:=lol;
        end;
BEGIN
readln(s);
lt:=0;
rg:=0;
sp:=0;
for i:=1 to length(s) do
      if(s[i]='(') then inc(lt) else if(s[i]=')') then inc(rg) else inc(sp);

if(rg+sp>lt) or (not check(s,lt,rg,sp)) then write(-1)
        else begin for i:=1 to sp-1 do writeln(1);
                     write(lt-sp-rg+1);
                  end;
END.