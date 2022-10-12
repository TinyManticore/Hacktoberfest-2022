//PROVA 1 PROGRAMAÇÃO ORIENTADA A OBJETOS
//YHASMIM DE SOUZA TIGRE - 20210026966

//QUESTÂO 1

//biblioteca
#include <iostream>
#include <stdlib.h>

//usaremos encapsulamento para esses comandos, usando-os de forma implicita
using std::cout;
using std::cin;
using std::endl;

/////////////classes////////////

//Uma classe é um tipo de dado definido
//pelo usuário que possui membros de dados e funções de membro

class cliente{ 

    //declarando membros
    long cpf;
    int idade;

public://parte da classe que pode ser acessada mais livremente

    //metodos

    cliente (long c, int i):cpf(c), idade(i) { //metodo construtor
        cout << "cliente" << cpf << "criado!" << endl;
    }
    
    ~cliente(){//metodo destrutor
        cout << "cliente" << cpf << "removido!" << endl;
    }

    //funcoes

    long get_cpf(){//retorna o cpf quando chamado
        return cpf;
    }
    void set_cpf(long c){//metodo de acesso
        cpf = c; 
    }

    int get_idade(){
        return idade;
    }
    void set_idade(int i){
        idade = i;
    }
    

};

///////////////////////

class veiculo{

    int qtd_pass;
    float valor_loc;

public:

    //metodo construtor e destrutor

    veiculo(int q, float v): qtd_pass(q), valor_loc(v){}
    ~veiculo(){}

    //funcoes
    
    int get_qtd_pass(){
        return qtd_pass;
    }
    void set_qtd_pass(int q){
        qtd_pass = q;
    }

    float get_valor_aloc(){
        return valor_loc;
    }
    void set_valor_aloc(float v){
        valor_loc = v;
    }

};

/////////////////////////

class locacao: public cliente, veiculo{//recebe atribuições de cliente (herança)
    int qtd_aloc;

public:

    locacao(int ql, int c, int i, int q, float v):qtd_aloc(ql), cliente(c, i), veiculo(q, v){//construtor
        cout << "locacao criada" << endl;
    }
    
    ~locacao(){//destrutor
        cout << "locacao removida!" << endl;
    }

    //funcoes

    int get_qtd_aloc(){
        return qtd_aloc;
    }
    void set_qtd_aloc(int ql){
        qtd_aloc = ql;        
    }

    //vamos mostrar todos os valores recebidos 

    void printinfo(){
        cout << "quantidade de veiculos alocados: " << qtd_aloc << endl;
        cout << "cpf do cliente 1: " << get_cpf() << endl;
        cout << "cpf do cliente 2: " << get_cpf() << endl;
        cout << "idade do cliente 1: " << get_idade() << endl;
        cout << "idade do cliente 2: " << get_idade() << endl;
        cout << "quantidade de passageiros no veiculo 1: " << get_qtd_pass() << endl;
        cout << "quantidade de passageiros no veiculo 2: " << get_qtd_pass() << endl;
        cout << "=================================" << endl;

    }


};

int main (void){


    long cpf_cliente;
    int idade_cliente;
    int qtd_pass_veiculo;
    float valor_aloc_veiculo;
    int qtd_loc_veiculo;

    //objetos
    locacao* locacao1;
    locacao* locacao2;
    cliente* cliente_aloc; //cliente_aloc é objeto da classe cliente. Um objeto é uma instancia da classe.
    

    cout << "PROVA POO" << endl;
	cout << "====================================" << endl << endl;

    //recebe os inputs do usuário
    cout << "Quantas locacoes deseja fazer? ";
    cin >> qtd_loc_veiculo;
    cout << "Digite o cpf do cliente: ";
    cin >> cpf_cliente;
    cout << "Digite a idade do cliente: ";
    cin >> idade_cliente;
    cout << "qual o valor da alocaçao? ";
    cin >> valor_aloc_veiculo;

    //verificando se o cliente pode alugar
    if (idade_cliente < 18){
        cout << "Cliente não pode alugar por restrição de idade" << endl;
    }
    else{
        cliente_aloc = new cliente(cpf_cliente, idade_cliente);
    }

    cout << "Digite a quantidade de passageiros no veiculo";
    cin >> qtd_pass_veiculo;

    //verificando a quantidade de passageiros
    if (qtd_pass_veiculo > 5){
        cout << "A quantidade maxima de passageiros é 5" << endl;
    }
    else{
        locacao1 = new locacao(qtd_loc_veiculo, cpf_cliente, idade_cliente, qtd_pass_veiculo, valor_aloc_veiculo);
        locacao2 = new locacao(qtd_loc_veiculo, cpf_cliente, idade_cliente, qtd_pass_veiculo, valor_aloc_veiculo);
    }    


    locacao1-> printinfo();
    locacao2-> printinfo();

    
    delete locacao1, locacao2;

    return 0;

}
