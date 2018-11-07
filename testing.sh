#basic testing of a submission for pa1-b/cs315001s18
#!/bin/sh
chmod 755 ./a.out
echo "\n running ./a.out < tests-pa1b/in10.txt.... expected 45"
time  ./a.out < tests-pa1b/in10.txt
echo "\n running ./a.out < tests-pa1b/in100.txt.... expected 2464"
time ./a.out < tests-pa1b/in100.txt
echo "\n running ./a.out < tests-pa1b/in10K.txt.... expected 25024837"
time ./a.out < tests-pa1b/in10K.txt
echo "\n running ./a.out < tests-pa1b/in100K.txt.... expected 2501103400"
time ./a.out < tests-pa1b/in100K.txt

echo "\n ....testing completed\n"

