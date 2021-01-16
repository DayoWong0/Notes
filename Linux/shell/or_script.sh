#! /bin/sh
touch file1
rm -f file2
if [-f file1] || echo "hello" || [-f file2] || echo "world"
then
    echo "in if"
else
    echo "in else"
fi
exit 0