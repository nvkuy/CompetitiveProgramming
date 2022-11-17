set -e
# code.cpp: name of code file
g++ code.cpp -o code
g++ gen.cpp -o gen
g++ checker.cpp -o brute
for((i = 1; ; ++i)); do
    ./gen $i > inp
    ./code < inp > out
    ./brute < inp > out_ans
    diff -Z out out_ans > /dev/null || break
    echo "Passed test: "  $i
done
echo "WA on the following test:"
cat inp
echo "Your answer is:"
cat out
echo "Correct answer is:"
cat out_ans