var n:longint;    s:string;
BEGIN
               assign(input,'INPUT.TXT');
               reset(input);

    read(n);
    str(n,s);
    while length(s)<4 do s:='0'+s;
    close(input);
    assign(output,'OUTPUT.TXT');
               rewrite(output);

    
	if (n mod 400=0)or ((n mod 4=0)and(n mod 100<>0)) then write('12/09/',s) else write('13/09/',s);
    close(output);

    END.
  