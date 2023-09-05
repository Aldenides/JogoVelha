#include"Game.h"

Game::Game()
{
	resetTabuleiro();
	jogadaPlayer1 = 0;
	jogadaPlayer2 = 0;

}

Game::~Game()
{
	delete tabuleiro;
	delete &jogadaPlayer1;
	delete &jogadaPlayer2;

}

void Game::resetTabuleiro()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			this->tabuleiro[i][j] = 0;
		}
	}
}

void Game::printTabuleiro()
{
	for (int i = 0; i < 3; i++)
	{
		cout << "              ";
		for (int j = 0; j < 3; j++)
		{
			cout<<"|" << this->tabuleiro[i][j]
;
		}
		
		cout <<"|" << endl;
	}
}

void Game::resetPlayer1()
{
	this->jogadaPlayer1 = 0;
}

void Game::resetPlayer2()
{
	this->jogadaPlayer2 = 0;
}

void Game::setTabuleiro(int l, int c, int marcador)
{
	tabuleiro[l][c] = marcador;
}

int Game::getPlayer1()
{
	return this->jogadaPlayer1;
}

int  Game::getPlayer2()
{
	return this->jogadaPlayer2;
}

void Game::setPlayer1()
{
	jogadaPlayer1++;
}

void Game::setPlayer2()
{
	jogadaPlayer2++;
}

int Game::jogadorTurno()
{
	int result = (getPlayer1() - getPlayer2()) % 2;
	if (result == 0)
	{
		return 1;
	}

	else
	{
		return 2;
	}

}

int Game::conferir()
{


	if(compararColunas(0, 0, 0) || compararLinhas(0, 0, 0) || compararDiagonais(0,0,0))
	{

		return jogadorTurno();

	}

	return 0;
}

bool Game::verificarJogada(int l, int c)
{
	if (l > 2 || l < 0 || c>2 || c < 0)
	{
		return true;
	}

	if (tabuleiro[l][c] != 0)
	{
		return true;
	}

	return false;
}

bool Game::compararColunas(int l, int c, int flag)
{

	if (this->tabuleiro[l][c] == jogadorTurno()) // Verificando  colunas
	{
		flag++;
		

		if (flag == 3)
		{

			return true;
		}

		else if(l < 3)
		{
			l++;
			compararColunas(l, c, flag);
			
		}


	}

	else if (c <= 2)
	{

		if (c == 2)
		{

			return false;
		}
		flag = 0;
		c++;
		l = 0;
		compararColunas(l, c, flag);
	}


}

bool Game::compararLinhas(int l, int c, int flag)// Verificando  linhas
{

	if (this->tabuleiro[l][c] == jogadorTurno()) 
	{
		flag++;


		if (flag == 3)
		{

			return true;
		}

		if (c < 3)
		{
			c++;
			compararLinhas(l, c, flag);

		}


	}

	else if (l <= 2)
	{
		if (l == 2)
		{
			return false;
		}
		flag = 0;
		l++;
		c = 0;
		compararLinhas(l, c, flag);
	}

}

bool Game::compararDiagonais(int l, int c, int flag)
{

	if (flag >= 0)//verificar da casa 0 0 até 2 2
	{


		if (this->tabuleiro[l][c] == jogadorTurno())
		{
			flag++;

			if (flag == 3)
			{
				return true;
			}

			else
			{
				l++;
				c++;

				compararDiagonais(l, c, flag);
			}

		}
		else
		{
			flag = -1;
			c = 2;
			l = 0;
			compararDiagonais(l, c, flag);
		}

	}

	else if(flag <= 0)
	{
		if (flag == 0 )//essa condicional é para saber se já comparou a primeira diagonal
		{
			flag = -1;
			c = 2;
			l = 0;
			compararDiagonais(l, c, flag);
		}

		else if (this->tabuleiro[l][c] == jogadorTurno())
		{
			flag--;

			if (flag == -4)
			{
				return true;
			}

			else
			{
				
				l++;
				c--;

				compararDiagonais(l, c, flag);
			}

		}

		else
		{
			return false;
		}
	}


}

void Game::jogar(int l, int c)
{
	if (this->jogadorTurno() == 1)
	{
		setTabuleiro(l, c, 1);
		// this->jogadaPlayer1++;
	}

	else
	{
		setTabuleiro(l, c, 2);
		//this->jogadaPlayer2++;
	}
}

