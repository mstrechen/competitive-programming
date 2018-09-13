procedure qSort(var ar: array of integer);
  procedure sort(var ar: array of integer; low, high: integer);
  var i, j: integer;
      m, wsp: integer;
  begin
     repeat
      i:=low; j:=high; m:=ar[(i+j) div 2];
      repeat
        while ar[i]>m do Inc(i);
        while ar[j]<m do Dec(j);
        if i<=j then begin
          wsp:=ar[i]; ar[i]:=ar[j]; ar[j]:=wsp;
          Inc(i); Dec(j);
         end;
      until i>j;
     if (j - low) < (high - i) then begin
      if low<j then sort(ar, low, j);
     low := i;
       end
     else begin
      if i<high then sort(ar, i, high);
     high := j;
     end;
    until low = high;
  end;
begin
  sort(ar, 0, High(ar));
end;

var a:array[1..1000] of integer;
	n,i:longint;
  summ: longint;
BEGIN
assign(input,'INPUT.TXT');reset(input);
read(n);
summ:=0;
for i:=1 to n do read(a[i]);
close(input);
qsort(a);
for i:=((n-1) div 2 ) + 1 to n do
        begin
            inc(summ, ((a[i]) div 2)+1);
        end;
assign(output,'OUTPUT.TXT'); rewrite(output);
        writeln(summ);

END.