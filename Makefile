make:
	@gcc ./"niveau 0"/asm.c
	@./a.out
clean:
	$(RM) */a.out
	$(RM) a.out
	$(RM) */dicke
