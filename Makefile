
all : run

test.run :
	make -C test $@

main.run :
	make -C src $@

test : test.run
	./test.run

run : test main.run
	./main.run

clean :
	make -C test clean
	make -C src clean
	rm -vf *.run