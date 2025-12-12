
all : run

test.run :
	$(MAKE) -C test

main.run :
	$(MAKE) -C src

test : test.run
	./test.run

run : test main.run
	./main.run

clean :
	$(MAKE) -C test clean
	$(MAKE) -C src clean
	rm -vf *.run

.PHONY : all test run clean test.run main.run