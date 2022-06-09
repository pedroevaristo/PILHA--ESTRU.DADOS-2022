#include "head.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

Pilha *CriarPilha()
{
	Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
	if (pilha != NULL)
	{
		pilha->Inicio = NULL;
		pilha->Final = NULL;
	}
	else
	{
		cout << "Erro ao criar pilha";
	}
	return pilha;
}
int tamanhoPilha(Pilha *pilha)
{
	if (pilha == NULL)
	{
		cout << "pilha Vazia!";
		return 0;
	}
	else
	{
		int cont = 0;
		Elemento *no = pilha->Inicio;
		while (no != NULL)
		{
			cont++;
			no = no->Proximo;
		}
		return cont;
	}
}

void buscarMatricula(Pilha *pilha)
{

	int matricula;
	
	Elemento *no = pilha->Final;
		
	cout << "Nome: " << no->Dados.Nome << endl;
	cout << "Idade: " << no->Dados.idade << endl;
	cout << "Matricula: " << no->Dados.Matricula << endl;

	char escolha;
	
	cout<<"Deseja adicionar nota? s ou n?"<<endl;
	
	cin>>escolha;
	
	if(escolha == 's'){
		
			cout << "N1: " << endl;
            cin >> no->Dados.n1;
            while (no->Dados.n1 < 0 || no->Dados.n1 > 10)
            {
                cout << " Tem que ser entre 0 a 10" << endl;
                cout << "digite novamente" << endl;
                cin >> no->Dados.n1;
            }
            cout << "N2 " << endl;
            cin >> no->Dados.n2;
            while (no->Dados.n2 < 0 || no->Dados.n2 > 10)
            {
                cout << "Tem que ser entre 0 a 10" << endl;
                cout << "digite novamente" << endl;
                cin >> no->Dados.n2;
            }
            no->Dados.MF = ((no->Dados.n1 * (0.4)) + (no->Dados.n2 * (0.6)));
			if (no->Dados.MF >= 6)
			{
				strcpy(no->Dados.status, "Aprovado");
			}			
			else
			{
				strcpy(no->Dados.status, "Reprovado");
			}
			cout << "Media Final: " << no->Dados.MF << endl;
			cout << "Status do aluno: " << no->Dados.status << endl;
		
	}else if(escolha == 'n'){
		return;
	}
		
	
}


int inforAlunoFinal(Pilha *pilha, Alunos apont)
{
	if (pilha == NULL)
	{
		return 0;
	}
	else
	{
		Elemento *no = (Elemento *)malloc(sizeof(Elemento));
		if (no == NULL)
		{
			return 0;
		}
		no->Dados = apont;
		no->Proximo = NULL;
		if (pilha->Final == NULL)
		{
			pilha->Inicio = no;
		}
		else
		{
			pilha->Final->Proximo = no;
		}
		pilha->Final = no;
		return 1;
	}
}

int statusVazio(Pilha *pilha)
{
	if (pilha == NULL || pilha->Inicio == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void mostrarPilha(Pilha *pilha)
{
	system("cls");
	if (statusVazio(pilha))
	{
		cout << "Pilha Vazia!";
	}
	else
	{
		int cont = 0;
		Elemento *no = pilha->Inicio;
		while (no != NULL)
		{
			cout << "\n\nDados da Pessoa da Posicao: " << cont + 1 << " na PILHA!" << endl;
			cout << "Nome: " << no->Dados.Nome << endl;
			cout << "Idade: " << no->Dados.idade << endl;
			cout << "Matricula: " << no->Dados.Matricula << endl;
			no = no->Proximo;

			cont++;
		}
	}
}

void mediaTotal(Pilha *pilha)
{
	system("cls");
	if (statusVazio(pilha))
	{
		cout << "Pilha Vazia!";
	}
	else
	{
		int cont = 0;
		float media = 0;
		Elemento *no = pilha->Inicio;
		while (no != NULL)
		{
			media += no->Dados.MF;
			cont += 1;
			no = no->Proximo;
		}
		media = media / cont;
		cout << "\nMedia da turma: " << media << "\n"
			 << endl;
	}
}

void liberarPilha(Pilha *pilha)
{
	if (pilha != NULL)
	{
		Elemento *no;
		while (pilha->Inicio != NULL)
		{
			no = pilha->Inicio;
			pilha->Inicio = pilha->Inicio->Proximo;
			free(no);
		}
		free(pilha);
	}
}

void removerPilhaFinal(Pilha *pilha)
{
	int tam = 0;

	tam = tamanhoPilha(pilha);

	if (tam == 1)
	{
		free(pilha->Inicio);
		pilha->Inicio = NULL;
		pilha->Final = NULL;
	}
	else if (tam >= 2)
	{
		Elemento *no = pilha->Inicio;
		while (no->Proximo->Proximo != NULL)
		{
			no = no->Proximo;
		}

		free(no->Proximo);
		no->Proximo = NULL;
		pilha->Final = no;
	}
}
