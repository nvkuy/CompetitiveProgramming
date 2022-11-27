set -e
# code.cpp: name of code file
g++ code.cpp -o code
g++ gen.cpp -o gen
g++ checker.cpp -o check
for((i = 1; ; ++i)); do
    ./gen $i > inp
    ./code < inp > out
    ans = ./check < out
    if [$ans == 0]; then break fi
    echo "Passed test: "  $i
done
echo "WA on the following test:"
cat inp
echo "Your answer is:"
cat out