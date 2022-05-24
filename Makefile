make:
	@gcc ./"niveau 2"/prime.c
	@./a.out
clean:
	$(RM) */a.out
	$(RM) a.out
	$(RM) */dicke