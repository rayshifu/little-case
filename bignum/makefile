ex: ex.o bignum.o vlstack.o rsf_common.o
	cc ex.o bignum.o vlstack.o rsf_common.o -o ex

ex.o: ex.c
	cc -c ex.c

bignum.o:  bignum.c rsf_common.c
	cc -c bignum.c

vlstack.o:  vlstack.c vlstack.h
	cc -c vlstack.c

rsf_common.o: rsf_common.c
	cc -c rsf_common.c

clean:
	rm -rf *.o *.core ex
