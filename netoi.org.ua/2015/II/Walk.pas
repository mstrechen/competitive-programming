!!!!!!!!!
!!!!!!!!!
!!!!!!!!!
const modular=1000000007;
var last:qword;
	summ: qword=1;
	i,n:longint;
BEGIN
	last:=1;
	read(n);
	n:=(n-1) div 2;
	for i:=0 to n-1 do
		begin
			last:=(last*2*(2*i+1) div (i+2)) mod modular;
			summ+=last;
			summ:=summ mod modular;
		end;
	if n=0 then write(0)
	else 
	write(summ);
END.
{
НЕДОРАБОТКА МОДУЛЕЙ, ЧИТАТЬ ЕМАКС
}