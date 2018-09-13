var	s:ansistring;
		s1,s2:ansistring;
function max(a,b:ansistring):ansistring;
	begin
		if length(a)>length(b) then max:=a
		else if length(a)<length(b) then max:=b
		else if a>b then max:=a
		else max:=b;
	end;
BEGIN
	readln(s);
	s1:=copy(s,1,pos(' ',s)-1);
	delete(s,1,pos(' ',s));
	s2:=copy(s,1,pos(' ',s)-1);
	delete(s,1,pos(' ',s));
	writeln(max(s,max(s1,s2)));
END.