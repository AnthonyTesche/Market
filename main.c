#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

//Structs Abaixo
struct Telefones{
	char fixo[15];
	char movel[16];
};

struct Clientes{
	int codClient;
	char nome[50];
	double cpf;
    char sexo[1];
	struct Telefones tel;
};

struct Modelos{
	char marca[20];
	char modelo[20];
};

struct Produtos{
	int codProd;
	char nome[50];
	double valor;
	struct Modelos model;
};

struct Carrinho{
	struct Clientes client[3];
	struct Produtos prod[10];
	int quant[3];
	double subtotal;	
	double desc;
	double total;
};

int c, p, b; //Contagem de Clientes, Produtos e Buy

// Structs Acima

int codigoCliente(struct Clientes auxR){ // Gera o codigo do Cliente
	
	auxR.codClient = auxR.cpf / 100000;
	fflush(stdin);
	//printf("%d", auxR->codClient);
	
	return auxR.codClient;	
}

struct Clientes Register(struct Clientes *listClient){ //Funcao para cadastro de Clientes
	
	struct Clientes auxR;
    system("cls");
	printf("Inserir Nome: ");
	scanf("%s", auxR.nome);
	fflush(stdin);
	//printf("%s", auxR->.nome);
	
	printf("Inserir CPF: ");
	scanf("%lf", &auxR.cpf);// Seria bom verificar duplicatas.

	codigoCliente(auxR);
	
	printf("Inserir Sexo: ");
	gets(auxR.sexo);
	fflush(stdin);

	printf("Inserir Movel: ");
	scanf("%s", auxR.tel.movel);
	fflush(stdin);
	//printf("%s", auxR->tel.movel);
	
	printf("Inserir Fixo: ");
	scanf("%s", auxR.tel.fixo);
	fflush(stdin);
	//printf("%s", auxR->tel.fixo);
	
	listClient[c] = auxR;
	c++;
	
	printf("Codigo do cliente: %d \n", auxR.codClient);
	system("pause");
	return auxR;

};
// Fim da Funcao de Cadastro de Clientes

void exampleClient(struct Clientes *listClient){ // Clientes de Exemplo
	
	struct Clientes auxR;
	
	strcpy(auxR.nome, "Anthony");
	auxR.cpf = 11630305979;
	codigoCliente(auxR);
	listClient[0].codClient = codigoCliente(auxR);
	strcpy(auxR.sexo, "M");
	strcpy(auxR.tel.fixo, "(43)3066-2870");
	strcpy(auxR.tel.movel, "(43)99157-4920");
	listClient[0] = auxR;
	
	strcpy(auxR.nome, "Millena");
	auxR.cpf = 87895432323;
	codigoCliente(auxR);
	listClient[1].codClient = codigoCliente(auxR);
	strcpy(auxR.sexo, "F");
	strcpy(auxR.tel.fixo, "(43)3066-2870");
	strcpy(auxR.tel.movel, "(43)99157-4920");
	listClient[1] = auxR;
	
	strcpy(auxR.nome, "Marcelo");
	auxR.cpf = 99764543204;
	codigoCliente(auxR);
	listClient[2].codClient = codigoCliente(auxR);
	strcpy(auxR.sexo, "M");
	strcpy(auxR.tel.fixo, "(43)3066-2870");
	strcpy(auxR.tel.movel, "(43)99157-4920");
	listClient[2] = auxR;
	
	strcpy(auxR.nome, "Felipe");
	auxR.cpf = 58935892982;
	codigoCliente(auxR);
	listClient[3].codClient = codigoCliente(auxR);
	strcpy(auxR.sexo, "M");
	strcpy(auxR.tel.fixo, "(43)3066-2870");
	strcpy(auxR.tel.movel, "(43)99157-4920");
	listClient[3] = auxR;
	
	strcpy(auxR.nome, "Ana");
	auxR.cpf = 578934573484;
	codigoCliente(auxR);
	listClient[4].codClient = codigoCliente(auxR);
	strcpy(auxR.sexo, "F");
	strcpy(auxR.tel.fixo, "(43)3066-2870");
	strcpy(auxR.tel.movel, "(43)99157-4920");
	listClient[4] = auxR;
	
};

void ListaClient(struct Clientes *listClient){ // Listagem de Clientes
	int j = 0;
	
	printf("\n Clientes Cadastrados \n");

	do{
		printf("%d - ", listClient[j].codClient); 
		printf("%s - %s - %lf - %s \n", listClient[j].nome, listClient[j].tel.movel, listClient[j].cpf, listClient[j].sexo);
		j++;
	} while(j < c);
	system("pause");
	
}; // Fim da Listagem de Clientes


int codigoProduto(struct Produtos auxP){ // Gera o codigo do produto
	
	char *temp, *aux;
	aux = malloc(sizeof(char));
	temp = malloc(sizeof(int));
	strncpy(aux, auxP.nome, 3);
	//aux[2] = "\0";
	auxP.codProd = *aux;
	if (auxP.codProd < 0){
		auxP.codProd *= -1;
		//printf("%d", auxP.codProd);
	} else {
		//printf("%d", auxP.codProd);
	}
	
	temp = NULL;
	aux = NULL;
	free(temp);
	free(aux);
	//auxP.codProd = auxP.codProd / 1000; 
	return auxP.codProd;
}

struct Produtos Products(struct Produtos *prodList){ // Cadastro de Produtos
	
	struct Produtos auxP;
	
	system("cls");
	printf("Nome do Produto: ");
	scanf("%s", auxP.nome);
	fflush(stdin);
	
	codigoProduto(auxP);
	auxP.codProd = codigoProduto(auxP);
	
	printf("Inserir Marca: ");
	scanf("%s", auxP.model.marca);
	fflush(stdin);
	
	printf("Inserir Modelo: ");
	scanf("%s", auxP.model.modelo);
	fflush(stdin);
	
	printf("Inserir valor: ");
	scanf("%lf", &auxP.valor);
	fflush(stdin);
	
	prodList[p] = auxP;
	p++;
	
	printf("Codigo do produto: %d \n", auxP.codProd);
	system("pause");
	return auxP;
	
};


void exampleProds(struct Produtos *prodList){ //Add produtos de exemplo
	struct Produtos auxP;
	
	strcpy(auxP.nome, "Escova");
	codigoProduto(auxP);
	strcpy(auxP.model.marca, "Colgate");
	strcpy(auxP.model.modelo, "Speed");
	auxP.valor = 2.50; //Aqui arredonda mas no codigo n
	prodList[0] = auxP;
	
	strcpy(auxP.nome, "Arroz");
	codigoProduto(auxP);
	strcpy(auxP.model.marca, "Tio Joao");
	strcpy(auxP.model.modelo, "5KG");
	auxP.valor = 12.30; //Aqui arredonda mas no codigo n
	prodList[1] = auxP;
	
	strcpy(auxP.nome, "Geladeira");
	codigoProduto(auxP);
	strcpy(auxP.model.marca, "Consul");
	strcpy(auxP.model.modelo, "200L");
	auxP.valor = 120.30; //Aqui arredonda mas no codigo n
	prodList[2] = auxP;
	
	strcpy(auxP.nome, "Feijao");
	codigoProduto(auxP);
	strcpy(auxP.model.marca, "Feijuca");
	strcpy(auxP.model.modelo, "3KG");
	auxP.valor = 6.80; //Aqui arredonda mas no codigo n
	prodList[3] = auxP;
	
	strcpy(auxP.nome, "Panela Anti-aderente");
	codigoProduto(auxP);
	strcpy(auxP.model.marca, "Panelas SA");
	strcpy(auxP.model.modelo, "Vermelha");
	auxP.valor = 120.30; //Aqui arredonda mas no codigo n
	prodList[4] = auxP;

};

void ListProd(struct Produtos *prodList){ //Listagens de Produtos
	int j = 0;
	printf("	Produtos Disponiveis \n");
	
	do{
		printf("%d - ", prodList[j].codProd);
		printf("%s - R$ %.0lf - %s - %s \n", prodList[j].nome, prodList[j].valor, prodList[j].model.marca, prodList[j].model.modelo);
		j++;
	} while(j < p);
	system("pause");
};





struct Carrinho compras(struct Clientes *listClient, struct Produtos *prodList, struct Carrinho *car){
	system("cls");
	int buying;
	int j = 0;
	do{
		printf("%d - ", prodList[j].codProd);
		printf("%s - R$ %.0lf - %s - %s \n", prodList[j].nome, prodList[j].valor, prodList[j].model.marca, prodList[j].model.modelo);
		j++;
	} while(j < p);
	printf("Quais itens estara comprando %s", car[b].client[b].nome);
	scanf("%d", &buying);
	
};

struct Clientes gpsClient(int escolheClient, struct Clientes *listClient, struct Produtos *prodList, struct Carrinho *car){
	int confirm = 0;
	int j = 0;
	
	while (confirm != 1){
		if (escolheClient == listClient[j].codClient){ //Compara a entrada com os cod de client
			confirm = 1;
			car[b].client[b] = listClient[j];
			compras(listClient, prodList, car);
		} else {
			if (j >= 10){
				printf("Cliente Inexistente");
				main();
			}
			j++;
		}
	}
}

struct Carrinho Selling(struct Clientes *listClient, struct Produtos *prodList, struct Carrinho *car){ //Comecar solicitando o codClient
	system("cls");
	int escolheClient;
	int j = 0;

	printf("\n Clientes Cadastrados \n");
	do{
		printf("%d - ", listClient[j].codClient); 
		printf("%s - %s - %lf - %s \n", listClient[j].nome, listClient[j].tel.movel, listClient[j].cpf, listClient[j].sexo);
		j++;
	} while(j < c);
	printf("\nDigitar Codigo do Cliente que ira fazer a compra: ");
	scanf("%d", &escolheClient);
	
	gpsClient(escolheClient, listClient, prodList, car); //Localiza quem e o client
	
};

int Escolha(int *a, struct Clientes *listClient, struct Produtos *prodList, struct Carrinho *car){ // Funcao para chamada da funcao do menu
	
	do{ //So pode passar uma vez ou buga as listagens
		exampleClient(listClient);
		exampleProds(prodList);
		*a = 1;
	} while (*a != 1);
	
	int *res; //Escolha, fiz com ponteiro pra tentar usar o maximo possivel e estudar
	res = (int *) malloc(sizeof(int));
	scanf("%d", &*res);
	fflush(stdin);
	
	switch (*res){
		case 1:	
			Register(listClient); //Add Cliente
		break;
				
		case 2:
			Products(prodList); //Add Produto
		break;
		
		case 3:
			ListaClient(listClient); //Listagens de Clientes
		break;

        case 4:
        	ListProd(prodList); //Listagens de Produtos
		break;
		
		case 5:
			Selling(listClient, prodList, car); // Vendas
		break;
		
		case 0:
			printf("Encerrando!"); // Ja diz tudo
			exit(0);
		break;
		
		default:
			Escolha(a, listClient, prodList, car); // Valores diferentes de 1~5
	}
	
	return *res;
		
}; // Fim da funcao de chamada do menu

void Menu(){ // Chama parte grafica do menu e "algumas" variaveis

	struct Clientes listClient[10];
	struct Produtos prodList[10];
	struct Carrinho car[3];
	p = 5;
	c = 5;
	int x;
	int *a;
	a = malloc(sizeof(int));
	*a = 0;
	
	do{
		system("cls");
		printf("[1] - Registrar Clientes \n");
		printf("[2] - Registrar Produto \n");
		printf("[3] - Listar Clientes \n");
		printf("[4] - Listar Produtos \n");
		printf("[5] - Comprar Produtos \n");
		printf("[0] - Sair \n");
		x = Escolha(a, listClient, prodList, car);
	} while (x != 0);
	
}; // Fim da Chamada grafica do menu

void main(){ // Chamada da funcao menu apenas
	
    Menu();

} // Fim da Main
