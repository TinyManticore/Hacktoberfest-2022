/*
Samila Ellen Garrido Rodrigues - 20210026788
*/
/*
1) Faça um programa em C++ que contenha uma classe que representa um 
funcionário, registrando seu CPF, salário e idade e departamento. 
Crie uma classe que representa uma empresa, registrando seu CNPJ. Em todas
as classes defina os atributos como privados e crie métodos públicos 
para acessar e modificar os atributos. Crie também um método que exiba na 
tela todos os dados do funcionário.

Finalmente, faça um programa que: 
    • Crie uma empresa; 
    • Adicione a empresa 5 funcionários
    • Dê aumento de 10% a todos os funcionários com um determinado valor de 
    departamento.
*/

#include <iostream>
#include <stdio.h>



class Funcionario{
    long cpf;
    float salario;
    int idade;
    int departamento;

public:
    Funcionario(long c, float s, int i, int d): cpf(c), salario(s), idade(i), departamento(d) { 
        printf("=-=-=-=-=-=-=-=\n");
        printf("Funcionario %ld criado com sucesso!\n", cpf);
    
    }
    ~Funcionario(){ 
        printf("=-=-=-=-=-=-=-=\n");
        printf("Funcionario %ld removido com sucesso!\n", cpf);
    }
    
    long get_cpf() { 
        return cpf;
    }
    void set_cpf(long c) { 
        cpf = c;
    }
    float get_salario() {
        return salario;
    }
    void set_salario(float s){
        salario = s;
    }
    int get_idade() {
        return idade;
    }
    void set_idade(int i){
        idade = i;
    }
    int get_departamento() {
        return departamento;
    }
    void set_departamento(int d){
        departamento = d;
    }
    void print(){
        printf("=-=-=-=-=-=-=-=\n");
        printf("Funcionario %ld\n", cpf);
        printf("Salario: %.2f \n", salario);
        printf("Idade: %d \n", idade);
        printf("Departamento: %d \n", departamento);
    }
};

class Empresa{
    long cnpj;
    int qtd_funcionarios;
    Funcionario** funcionarios;

public:
    
    Empresa(long c, int q): cnpj(c), qtd_funcionarios(q) {
        printf("=-=-=-=-=-=-=-=\n");
        printf("Empresa %ld criada com sucesso!\n", cnpj);
        funcionarios = new Funcionario*[qtd_funcionarios];
    }
    ~Empresa(){
        printf("=-=-=-=-=-=-=-=\n");
        printf("Empresa %ld removida com sucesso!\n", cnpj);
        for(int i = 0; i < qtd_funcionarios; i++){
            delete funcionarios[i];
        }
        delete[] funcionarios;
    }
    
    long get_cnpj() { 
        return cnpj;
    }
    void set_cnpj(long c) { 
        cnpj = c;
    }
    int get_qtd_funcionarios() {
        return qtd_funcionarios;
    }
    void set_qtd_funcionarios(int q){
        qtd_funcionarios = q;
    }
    void add_funcionario(Funcionario* f){
        for(int i = 0; i < qtd_funcionarios; i++){
            if(funcionarios[i] == NULL){
                funcionarios[i] = f;
                return;
            }
        }
        printf("=-=-=-=-=-=-=-=\n");
        printf("Empresa %ld sem espaço\n", cnpj);
    }
    void print(){
        printf("=-=-=-=-=-=-=-=\n");
        printf("Empresa %ld\n", cnpj);
        for(int i = 0; i < qtd_funcionarios; i++){
            if(funcionarios[i] != NULL){
                funcionarios[i]->print();
            }
        }
    }
    void aumenta_salario(int departamento, float percentual){
        for(int i = 0; i < qtd_funcionarios; i++){
            if(funcionarios[i] != NULL && funcionarios[i]->get_departamento() == departamento){
                funcionarios[i]->set_salario(funcionarios[i]->get_salario() * (1 + percentual));
            }
        }
    }
};


int main(){
    long cnpj;
    int qtd_funcionarios;
    long cpf;
    float salario;
    int idade;
    int departamento;
    int departamento_aumento;
    float percentual_aumento;
    Empresa* empresa;


    printf("=-=-=-=-=-=-=-=\n");
    printf("Digite o CNPJ da empresa: ");
    scanf("%ld", &cnpj);
    printf("Digite a quantidade de funcionarios: ");
    scanf("%d", &qtd_funcionarios);
    empresa = new Empresa(cnpj, qtd_funcionarios);

    for(int i = 0; i < qtd_funcionarios; i++){
        printf("=-=-=-=-=-=-=-=\n");
        printf("Digite o CPF do funcionario %d: ", i);
        scanf("%ld", &cpf);
        printf("Digite o salario do funcionario %d: ", i);
        scanf("%f", &salario);
        printf("Digite a idade do funcionario %d: ", i);
        scanf("%d", &idade);
        printf("Digite o departamento do funcionario %d: ", i);
        scanf("%d", &departamento);
        empresa->add_funcionario(new Funcionario(cpf, salario, idade, departamento));
    }

    empresa->print();

    printf("=-=-=-=-=-=-=-=\n");
    printf("Digite o departamento para aumento(1, 2, 3, 4, 5): ");
    scanf("%d", &departamento_aumento);
    printf("Digite o percentual de aumento: ");
    scanf("%f", &percentual_aumento);
    empresa->aumenta_salario(departamento_aumento, percentual_aumento);

    empresa->print();

    delete empresa;

    return 0;

}