for out in *.out
    rm $out
end
for test in *.in
    ./sol.bin < $test > $test.out
end
for test in *.in
    ./tester.bin $test $test.out
    echo '!'
    cat $test.res
    echo
end

