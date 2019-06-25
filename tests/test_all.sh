
for ex in ../*;
do
     if [ "$ex" = "../bonus" ]
      then
     echo "NO BONUS"
     elif [ "$ex" = "../tests" ] && [ "$ex" = "../ex03" ] && [ "$ex" = "../ex04" ] && [ "$ex" = "../ex05" ] && [ "$ex" = "../ex06" ]; then
     echo "NO TEST"
     else
     cd $ex
     echo "TEST $ex"
     gcc -o test *.c
     if ./test; then echo "OK exit $?" && rm test;else echo "KO exit $?" ;fi
     echo "test compiled $ex DONE\n"
     fi
done;
