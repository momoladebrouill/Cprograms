make:
	@gcc ./"niveau 1"/matrix.c
	@./a.out
clean:
	$(RM) */a.out
	$(RM) a.out
	$(RM) */dicke
