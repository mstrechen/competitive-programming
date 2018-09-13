var a_mat,n_mat,i_mat,counter_mat:longint;
function mat_sq(mat_a:longint):boolean;
        begin
                if sqr(int(sqrt(mat_a))) = mat_a then mat_sq:=true
                else mat_sq:=false;
        end;
BEGIN
counter_mat:=0;
read(n_mat);
for i_mat:=1 to n_mat do
        begin
                read(a_mat);
                if mat_sq(a_mat) then inc(counter_mat);
        end;

END.