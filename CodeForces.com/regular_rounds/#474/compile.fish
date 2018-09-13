set CompileSettingsA 'g++ -O2 -Wall -std=c++14'
set CompileSettingsB ' -o '
set extention 'cxx'

for solution in $argv[1..-1]
    eval $CompileSettingsA $solution.$extention $CompileSettingsB $solution.out 
end

