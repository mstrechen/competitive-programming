var
	n,i,k,z:integer;
  impos:boolean;
  sysem: longint;

function iselem(s:integer): boolean;
        var  i1:integer;
begin      if s>1 then begin
           iselem:=true;
   for i1:=2 to n div 2 do if s mod i = 0 then iselem:=false;
                            end
   else iselem:=false;
end;

BEGIN
{assign(input,'INPUT.TXT');reset(input);
}read(n);
{close(input);
}
{assign(output,'OUTPUT.TXT'); rewrite(output);
}

writeln(z,' ', n-z);
END.