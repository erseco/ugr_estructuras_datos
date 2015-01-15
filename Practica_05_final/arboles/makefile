FUENTES = ana_lex.c td_arb_g.c
CC = gcc

ana_lex: ana_lex.o td_arb_g.o
	$(CC) -o ana_lex $(FUENTES:.c=.o)
.c.o: 
	$(CC) -c $(CFLAGS) -o $@ $<
         
