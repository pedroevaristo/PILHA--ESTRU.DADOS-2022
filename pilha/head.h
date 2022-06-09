struct Alunos
{
    char Nome[50];
    int Matricula;
    int idade;
    float n1,n2, MF;//nota1,nota2,media final
    char status[20];
};

struct Elemento{
	Alunos Dados;
	Elemento *Proximo;
};
struct Pilha{
	Elemento *Inicio;
	Elemento *Final;
};



Pilha* CriarPilha();
int statusVazio(Pilha *pilha);
void mostrarPilha(Pilha *pilha);
void mediaTotal(Pilha *pilha);

void buscarMatricula(Pilha *pilha);


int inforAlunoFinal(Pilha *pilha, Alunos apont);

void liberarPilha(Pilha *pilha);


void removerPilhaFinal(Pilha *pilha);
void removerMatricula(Pilha *pilha);

