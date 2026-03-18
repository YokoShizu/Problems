
echo "Template template" > test1.txt
echo "TeMpLaTe." >> test1.txt
echo "template TEmpLAte template." >> test1.txt
echo "Without this word." >> test1.txt

run_test() {
    flags="$1"

     valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1 ./s21_grep $flags test1.txt > test_file_grep.txt 2> valgrind.log

    if grep -q "definitely lost: 0 bytes" valgrind.log && \
       grep -q "indirectly lost: 0 bytes" valgrind.log; then
        return 1  # нет утечек
    else
        echo "Valgrind found leaks for flags: $flags"
        grep "lost" valgrind.log
        return 0  # есть утечки
    fi
}

passed_count=0
failed_count=0

echo "Without flags:"
if run_test "template"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-i flag:"
if run_test "-i template"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-v flag:"
if run_test "-v template"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-c flag:"
if run_test "-c template"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-l flag:"
if run_test "-l template"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-n flag:"
if run_test "-n template"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-h flag:"
if run_test "-h template"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-s flag:"
if run_test "-s template"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-o flag:"
if run_test "-o template"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-e flag:"
if run_test "-e template"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-f flag:"
if run_test "-f find.txt"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-i -v flags APART:"
if run_test "-i -v template"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-i -v flags ALONG:"
if run_test "-vi template"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-i -c flags APART:"
if run_test "-i -c template"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-i -c flags ALONG:"
if run_test "-ic template"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-v -c flags APART:"
if run_test "-v -c template"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-v -c flags ALONG:"
if run_test "-vc template"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-l -n flags APART:"
if run_test "-l -n template"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-l -n flags ALONG:"
if run_test "-ln template"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-h -s flags APART:"
if run_test "-h -s template"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-h -s flags ALONG:"
if run_test "-hs template"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-o -e flags APART:"
if run_test "-o -e template"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-o -e flags ALONG:"
if run_test "-oe template"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-f -i flags APART:"
if run_test "-f find.txt -i"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-f -i flags ALONG:"
if run_test "-if find.txt"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-f -v flags APART:"
if run_test "-f find.txt -v"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-f -v flags ALONG:"
if run_test "-vf find.txt"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-f -c flags APART:"
if run_test "-f find.txt -c"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-f -c flags ALONG:"
if run_test "-cf find.txt"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-f -l flags APART:"
if run_test "-f find.txt -l"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-f -l flags ALONG:"
if run_test "-lf find.txt"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-f -n flags APART:"
if run_test "-f find.txt -n"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-f -n flags ALONG:"
if run_test "-nf find.txt"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-f -h flags APART:"
if run_test "-f find.txt -h"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-f -h flags ALONG:"
if run_test "-hf find.txt"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-f -s flags APART:"
if run_test "-f find.txt -s"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-f -s flags ALONG:"
if run_test "-sf find.txt"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-f -o flags APART:"
if run_test "-f find.txt -o"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-f -o flags ALONG:"
if run_test "-of find.txt"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-f -e flags:"
if run_test "-f find.txt -e template"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi

echo "Tests passed: $passed_count"
echo "Tests failed: $failed_count"
