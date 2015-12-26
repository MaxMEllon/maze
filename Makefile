all:
	cd src; make game; make test;

exec:
	cd src; make exec

.PHONY: test
test:
	cd src; make test; ./test.out

.PHONY: clean
clean:
	cd src; make clean;

