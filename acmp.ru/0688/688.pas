var tmpx,tmpy,xs,ys,xd,yd,n,i:longint;
	 hasBeenFound:boolean;	
BEGIN{
	assign(input,'output.txt');
	assign(output,'output.txt');
	reset(input);
	rewrite(output);}
	read(xs,ys,xd,yd,n);
	hasBeenFound:=false;
	for i:=1 to n do
		begin
			read(tmpx,tmpy);
			if((sqr(tmpx-xd)+sqr(tmpy-yd))/4>(sqr(tmpx-xs)+sqr(tmpy-ys)) ) and (not hasBeenFound) then
				begin
					write(i);
					hasBeenFound:=true;
				end;
		end;
	if not hasBeenFound then write('NO');
	{close(input);
	close(output);}
END.