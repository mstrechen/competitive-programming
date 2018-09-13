set CompileSettingsA 'g++ -O2 -Wall'
set CompileSettingsB ' -o '
set extention 'cpp'

for solution in $argv[1..-1]
    eval $CompileSettingsA $solution.$extention $CompileSettingsB $solution.out 
end

