#include <iostream>
#include <cstdlib>
#include <cstring>
#include "head.h"

using namespace std;

int main()
{
    Alunos apont; // apontando
    Pilha *pilha;
    char escolha, op;
    int x = 1, aux = 0;

    pilha = CriarPilha();
    while (x != 0)
    {
        cout << "\n\nO que voce quer fazer?\n"
             << endl;

        cout << "1 - colocar novo item" << endl;
        cout << "2 - remover item" << endl;
        cout<<"3 - Buscar aluno"<<endl;

        cout << "4 - Calcular a media final" << endl;
        cout << "5 -  mostrar a Pilha" << endl;
        cout << "6 - Sair" << endl;

        cin >> escolha;

        switch (escolha)
        {
        case '1':
         
			fflush(stdin);
            cout << "Informe o nome da pessoa a ser inserida na PILHA: ";
            cin.getline(apont.Nome, 50);
            cout << "Idade do aluno: " << endl;
            cin >> apont.idade;
            while (apont.idade < 0 || apont.idade > 100)
            {
                cout << "A idade ta fora do comum. Digite entre 0 a 100" << endl;
                cout << "digite novamente" << endl;
                cin >> apont.idade;
            }
            cout << "Matricula:" << endl;
            cin >> apont.Matricula;

            
                aux = inforAlunoFinal(pilha, apont);
            

            break;
            case '2':

            removerPilhaFinal(pilha);
            
            break;
        case '3':
            			
			buscarMatricula(pilha);
			
            break;
        case '4':
            mediaTotal(pilha);

            break;
        case '5':
            mostrarPilha(pilha);

            break;
        case '6':
            cout << "Obrigado por usar nosso serviço." << endl;
            liberarPilha(pilha);
            exit(0);
            break;
        }
    }
}
