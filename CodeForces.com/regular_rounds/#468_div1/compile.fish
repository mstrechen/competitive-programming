set CompileSettingsA 'clang++ -O2 -std=c++17 '
set CompileSettingsB ' -o '

for solution in $argv[2..-1]
    eval $CompileSettingsA $solution $CompileSettingsB $solution.out  
end
