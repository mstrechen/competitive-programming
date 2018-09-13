type elementaryPart=record
		value, power:longint;
		powerInFactorial:int64;
		end;
var dividersOfNumber:array[1..5] of elementaryPart;
		numberOfElements:longint;
		n, base:longint;
		i, divider:longint;
		currentPow:int64;
		answer:int64;
function isElementary(n:longint):boolean;
		var i:longint;
			isElementaryDouble:boolean;
		begin
			i:=2;
			isElementaryDouble:=true;
			while (isElementaryDouble=true) and (sqr(i)<=n) do
				begin
					if n mod i=0 then isElementaryDouble:=false;
					i+=1;
				end;
			isElementary:=isElementaryDouble;
		end;
function min(a,b:int64):int64;
			begin
				if a>b then min:=b else min:=a;
			end;
BEGIN
	for i:=1 to 5 do
		with dividersOfNumber[i] do
			begin
				value:=0;
				power:=0;
				powerInFactorial:=0;
			end;
	i:=1;
	divider:=2;
	read(n, base);
	while(base>=divider) do	
		begin
			while not isElementary(divider) do
				divider+=1;
			if(base mod divider = 0) then 
			begin 
				if(dividersOfNumber[i].value=divider) then dividersOfNumber[i].power+=1
				else if dividersOfNumber[i].value=0 then with dividersOfNumber[i] do 
					begin
						value:=divider;
						power:=1;
					end
				else begin	
						i+=1;
					with dividersOfNumber[i] do 
						begin
							value:=divider;
							power:=1;
						end
							
					end;
				base:=base div divider;
			end
			else divider+=1;
		end;
	numberOfElements:=i;
	for i:=1 to numberOfElements do
		begin
			currentPow:=dividersOfNumber[i].value;
			while (currentPow<=n) and (n div currentPow>0) do
				begin
					dividersOfNumber[i].powerInFactorial+=n div currentPow;
					currentPow*=dividersOfNumber[i].value;
				end;
		end;

	answer:=dividersOfNumber[1].powerInFactorial div dividersOfNumber[1].power;
	for i:=2 to numberOfElements do answer:=min(answer,dividersOfNumber[i].powerInFactorial div dividersOfNumber[i].power);
	write(answer);

END.