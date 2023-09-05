#pragma once
#include<iostream>
#include "Game.h"
#include <Windows.h>

using namespace std;

int imprimirMenu(Game *jogo)
{
	if (jogo->getPlayer1() == 0 && jogo->getPlayer1() == 0)
	{
		jogo->resetTabuleiro();
	}//Caso seja o inicio do jogo preciso reiniciar o tabuleiro

	int l,c;
	system("cls");

	cout << "***Bem vindo ao nosso jogo da velha!!***\n";

	jogo->printTabuleiro();
	cout << "Jogador " << jogo->jogadorTurno() << " digite aonde devemos marcar.\n";
	cout << "***DIGITE A LINHA--> ";
	cin >> l;
	cout << endl << "***DIGITE A COLUNA--> ";
	cin >> c;
	if (jogo->verificarJogada(l, c))//verifica jogada se é possivel e não ferir nenhuma regra do game. Se não for possivel entra no loop
	{
		system("cls");
		cout << "JOGADA INVALIDA!!!\nJOGUE NOVAMENTE!!!\n";
			system("pause");
			imprimirMenu(jogo);
	}
	jogo->jogar(l, c);
	
	if (jogo->conferir() == 0)//Conferir se o alguem ganhou ou se deu velha
	{
		if (jogo->jogadorTurno() == 1)
		{
			jogo->setPlayer1();
			imprimirMenu(jogo);
		}
		else {
			jogo->setPlayer2();
			imprimirMenu(jogo);
		}

	}
	else
	{
		//system("cls");

		jogo->printTabuleiro();

		jogo->resetTabuleiro();
		return jogo->jogadorTurno();
	}
}