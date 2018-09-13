var a,b:longint;

operator **(const a,b:longint)r:longint;
	var i,tmp:longint;
	Begin
		tmp:=1;
		for i:=1 to b do 
			tmp*=a;
		r:=tmp;
	End;
BEGIN
read(a,b);

write(a**b);
END.