
run_test() {
    flags="$1"
    leaks -quiet -atExit -- ./s21_cat $flags test_file.txt > test_s21_cat.log
}

passed_count=0
failed_count=0

echo "Without flags:"
if run_test ""; then
    ((passed_count++))
else
    ((failed_count++))
fi
echo "-s flag:"
if run_test "-s"; then
    ((passed_count++))
else
    ((failed_count++))
fi
echo "-b flag:"
if run_test "-b"; then
    ((passed_count++))
else
    ((failed_count++))
fi
echo "-t flag:"
if run_test "-t"; then
    ((passed_count++))
else
    ((failed_count++))
fi
echo "-e flag:"
if run_test "-e"; then
    ((passed_count++))
else
    ((failed_count++))
fi
echo "-v flag:"
if run_test "-v"; then
    ((passed_count++))
else
    ((failed_count++))
fi

echo "Tests passed: $passed_count"
echo "Tests failed: $failed_count"

rm test_s21_cat.log
