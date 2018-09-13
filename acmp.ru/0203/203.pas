var a,b,i:longint;
    s1,s2,tmp:string;
    was:boolean;
BEGIN    { assign(input,'INPUT.TXT'); reset(input);            }
readln(s1);
readln(s2);
if s1<>s2 then begin                                         {close(input);  }
for i:=0 to length(s1)-1 do
begin
tmp:=copy(s1,length(s1),1);
delete(s1,length(s1),1);
s1:=s1+tmp;
 if(s1=s2)  then begin
  write(i);
  was:=true;
 end;
end;                                                         {   assign(output,'OUTPUT.TXT');
                                                            rewrite(output);}
          end
 else write(0);  if was then write(-1);            close(output);

END.
