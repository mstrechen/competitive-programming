var n:longint; 
begin 
assign(input, 'INPUT.TXT');reset(input); 
readln(n); close(input);
assign(output, 'OUTPUT.TXT'); rewrite(output); 
writeln((n-1)*(n-2));close(output);
end.