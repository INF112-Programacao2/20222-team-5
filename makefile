all: cassino

cassino: main.o usuario.o jogo.o roleta.o jackpot.o figuras.o MaoBlackjack.o blackjack.o baralho.o
	g++ -o cassino main.o usuario.o jogo.o roleta.o jackpot.o figuras.o MaoBlackjack.o blackjack.o baralho.o

main.o: main.cpp
	g++ -c main.cpp

usuario.o: usuario/usuario.cpp usuario/usuario.h usuario/senhaInvalida.h usuario/limMaxDeCaracteres.h usuario/emailInvalido.h
	g++ -c usuario/usuario.cpp

jogo.o: jogo/jogo.cpp jogo/jogo.h
	g++ -c jogo/jogo.cpp

roleta.o: jogo/roleta/roleta.cpp jogo/roleta/roleta.h
	g++ -c jogo/roleta/roleta.cpp 

jackpot.o: jackpot/jackpot.cpp jackpot/jackpot.h
	g++ -c jackpot/jackpot.cpp

figuras.o: jackpot/figuras.cpp jackpot/figuras.h
	g++ -c jackpot/figuras.cpp

MaoBlackjack.o: blackjack/MaoBlackjack.cpp blackjack/MaoBlackjack.h
	g++ -c blackjack/MaoBlackjack.cpp

blackjack.o: blackjack/blackjack.cpp blackjack/blackjack.h
	g++ -c blackjack/blackjack.cpp

baralho.o: blackjack/baralho.cpp blackjack/baralho.h
	g++ -c blackjack/baralho.cpp

run: cassino
	./cassino
	./cassino.exe

clean: 
	rm *.o cassino.exe cassino