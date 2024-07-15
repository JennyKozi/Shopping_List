all: shoprec shopmem shopdp shopmemcosts shopdpcosts

shoprec: shop.o shoprec.o
	gcc -o shoprec shop.o shoprec.o

shopmem: shop.o shopmem.o
	gcc -o shopmem shop.o shopmem.o

shopdp: shop.o shopdp.o
	gcc -o shopdp shop.o shopdp.o

shopmemcosts: shop.c shopmem.c
	gcc -DCOSTS -o shopmemcosts shop.c shopmem.c

shopdpcosts: shop.c shopdp.c
	gcc -DCOSTS -o shopdpcosts shop.c shopdp.c

shop.o: shop.c
	gcc -c -o shop.o shop.c

shoprec.o: shoprec.c
	gcc -c -o shoprec.o shoprec.c

shopmem.o: shopmem.c
	gcc -c -o shopmem.o shopmem.c

shopdp.o: shopdp.c
	gcc -c -o shopdp.o shopdp.c

clean:
	rm -rf shoprec shopmem shopdp shopmemcosts shopdpcosts shop.o shoprec.o shopmem.o shopdp.o