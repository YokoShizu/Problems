run_test() {
    flags="$1"

    valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1 \
        ./s21_cat $flags test_file.txt > test_file_cat.txt 2> valgrind.log


    if grep -q "definitely lost: 0 bytes" valgrind.log && \
       grep -q "indirectly lost: 0 bytes" valgrind.log; then
        return 1  # нет утечек → Passed
    else
        echo "Valgrind found leaks for flags: $flags"
        grep "lost" valgrind.log
        return 0  # есть утечки → Failed
    fi
}

passed_count=0
failed_count=0

echo "Without flags:"
if run_test ""; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-s flag:"
if run_test "-s"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-b flag:"
if run_test "-b"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-t flag:"
if run_test "-t"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-e flag:"
if run_test "-e"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi
echo "-v flag:"
if run_test "-v"; then
    passed_count=$((passed_count + 1))
    echo "Passed"
else
    failed_count=$((failed_count + 1))
    echo "Failed"
fi

echo "Tests passed: $passed_count"
echo "Tests failed: $failed_count"