// JogodaVelha.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include "Game.h"
#include "Menu.h"

using namespace std;

int main()
{
	int flag=0;
	Game jogo;

	while (flag==0)
	{
		flag = imprimirMenu(&jogo);

		if (flag == 1)
		{

			cout << "O jogador 1 ganhou!!!\nDeseja jogar Novamente?\n**DIGITE 0 PARA JOGAR NOVAMENTE";
			cin >> flag;

		}

		else if (flag == 2)
		{

			cout << "O jogador 2 ganhou!!!\nDeseja jogar Novamente?\n**DIGITE 0 PARA JOGAR NOVAMENTE";
			cin >> flag;
		}
	}
	
	cout << "terminou o jogo\n";
	
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
