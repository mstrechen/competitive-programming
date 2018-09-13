var a,b,i:longint;
BEGIN     assign(input,'INPUT.TXT'); reset(input);
read(a,b);                                         close(input);
while a<>b do if(a>b)then dec(a,b) else dec(b,a);
                                                            assign(output,'OUTPUT.TXT');
                                                            rewrite(output);
for i:=1 to a do write(1);                         close(output);

END.
