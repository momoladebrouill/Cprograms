make:
	@gcc ./"niveau 2"/structArray.c
	@./a.out
clean:
	$(RM) */a.out
	$(RM) a.out
	$(RM) */dicke