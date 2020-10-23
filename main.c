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
Sistema de gestão e controle financeiro para uma pizzaria.
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
    "3. Relatórios",
    "4. Opções",
    "0. Sair",
    NULL /* ACABARAM AS OPÇÕES*/
};

char *MenuPrincipalUsuario[]={
    "1. Cadastros",
    "2. Vendas",
    "3. Opções",
    "0. Sair",
    NULL /* ACABARAM AS OPÇÕES*/
};

char *MenuCadastro[]={
    "1. Produtos",
    "2. Clientes",
    "3. Funcionarios",
    "4. Fornecedor",
    "5. Gastos",
    "6. Voltar",
    "0. Sair",
    NULL /* ACABARAM AS OPÇÕES*/
};

char *MenuCadastroUsuario[]={
    "1. Produtos",
    "2. Clientes",
    "3. Fornecedor",
    "4. Voltar",
    "0. Sair",
    NULL /* ACABARAM AS OPÇÕES*/
};

char *MenuProduto[]={
    "1. Inserir produto",
    "2. Alterar produto",
    "3. Apagar produto",
    "4. Listar produtos",
    "5. Voltar",
    "0. Sair",
    NULL /* ACABARAM AS OPÇÕES*/
};

char *MenuCliente[]={
    "1. Inserir cliente",
    "2. Alterar cliente",
    "3. Apagar cliente",
    "4. Listar clientes",
    "5. Voltar",
    "0. Sair",
    NULL /* ACABARAM AS OPÇÕES*/
};

char *MenuFuncionario[]={
    "1. Inserir funcionario",
    "2. Alterar funcionario",
    "3. Apagar funcionario",
    "4. Listar funcionario",
    "5. Voltar",
    "0. Sair",
    NULL /* ACABARAM AS OPÇÕES*/
};

char *MenuFornecedor[]={
    "1. Inserir fornecedor",
    "2. Alterar fornecedor",
    "3. Apagar fornecedor",
    "4. Listar fornecedor",
    "5. Voltar",
    "0. Sair",
    NULL /* ACABARAM AS OPÇÕES*/
};

char *MenuVendas[]={
    "1. Gerar nova venda",
    "2. Listar vendas",
    "3. Fazer cancelamento de venda",
    "4. Voltar",
    "0. Sair",
    NULL /* ACABARAM AS OPÇÕES*/
};

char *MenuOpcoes[]={
    "1. Sobre",
    "2. Manual",
    "3. Voltar",
    NULL /* ACABARAM AS OPÇÕES*/
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
    NULL /* ACABARAM AS OPÇÕES*/
};


typedef struct Produto{
    char nomeProduto[30];
    int quantidadeProduto;
    float valorPromocaoProduto, valorVendaProduto, valorCustoProduto;
    char status; /* '*' indica que o produto está apagado*/
}Produto;

typedef struct Cliente{
    char nomeCliente[50],cpfCliente[14], rgCliente[12], celularCliente[14], emailCliente[50], enderecoCliente[100], observacaoCliente[1000];
    char status; /* '*' indica que o produto está apagado*/
}Cliente;

typedef struct Funcionario{
    float salarioFuncionario;
    char cpfFuncionario[14], rgFuncionario[12], celularFuncionario[13], emailFuncionario[100], enderecoFuncionario[100], nomeFuncionario[100];
    char status; /* '*' indica que o produto está apagado*/
}Funcionario;

typedef struct Fornecedor{
    char nomeFornecedor[50],cnpjFornecedor[14], rgFornecedor[12], celularFornecedor[14], emailFornecedor[50], enderecoFornecedor[100], observacaoFornecedor[1000];
    char status; /* '*' indica que o produto está apagado*/
}Fornecedor;

typedef struct Gastos{
    char tipo[50];
    int unidadeGasto;
    float valorGasto;
    char status; /* '*' indica que o produto está apagado*/
}Gastos;

typedef struct Venda{
    char nomeCliente[30], nomeProduto[30];
    int quantidadeProduto;
    float valorUnitarioProduto, total;
    char status; /* '*' indica que o produto está apagado*/
}Venda;

FILE *fp; /*variável global pois é útil ao longo do programa*/

/*Variáveis para trabalhar com vendas*/
Produto ProdutoVendido;
Cliente ClienteEscolhido;
int quantidade;
long int idProdutoVenda;
float total;

/* lê os valores inseridos pelo usuário*/
void Ler_Gastos(Gastos *g){
int opcaoDigitada=0;

do{
		system("cls");
	    printf("Escolha uma unidade para inserir o gasto: \n\n 1- Unidade 1 \n 2- Unidade 2 \n 3- Unidade 3  \n");
	    printf ("\n Escolha a opção (1,2,3): ");
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

	printf("Digite o valor de promoção (Se não houver promoção repita o valor de venda):   ");
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

	printf("Digite o endereço do cliente:   ");
	gets(c->enderecoCliente);
	system("cls");

	printf("Digite o observação do cliente:   ");
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

	printf("Digite o endereço do funcionario:   ");
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

	printf("Digite o endereço do fornecedor:   ");
	gets(f->enderecoFornecedor);
	system("cls");

	printf("Digite o observação do fornecedor:   ");
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
	printf("Valor unitário: %2.f \n",v.valorUnitarioProduto);
	printf("Quantidade: %d \n", v.quantidadeProduto);
	printf("Total: %2.f\n", v.total);
	printf("-=-=-=-=-=-=-=-=-=-=\n");
}

void Mostrar_Produto(Produto p){
    printf("Nome: %-30s \n",p.nomeProduto);
	printf("Quantidade do produto: %3d \n",p.quantidadeProduto);
	printf("Valor de venda: %10.2f\n",p.valorVendaProduto);
	printf("Valor de custo: %10.2f\n",p.valorCustoProduto);
	printf("Valor de promoção: %10.2f\n",p.valorPromocaoProduto);
	printf("=-=-=-=-=-=-=\n");
}

void Mostrar_Cliente(Cliente c){
	printf("Nome: %-30s \n",c.nomeCliente);
	printf("CPF: %-30s \n",c.cpfCliente);
	printf("RG: %-30s \n",c.rgCliente);
	printf("Celular: %-30s \n",c.celularCliente);
	printf("Email: %-30s \n",c.emailCliente);
	printf("Endereço: %-30s \n",c.enderecoCliente);
	printf("Observação: %-30s \n",c.observacaoCliente);
	printf("=-=-=-=-=-=-=\n");
}

void Mostrar_Funcionario(Funcionario f){
	printf("Nome: %-30s \n",f.nomeFuncionario);
	printf("CPF: %-30s \n",f.cpfFuncionario);
	printf("RG: %-30s \n",f.rgFuncionario);
	printf("Celular: %-30s \n",f.celularFuncionario);
	printf("Email: %-30s \n",f.emailFuncionario);
	printf("Endereço: %-30s \n",f.enderecoFuncionario);
	printf("Salário: %10.2f\n",f.salarioFuncionario);
	printf("=-=-=-=-=-=-=\n");
}

void Mostrar_Fornecedor(Fornecedor f){
	printf("Nome: %-30s \n",f.nomeFornecedor);
	printf("CPF/CNPJ: %-30s \n",f.cnpjFornecedor);
	printf("RG: %-30s \n",f.rgFornecedor);
	printf("Celular: %-30s \n",f.celularFornecedor);
	printf("Email: %-30s \n",f.emailFornecedor);
	printf("Endereço: %-30s \n",f.enderecoFornecedor);
	printf("Observação: %-30s \n",f.observacaoFornecedor);
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

/*Verificar se o arquivo já existe. Se não existir, ele é criado
se já existir, abre-o em modo de leitura e escrita (r+b)*/
void AbrirArquivoGastos1(){
    fp=fopen(ARQUIVO_GASTOS_1,"r+b");
    if(fp == NULL){
        fp=fopen(ARQUIVO_GASTOS_1,"w+b");
        if(fp==NULL){
            printf("Erro: Impossível criar arquivo de gastos\n");
            exit(1);
        }
            }

}

void AbrirArquivoGastos2(){
    fp=fopen(ARQUIVO_GASTOS_2,"r+b");
    if(fp == NULL){
        fp=fopen(ARQUIVO_GASTOS_2,"w+b");
        if(fp==NULL){
            printf("Erro: Impossível criar arquivo de gastos\n");
            exit(1);
        }
            }

}

void AbrirArquivoGastos3(){
    fp=fopen(ARQUIVO_GASTOS_3,"r+b");
    if(fp == NULL){
        fp=fopen(ARQUIVO_GASTOS_3,"w+b");
        if(fp==NULL){
            printf("Erro: Impossível criar arquivo de gastos\n");
            exit(1);
        }
            }

}

void AbrirArquivoProduto(){
    fp= fopen(ARQUIVO_PRODUTO, "r+b"); //tentar abrir
    if(fp==NULL){
        fp = fopen(ARQUIVO_PRODUTO, "w+b"); // criar o arquivo
        if(fp==NULL){
            printf("Erro fatal: impossível criar arquivo de produtos\n");
            exit(1);
        }
    }
}

void AbrirArquivoCliente(){
    fp= fopen(ARQUIVO_CLIENTE, "r+b"); //tentar abrir
    if(fp==NULL){
        fp = fopen(ARQUIVO_CLIENTE, "w+b"); // criar o arquivo
        if(fp==NULL){
            printf("Erro fatal: impossível criar arquivo de clientes\n");
            exit(1);
        }
    }
}

void AbrirArquivoFuncionario(){
    fp= fopen(ARQUIVO_FUNCIONARIO, "r+b"); //tentar abrir
    if(fp==NULL){
        fp = fopen(ARQUIVO_FUNCIONARIO, "w+b"); // criar o arquivo
        if(fp==NULL){
            printf("Erro fatal: impossível criar arquivo de funcionario\n");
            exit(1);
        }
    }
}

void AbrirArquivoFornecedor(){
    fp= fopen(ARQUIVO_FORNECEDOR, "r+b"); //tentar abrir
    if(fp==NULL){
        fp = fopen(ARQUIVO_FORNECEDOR, "w+b"); // criar o arquivo
        if(fp==NULL){
            printf("Erro fatal: impossível criar arquivo de fornecedor\n");
            exit(1);
        }
    }
}

void AbrirArquivoVenda1(){
    fp= fopen(ARQUIVO_VENDA_1, "r+b"); //tentar abrir
    if(fp==NULL){
        fp = fopen(ARQUIVO_VENDA_1, "w+b"); // criar o arquivo
        if(fp==NULL){
            printf("Erro fatal: impossível criar arquivo de venda\n");
            exit(1);
        }
    }
}

void AbrirArquivoVenda2(){
    fp= fopen(ARQUIVO_VENDA_2, "r+b"); //tentar abrir
    if(fp==NULL){
        fp = fopen(ARQUIVO_VENDA_2, "w+b"); // criar o arquivo
        if(fp==NULL){
            printf("Erro fatal: impossível criar arquivo de venda\n");
            exit(1);
        }
    }
}

void AbrirArquivoVenda3(){
    fp= fopen(ARQUIVO_VENDA_3, "r+b"); //tentar abrir
    if(fp==NULL){
        fp = fopen(ARQUIVO_VENDA_3, "w+b"); // criar o arquivo
        if(fp==NULL){
            printf("Erro fatal: impossível criar arquivo de venda\n");
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

/* Faz um menu simples com as opções do vetor de strings.
seleciona a opção, usando o primeiro caracter de cada string.
devolve o primeiro caracter da opção.
*/
char FuncoesMenuPrincipal(char *opcoes[]){
    int i;
    char ch;
    while(1){

	    FuncaoExibirData();

        printf("\n\n\n\n\n");
            for(i=0; opcoes[i]!=NULL; i++)
                printf("\t\t%s\n\n",opcoes[i]);

            printf("\n\n\t\tOpção: ");
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

            printf("\n\n\t\tOpção: ");
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

            printf("\n\n\t\tOpção: ");
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

            printf("\n\n\t\tOpção: ");
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

            printf("\n\n\t\tOpção: ");
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

            printf("\n\n\t\tOpção: ");
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

            printf("\n\n\t\tOpção: ");
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

            printf("\n\n\t\tOpção: ");
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

            printf("\n\n\t\tOpção: ");
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

            printf("\n\n\t\tOpção: ");
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
        printf("Um produto apagado não pode ser alterado!!! \n\n");
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
    fflush(fp); /*despejar os arquivos no disco rígido*/
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
        printf("produto já está apagado!!!\n\n");
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
    fflush(fp); /*Despejar os arquivos no disco rígido*/
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
		 break; /*Sair do laço*/
		}else{
			cont=cont+1;
		}
        if(reg.status=='*'){
        	continue; /*Passa ao próximo*/
		}
		printf("ID: %d\n", cont);
        Mostrar_Produto(reg);
    }
}

//Faz inserção e leitura de venda
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
		 break; /*Sair do laço*/
		}else{
			cont=cont+1;
		}
        if(reg.status=='*'){
        	continue; /*Passa ao próximo*/
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
        printf("Venda já está apagada!!!\n\n");
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
    fflush(fp); /*Despejar os arquivos no disco rígido*/
    system("cls");
	printf("\nVenda exluida com sucesso!\n");
}

//Faz inserção e leitura de gasto
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
        printf("Um gasto apagado não pode ser alterado!!! \n\n");
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
    fflush(fp); /*despejar os arquivos no disco rígido*/
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
        printf("Gasto já está apagada!!!\n\n");
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
    fflush(fp); /*Despejar os arquivos no disco rígido*/
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
		 break; /*Sair do laço*/
		}else{
			cont=cont+1;
		}
        if(reg.status=='*'){
        	continue; /*Passa ao próximo*/
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
        printf("Um cliente apagado não pode ser alterado!!! \n\n");
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
    fflush(fp); /*despejar os arquivos no disco rígido*/
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
        printf("Cliente já está apagado!!!\n\n");
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
    fflush(fp); /*Despejar os arquivos no disco rígido*/
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
		 break; /*Sair do laço*/
		}else{
			cont=cont+1;
		}
        if(reg.status=='*'){
        	continue; /*Passa ao próximo*/
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
        printf("Um funcionario apagado não pode ser alterado!!! \n\n");
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
    fflush(fp); /*despejar os arquivos no disco rígido*/
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
        printf("Funcionario inexistente ou problemas no funcionário!!!");
        system("pause");
        return;
    }
    if(fread(&x, sizeof(Funcionario), 1, fp)!= 1){
        printf("Problema na leitura do funcionario!!!");
        system("pause");
        return;
    }
    if(x.status=='*'){
        printf("Funcionario já está apagado!!!\n\n");
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
    fflush(fp); /*Despejar os arquivos no disco rígido*/
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
		 break; /*Sair do laço*/
		}else{
			cont=cont+1;
		}
        if(reg.status=='*'){
        	continue; /*Passa ao próximo*/
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
        printf("Um fornecedor apagado não pode ser alterado!!! \n\n");
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
    fflush(fp); /*despejar os arquivos no disco rígido*/
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
        printf("Fornecedor já está apagado!!!\n\n");
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
    fflush(fp); /*Despejar os arquivos no disco rígido*/
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
		 break; /*Sair do laço*/
		}else{
			cont=cont+1;
		}
        if(reg.status=='*'){
        	continue; /*Passa ao próximo*/
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
					    	printf ("\n Escolha a opção (1,2,3): ");
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
					    	printf ("\n Escolha a opção (1,2,3): ");
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

/*Funções do menu de venda */
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
        printf("Um produto apagado não pode ser vendido!!! \n\n");
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
        printf("Um cliente apagado não pode ser vendido!!! \n\n");
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
	printf("Valor unitário: %2.f \n",ProdutoVendido.valorPromocaoProduto);
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
        printf("Um produto apagado não pode ser alterado!!! \n\n");
        system("pause");
        return;
    }

    x.quantidadeProduto = x.quantidadeProduto - 1;
    // recuar um produto no arquivo
    fseek(fp, -(long) sizeof(Produto), SEEK_CUR);
    // reescrever o produto;
    fwrite(&x, sizeof(Produto), 1, fp);
    fflush(fp); /*despejar os arquivos no disco rígido*/
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
        printf("Um produto apagado não pode ser alterado!!! \n\n");
        system("pause");
        return;
    }

    x.quantidadeProduto = x.quantidadeProduto + 1;
    // recuar um produto no arquivo
    fseek(fp, -(long) sizeof(Produto), SEEK_CUR);
    // reescrever o produto;
    fwrite(&x, sizeof(Produto), 1, fp);
    fflush(fp); /*despejar os arquivos no disco rígido*/
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
	    	printf ("\n Escolha a opção (1,2,3): ");
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
		printf("Venda não salva\n");
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

//Funçao que verifica qual a unidade e abre o txt de acordo com a escolha
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

	setlocale(LC_ALL, "Portuguese"); /* Torna possível a utilização de acentuação e caracteres especiais no programa. */

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
					    	printf ("\n Escolha a opção (1,2,3): ");
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
					    	printf ("\n Escolha a opção (1,2,3): ");
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
                            printf("\nO faturamento da unidade1 é de: %.2f\n\n",TotalUnidade1);
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
                            printf("\nO faturamento da unidade2 é de: %.2f\n\n",TotalUnidade2);
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
                            printf("\nO faturamento da unidade3 é de: %.2f\n\n",TotalUnidade3);
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
                            printf("\n O faturamento da rede é de: %.2f\n\n",TotalRede);
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
        				printf("O projeto se consiste em funcionalidades que toda pizzaria precisa, porém, este sistema contém funções automatizadas e seguras para que o funcionário trabalhe de forma eficiente e prática, sempre visando a produtividade, consequentemente gerando mais rentabilidade, maior desempenho e agilidade nas tarefas diárias da pizzaria.\n\n");
        				printf("CÓDIGO FONTE EM: \nhttps://github.com/GabrielFernandesLemos/Controle-financeiro-em-C\n\n");
        				printf("CONTRIBUIDORES:\n\n");
        				printf("- Gabriel Fernandes Lemos \n\n- Matheus Nunes Nepomuceno\n\n- Erik Hideyuki Yoshimoto Seki\n\n- Clayton Belarmino da Silva\n\n- Gabriel Franco Garcia Rodrigues de Paula\n\n");
        				system("pause");
        				system("cls");
        				break;
        			case '2':        				
        				//Manual
        				printf("Faça seu login no sistema e comece a usufruir das suas funcionalidades. \n\nEste manual foi feito pelo sistema operacional Windows 7. \n\nPara iniciar a configuração Banda Larga, Clique em Iniciar. Em seguida clique em Painel de Controle Clique na opção Rede e Internet \n\nEm seguida escolha a opção Centro de Rede e Compartilhamento No menu à direita, clique na opção Configurar uma conexão ou uma rede nova. \n\nClique na opção de conexão Conectar-se à Internet e depois em Avançar. \n\nClique em Banda larga (PPPoE). \n\nPreencha o campo Nome de usuário com o endereço de e-mail de conexão completo (Ex.: username@terra.com.br), abaixo, insira a senha e em seguida dê um nome para a conexão. \n\nImportante ressaltar, marque a opção Lembrar esta senha para não precisar digitá-la sempre que for estabelecer a conexão. \n\nMarque a opção “Permitir que outras pessoas usem esta conexão” caso o computador seja acessado por outras pessoas através de suas contas de usuário. \n\nClique em “Conectar”. Aguarde enquanto o sistema estabelece a conexão e feche a tela após a conexão ser estabelecida. \n\nSempre que desejar conectar, basta acessar a conexão criada e clicar em “Conectar”. \n\nO sistema é bem intuitivo e de fácil aprendizado. \n\nA tela mais importante é a de cadastros, na qual poderá cadastrar Produtos, clientes, funcionários e gastos Para cadastrar um produto, aperte a tecla 1. \n\nEm seguida o programa irá lhe solicitar o que deseja fazer, seja inserir, alterar, apagar ou ligar um produto. \n\nAperte o número em seu teclado referente ao que deseja fazer e faça sua ação. \n\nO mesmo funciona para cadastros de clientes, funcionários e gastos. \n\nO menu de vendas é utilizado para realizar vendas, ele contém as opções de gerar nova venda, listar vendas e fazer o cancelamento de uma venda Aperte o número em seu teclado referente ao que deseja fazer e faça sua ação. \n\nA tela de relatórios somente o administrador do sistema tem acesso, pois nela tem contém informação de faturamento onde um funcionário comum não tem acesso. \n\nEssa opção tem disponível sabores mais vendidos por unidade, faturamento mensal e faturamento total. \n\nPara visualizar essas opções, basta aperta em seu teclado o número referente a ação que irá fazer\n\n");
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
