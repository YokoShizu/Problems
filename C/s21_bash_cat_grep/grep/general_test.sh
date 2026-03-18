
echo "Template template" > test1.txt
echo "TeMpLaTe." >> test1.txt
echo "template TEmpLAte template." >> test1.txt
echo "Without this word." >> test1.txt

run_test() {
    flags="$1"
    ./s21_grep $flags test1.txt > s21_grep_output.txt 2> /dev/null
    grep $flags test1.txt > grep_output.txt 2> /dev/null

   
    if diff s21_grep_output.txt grep_output.txt &> test_grep.txt; then
        echo "Passed"
        return 0
    else
        echo "Failed"
        return 1
    fi
}

passed_count=0
failed_count=0

echo "Without flags:"
if run_test "template"; then
    passed_count=$((passed_count + 1))
else
    failed_count=$((failed_count + 1))
fi
echo "-i flag:"
if run_test "-i template"; then
    passed_count=$((passed_count + 1))
else
    failed_count=$((failed_count + 1))
fi
echo "-v flag:"
if run_test "-v template"; then
    passed_count=$((passed_count + 1))
else
    failed_count=$((failed_count + 1))
    
fi
echo "-c flag:"
if run_test "-c template"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-l flag:"
if run_test "-l template"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-n flag:"
if run_test "-n template"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-h flag:"
if run_test "-h template"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-s flag:"
if run_test "-s template"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-o flag:"
if run_test "-o template"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-e flag:"
if run_test "-e template"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-f flag:"
if run_test "-f test1.txt"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-i -v flags APART:"
if run_test "-i -v template"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-i -v flags ALONG:"
if run_test "-vi template"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-i -c flags APART:"
if run_test "-i -c template"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-i -c flags ALONG:"
if run_test "-ic template"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-v -c flags APART:"
if run_test "-v -c template"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-v -c flags ALONG:"
if run_test "-vc template"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-l -n flags APART:"
if run_test "-l -n template"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-l -n flags ALONG:"
if run_test "-ln template"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-h -s flags APART:"
if run_test "-h -s template"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-h -s flags ALONG:"
if run_test "-hs template"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-o -e flags APART:"
if run_test "-o -e template"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-o -e flags ALONG:"
if run_test "-oe template"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-f -i flags APART:"
if run_test "-f test1.txt -i"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-f -i flags ALONG:"
if run_test "-if test1.txt"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-f -v flags APART:"
if run_test "-f test1.txt -v"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-f -v flags ALONG:"
if run_test "-vf test1.txt"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-f -c flags APART:"
if run_test "-f test1.txt -c"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-f -c flags ALONG:"
if run_test "-cf test1.txt"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-f -l flags APART:"
if run_test "-f test1.txt -l"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-f -l flags ALONG:"
if run_test "-lf test1.txt"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-f -n flags APART:"
if run_test "-f test1.txt -n"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-f -n flags ALONG:"
if run_test "-nf test1.txt"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-f -h flags APART:"
if run_test "-f test1.txt -h"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-f -h flags ALONG:"
if run_test "-hf test1.txt"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-f -s flags APART:"
if run_test "-f test1.txt -s"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-f -s flags ALONG:"
if run_test "-sf test1.txt"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-f -o flags APART:"
if run_test "-f test1.txt -o"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-f -o flags ALONG:"
if run_test "-of test1.txt"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi
echo "-f -e flags:"
if run_test "-f test1.txt -e template"; then
    passed_count=$((passed_count + 1))
    
else
    failed_count=$((failed_count + 1))
    
fi

echo "Tests passed: $passed_count"
echo "Tests failed: $failed_count"
