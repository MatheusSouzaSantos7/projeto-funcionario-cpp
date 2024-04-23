#include <iostream>
using namespace std;

struct Funcionario
{
  int prontuario;
  string nome;
  double salario;
  Funcionario *prox;
};

Funcionario* init() {
	return NULL;
}

int isEmpty(Funcionario* funcionario) {
	return (funcionario==NULL);
}

// insere o funcionário na lista
Funcionario* insert(Funcionario* funcionario, int prontuario, string nome, double salario) {

    Funcionario* aux;
    aux = funcionario;

    // Se a lista estiver vazia um novo funcionário será criado
    if (isEmpty(funcionario)) {
        Funcionario* novo = new Funcionario();
        novo->prontuario = prontuario;
        novo->nome = nome;
        novo->salario = salario;
        novo->prox = NULL;
        return novo;
    }

    // Caso contrário, terá que ver se o prontuário já existe na lista
    while (aux->prox != NULL && aux->prontuario != prontuario) {
        aux = aux->prox;
    }

    // Se encontrarmos um funcionário com o mesmo prontuário, mostramos uma mensagem de erro
    if (aux->prontuario == prontuario) {
        cout << "Não é possível adicionar esse funcionário, pois esse prontuário já existe!" << endl;
        return funcionario;
    } else {
        // Caso contrário, criamos um novo funcionário e o inserimos no início da lista
        Funcionario* novo = new Funcionario();
        novo->prontuario = prontuario;
        novo->nome = nome;
        novo->salario = salario;
        novo->prox = funcionario;
        return novo;
    }
}

// Remove o funcionário da lista pelo seu prontuário
Funcionario* remove(Funcionario* funcionario, int prontuario) {
    // Se a lista estiver vazia, não há nada para excluir
    if (isEmpty(funcionario)) {
        cout << "Lista vazia, nada para excluir!" << endl;
        return funcionario;
    }

    Funcionario* atual = funcionario;
    Funcionario* anterior = NULL;

    // Procurar o funcionário a ser excluído
    while (atual != NULL && atual->prontuario != prontuario) {
        anterior = atual;
        atual = atual->prox;
    }

    // Se o funcionário não foi encontrado
    if (atual == NULL) {
        cout << "Funcionário não encontrado na lista!" << endl;
        return funcionario;
    }

    // Se o funcionário a ser excluído é o primeiro da lista
    if (anterior == NULL) {
        Funcionario* proximo = atual->prox;
        delete atual;
        return proximo;
    }

    // Se o funcionário a ser excluído não é o primeiro da lista
    anterior->prox = atual->prox;
    delete atual;
    return funcionario;
}




// Mostra a listagem completa de funcionários
void printListagemFuncionarios(Funcionario* funcionario) {
	Funcionario* aux;
	aux = funcionario;
	if (aux == NULL){
	    cout << "Sem funcionários na lista" << endl << endl;
	}
	else{
    	while (aux != NULL) {
            cout << "|-------------------|" << endl;
        	cout << "|Nome: " << aux->nome << endl;
        	cout << "|Prontuário: " << aux->prontuario << endl;
        	cout << "|Salário: " << aux->salario << endl;
        	cout << "|-------------------|" << endl << endl << endl;
        	aux = aux->prox;
    	}
	}
}

// Mostra apenas um funcionário
void printFuncionario(Funcionario* funcionario) {
	Funcionario* aux;
	aux = funcionario;
    cout << "|-------------------|" << endl;
    cout << "|Nome: " << aux->nome << endl;
    cout << "|Prontuário: " << aux->prontuario << endl;
    cout << "|Salário: " << aux->salario << endl;
    cout << "|-------------------|" << endl << endl << endl;
}

// Procura o funcionário pelo prontuário
Funcionario* find(Funcionario* funcionario, int i) {
    Funcionario* aux;
	aux = funcionario;
	while (aux != NULL && aux->prontuario != i) {
		aux = aux->prox;
	}	
	return aux;
}

int main()
{
  Funcionario *funcionario;
  funcionario = init();
  
  int prontuario;
  string nome;
  double salario;
  
  int escolha;
  
  do{
      cout << "Programa de administração de funcionários" << endl;
      cout << "0. Sair" << endl << "1. Incluir" << endl << "2. Excluir" << endl << "3. Pesquisar" << endl << "4. Listar" << endl;
      cin >> escolha;
      cout << endl << endl;
      
      switch (escolha){
       case 0: // Sair
        break;
    
       case 1: // Incluir
       cout << "Digite o nome do funcionário: ";
       cin >> nome;
       
       cout << "Digite o prontuario do funcionário: ";
       cin >> prontuario;
       
       cout << "Digite o salário do funcionário: ";
       cin >> salario;
       
       funcionario = insert(funcionario, prontuario, nome, salario);
       cout << endl << endl;
        break;
    
       case 2: // Excluir
       cout << "Escreva qual prontuário você quer apagar: ";
       cin >> prontuario;
       remove(funcionario, prontuario);
        break;
    
       case 3: // Pesquisar
       cout << "Escreva o prontuário do funcionário:" << endl;
       cin >> prontuario;
       
       if(isEmpty(find(funcionario, prontuario))){
       cout << "Prontuário inválido!" << endl << endl;
       }
       else{
           printFuncionario(find(funcionario, prontuario));
       }
       
        break;
        
       case 4: // Listar
       printListagemFuncionarios(funcionario);
        break;
      
      }
  
  
    }while(escolha != 0);
    return 0;
}
