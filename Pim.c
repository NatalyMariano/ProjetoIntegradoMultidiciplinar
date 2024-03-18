#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

int cod1 = 123456;
int ultimoCodigo = 0;

typedef struct {
    int tipo;
    int codigo;
} ingresso;

typedef struct{
    char login[30];
    char senha[30];
} pessoa; pessoa p[1];

int menu();
void terminal();
void exibirObra();
int exibirQuestionario();
void validacaoDeIngresso();
void venda();
int gerarCodigo();
int validaCod(int codigo);
void gravaIngressos(ingresso lista[], int tamanho);
int login();
void areaAdm();
int exibirRelatorio();


int main(){
    setlocale(LC_ALL, "pt");
    int opcao = 0;
    while( opcao >=0){
        opcao = menu();
    }
}

int menu()
{
    int menu;
    printf("Escolha a opção desejada:\n");
    printf("1-Terminal de exibição\n");
    printf("2-Vendas\n");
    printf("3-Validação de ingresso\n");
    printf("4-Area do administrador\n");
    scanf("%d", &menu);
    system("cls");

     switch (menu) {
        case 1:
            terminal();
            break;
        case 2:
            venda();
            break;
        case 3:
            validacaoDeIngresso();
            break;
        case 4:
            areaAdm();
            break;
        default:
            break;
           
    }
    return menu;
}

void venda()
{
    int tipoIngresso;
    int qtdMeiaEntrda;
    int qtdMeiaSolidaria;
    int qtdInteira;
    int vlrMeiaEntrada = 15;
    int vlrMeiaSolidaria = 15;
    int vlrInteira = 30;
    int totalVenda;
    int metodoPagamento;
    int totalIngressos;
    
    printf("VENDA DE INGRESSO\n");
    printf("\n");
    printf("PLOTICA DE INGRESSOS:\n");
    printf("\n");
    printf("Meia entrada (Valida para estudantes, menores de 12 anos, maiores de 60 e funcionarios publicos)\n");
    printf("Meia Solidaria (Venda mediante a doação de alimento na entrada)\n");
    printf("\n");
    printf("VALOR\n");
    printf("\n");
    printf("Meia R$15,00\n")/
    printf("Inteira R$30,00\n");
    printf("\n");
    printf("\n");
    printf("Quantas Meias entradas voce deseja?\n");
    scanf("%d", &qtdMeiaEntrda);
    printf("Quantas Meias Solidarias voce deseja?\n");
    scanf("%d", &qtdMeiaSolidaria);
    printf("Quantas Inteiras voce deseja?\n");
    scanf("%d", &qtdInteira);
    totalVenda = qtdInteira * vlrInteira + qtdMeiaEntrda * vlrMeiaEntrada + qtdMeiaSolidaria * vlrMeiaSolidaria;
    printf("Sua compra ficou em: %d", totalVenda);
    printf("\n");
    printf("METODO DE PAGAMENTO:\n");
    printf("\n");
    printf("\n");
    printf("Escolha o metodo desejado:\n");
    printf("\n");
    printf("1-Pix\n");
    printf("2-Cartão de Debito\n");
    printf("3-Cartão de Credito\n");
    scanf("%d", &metodoPagamento);
    system("cls");
    printf("Pagamento aprovado!\n");
    printf("\n");
    totalIngressos = qtdInteira + qtdMeiaEntrda + qtdMeiaSolidaria;
    ingresso ingressos[totalIngressos];
    int i=0;
    int pos=0;
    for (i=0; i < qtdInteira; i++) {
       ingressos[pos].tipo=1;
       ingressos[pos].codigo=gerarCodigo();
        printf("Codigo do ingresso %d: %d \n", pos+1, ingressos[pos].codigo);
        pos++;
    }
    for (i=0; i < qtdMeiaEntrda; i++) {
       ingressos[pos].tipo=2;
       ingressos[pos].codigo=gerarCodigo();
        printf("Codigo do ingresso %d: %d \n", pos+1, ingressos[pos].codigo);
        pos++;
    }
    for (i=0; i < qtdMeiaSolidaria; i++) {
       ingressos[pos].tipo=3;
       ingressos[pos].codigo=gerarCodigo();
        printf("Codigo do ingresso %d: %d \n", pos+1, ingressos[pos].codigo);
        pos++;
    }
   gravaIngressos(ingressos, totalIngressos);
} 

 int gerarCodigo(){
    if (ultimoCodigo == 0) {
        ultimoCodigo = cod1;
        return ultimoCodigo;
    }
    ultimoCodigo += 1;
    return ultimoCodigo;
 }
int validaCod(int codigo){
    if(codigo >= cod1 && codigo <=ultimoCodigo) {
        return 1;
    }
    return 0;
}
 
 void validacaoDeIngresso(){
    int codigo;
    int qtdIngresso;

    printf("Quantos ingressos deseja validar?\n");
    scanf("%d", &qtdIngresso);

    for(int i=0; i<qtdIngresso; i++){
     printf("Digite o codigo do ingresso para validar: \n");
     scanf("%d", &codigo);
        if(validaCod(codigo)==1){
        printf("Codigo valido\n");
    }
        else{
        printf("Codigo invalido\n");
    }
}
   
    char botao;

    fflush(stdin); 
    printf("Aperte um botão para confirmar\n");
    scanf("%c", &botao);
 }

 void terminal()
{
   int terminalObra = 0;
    while(terminalObra >=0){
        exibirObra();
        terminalObra = exibirQuestionario();
//quando quer sair digita -1
    }
}


void exibirObra()
{
    system("cls");
    FILE *arq;
    char Linha[350];
    char *result;

    arq = fopen("TochaOlimpica.txt", "r");
    if (arq == NULL)
    {
        printf("Problema na abertura do arquivo\n");
        return;
    }

    while (!feof(arq))
    {
        result = fgets(Linha, 350, arq);
        if (result)
            printf("%s", Linha);

    }
    fclose(arq);

}

int exibirQuestionario()
{

    int responderQuestionario;
    int respostas[5]={0};

    printf("\nDeseja responder o questionario?\n");
    printf("1- SIM\n");
    printf("2- NAO\n");
    scanf("%d", &responderQuestionario);
    if(responderQuestionario==1)
    {
        system("cls"); 
        printf(" É a primeira vez que você visita este Museu?\n");
        printf("1-SIM\n");
        printf("2-NAO\n");
        scanf("%d", &respostas[0]);

        printf("Qual é a sua impressão geral sobre a exposição das Olimpíadas de 2024 neste museu?\n");
        printf("1-Muito Insatisfeito\n");
        printf("2-Insatisfeito\n");
        printf("3-Neutro \n");
        printf("4-Satisfeito\n");
        printf("5-Muito Satisfeito\n");
        scanf("%d", &respostas[1]);

        printf("Como você avaliaria a interatividade da exposição, incluindo as atividades práticas e as oportunidades de aprendizado?\n");
        printf("1-Insatisfatório\n");
        printf("2-Precisa de Melhorias\n");
        printf("3-Suficiente \n");
        printf("4-Bom\n");
        printf("5-Excelente\n");
        scanf("%d", &respostas[2]);

        printf("Como você classificaria a acessibilidade do museu, incluindo a facilidade de acesso, as instalações para visitantes com necessidades especiais e a disponibilidade de estacionamento?\n");
        printf("1-Insatisfatório\n");
        printf("2-Precisa de Melhorias\n");
        printf("3-Suficiente \n");
        printf("4-Bom\n");
        printf("5-Excelente\n");
        scanf("%d", &respostas[3]);

        printf("O museu forneceu informações relevantes e atualizadas sobre as Olimpíadas de 2024?\n");
        printf("1-SIM\n");
        printf("2-NAO\n");
        scanf("%d", &respostas[4]);

        FILE*arqRespostas;
        int i;

    arqRespostas = fopen("respostasQuestionario.txt", "a"); 
        if(arqRespostas == NULL){
            printf("erro na criação do arquivo");
            return responderQuestionario;
        }
        for (i=0;i<5;i++){
            fprintf(arqRespostas, "%d;", respostas[i]);
        }
        fprintf(arqRespostas, "\n");

        fclose(arqRespostas);
    }
    return responderQuestionario;

}

void gravaIngressos(ingresso lista[], int tamanho){
    FILE*arqIngressos;
    int i;

    arqIngressos = fopen("Ingressos.txt", "a"); 
    if(arqIngressos == NULL){
        printf("erro na criação do arquivo");
        return ;
    }
    for (i=0;i<tamanho;i++){
        fprintf(arqIngressos, "%d;%d\n", lista[i].tipo, lista[i].codigo);
    }
    
    fclose(arqIngressos);
    
}

int login(){
    char login[30];
    char senha[30];

    strcpy(p[0].login, "Nataly");
    strcpy(p[0].senha, "Lulu02");

    printf("\n\t\tlogin:");
    scanf("%s", login);
    printf("\n\t\tsenha:");
    scanf("%s", senha);

    if ( (strcmp(login, p[0].login)==0) && (strcmp(senha,p[0].senha)==0)){
         printf("\nUsuário logado\n");
         return 1;
    }
    else{
        printf("Login e/ou senha incorretos\n");
        return 0;
    }
    

}

void areaAdm(){
    int loginValido = login();
    int arqIngresso;
    char botao;

    if(loginValido == 1){
       exibirRelatorio();
       fflush(stdin);
       printf("\naperte qualquer botão botão para sair\n");
       scanf("%c", &botao);
    }

}

int exibirRelatorio(){

    int codIngresso;
    int tipoIngrsso;
    int qtdMeiaSolidaria=0, qtdMeiaEntrda=0, qtdInteira=0, qtdTotal=0, valorInteira, valorMeiaEntrada, valorMeiaSolidaria, valorTotal;

     printf("\nRelatorio de vendas\n");
        
         FILE*arqIngresso;
         int i;

    arqIngresso = fopen("Ingressos.txt", "r");
    while(!feof(arqIngresso)){
        fscanf(arqIngresso,"%d;%d", &tipoIngrsso, &codIngresso);
        if(tipoIngrsso==1){
            qtdInteira +=1;
        }
        else if(tipoIngrsso==2){
            qtdMeiaEntrda +=1;
        }
        else if(tipoIngrsso==3){
            qtdMeiaSolidaria +=1;
        }
    }
    
    qtdTotal = qtdInteira + qtdMeiaEntrda + qtdMeiaSolidaria;
    valorInteira = qtdInteira * 30;
    valorMeiaEntrada = qtdMeiaEntrda * 15;
    valorMeiaSolidaria = qtdMeiaSolidaria * 15;
    valorTotal = valorInteira + valorMeiaEntrada + valorMeiaSolidaria;

    printf("\n");
    printf("Quantidade de Inteiras vendidas: %d\n", qtdInteira);
    printf("Quantidade de Meias Entrdas vendidas: %d\n", qtdMeiaEntrda);
    printf("Quantidade de Meias Solidarias vendidas: %d\n", qtdMeiaSolidaria);
    printf("Quantidade total de ingressos vendidos: %d\n", qtdTotal);
    printf("Valor total de Inteiras: %d\n", valorInteira);
    printf("Valor total de Meia Entrada: %d\n", valorMeiaEntrada);
    printf("Valor total de Meia Solidaria: %d\n", valorMeiaSolidaria);
    printf("Valor total de vendas: %d\n", valorTotal);
}