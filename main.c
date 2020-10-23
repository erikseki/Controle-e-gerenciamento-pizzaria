#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <time.h> /*Biblioteca para trabalhar com data */

#define ARQUIVO_PRODUTO "produto.txt"
#define ARQUIVO_CLIENTE "cliente.txt"
#define ARQUIVO_FUNCIONARIO "funcionario.txt"
#define ARQUIVO_FORNECEDOR "fornecedor.txt"
#define ARQUIVO_GASTOS_1 "gastoUnidade1.txt"
#define ARQUIVO_GASTOS_2 "gastoUnidade2.txt"
#define ARQUIVO_GASTOS_3 "gastoUnidade3.txt"
#define ARQUIVO_VENDA_1 "Venda1.txt"
#define ARQUIVO_VENDA_2 "Venda2.txt"
#define ARQUIVO_VENDA_3 "Venda3.txt"
#define SAIR '0'

/**
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
Sistema de gest�o e controle financeiro para uma pizzaria.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
Autores: Gabriel Fernandes Lemos,
Erik Hideyuki Yoshimoto Seki,
Gabriel Franco Garcia Rodrigues de Paula,
Matheus Nunes Nepomuceno,
Clayton Belarmino da Silva,
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
Data de inicio: 01/10/2019
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
**/


char *MenuPrincipal[]={
    "1. Cadastros",
    "2. Vendas",
    "3. Relat�rios",
    "4. Op��es",
    "0. Sair",
    NULL /* ACABARAM AS OP��ES*/
};

char *MenuPrincipalUsuario[]={
    "1. Cadastros",
    "2. Vendas",
    "3. Op��es",
    "0. Sair",
    NULL /* ACABARAM AS OP��ES*/
};

char *MenuCadastro[]={
    "1. Produtos",
    "2. Clientes",
    "3. Funcionarios",
    "4. Fornecedor",
    "5. Gastos",
    "6. Voltar",
    "0. Sair",
    NULL /* ACABARAM AS OP��ES*/
};

char *MenuCadastroUsuario[]={
    "1. Produtos",
    "2. Clientes",
    "3. Fornecedor",
    "4. Voltar",
    "0. Sair",
    NULL /* ACABARAM AS OP��ES*/
};

char *MenuProduto[]={
    "1. Inserir produto",
    "2. Alterar produto",
    "3. Apagar produto",
    "4. Listar produtos",
    "5. Voltar",
    "0. Sair",
    NULL /* ACABARAM AS OP��ES*/
};

char *MenuCliente[]={
    "1. Inserir cliente",
    "2. Alterar cliente",
    "3. Apagar cliente",
    "4. Listar clientes",
    "5. Voltar",
    "0. Sair",
    NULL /* ACABARAM AS OP��ES*/
};

char *MenuFuncionario[]={
    "1. Inserir funcionario",
    "2. Alterar funcionario",
    "3. Apagar funcionario",
    "4. Listar funcionario",
    "5. Voltar",
    "0. Sair",
    NULL /* ACABARAM AS OP��ES*/
};

char *MenuFornecedor[]={
    "1. Inserir fornecedor",
    "2. Alterar fornecedor",
    "3. Apagar fornecedor",
    "4. Listar fornecedor",
    "5. Voltar",
    "0. Sair",
    NULL /* ACABARAM AS OP��ES*/
};

char *MenuVendas[]={
    "1. Gerar nova venda",
    "2. Listar vendas",
    "3. Fazer cancelamento de venda",
    "4. Voltar",
    "0. Sair",
    NULL /* ACABARAM AS OP��ES*/
};

char *MenuOpcoes[]={
    "1. Sobre",
    "2. Manual",
    "3. Voltar",
    NULL /* ACABARAM AS OP��ES*/
};

char *MenuGastos[]={
    "1. Inserir Gastos",
    "2. Alterar Gastos",
    "3. Apagar Gastos",
    "4. Consultar Gastos",
    "5. Voltar",
    NULL
};

char *MenuGastosUnidade[]={
    "1. Unidade 1",
    "2. Unidade 2",
    "3. Unidade 3",
    "4. Voltar",
    NULL
};

char *MenuRelatorios[]={
    "1. Sabores mais vendidos por unidade",
    "2. Faturamento mensal",
    "3. Faturamento total",
    "4. Voltar",
    "0. Sair",
    NULL /* ACABARAM AS OP��ES*/
};


typedef struct Produto{
    char nomeProduto[30];
    int quantidadeProduto;
    float valorPromocaoProduto, valorVendaProduto, valorCustoProduto;
    char status; /* '*' indica que o produto est� apagado*/
}Produto;

typedef struct Cliente{
    char nomeCliente[50],cpfCliente[14], rgCliente[12], celularCliente[14], emailCliente[50], enderecoCliente[100], observacaoCliente[1000];
    char status; /* '*' indica que o produto est� apagado*/
}Cliente;

typedef struct Funcionario{
    float salarioFuncionario;
    char cpfFuncionario[14], rgFuncionario[12], celularFuncionario[13], emailFuncionario[100], enderecoFuncionario[100], nomeFuncionario[100];
    char status; /* '*' indica que o produto est� apagado*/
}Funcionario;

typedef struct Fornecedor{
    char nomeFornecedor[50],cnpjFornecedor[14], rgFornecedor[12], celularFornecedor[14], emailFornecedor[50], enderecoFornecedor[100], observacaoFornecedor[1000];
    char status; /* '*' indica que o produto est� apagado*/
}Fornecedor;

typedef struct Gastos{
    char tipo[50];
    int unidadeGasto;
    float valorGasto;
    char status; /* '*' indica que o produto est� apagado*/
}Gastos;

typedef struct Venda{
    char nomeCliente[30], nomeProduto[30];
    int quantidadeProduto;
    float valorUnitarioProduto, total;
    char status; /* '*' indica que o produto est� apagado*/
}Venda;

FILE *fp; /*vari�vel global pois � �til ao longo do programa*/

/*Vari�veis para trabalhar com vendas*/
Produto ProdutoVendido;
Cliente ClienteEscolhido;
int quantidade;
long int idProdutoVenda;
float total;

/* l� os valores inseridos pelo usu�rio*/
void Ler_Gastos(Gastos *g){
int opcaoDigitada=0;

do{
		system("cls");
	    printf("Escolha uma unidade para inserir o gasto: \n\n 1- Unidade 1 \n 2- Unidade 2 \n 3- Unidade 3  \n");
	    printf ("\n Escolha a op��o (1,2,3): ");
	    scanf("%d",&g->unidadeGasto);
    }while((g->unidadeGasto< 1) || (g->unidadeGasto > 3));
    system("cls");
    printf("Digite o valor dos gastos: ");
    scanf("%f",&g->valorGasto);
    system("cls");
    fflush(stdin);
    printf("Digite o tipo de gasto: ");
    gets(g->tipo);
    system("cls");
   fflush(stdin);
}

void Ler_Produto(Produto *p){
	int opcaoDigitada = 0;

    printf("Digite o nome do produto:   ");
	gets(p->nomeProduto);
	system("cls");

    printf("Digite a quantidade:   ");
	scanf("%d",&p->quantidadeProduto);
	system("cls");

	printf("Digite o valor de custo:   ");
	scanf("%f",&p->valorCustoProduto);
	system("cls");

	printf("Digite o valor de venda:   ");
	scanf("%f",&p->valorVendaProduto);
	system("cls");

	printf("Digite o valor de promo��o (Se n�o houver promo��o repita o valor de venda):   ");
	scanf("%f",&p->valorPromocaoProduto);
	system("cls");

    p->status = ' ';
    fflush(stdin);
}

void Ler_Cliente(Cliente *c){
	printf("Digite o nome do cliente:   ");
	gets(c->nomeCliente);
	system("cls");

	printf("Digite o CPF do cliente:   ");
	gets(c->cpfCliente);
	system("cls");

	printf("Digite o RG do cliente:   ");
	gets(c->rgCliente);
	system("cls");

	printf("Digite o celular do cliente:   ");
	gets(c->celularCliente);
	system("cls");

	printf("Digite o email do cliente:   ");
	gets(c->emailCliente);
	system("cls");

	printf("Digite o endere�o do cliente:   ");
	gets(c->enderecoCliente);
	system("cls");

	printf("Digite o observa��o do cliente:   ");
	gets(c->observacaoCliente);
	system("cls");

	c->status = ' ';
    fflush(stdin);
}

void Ler_Funcionario(Funcionario *f){
	printf("Digite o nome do funcionario:   ");
	gets(f->nomeFuncionario);
	system("cls");

	printf("Digite o CPF do funcionario:   ");
	gets(f->cpfFuncionario);
	system("cls");

	printf("Digite o RG do funcionario:   ");
	gets(f->rgFuncionario);
	system("cls");

	printf("Digite o celular do funcionario:   ");
	gets(f->celularFuncionario);
	system("cls");

	printf("Digite o email do funcionario:   ");
	gets(f->emailFuncionario);
	system("cls");

	printf("Digite o endere�o do funcionario:   ");
	gets(f->enderecoFuncionario);
	system("cls");

	printf("Digite o salario do funcionario:   ");
	scanf("%f",&f->salarioFuncionario);
	system("cls");

	f->status = ' ';
    fflush(stdin);
}

void Ler_Fornecedor(Fornecedor *f){

	printf("Digite o nome do fornecedor:   ");
	gets(f->nomeFornecedor);
	system("cls");

	printf("Digite o CPF/CNPJ do fornecedor:   ");
	gets(f->cnpjFornecedor);
	system("cls");

	printf("Digite o RG do fornecedor:   ");
	gets(f->rgFornecedor);
	system("cls");

	printf("Digite o celular do fornecedor:   ");
	gets(f->celularFornecedor);
	system("cls");

	printf("Digite o email do fornecedor:   ");
	gets(f->emailFornecedor);
	system("cls");

	printf("Digite o endere�o do fornecedor:   ");
	gets(f->enderecoFornecedor);
	system("cls");

	printf("Digite o observa��o do fornecedor:   ");
	gets(f->observacaoFornecedor);
	system("cls");

	f ->status = ' ';
    fflush(stdin);
}

void Atribuir_Valores_Venda(Venda *v){

	strcpy(v->nomeCliente,ClienteEscolhido.nomeCliente);

	strcpy(v->nomeProduto,ProdutoVendido.nomeProduto);

	v->quantidadeProduto = quantidade;

	v->valorUnitarioProduto = ProdutoVendido.valorPromocaoProduto;

	v->total = total;

    v->status = ' ';
    fflush(stdin);
}

/*Mostra na tela os produtos existentes nos arquivos*/
void Mostrar_Gastos(Gastos g){
    printf("Tipo de gasto: %-30s \n",g.tipo);
    printf("Valor do gasto: %10.2f\n",g.valorGasto);
    printf("=-=-=-=-=-=-=-=\n");
}

void Mostrar_Venda(Venda v){
	printf("Cliente: %s \n",v.nomeCliente);
	printf("Produto: %s \n",v.nomeProduto);
	printf("Valor unit�rio: %2.f \n",v.valorUnitarioProduto);
	printf("Quantidade: %d \n", v.quantidadeProduto);
	printf("Total: %2.f\n", v.total);
	printf("-=-=-=-=-=-=-=-=-=-=\n");
}

void Mostrar_Produto(Produto p){
    printf("Nome: %-30s \n",p.nomeProduto);
	printf("Quantidade do produto: %3d \n",p.quantidadeProduto);
	printf("Valor de venda: %10.2f\n",p.valorVendaProduto);
	printf("Valor de custo: %10.2f\n",p.valorCustoProduto);
	printf("Valor de promo��o: %10.2f\n",p.valorPromocaoProduto);
	printf("=-=-=-=-=-=-=\n");
}

void Mostrar_Cliente(Cliente c){
	printf("Nome: %-30s \n",c.nomeCliente);
	printf("CPF: %-30s \n",c.cpfCliente);
	printf("RG: %-30s \n",c.rgCliente);
	printf("Celular: %-30s \n",c.celularCliente);
	printf("Email: %-30s \n",c.emailCliente);
	printf("Endere�o: %-30s \n",c.enderecoCliente);
	printf("Observa��o: %-30s \n",c.observacaoCliente);
	printf("=-=-=-=-=-=-=\n");
}

void Mostrar_Funcionario(Funcionario f){
	printf("Nome: %-30s \n",f.nomeFuncionario);
	printf("CPF: %-30s \n",f.cpfFuncionario);
	printf("RG: %-30s \n",f.rgFuncionario);
	printf("Celular: %-30s \n",f.celularFuncionario);
	printf("Email: %-30s \n",f.emailFuncionario);
	printf("Endere�o: %-30s \n",f.enderecoFuncionario);
	printf("Sal�rio: %10.2f\n",f.salarioFuncionario);
	printf("=-=-=-=-=-=-=\n");
}

void Mostrar_Fornecedor(Fornecedor f){
	printf("Nome: %-30s \n",f.nomeFornecedor);
	printf("CPF/CNPJ: %-30s \n",f.cnpjFornecedor);
	printf("RG: %-30s \n",f.rgFornecedor);
	printf("Celular: %-30s \n",f.celularFornecedor);
	printf("Email: %-30s \n",f.emailFornecedor);
	printf("Endere�o: %-30s \n",f.enderecoFornecedor);
	printf("Observa��o: %-30s \n",f.observacaoFornecedor);
	printf("=-=-=-=-=-=-=\n");
}

/*Adiciona valores ao arquivo*/
void Adiciona_Gasto(Gastos g){
    fseek(fp, 0L, SEEK_END);
    if(fwrite(&g, sizeof(g), 1, fp)!=1)
        printf("Adicionar Gasto: Falhou a escrita de gastos");
}

void Adiciona_Venda(Venda v){
    fseek(fp, 0L, SEEK_END);
    if(fwrite(&v, sizeof(v), 1, fp)!=1)
        printf("Adicionar Venda: Falhou a escrita de venda");
}

void Adiciona_Produto(Produto p){
    fseek(fp, 0L, SEEK_END);
    if(fwrite(&p, sizeof(p), 1, fp)!=1)
        printf("Adicionar Produto: Falhou a escrita do produto");
}

void Adiciona_Cliente(Cliente p){
	fseek(fp, 0L, SEEK_END);
    if(fwrite(&p, sizeof(p), 1, fp)!=1)
        printf("Adicionar Cliente: Falhou a escrita do produto");
}

void Adiciona_Funcionario(Funcionario f){
	fseek(fp, 0L, SEEK_END);
    if(fwrite(&f, sizeof(f), 1, fp)!=1)
        printf("Adicionar funcionario: Falhou a escrita do funcionario");
}

void Adiciona_Fornecedor(Fornecedor f){
	fseek(fp, 0L, SEEK_END);
    if(fwrite(&f, sizeof(f), 1, fp)!=1)
        printf("Adicionar Fornecedor: Falhou a escrita do fornecedor");
}

/*Verificar se o arquivo j� existe. Se n�o existir, ele � criado
se j� existir, abre-o em modo de leitura e escrita (r+b)*/
void AbrirArquivoGastos1(){
    fp=fopen(ARQUIVO_GASTOS_1,"r+b");
    if(fp == NULL){
        fp=fopen(ARQUIVO_GASTOS_1,"w+b");
        if(fp==NULL){
            printf("Erro: Imposs�vel criar arquivo de gastos\n");
            exit(1);
        }
            }

}

void AbrirArquivoGastos2(){
    fp=fopen(ARQUIVO_GASTOS_2,"r+b");
    if(fp == NULL){
        fp=fopen(ARQUIVO_GASTOS_2,"w+b");
        if(fp==NULL){
            printf("Erro: Imposs�vel criar arquivo de gastos\n");
            exit(1);
        }
            }

}

void AbrirArquivoGastos3(){
    fp=fopen(ARQUIVO_GASTOS_3,"r+b");
    if(fp == NULL){
        fp=fopen(ARQUIVO_GASTOS_3,"w+b");
        if(fp==NULL){
            printf("Erro: Imposs�vel criar arquivo de gastos\n");
            exit(1);
        }
            }

}

void AbrirArquivoProduto(){
    fp= fopen(ARQUIVO_PRODUTO, "r+b"); //tentar abrir
    if(fp==NULL){
        fp = fopen(ARQUIVO_PRODUTO, "w+b"); // criar o arquivo
        if(fp==NULL){
            printf("Erro fatal: imposs�vel criar arquivo de produtos\n");
            exit(1);
        }
    }
}

void AbrirArquivoCliente(){
    fp= fopen(ARQUIVO_CLIENTE, "r+b"); //tentar abrir
    if(fp==NULL){
        fp = fopen(ARQUIVO_CLIENTE, "w+b"); // criar o arquivo
        if(fp==NULL){
            printf("Erro fatal: imposs�vel criar arquivo de clientes\n");
            exit(1);
        }
    }
}

void AbrirArquivoFuncionario(){
    fp= fopen(ARQUIVO_FUNCIONARIO, "r+b"); //tentar abrir
    if(fp==NULL){
        fp = fopen(ARQUIVO_FUNCIONARIO, "w+b"); // criar o arquivo
        if(fp==NULL){
            printf("Erro fatal: imposs�vel criar arquivo de funcionario\n");
            exit(1);
        }
    }
}

void AbrirArquivoFornecedor(){
    fp= fopen(ARQUIVO_FORNECEDOR, "r+b"); //tentar abrir
    if(fp==NULL){
        fp = fopen(ARQUIVO_FORNECEDOR, "w+b"); // criar o arquivo
        if(fp==NULL){
            printf("Erro fatal: imposs�vel criar arquivo de fornecedor\n");
            exit(1);
        }
    }
}

void AbrirArquivoVenda1(){
    fp= fopen(ARQUIVO_VENDA_1, "r+b"); //tentar abrir
    if(fp==NULL){
        fp = fopen(ARQUIVO_VENDA_1, "w+b"); // criar o arquivo
        if(fp==NULL){
            printf("Erro fatal: imposs�vel criar arquivo de venda\n");
            exit(1);
        }
    }
}

void AbrirArquivoVenda2(){
    fp= fopen(ARQUIVO_VENDA_2, "r+b"); //tentar abrir
    if(fp==NULL){
        fp = fopen(ARQUIVO_VENDA_2, "w+b"); // criar o arquivo
        if(fp==NULL){
            printf("Erro fatal: imposs�vel criar arquivo de venda\n");
            exit(1);
        }
    }
}

void AbrirArquivoVenda3(){
    fp= fopen(ARQUIVO_VENDA_3, "r+b"); //tentar abrir
    if(fp==NULL){
        fp = fopen(ARQUIVO_VENDA_3, "w+b"); // criar o arquivo
        if(fp==NULL){
            printf("Erro fatal: imposs�vel criar arquivo de venda\n");
            exit(1);
        }
    }
}

/*Exibe a data do dia */
void FuncaoExibirData(){
	time_t mytime;
	mytime = time(NULL);
	struct tm tm = *localtime(&mytime);
	printf("Data de hoje: %d/%d/%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

/* Faz um menu simples com as op��es do vetor de strings.
seleciona a op��o, usando o primeiro caracter de cada string.
devolve o primeiro caracter da op��o.
*/
char FuncoesMenuPrincipal(char *opcoes[]){
    int i;
    char ch;
    while(1){

	    FuncaoExibirData();

        printf("\n\n\n\n\n");
            for(i=0; opcoes[i]!=NULL; i++)
                printf("\t\t%s\n\n",opcoes[i]);

            printf("\n\n\t\tOp��o: ");
            ch = getchar(); fflush(stdin);
            for(i=0; opcoes[i]!= NULL; i++)
                if(opcoes[i][0]==ch)
                    return ch;
    }
}

char FuncoesMenuProduto(char *opcoes[]){
    int i;
    char ch;
    while(1){

    	FuncaoExibirData();

        printf("\n\n\n\n\n");
            for(i=0; opcoes[i]!=NULL; i++)
                printf("\t\t%s\n\n",opcoes[i]);

            printf("\n\n\t\tOp��o: ");
            ch = getchar(); fflush(stdin);
            for(i=0; opcoes[i]!= NULL; i++)
                if(opcoes[i][0]==ch)
                    return ch;
    }
}

char FuncoesMenuCliente(char *opcoes[]){
    int i;
    char ch;
    while(1){

        FuncaoExibirData();

        printf("\n\n\n\n\n");
            for(i=0; opcoes[i]!=NULL; i++)
                printf("\t\t%s\n\n",opcoes[i]);

            printf("\n\n\t\tOp��o: ");
            ch = getchar(); fflush(stdin);
            for(i=0; opcoes[i]!= NULL; i++)
                if(opcoes[i][0]==ch)
                    return ch;
    }
}

char FuncoesMenuFornecedor(char *opcoes[]){
    int i;
    char ch;
    while(1){

        FuncaoExibirData();

        printf("\n\n\n\n\n");
            for(i=0; opcoes[i]!=NULL; i++)
                printf("\t\t%s\n\n",opcoes[i]);

            printf("\n\n\t\tOp��o: ");
            ch = getchar(); fflush(stdin);
            for(i=0; opcoes[i]!= NULL; i++)
                if(opcoes[i][0]==ch)
                    return ch;
    }
}

char FuncoesMenuFuncionario(char *opcoes[]){
    int i;
    char ch;
    while(1){

        FuncaoExibirData();

        printf("\n\n\n\n\n");
            for(i=0; opcoes[i]!=NULL; i++)
                printf("\t\t%s\n\n",opcoes[i]);

            printf("\n\n\t\tOp��o: ");
            ch = getchar(); fflush(stdin);
            for(i=0; opcoes[i]!= NULL; i++)
                if(opcoes[i][0]==ch)
                    return ch;
    }
}

char FuncoesMenuCadastro(char *opcoes[]){
    int i;
    char ch;
    while(1){

        FuncaoExibirData();

        printf("\n\n\n\n\n");
            for(i=0; opcoes[i]!=NULL; i++)
                printf("\t\t%s\n\n",opcoes[i]);

            printf("\n\n\t\tOp��o: ");
            ch = getchar(); fflush(stdin);
            for(i=0; opcoes[i]!= NULL; i++)
                if(opcoes[i][0]==ch)
                    return ch;
    }
}

char FuncoesMenuVendas(char *opcoes[]){
    int i;
    char ch;
    while(1){

        FuncaoExibirData();

        printf("\n\n\n\n\n");
            for(i=0; opcoes[i]!=NULL; i++)
                printf("\t\t%s\n\n",opcoes[i]);

            printf("\n\n\t\tOp��o: ");
            ch = getchar(); fflush(stdin);
            for(i=0; opcoes[i]!= NULL; i++)
                if(opcoes[i][0]==ch)
                    return ch;
    }
}

char FuncoesMenuOpcoes(char *opcoes[]){
    int i;
    char ch;
    while(1){

        FuncaoExibirData();

        printf("\n\n\n\n\n");
            for(i=0; opcoes[i]!=NULL; i++)
                printf("\t\t%s\n\n",opcoes[i]);

            printf("\n\n\t\tOp��o: ");
            ch = getchar(); fflush(stdin);
            for(i=0; opcoes[i]!= NULL; i++)
                if(opcoes[i][0]==ch)
                    return ch;
    }
}

char FuncoesMenuGastos(char *opcoes[]){
int i;
    char ch;
    while(1){

        FuncaoExibirData();

        printf("\n\n\n\n\n");
            for(i=0; opcoes[i]!=NULL; i++)
                printf("\t\t%s\n\n",opcoes[i]);

            printf("\n\n\t\tOp��o: ");
            ch = getchar(); fflush(stdin);
            for(i=0; opcoes[i]!= NULL; i++)
                if(opcoes[i][0]==ch)
                    return ch;
    }
}

char FuncoesMenuRelatorios(char *opcoes[]){
    int i;
    char ch;
    while(1){

        FuncaoExibirData();

        printf("\n\n\n\n\n");
            for(i=0; opcoes[i]!=NULL; i++)
                printf("\t\t%s\n\n",opcoes[i]);

            printf("\n\n\t\tOp��o: ");
            ch = getchar(); fflush(stdin);
            for(i=0; opcoes[i]!= NULL; i++)
                if(opcoes[i][0]==ch)
                    return ch;
    }
}

//Faz o CRUD de produto
void InserirProduto(){
	system("cls");
    Produto x;
    Ler_Produto(&x);
    Adiciona_Produto(x);
}

void AlterarProduto(){
	system("cls");
    Produto x;
    long int id;
    printf("Qual o numero do produto: ");
    scanf("%ld", & id); fflush(stdin);
    if(fseek(fp, (id-1)*sizeof(Produto), SEEK_SET)!=0){
        printf("produto inexistente!!!");
        system("pause");
        return;
    }
    if(fread(&x, sizeof(Produto), 1, fp)!= 1){
        printf("Problemas na leitura do produto!!!");
        system("pause");
        return;
    }

    if(x.status=='*'){
        printf("Um produto apagado n�o pode ser alterado!!! \n\n");
        system("pause");
        return;
    }

    printf("\n\n produtos Atuais \n\n");
    Mostrar_Produto(x);
    printf("\n\n Novos produtos \n\n");
    Ler_Produto(&x);
    // recuar um produto no arquivo
    fseek(fp, -(long) sizeof(Produto), SEEK_CUR);
    // reescrever o produto;
    fwrite(&x, sizeof(Produto), 1, fp);
    fflush(fp); /*despejar os arquivos no disco r�gido*/
    printf("\nProduto alterado com sucesso!\n");
	system("pause");
}

void ApagarProduto(){
	system("cls");
    Produto x;
    long int id;
    char resp;

    printf("Qual o numero do produto: ");
    scanf("%ld", & id); fflush(stdin);
    if(fseek(fp, (id - 1)*sizeof(Produto), SEEK_SET)!= 0){
        printf("produto inexistente ou problemas no produto!!!");
        system("pause");
        return;
    }
    if(fread(&x, sizeof(Produto), 1, fp)!= 1){
        printf("Problema na leitura do produto!!!");
        system("pause");
        return;
    }
    if(x.status=='*'){
        printf("produto j� est� apagado!!!\n\n");
        return;
        system("pause");
    }
    printf("\n\n produtos atuais \n\n");
    Mostrar_Produto(x);
    printf("\n\n Apagar o produto (s/n)???: ");
	resp = getchar();
    fflush(stdin);
    if(toupper(resp)!= 'S')
	return;

    x.status= '*';
    // recuar um produto no arquivo
    fseek(fp, -(long) sizeof(Produto), SEEK_CUR);
    // reescrever o produto;
    fwrite(&x, sizeof(Produto), 1, fp);
    fflush(fp); /*Despejar os arquivos no disco r�gido*/
    system("cls");
	printf("\nProduto exluido com sucesso!\n");
}

void ListarProduto(){
    system("cls");
    Produto reg;
    rewind(fp);
    int cont=0;
    while(1){
        if(fread(&reg, sizeof(reg), 1, fp)!= 1){
		 break; /*Sair do la�o*/
		}else{
			cont=cont+1;
		}
        if(reg.status=='*'){
        	continue; /*Passa ao pr�ximo*/
		}
		printf("ID: %d\n", cont);
        Mostrar_Produto(reg);
    }
}

//Faz inser��o e leitura de venda
void InserirVenda(){
    system("cls");
    Venda v;
    Atribuir_Valores_Venda(&v);
    Adiciona_Venda(v);
}

void ListarVenda(){
    system("cls");
    Venda reg;
    rewind(fp);
    int cont=0;
    while(1){
        if(fread(&reg, sizeof(reg), 1, fp)!= 1){
		 break; /*Sair do la�o*/
		}else{
			cont=cont+1;
		}
        if(reg.status=='*'){
        	continue; /*Passa ao pr�ximo*/
		}
		printf("ID: %d\n", cont);
        Mostrar_Venda(reg);
    }
}

void ApagarVenda(){
	system("cls");
    Venda x;
    long int id;
    char resp;

    printf("Qual o numero da venda: ");
    scanf("%ld", & id); fflush(stdin);
    if(fseek(fp, (id - 1)*sizeof(Venda), SEEK_SET)!= 0){
        printf("Venda inexistente ou problemas na venda!!!");
        system("pause");
        return;
    }
    if(fread(&x, sizeof(Venda), 1, fp)!= 1){
        printf("Problema na leitura da Venda!!!");
        system("pause");
        return;
    }
    if(x.status=='*'){
        printf("Venda j� est� apagada!!!\n\n");
        system("pause");
        return;
    }
    printf("\n\n Vendas atuais \n\n");
    Mostrar_Venda(x);
    printf("\n\n Apagar a venda (s/n)???: "); resp = getchar();
    fflush(stdin);
    if(toupper(resp)!= 'S')return;

    x.status= '*';
    // recuar um Venda no arquivo
    fseek(fp, -(long) sizeof(Venda), SEEK_CUR);
    // reescrever a Venda;
    fwrite(&x, sizeof(Venda), 1, fp);
    fflush(fp); /*Despejar os arquivos no disco r�gido*/
    system("cls");
	printf("\nVenda exluida com sucesso!\n");
}

//Faz inser��o e leitura de gasto
void InserirGasto(){
    system("cls");
    Gastos g;
    Ler_Gastos(&g);
    Adiciona_Gasto(g);
}

void AlterarGasto(){
	system("cls");
    Gastos x;
    long int id;
    printf("Qual o numero de id do gasto: ");
    scanf("%ld", & id); fflush(stdin);
    if(fseek(fp, (id-1)*sizeof(Gastos), SEEK_SET)!=0){
        printf("Gasto inexistente!!!");
        system("pause");
        return;
    }
    if(fread(&x, sizeof(Gastos), 1, fp)!= 1){
        printf("Problemas na leitura de Gastos!!!");
        system("pause");
        return;
    }

    if(x.status=='*'){
        printf("Um gasto apagado n�o pode ser alterado!!! \n\n");
        system("pause");
        return;
    }

    printf("\n\n Gastos Atuais \n\n");
    Mostrar_Gastos(x);
    printf("\n\n Novos Gastos \n\n");
    Ler_Gastos(&x);
    // recuar um produto no arquivo
    fseek(fp, -(long) sizeof(Gastos), SEEK_CUR);
    // reescrever o produto;
    fwrite(&x, sizeof(Gastos), 1, fp);
    fflush(fp); /*despejar os arquivos no disco r�gido*/
    printf("\nGasto alterado com sucesso!\n");
	system("pause");
}

void ApagarGasto(){
	system("cls");
    Gastos x;
    long int id;
    char resp;

    printf("Qual o numero do id do gasto: ");
    scanf("%ld", & id); fflush(stdin);
    if(fseek(fp, (id - 1)*sizeof(Gastos), SEEK_SET)!= 0){
        printf("Gasto inexistente ou problemas nos gastos!!!");
        system("pause");
        return;
    }
    if(fread(&x, sizeof(Gastos), 1, fp)!= 1){
        printf("Problema na leitura do gasto!!!");
        system("pause");
        return;
    }
    if(x.status=='*'){
        printf("Gasto j� est� apagada!!!\n\n");
        system("pause");
        return;
    }
    printf("\n\n Gastos atuais \n\n");
    Mostrar_Gastos(x);
    printf("\n\n Apagar o gasto (s/n)???: "); resp = getchar();
    fflush(stdin);
    if(toupper(resp)!= 'S')return;

    x.status= '*';
    // recuar um Venda no arquivo
    fseek(fp, -(long) sizeof(Gastos), SEEK_CUR);
    // reescrever a Venda;
    fwrite(&x, sizeof(Gastos), 1, fp);
    fflush(fp); /*Despejar os arquivos no disco r�gido*/
    system("cls");
	printf("\nGasto exluido com sucesso!\n");
}

void ListarGasto(){
    system("cls");
    Gastos reg;
    rewind(fp);
    int cont=0;
    while(1){
        if(fread(&reg, sizeof(reg), 1, fp)!= 1){
		 break; /*Sair do la�o*/
		}else{
			cont=cont+1;
		}
        if(reg.status=='*'){
        	continue; /*Passa ao pr�ximo*/
		}
		printf("ID: %d\n", cont);
        Mostrar_Gastos(reg);
    }
}

//Soma todos os gastos de acordo com a unidade escolhida
int CalcularGasto(){
	float valor=0,valorTotalGastos;
	int i,j;
	Gastos x[700];
	rewind (fp);
	do{



		fread(&x,sizeof(x), 1,fp);
		for(i=0;i<50;i++){
		if(x[i].status =='*') {
		continue;}

			if(valor == 0){
				valor == x[i].valorGasto;
			}
			valor= valor + x[i].valorGasto;
		}




	}while(i!=50);
	return (valor);
}
//Faz o CRUD de cliente
void InserirCliente(){
	system("cls");
    Cliente x;
    Ler_Cliente(&x);
    Adiciona_Cliente(x);
}

void AlterarCliente(){
	system("cls");
    Cliente x;
    long int id;
    printf("Qual o numero do cliente: ");
    scanf("%ld", & id); fflush(stdin);
    if(fseek(fp, (id-1)*sizeof(Cliente), SEEK_SET)!=0){
        printf("Cliente inexistente!!!");
        system("pause");
        return;
    }
    if(fread(&x, sizeof(Cliente), 1, fp)!= 1){
        printf("Problemas na leitura do cliente!!!");
        system("pause");
        return;
    }

    if(x.status=='*'){
        printf("Um cliente apagado n�o pode ser alterado!!! \n\n");
        system("pause");
        return;
    }

    printf("\n\n Clientes Atuais \n\n");
    Mostrar_Cliente(x);
    printf("\n\n Novos clientes \n\n");
    Ler_Cliente(&x);
    // recuar um cliente no arquivo
    fseek(fp, -(long) sizeof(Cliente), SEEK_CUR);
    // reescrever o cliente;
    fwrite(&x, sizeof(Cliente), 1, fp);
    fflush(fp); /*despejar os arquivos no disco r�gido*/
    printf("\nCliente alterado com sucesso!\n");
	system("pause");
}

void ApagarCliente(){
	system("cls");
    Cliente x;
    long int id;
    char resp;

    printf("Qual o numero do cliente: ");
    scanf("%ld", & id); fflush(stdin);
    if(fseek(fp, (id - 1)*sizeof(Cliente), SEEK_SET)!= 0){
        printf("Cliente inexistente ou problemas no cliente!!!");
        system("pause");
        return;
    }
    if(fread(&x, sizeof(Cliente), 1, fp)!= 1){
        printf("Problema na leitura do cliente!!!");
        system("pause");
        return;
    }
    if(x.status=='*'){
        printf("Cliente j� est� apagado!!!\n\n");
        return;
        system("pause");
    }
    printf("\n\n Clientes atuais \n\n");
    Mostrar_Cliente(x);
    printf("\n\n Apagar o cliente (s/n)???: "); resp = getchar();
    fflush(stdin);
    if(toupper(resp)!= 'S')return;

    x.status= '*';
    // recuar um cliente no arquivo
    fseek(fp, -(long) sizeof(Cliente), SEEK_CUR);
    // reescrever o cliente;
    fwrite(&x, sizeof(Cliente), 1, fp);
    fflush(fp); /*Despejar os arquivos no disco r�gido*/
    system("cls");
	printf("\nCliente exluido com sucesso!\n");
}

void ListarCliente(){
    system("cls");
    Cliente reg;
    rewind(fp);
    int cont=0;
    while(1){
        if(fread(&reg, sizeof(reg), 1, fp)!= 1){
		 break; /*Sair do la�o*/
		}else{
			cont=cont+1;
		}
        if(reg.status=='*'){
        	continue; /*Passa ao pr�ximo*/
		}
		printf("ID: %d\n", cont);
        Mostrar_Cliente(reg);
    }
}

//Faz CRUD de funcionario
void InserirFuncionario(){
	system("cls");
    Funcionario x;
    Ler_Funcionario(&x);
    Adiciona_Funcionario(x);
}

void AlterarFuncionario(){
	system("cls");
    Funcionario x;
    long int id;
    printf("Qual o numero do funcionario: ");
    scanf("%ld", & id); fflush(stdin);
    if(fseek(fp, (id-1)*sizeof(Funcionario), SEEK_SET)!=0){
        printf("Funcionario inexistente!!!");
        system("pause");
        return;
    }
    if(fread(&x, sizeof(Funcionario), 1, fp)!= 1){
        printf("Problemas na leitura do funcionario!!!");
        system("pause");
        return;
    }

    if(x.status=='*'){
        printf("Um funcionario apagado n�o pode ser alterado!!! \n\n");
        system("pause");
        return;
    }

    printf("\n\n Funcionarios Atuais \n\n");
    Mostrar_Funcionario(x);
    printf("\n\n Novos funcionario \n\n");
    Ler_Funcionario(&x);
    // recuar um funcionario no arquivo
    fseek(fp, -(long) sizeof(Funcionario), SEEK_CUR);
    // reescrever o funcionario;
    fwrite(&x, sizeof(Funcionario), 1, fp);
    fflush(fp); /*despejar os arquivos no disco r�gido*/
    printf("\nFuncionario alterado com sucesso!\n");
	system("pause");
}

void ApagarFuncionario(){
	system("cls");
    Funcionario x;
    long int id;
    char resp;

    printf("Qual o numero do funcionario: ");
    scanf("%ld", & id); fflush(stdin);
    if(fseek(fp, (id - 1)*sizeof(Funcionario), SEEK_SET)!= 0){
        printf("Funcionario inexistente ou problemas no funcion�rio!!!");
        system("pause");
        return;
    }
    if(fread(&x, sizeof(Funcionario), 1, fp)!= 1){
        printf("Problema na leitura do funcionario!!!");
        system("pause");
        return;
    }
    if(x.status=='*'){
        printf("Funcionario j� est� apagado!!!\n\n");
        return;
        system("pause");
    }
    printf("\n\n Funcionarios atuais \n\n");
    Mostrar_Funcionario(x);
    printf("\n\n Apagar o funcionario (s/n)???: "); resp = getchar();
    fflush(stdin);
    if(toupper(resp)!= 'S')return;

    x.status= '*';
    // recuar um funcionario no arquivo
    fseek(fp, -(long) sizeof(Funcionario), SEEK_CUR);
    // reescrever o funcionario;
    fwrite(&x, sizeof(Funcionario), 1, fp);
    fflush(fp); /*Despejar os arquivos no disco r�gido*/
    system("cls");
	printf("\nFuncionario exluido com sucesso!\n");
}

void ListarFuncionario(){
    system("cls");
    Funcionario reg;
    rewind(fp);
    int cont=0;
    while(1){
        if(fread(&reg, sizeof(reg), 1, fp)!= 1){
		 break; /*Sair do la�o*/
		}else{
			cont=cont+1;
		}
        if(reg.status=='*'){
        	continue; /*Passa ao pr�ximo*/
		}
		printf("ID: %d\n", cont);
        Mostrar_Funcionario(reg);
    }
}

//Faz CRUD de fornecedor
void InserirFornecedor(){
	system("cls");
    Fornecedor x;
    Ler_Fornecedor(&x);
    Adiciona_Fornecedor(x);
}

void AlterarFornecedor(){
	system("cls");
    Fornecedor x;
    long int id;
    printf("Qual o numero do fornecedor: ");
    scanf("%ld", & id); fflush(stdin);
    if(fseek(fp, (id-1)*sizeof(Fornecedor), SEEK_SET)!=0){
        printf("Fornecedor inexistente!!");
        system("pause");
        return;
    }
    if(fread(&x, sizeof(Fornecedor), 1, fp)!= 1){
        printf("Problemas na leitura do fornecedor!!!");
        system("pause");
        return;
    }

    if(x.status=='*'){
        printf("Um fornecedor apagado n�o pode ser alterado!!! \n\n");
        system("pause");
        return;
    }

    printf("\n\n Fornecedor Atuais \n\n");
    Mostrar_Fornecedor(x);
    printf("\n\n Novos fornecedores \n\n");
    Ler_Fornecedor(&x);
    // recuar um fornecedor no arquivo
    fseek(fp, -(long) sizeof(Fornecedor), SEEK_CUR);
    // reescrever o fornecedor;
    fwrite(&x, sizeof(Fornecedor), 1, fp);
    fflush(fp); /*despejar os arquivos no disco r�gido*/
    printf("\nFornecedor alterado com sucesso!\n");
	system("pause");
}

void ApagarFornecedor(){
	system("cls");
    Fornecedor x;
    long int id;
    char resp;

    printf("Qual o numero do Fornecedor: ");
    scanf("%ld", & id); fflush(stdin);
    if(fseek(fp, (id - 1)*sizeof(Fornecedor), SEEK_SET)!= 0){
        printf("Fornecedor inexistente ou problemas no cliente!!!");
        system("pause");
        return;
    }
    if(fread(&x, sizeof(Fornecedor), 1, fp)!= 1){
        printf("Problema na leitura do fornecedor!!!");
        system("pause");
        return;
    }
    if(x.status=='*'){
        printf("Fornecedor j� est� apagado!!!\n\n");
        return;
        system("pause");
    }
    printf("\n\n Fornecedor atuais \n\n");
    Mostrar_Fornecedor(x);
    printf("\n\n Apagar o fornecedor (s/n)???: "); resp = getchar();
    fflush(stdin);
    if(toupper(resp)!= 'S')return;

    x.status= '*';
    // recuar um fornecedor no arquivo
    fseek(fp, -(long) sizeof(Fornecedor), SEEK_CUR);
    // reescrever o fornecedor;
    fwrite(&x, sizeof(Fornecedor), 1, fp);
    fflush(fp); /*Despejar os arquivos no disco r�gido*/
    system("cls");
	printf("\nFornecedor exluido com sucesso!\n");
}

void ListarFornecedor(){
    system("cls");
    Fornecedor reg;
    rewind(fp);
    int cont=0;
    while(1){
        if(fread(&reg, sizeof(reg), 1, fp)!= 1){
		 break; /*Sair do la�o*/
		}else{
			cont=cont+1;
		}
        if(reg.status=='*'){
        	continue; /*Passa ao pr�ximo*/
		}
		printf("ID: %d\n", cont);
        Mostrar_Fornecedor(reg);
    }
}

/*Exibe mensagem de despedida ao sair do programa*/
void msgSair(){
	system("cls");
	printf("Obrigado por utilizar nosso software.\n\nTenha um bom dia! :D\n\n");
	exit(1);
}

void login(){
    char senharecebida[10],loginrecebido[10],opcao;
    char loginmaster[6]="admin";
    char senhamaster[6]="admin";
    char loginpadrao[10]="user";
    char senhapadrao[10]="user";



        do{
            printf("\n Login: ");
            scanf("%s",&loginrecebido);
            fflush(stdin);
            printf("\n Senha: ");
             scanf("%s",&senharecebida);
             fflush(stdin);


            if(strcmp(loginrecebido,loginmaster)==0&&strcmp(senharecebida,senhamaster)==0){
                    return;


            }else{
            if(strcmp(loginrecebido,loginpadrao)==0&& strcmp(senharecebida,senhapadrao)==0){
                MenuPrincipalUsuario: //GOTO
                    system("cls");
    while((opcao = FuncoesMenuPrincipal(MenuPrincipalUsuario))!= SAIR)
    switch(opcao){

        case '1':
            	system("cls");
            	MenuCadastroUsuario: //GOTO
				//Menu Cadastro
				while((opcao = FuncoesMenuCadastro(MenuCadastroUsuario))!= SAIR)
        		switch(opcao){
		            case '1':
		            	system("cls");
		            	//Menu Produto
		            	AbrirArquivoProduto();
						while((opcao = FuncoesMenuProduto(MenuProduto))!= SAIR)
				        switch(opcao){

				            case '1':
								InserirProduto();
								system("cls");
								printf("\nProduto inserido com sucesso!\n");
				    			system("pause");
				    			system("cls");
								break;
				            case '2':
								AlterarProduto();
				    			system("cls");
								break;
				            case '3':
								ApagarProduto();
				    			system("pause");
				    			system("cls");
								break;
				            case '4':
								ListarProduto();
								system("pause");
								system("cls");
								break;
							case '5':
								system("cls");
		            			goto MenuCadastroUsuario;
								break;

				        }
				        msgSair();
				        break;
		            case '2':
						system("cls");
		            	//Menu Cliente
		            	AbrirArquivoCliente();
						while((opcao = FuncoesMenuCliente(MenuCliente))!= SAIR)
				        switch(opcao){

				            case '1':
								InserirCliente();
								system("cls");
								printf("\nCliente inserido com sucesso!\n");
				    			system("pause");
				    			system("cls");
								break;
				            case '2':
								AlterarCliente();
				    			system("cls");
								break;
				            case '3':
								ApagarCliente();
				    			system("pause");
				    			system("cls");
								break;
				            case '4':
								ListarCliente();
								system("pause");
								system("cls");
								break;
							case '5':
								system("cls");
		            			goto MenuCadastroUsuario;
								break;
				        }
				        msgSair();
				        break;

		            case '3':
		            	system("cls");
		            	//Menu Fornecedor
		            	AbrirArquivoFornecedor();
						while((opcao = FuncoesMenuFornecedor(MenuFornecedor))!= SAIR)
				        switch(opcao){

				            case '1':
								InserirFornecedor();
								system("cls");
								printf("\nFornecedor inserido com sucesso!\n");
				    			system("pause");
				    			system("cls");
								break;
				            case '2':
								AlterarFornecedor();
				    			system("cls");
								break;
				            case '3':
								ApagarFornecedor();
				    			system("pause");
				    			system("cls");
								break;
				            case '4':
								ListarFornecedor();
								system("pause");
								system("cls");
								break;
							case '5':
								system("cls");
		            			goto MenuCadastroUsuario;
								break;

				        }
                    case '4':
                        system("cls");
                        goto MenuPrincipalUsuario;
                        break;
        		}

				        msgSair();
				        break;

            case '2':
            	system("cls");
            	int unidadeVendaProduto;
				while((opcao = FuncoesMenuVendas(MenuVendas))!= SAIR)
        		switch(opcao){
        			case '1':
        				MontarVenda();
        				break;
        			case '2':
        				do{
							system("cls");
					    	printf("Escolha uma unidade de venda: \n\n 1- Unidade 1 \n 2- Unidade 2 \n 3- Unidade 3  \n");
					    	printf ("\n Escolha a op��o (1,2,3): ");
					    	scanf("%d",&unidadeVendaProduto);
				    	}while((unidadeVendaProduto < 1 ) || (unidadeVendaProduto > 3));

				    	switch (unidadeVendaProduto){
				    		case 1:
				    			AbrirArquivoVenda1();
				    			ListarVenda();
				    			system("pause");
                                system("cls");
                                fflush(stdin);
                                fclose(fp);
				    			break;
				    		case 2:
				    			AbrirArquivoVenda2();
				    			ListarVenda();
				    			system("pause");
                                system("cls");
                                fflush(stdin);
                                fclose(fp);
				    			break;
				    		case 3:
				    			AbrirArquivoVenda3();
				    			ListarVenda();
				    			system("pause");
                                system("cls");
                                fflush(stdin);
                                fclose(fp);
				    			break;
						}
        				break;
        			case '3':
        				do{
							system("cls");
					    	printf("Escolha uma unidade de venda: \n\n 1- Unidade 1 \n 2- Unidade 2 \n 3- Unidade 3  \n");
					    	printf ("\n Escolha a op��o (1,2,3): ");
					    	scanf("%d",&unidadeVendaProduto);
				    	}while((unidadeVendaProduto < 1 ) || (unidadeVendaProduto > 3));

				    	switch (unidadeVendaProduto){
				    		case 1:
				    			AbrirArquivoVenda1();
				    			ApagarVenda();
				    			system("pause");
                                system("cls");
                                fflush(stdin);
                                AdicionarEstoqueProdutoCancelado(idProdutoVenda);
                                fclose(fp);
				    			break;
				    		case 2:
				    			AbrirArquivoVenda2();
				    			ApagarVenda();
				    			system("pause");
                                system("cls");
                                fflush(stdin);
                                AdicionarEstoqueProdutoCancelado(idProdutoVenda);
                                fclose(fp);
				    			break;
				    		case 3:
				    			AbrirArquivoVenda3();
				    			ApagarVenda();
				    			system("pause");
                                system("cls");
                                fflush(stdin);
                                AdicionarEstoqueProdutoCancelado(idProdutoVenda);
                                fclose(fp);
				    			break;
				    		}
					case '4':
						system("cls");
		            	goto MenuPrincipalUsuario;
						break;


				}
            case '3':
            	system("cls");
            	//MenuOpcoes
            	while((opcao = FuncoesMenuOpcoes(MenuOpcoes))!= SAIR)
        		switch(opcao){
        			case '1':
        				break;
        			case '2':
        				break;
        			case '3':
        				break;
        			case '4':
        				system("cls");
		            	goto MenuPrincipalUsuario;
						break;
				}
				break;
         }
    msgSair();
                }
            else{
                    printf("login incorreto");
            }
            }

        }while(strcmp(loginrecebido,loginmaster)!=0 || strcmp(loginrecebido,loginpadrao)!=0);

}

/*Fun��es do menu de venda */
void TratamentoErroVenda(Produto p){
	//Se estoque de produto for <= 0
	if (p.quantidadeProduto <= 0){
		system("cls");
		printf("Produto informado sem estoque\n");
		system("pause");
		exit(1);
	}

	//Se valor de venda e promocional for <= 0

}

void PesquisarProduto(Produto *p){
pesquisarProduto:

AbrirArquivoProduto();
system("cls");

    Produto x;
    printf("Qual o numero do produto: ");
    scanf("%ld", & idProdutoVenda); fflush(stdin);

    if(fseek(fp, (idProdutoVenda-1)*sizeof(Produto), SEEK_SET)!=0){
        printf("produto inexistente!!!");
        system("pause");
        goto pesquisarProduto;
    }
    if(fread(&x, sizeof(Produto), 1, fp)!= 1){
        printf("Problemas na leitura do produto!!!");
        system("pause");

        goto pesquisarProduto;
    }

    if(x.status=='*'){
        printf("Um produto apagado n�o pode ser vendido!!! \n\n");
        system("pause");

        goto pesquisarProduto;
    }

    TratamentoErroVenda(x);

    printf("\n\n Produto escolhido \n\n");
    Mostrar_Produto(x);

    ProdutoVendido = x;
    system("pause");

}

void PesquisarCliente(Cliente *c){
pesquisarCliente:

    AbrirArquivoCliente();
	system("cls");

	long int id;
    Cliente x;

    printf("Qual o numero do cliente: ");
    scanf("%ld", & id); fflush(stdin);

    if(fseek(fp, (id-1)*sizeof(Cliente), SEEK_SET)!=0){
        printf("Cliente inexistente!!!");
        system("pause");
        goto pesquisarCliente;
    }
    if(fread(&x, sizeof(Cliente), 1, fp)!= 1){
        printf("Problemas na leitura do cliente!!!");
        system("pause");
        goto pesquisarCliente;
    }

    if(x.status=='*'){
        printf("Um cliente apagado n�o pode ser vendido!!! \n\n");
        system("pause");
        goto pesquisarCliente;
    }

    printf("\n\n Cliente escolhido \n\n");
    Mostrar_Cliente(x);

    ClienteEscolhido = x;
    system("pause");
}

void ExibirVenda(){
	system("cls");

	printf("=-=-=-=RESUMO-=-=-=-\n");
	printf("Cliente: %-30s \n",ClienteEscolhido.nomeCliente);
	printf("-=-=-=-=-=-=-=-=-=-=\n");
	printf("Produto: %-30s \n",ProdutoVendido.nomeProduto);
	printf("Valor unit�rio: %2.f \n",ProdutoVendido.valorPromocaoProduto);
	printf("Quantidade: %d \n", quantidade);
	printf("-=-=-=-=-=-=-=-=-=-=\n");
	//Calcular total da venda
	total = ProdutoVendido.valorPromocaoProduto * quantidade;

	printf("Total: %2.f\n", total);
	printf("-=-=-=-=-=-=-=-=-=-=\n\n");
	system("pause");
}

void RetirarEstoqueProdutoVendido(long int id){
	AbrirArquivoProduto();

    Produto x;

	if(fseek(fp, (id-1)*sizeof(Produto), SEEK_SET)!=0){
        printf("produto inexistente!!!");
        system("pause");
        return;
    }

    if(fread(&x, sizeof(Produto), 1, fp)!= 1){
        printf("Problemas na leitura do produto!!!");
        system("pause");
        return;
    }

    if(x.status=='*'){
        printf("Um produto apagado n�o pode ser alterado!!! \n\n");
        system("pause");
        return;
    }

    x.quantidadeProduto = x.quantidadeProduto - 1;
    // recuar um produto no arquivo
    fseek(fp, -(long) sizeof(Produto), SEEK_CUR);
    // reescrever o produto;
    fwrite(&x, sizeof(Produto), 1, fp);
    fflush(fp); /*despejar os arquivos no disco r�gido*/
}

void AdicionarEstoqueProdutoCancelado(long int id){
	AbrirArquivoProduto();

    Produto x;

	if(fseek(fp, (id-1)*sizeof(Produto), SEEK_SET)!=0){
        printf("produto inexistente!!!");
        system("pause");
        return;
    }

    if(fread(&x, sizeof(Produto), 1, fp)!= 1){
        printf("Problemas na leitura do produto!!!");
        system("pause");
        return;
    }

    if(x.status=='*'){
        printf("Um produto apagado n�o pode ser alterado!!! \n\n");
        system("pause");
        return;
    }

    x.quantidadeProduto = x.quantidadeProduto + 1;
    // recuar um produto no arquivo
    fseek(fp, -(long) sizeof(Produto), SEEK_CUR);
    // reescrever o produto;
    fwrite(&x, sizeof(Produto), 1, fp);
    fflush(fp); /*despejar os arquivos no disco r�gido*/
}

void MontarVenda(){
	char opcaoDigitada;
	int unidadeVendaProduto;

	system("cls");

	Produto p;
	Cliente c;

	PesquisarProduto(&p);
	PesquisarCliente(&c);
	system("cls");

	printf("Digite a quantidade: ");
	scanf("%d", &quantidade);

	ExibirVenda();

	system("cls");
	printf("Deseja concretizar a venda ? (s/n)");
	scanf("%s", &opcaoDigitada);

	if ((opcaoDigitada == 's') || (opcaoDigitada == 'S')){
		do{
			system("cls");
	    	printf("Escolha uma unidade de venda: \n\n 1- Unidade 1 \n 2- Unidade 2 \n 3- Unidade 3  \n");
	    	printf ("\n Escolha a op��o (1,2,3): ");
	    	scanf("%d",&unidadeVendaProduto);
    	}while((unidadeVendaProduto < 1 ) || (unidadeVendaProduto > 3));

    	switch (unidadeVendaProduto){
    		case 1:
    			//Caso unidade 1
    			AbrirArquivoVenda1();
    			InserirVenda();
    			printf("Venda salva com sucesso!\n");
    			fclose(fp);
    			RetirarEstoqueProdutoVendido(idProdutoVenda);
    			system("pause");
    			system("cls");
    			return;
    			break;
    		case 2:
    			//Caso unidade 2
    			AbrirArquivoVenda2();
    			InserirVenda();
    			printf("Venda salva com sucesso!\n");
    			fclose(fp);
    			RetirarEstoqueProdutoVendido(idProdutoVenda);
    			system("pause");
    			system("cls");
    			return;
    			break;
    		case 3:
    			//Caso unidade 3
    			AbrirArquivoVenda3();
    			InserirVenda();
    			printf("Venda salva com sucesso!\n");
    			fclose(fp);
    			RetirarEstoqueProdutoVendido(idProdutoVenda);
    			system("pause");
    			system("cls");
    			return;
    			break;
		}
	}else{
		printf("Venda n�o salva\n");
		system("pause");
		fflush(stdin);
		system("cls");
	}
}

int CalcularVenda(){
	float valorVenda=0,valorTotalGastos;
	int i,j;
    Venda x[700];
	rewind (fp);
	do{



		fread(&x,sizeof(x), 1,fp);
		for(i=0;i<50;i++){
		if(x[i].status =='*') {
		continue;}

			if(valorVenda == 0){
				valorVenda == x[i].total;
			}
			valorVenda= valorVenda + x[i].total;
		}




	}while(i!=50);
	return (valorVenda);
}

//Fun�ao que verifica qual a unidade e abre o txt de acordo com a escolha
void VerificaGasto(Gastos g){
    Ler_Gastos(&g);
    system("cls");
     if(g.unidadeGasto== 1){
        AbrirArquivoGastos1();
        Adiciona_Gasto(g);
        fclose(fp);
     }
     if(g.unidadeGasto == 2){
        AbrirArquivoGastos2();
        Adiciona_Gasto(g);
        fclose(fp);
     }
     if(g.unidadeGasto == 3){
        AbrirArquivoGastos3();
        Adiciona_Gasto(g);
        fclose(fp);
     }

}

int main(int argc, char *argv[]) {

	setlocale(LC_ALL, "Portuguese"); /* Torna poss�vel a utiliza��o de acentua��o e caracteres especiais no programa. */

    char opcao;
    float TotalGastos1,TotalGastos2,TotalGastos3,TotalVenda1,TotalVenda2,TotalVenda3;
    float TotalUnidade1,TotalUnidade2,TotalUnidade3,TotalRede;
    Gastos g;

    login();
    system("cls");

    //Menu Principal
    menuPrincipal: //GOTO
    while((opcao = FuncoesMenuPrincipal(MenuPrincipal))!= SAIR)
        switch(opcao){
            case '1':
            	system("cls");
            	menuCadastro: //GOTO
				//Menu Cadastro
				while((opcao = FuncoesMenuCadastro(MenuCadastro))!= SAIR)
        		switch(opcao){
		            case '1':
		            	system("cls");
		            	//Menu Produto
		            	AbrirArquivoProduto();
						while((opcao = FuncoesMenuProduto(MenuProduto))!= SAIR)
				        switch(opcao){

				            case '1':
								InserirProduto();
								system("cls");
								printf("\nProduto inserido com sucesso!\n");
				    			system("pause");
				    			system("cls");
								break;
				            case '2':
								AlterarProduto();
				    			system("cls");
								break;
				            case '3':
								ApagarProduto();
				    			system("pause");
				    			system("cls");
								break;
				            case '4':
								ListarProduto();
								system("pause");
								system("cls");
								break;
							case '5':
								system("cls");
		            			goto menuCadastro;
								break;

				        }
				        msgSair();
				        break;
		            case '2':
						system("cls");
		            	//Menu Cliente
		            	AbrirArquivoCliente();
						while((opcao = FuncoesMenuCliente(MenuCliente))!= SAIR)
				        switch(opcao){

				            case '1':
								InserirCliente();
								system("cls");
								printf("\nCliente inserido com sucesso!\n");
				    			system("pause");
				    			system("cls");
								break;
				            case '2':
								AlterarCliente();
				    			system("cls");
								break;
				            case '3':
								ApagarCliente();
				    			system("pause");
				    			system("cls");
								break;
				            case '4':
								ListarCliente();
								system("pause");
								system("cls");
								break;
							case '5':
								system("cls");
		            			goto menuCadastro;
								break;
				        }
				        msgSair();
				        break;
		            case '3':
						system("cls");
		            	//Menu Funcionario

						while((opcao = FuncoesMenuFuncionario(MenuFuncionario))!= SAIR)
				        switch(opcao){

				            case '1':
								InserirFuncionario();
								system("cls");
								printf("\nFuncionario inserido com sucesso!\n");
				    			system("pause");
				    			system("cls");
								break;
				            case '2':
								AlterarFuncionario();
				    			system("cls");
								break;
				            case '3':
								ApagarFuncionario();
				    			system("pause");
				    			system("cls");
								break;
				            case '4':
								ListarFuncionario();
								system("pause");
								system("cls");
								break;
							case '5':
								system("cls");
		            			goto menuCadastro;
								break;
				        }
				        msgSair();
				        break;
		            case '4':
		            	system("cls");
		            	//Menu Fornecedor
		            	AbrirArquivoFornecedor();
						while((opcao = FuncoesMenuFornecedor(MenuFornecedor))!= SAIR)
				        switch(opcao){

				            case '1':
								InserirFornecedor();
								system("cls");
								printf("\nFornecedor inserido com sucesso!\n");
				    			system("pause");
				    			system("cls");
								break;
				            case '2':
								AlterarFornecedor();
				    			system("cls");
								break;
				            case '3':
								ApagarFornecedor();
				    			system("pause");
				    			system("cls");
								break;
				            case '4':
								ListarFornecedor();
								system("pause");
								system("cls");
								break;
							case '5':
								system("cls");
		            			goto menuCadastro;
								break;

				        }
				        msgSair();
				        break;
					case '5':
						system("cls");
						//Menu Gastos
                        MenuGastos://goto
					    fflush(stdin);
	                    while((opcao= FuncoesMenuGastos(MenuGastos))!= SAIR)
	                    switch(opcao){
	                    case '1':
                                VerificaGasto(g);
                                system("cls");
                                printf("\nGastos inserido com sucesso!!");
                                system("pause");
                                system("cls");
                                break;
                    case '2':
                            system("cls");
                            while((opcao= FuncoesMenuGastos(MenuGastosUnidade))!= SAIR)
                            switch(opcao){
                            case'1':
                                AbrirArquivoGastos1();
                                AlterarGasto();
                                system("pause");
                                system("cls");
                                fclose(fp);
                                break;
                            case '2':
                                AbrirArquivoGastos2();
                                AlterarGasto();
                                system("pause");
                                system("cls");
                                fclose(fp);
                                break;
                            case '3':
                                AbrirArquivoGastos3();
                                AlterarGasto();
                                system("pause");
                                system("cls");
                                fclose(fp);
                                break;
                            case '4':
                                goto MenuGastos;
                                break;
                            }
                    case '3':
                            system("cls");
                            while((opcao= FuncoesMenuGastos(MenuGastosUnidade))!= SAIR)
                            switch(opcao){
                            case'1':
                                AbrirArquivoGastos1();
                                ApagarGasto();
                                system("pause");
                                system("cls");
                                fclose(fp);
                                break;
                            case '2':
                                AbrirArquivoGastos2();
                                ApagarGasto();
                                system("pause");
                                system("cls");
                                fclose(fp);
                                break;
                            case '3':
                                AbrirArquivoGastos3();
                                ApagarGasto();
                                system("pause");
                                system("cls");
                                fclose(fp);
                                break;
                            case '4':
                                goto MenuGastos;
                                break;
        			    }
                            break;
                    case '4':
                            system("cls");
                            while((opcao= FuncoesMenuGastos(MenuGastosUnidade))!= SAIR)
                            switch(opcao){
                            case'1':
                                AbrirArquivoGastos1();
                                ListarGasto();
                                system("pause");
                                system("cls");
                                fclose(fp);
                                break;
                            case '2':
                                AbrirArquivoGastos2();
                                ListarGasto();
                                system("pause");
                                system("cls");
                                fclose(fp);
                                break;
                            case '3':
                                AbrirArquivoGastos3();
                                ListarGasto();
                                system("pause");
                                system("cls");
                                fclose(fp);
                                break;
                            case '4':
                                goto MenuGastos;
                                break;
                            }
                            break;
                        case'5':
                                system("cls");
                              goto menuCadastro;
                              break;
	                    }

                        case '6':
                        system("cls");
                        goto menuPrincipal;
		            	break;


		        msgSair();
        		}
            case '2':
            	menuVendas:
            	system("cls");
            	//MenuVendas
            	int unidadeVendaProduto;
				while((opcao = FuncoesMenuVendas(MenuVendas))!= SAIR)
        		switch(opcao){
        			case '1':
        				MontarVenda();
        				break;
        			case '2':
        				do{
							system("cls");
					    	printf("Escolha uma unidade de venda: \n\n 1- Unidade 1 \n 2- Unidade 2 \n 3- Unidade 3  \n");
					    	printf ("\n Escolha a op��o (1,2,3): ");
					    	scanf("%d",&unidadeVendaProduto);
				    	}while((unidadeVendaProduto < 1 ) || (unidadeVendaProduto > 3));

				    	switch (unidadeVendaProduto){
				    		case 1:
				    			AbrirArquivoVenda1();
				    			ListarVenda();
				    			system("pause");
                                system("cls");
                                fflush(stdin);
                                fclose(fp);
				    			break;
				    		case 2:
				    			AbrirArquivoVenda2();
				    			ListarVenda();
				    			system("pause");
                                system("cls");
                                fflush(stdin);
                                fclose(fp);
				    			break;
				    		case 3:
				    			AbrirArquivoVenda3();
				    			ListarVenda();
				    			system("pause");
                                system("cls");
                                fflush(stdin);
                                fclose(fp);
				    			break;
						}
        				break;
        			case '3':
        				do{
							system("cls");
					    	printf("Escolha uma unidade de venda: \n\n 1- Unidade 1 \n 2- Unidade 2 \n 3- Unidade 3  \n");
					    	printf ("\n Escolha a op��o (1,2,3): ");
					    	scanf("%d",&unidadeVendaProduto);
				    	}while((unidadeVendaProduto < 1 ) || (unidadeVendaProduto > 3));

				    	switch (unidadeVendaProduto){
				    		case 1:
				    			AbrirArquivoVenda1();
				    			ApagarVenda();
				    			system("pause");
                                system("cls");
                                fflush(stdin);
                                AdicionarEstoqueProdutoCancelado(idProdutoVenda);
                                fclose(fp);
				    			break;
				    		case 2:
				    			AbrirArquivoVenda2();
				    			ApagarVenda();
				    			system("pause");
                                system("cls");
                                fflush(stdin);
                                AdicionarEstoqueProdutoCancelado(idProdutoVenda);
                                fclose(fp);
				    			break;
				    		case 3:
				    			AbrirArquivoVenda3();
				    			ApagarVenda();
				    			system("pause");
                                system("cls");
                                fflush(stdin);
                                AdicionarEstoqueProdutoCancelado(idProdutoVenda);
                                fclose(fp);
				    			break;
				    		}
					case '4':
						system("cls");
		            	goto menuPrincipal;
						break;


				}
            case '3':
        		system("cls");
            	//MenuRelatorios
				while((opcao = FuncoesMenuRelatorios(MenuRelatorios))!= SAIR)
        		switch(opcao){
        			case '1':
        				break;
        			case '2':
        			    system("cls");
        			    while((opcao=FuncoesMenuRelatorios(MenuGastosUnidade))!= SAIR)
                        switch(opcao){
                        case'1':
                            AbrirArquivoGastos1();
                            TotalGastos1=CalcularGasto();
                            fclose(fp);
                            AbrirArquivoVenda1();
                            TotalVenda1=CalcularVenda();
                            fclose(fp);
                            TotalUnidade1=TotalVenda1-(TotalGastos1);
                            system("cls");
                            printf("\nO faturamento da unidade1 � de: %.2f\n\n",TotalUnidade1);
                            system("pause");
                            system("cls");
                            break;
                        case'2':
                            AbrirArquivoGastos2();
                            TotalGastos2=CalcularGasto();
                            fclose(fp);
                            AbrirArquivoVenda2();
                            TotalVenda2=CalcularVenda();
                            fclose(fp);
                            TotalUnidade2=TotalVenda2-(TotalGastos2);
                            system("cls");
                            printf("\nO faturamento da unidade2 � de: %.2f\n\n",TotalUnidade2);
                            system("pause");
                            system("cls");
                            break;
                        case'3':
                            AbrirArquivoGastos3();
                            TotalGastos3=CalcularGasto();
                            fclose(fp);
                            AbrirArquivoVenda3();
                            TotalVenda3=CalcularVenda();
                            fclose(fp);
                            TotalUnidade3=TotalVenda3-(TotalGastos3);
                            system("cls");
                            printf("\nO faturamento da unidade3 � de: %.2f\n\n",TotalUnidade3);
                            system("pause");
                            system("cls");
                            break;
                        case'4':
                            system("cls");
                            goto menuPrincipal;
                            system("cls");
                            break;


                        }
        				break;
        			case '3':
                            TotalRede=TotalUnidade1+TotalUnidade2+TotalUnidade3;
                            printf("\n O faturamento da rede � de: %.2f\n\n",TotalRede);
                            system("pause");
                            system("cls");
						break;
					case '4':
                            system("cls");
                            goto menuPrincipal;
                            break;

				}
				break;
            case '4':
            	system("cls");
            	//MenuOpcoes
            	while((opcao = FuncoesMenuOpcoes(MenuOpcoes))!= SAIR)
        		switch(opcao){
        			case '1':
        				//Sobre
        				system("cls");
        				printf("SOBRE O SOFTWARE:\n\n");
        				printf("O projeto se consiste em funcionalidades que toda pizzaria precisa, por�m, este sistema cont�m fun��es automatizadas e seguras para que o funcion�rio trabalhe de forma eficiente e pr�tica, sempre visando a produtividade, consequentemente gerando mais rentabilidade, maior desempenho e agilidade nas tarefas di�rias da pizzaria.\n\n");
        				printf("C�DIGO FONTE EM: \nhttps://github.com/GabrielFernandesLemos/Controle-financeiro-em-C\n\n");
        				printf("CONTRIBUIDORES:\n\n");
        				printf("- Gabriel Fernandes Lemos \n\n- Matheus Nunes Nepomuceno\n\n- Erik Hideyuki Yoshimoto Seki\n\n- Clayton Belarmino da Silva\n\n- Gabriel Franco Garcia Rodrigues de Paula\n\n");
        				system("pause");
        				system("cls");
        				break;
        			case '2':        				
        				//Manual
        				printf("Fa�a seu login no sistema e comece a usufruir das suas funcionalidades. \n\nEste manual foi feito pelo sistema operacional Windows 7. \n\nPara iniciar a configura��o Banda Larga, Clique em Iniciar. Em seguida clique em Painel de Controle Clique na op��o Rede e Internet \n\nEm seguida escolha a op��o Centro de Rede e Compartilhamento No menu � direita, clique na op��o Configurar uma conex�o ou uma rede nova. \n\nClique na op��o de conex�o Conectar-se � Internet e depois em Avan�ar. \n\nClique em Banda larga (PPPoE). \n\nPreencha o campo Nome de usu�rio com o endere�o de e-mail de conex�o completo (Ex.: username@terra.com.br), abaixo, insira a senha e em seguida d� um nome para a conex�o. \n\nImportante ressaltar, marque a op��o Lembrar esta senha para n�o precisar digit�-la sempre que for estabelecer a conex�o. \n\nMarque a op��o �Permitir que outras pessoas usem esta conex�o� caso o computador seja acessado por outras pessoas atrav�s de suas contas de usu�rio. \n\nClique em �Conectar�. Aguarde enquanto o sistema estabelece a conex�o e feche a tela ap�s a conex�o ser estabelecida. \n\nSempre que desejar conectar, basta acessar a conex�o criada e clicar em �Conectar�. \n\nO sistema � bem intuitivo e de f�cil aprendizado. \n\nA tela mais importante � a de cadastros, na qual poder� cadastrar Produtos, clientes, funcion�rios e gastos Para cadastrar um produto, aperte a tecla 1. \n\nEm seguida o programa ir� lhe solicitar o que deseja fazer, seja inserir, alterar, apagar ou ligar um produto. \n\nAperte o n�mero em seu teclado referente ao que deseja fazer e fa�a sua a��o. \n\nO mesmo funciona para cadastros de clientes, funcion�rios e gastos. \n\nO menu de vendas � utilizado para realizar vendas, ele cont�m as op��es de gerar nova venda, listar vendas e fazer o cancelamento de uma venda Aperte o n�mero em seu teclado referente ao que deseja fazer e fa�a sua a��o. \n\nA tela de relat�rios somente o administrador do sistema tem acesso, pois nela tem cont�m informa��o de faturamento onde um funcion�rio comum n�o tem acesso. \n\nEssa op��o tem dispon�vel sabores mais vendidos por unidade, faturamento mensal e faturamento total. \n\nPara visualizar essas op��es, basta aperta em seu teclado o n�mero referente a a��o que ir� fazer\n\n");
        				system("pause");
        				system("cls");
        				break;
        			case '3':
        				//Voltar
        				system("cls");
						goto menuPrincipal;
        				break;
				}
				break;
         }
    msgSair();
    return 0;


}
