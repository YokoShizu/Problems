
run_test() {
    flags="$1"
    ./s21_cat $flags test_file.txt > s21_cat_output.txt 2> /dev/null
    cat $flags test_file.txt > cat_output.txt 2> /dev/null

   
    if diff s21_cat_output.txt cat_output.txt &> /dev/null; then
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
echo "-E flag:"
if run_test "-E"; then
    ((passed_count++))
else
    ((failed_count++))
fi
echo "-T flag:"
if run_test "-T"; then
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

rm s21_cat_output.txt cat_output.txt
