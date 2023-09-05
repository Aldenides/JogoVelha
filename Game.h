#pragma once
#include<iostream>
using namespace std;

class Game
{
private:
	int tabuleiro[3][3];
	int jogadaPlayer1;
	int jogadaPlayer2;

public:

	Game();
	~Game();
	
	void resetTabuleiro();
	void printTabuleiro();
	void resetPlayer1();
	void resetPlayer2();
	void setTabuleiro(int l, int c, int marcador);
	int getPlayer1();
	int getPlayer2();
	void setPlayer1();
	void setPlayer2();
	int jogadorTurno();
	int conferir();
	bool verificarJogada(int l, int c);
	bool compararColunas(int l, int c, int flag);
	bool compararLinhas(int l, int c, int flag);
	bool compararDiagonais(int l, int c, int flag);
	void jogar(int l, int c);



};