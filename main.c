#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
struct Cliente{
//código, nome, endereço, telefone, data de nascimento
int codigo;
char nome[20];
char endereco[20];
char telefone[20];
int dia;
int mes;
int ano;
};
struct funcionario{
//código, nome, telefone, função, salario, tipo (temporário ou fixo)
int codigo;
char nome[20];
char telefone[20];
char funcao[20];
float salario;
char tipo[20];
};
struct fornecedor{
//código, nome, telefone, produto fornecido
int codigo;
char nome[20];
char telefone[20];
char produto[20];
};
struct festa{
//código festa, quantidade de convidados, data, dia da semana, horário (inicio e fim),tema, código cliente,
int codigo;
int quantidadeConvidados;
int dia;
int mes;
int ano;
int diaSemana;
int horarioInicio;
int horarioFim;
char tema[20];
int codigoCliente;
};
struct contrato{
//número contrato, valor total, desconto, valor final, forma de pagamento, status, código festa
int numeroContrato;
int valorTotal;
int desconto;
int valorFinal;
char formaPagamento[20];
char status[20];
int codigFesta;
};
void cadastraCliente(struct Cliente);//Esta função cadastra todos os dados da Struct Cliente no arquivo txt clientes
void cadastraFunc(struct funcionario);
void cadastraFesta(struct festa);
void cadastraFornecedor(struct fornecedor);
void calculaFesta(int,int,int);
void alteraStatus();
void listaClientes();
void listaFestas();
void listaFunc();
void listaForn();
void listadatas();
void pesquisaCliente();
int main()
{
    struct Cliente NovoCliente;
    struct funcionario NovoFuncionario;
    struct fornecedor NovoFornecedor;
    struct festa NovaFesta;
    int opcao=50;
    setlocale(LC_ALL,"");
    printf("\n\n------   Bem vindo ao Salão de Festas Patati & Patata   ------\n");
    printf("------              A sua festa é a nossa               ------\n");
    printf("\n\nMENU PRINCIPAL                        \n\n");
    while (opcao != 0){
        printf("1 - Cadastrar Cliente\n2 - Cadastrar Funcionario\n3 - Cadastrar Fornecedor\n4 - Cadastrar nova Festa\n5 - Alterar Status de festa\n6 - Pesquisar Cliente\n7 - Listar Festas de cliente\n8 - Listar Funcionarios\n9 - Listar Fornecedores\n0 - Sair\n\nSua opção: ");
        scanf("%d",&opcao);
        switch ( opcao ){
            case 1 :
            cadastraCliente(NovoCliente);
            break;

            case 2 :
            cadastraFunc(NovoFuncionario);
            break;

            case 3 :
            cadastraFornecedor(NovoFornecedor);
            break;

            case 4 :
            cadastraFesta(NovaFesta);
            break;

            case 5 :
            listaFestas();
            alteraStatus();
            int escolha;
            printf("Deseja ver festas Pagas?\n");
            printf("[1 para sim /2 para não]: ");
            scanf("%d",&escolha);
            int c;
            FILE*escolhe;
            escolhe=fopen("pagos.txt","r+");
            if(escolha==1){
                do{
                    c=fgetc(escolhe);
                    if(c!=EOF){
                    printf("%c",c);
                    }
                }while(c!=EOF);
            }
            fclose(escolhe);
            break;

            case 6 :
            pesquisaCliente();
            break;

            case 7 :
            listaFestas();
            printf("\n\n");
            break;
            case 8 :
            listaFunc();
            break;
            case 9 :
            listaForn();
            break;
            case 0:
            printf("Obrigado caro cliente!\n\n");
            break;
            default :
            printf ("Valor invalido!\n");
        }


    }
    return 0;
}
void cadastraCliente(struct Cliente x){
    FILE*cliente;
    cliente = fopen("clientes.txt","a");
    FILE*exibecliente;
    exibecliente = fopen("exibeclientes.txt","a");
    FILE*codigos;
    char z  = '\n';
    codigos = fopen("codigos.txt","r+");
    int c;
    int contador=0;
    while(c!=EOF){
        c=fgetc(codigos);
        if(c=='\n'){contador++;}
    }
    x.codigo = contador+1;
    fputc(z,codigos);
    fprintf(codigos,"%d",x.codigo);
    fclose(codigos);
    fprintf(cliente,"%d",x.codigo);
    fprintf(exibecliente,"Codigo: %d",x.codigo);
    fputc(z,cliente);
    fputc(z,exibecliente);
    printf("Nome: ");
    fflush(stdin);
    gets(x.nome);
    fprintf(exibecliente,"Nome: %s",x.nome);
    int TamStr;
    int i;
    TamStr = strlen(x.nome);
    for(i=0; i<TamStr; i++)
    {
     x.nome[i] = toupper (x.nome[i]);
    }
    fprintf(cliente,"%s",x.nome);
    fputc(z,cliente);
    fputc(z,exibecliente);
    printf("Endereco: ");
    fflush(stdin);
    gets(x.endereco);
    fprintf(cliente,"%s",x.endereco);
    fprintf(exibecliente,"Endereço: %s",x.endereco);
    fputc(z,cliente);
    fputc(z,exibecliente);
    printf("Data de nascimento - Dia: ");
    scanf("%d",&x.dia);
    fprintf(cliente,"%d/",x.dia);
    fprintf(exibecliente,"Nascimento: %d/",x.dia);
    printf("Mês(outubro = 10): ");
    scanf("%d",&x.mes);
    fprintf(cliente,"%d/",x.mes);
    fprintf(exibecliente,"%d/",x.mes);
    printf("Ano: ");
    scanf("%d",&x.ano);
    fprintf(cliente,"%d",x.ano);
    fprintf(exibecliente,"%d",x.ano);
    fputc(z,cliente);
    fputc(z,exibecliente);
    fflush(stdin);
    printf("Telefone de contato: ");
    gets(x.telefone);
    fprintf(exibecliente,"Telefone: %s",x.telefone);
    fprintf(cliente,"%s",x.telefone);
    fputc(z,cliente);
    fputc(z,exibecliente);
    fputc(z,exibecliente);
    fclose(exibecliente);
    fclose(cliente);
}
void cadastraFunc(struct funcionario x){
    //código, nome, telefone, função, salario, tipo (temporário ou fixo)
    FILE*funcionario;
    funcionario = fopen("funcionarios.txt","a");
    FILE*exibe;
    exibe = fopen("exibefuncionarios.txt","a");
    FILE*codigos;
    char z  = '\n';
    codigos = fopen("codigosfuncionarios.txt","r+");
    int c;
    int contador=0;
    while(c!=EOF){
        c=fgetc(codigos);
        if(c=='\n'){contador++;}
    }
    x.codigo = contador+1;
    fputc(z,codigos);
    fprintf(codigos,"%d",x.codigo);
    fprintf(exibe,"Codigo: %d",x.codigo);
    fclose(codigos);
    fprintf(funcionario,"%d",x.codigo);
    fputc(z,funcionario);
    fputc(z,exibe);
    printf("Nome: ");
    fflush(stdin);
    gets(x.nome);
    fprintf(exibe,"Nome: %s",x.nome);
    int TamStr;
    int i;
    TamStr = strlen(x.nome);
    for(i=0; i<TamStr; i++)
    {
     x.nome[i] = toupper (x.nome[i]);
    }
    fprintf(funcionario,"%s",x.nome);
    fputc(z,funcionario);
    fputc(z,exibe);
    printf("Funçao: ");
    fflush(stdin);
    gets(x.funcao);
    fprintf(funcionario,"%s",x.funcao);
    fprintf(exibe,"Funcao: %s",x.funcao);
    fputc(z,funcionario);
    fputc(z,exibe);
    printf("Salario: ");
    scanf("%f",&x.salario);
    fprintf(funcionario,"%.2f",x.salario);
    fprintf(exibe,"Salario: %.2f",x.salario);
    fputc(z,funcionario);
    fputc(z,exibe);
    fflush(stdin);
    printf("Tipo(temporário ou fixo): ");
    gets(x.tipo);
    fprintf(funcionario,"%s",x.tipo);
    fprintf(exibe,"Tipo: %s",x.tipo);
    fputc(z,funcionario);
    fputc(z,exibe);
    printf("Telefone de contato: ");
    fflush(stdin);
    gets(x.telefone);
    fprintf(exibe,"Telefone: %s",x.telefone);
    fprintf(funcionario,"%s",x.telefone);
    fputc(z,exibe);
    fputc(z,funcionario);
    fclose(funcionario);
    fclose(exibe);
}
//código festa, quantidade de convidados, data, dia da semana, horário (inicio e fim),tema, código cliente,
void cadastraFesta(struct festa x){
    FILE*festa;
    festa = fopen("festa.txt","a");
    FILE*exibefesta;
    exibefesta = fopen("exibefesta.txt","a");
    FILE*codigos;
    char z  = '\n';
    codigos = fopen("codigosfestas.txt","r+");
    int c;
    int contador=0;
    while(c!=EOF){
        c=fgetc(codigos);
        if(c=='\n'){contador++;}
    }
    x.codigo = contador+1;
    fputc(z,codigos);
    fprintf(codigos,"%d",x.codigo);
    fclose(codigos);
    fputc(x.codigo,festa);
    fprintf(exibefesta,"Codigo: %d",x.codigo);
    fputc(z,festa);
    fputc(z,exibefesta);
    printf("Quantidade de convidados: ");
    scanf("%d",&x.quantidadeConvidados);
    if(x.quantidadeConvidados>100){
        printf("Máximo de convidados = 100! Insira um novo valor: ");
        scanf("%d",&x.quantidadeConvidados);
    }
    fprintf(festa,"%d",x.quantidadeConvidados);
    fprintf(exibefesta,"Numero de convidados: %d",x.quantidadeConvidados);
    fputc(z,festa);
    fputc(z,exibefesta);
    fflush(stdin);
    printf("Datas indisponívies:\n");
    listadatas();
    printf("Data da festa - Dia: ");
    scanf("%d",&x.dia);
    printf("Mês(outubro = 10): ");
    scanf("%d",&x.mes);
    printf("Ano: ");
    scanf("%d",&x.ano);
    FILE*data;
    data=fopen("datas.txt","a+");
    fprintf(data,"Festa %d:",x.codigo);
    fprintf(data,"%d/",x.dia);
    fprintf(data,"%d/",x.mes);
    fprintf(data,"%d",x.ano);
    fputc(z,data);
    fclose(data);
    fprintf(festa,"%d",x.dia);
    fprintf(exibefesta,"Data: %d/",x.dia);
    fprintf(festa,"%d",x.mes);
    fprintf(exibefesta,"%d/",x.mes);
    fprintf(festa,"%d",x.ano);
    fputc(z,festa);
    fprintf(exibefesta,"%d\n",x.ano);
    fflush(stdin);
    printf("Dia da semana!\n1 para Segunda\n2 para Terca\n3 para Quarta\n4 para Quinta\n5 para Sexta\n6 para Sábado\n7 para domingo\nDia da semana: ");
    scanf("%d",&x.diaSemana);
    fprintf(festa,"%d",x.diaSemana);
    if(x.diaSemana==1){
        fputs("Dia da Semana: Segunda\n",exibefesta);
    }else if(x.diaSemana==2){
        fputs("Dia da Semana: Terca\n",exibefesta);
    }else if(x.diaSemana==3){
        fputs("Dia da Semana: Quarta\n",exibefesta);
    }else if(x.diaSemana==4){
        fputs("Dia da Semana: Quinta\n",exibefesta);
    }else if(x.diaSemana==5){
        fputs("Dia da Semana: Sexta\n",exibefesta);
    }else if(x.diaSemana==7){
        fputs("Dia da Semana: Domingo\n",exibefesta);
    }
    int escolhadia;
    if(x.diaSemana==6){
        fputs("Dia da Semana: Sabado\n",exibefesta);
        printf("No Sábado o salão possui dois horários:\nOpção 1: 12 ás 16\nOpção 2: 18 às 22\nSua Escolha: ");
        scanf("%d",&escolhadia);
        if(escolhadia==1){
            x.horarioInicio = 12;
            x.horarioFim = 16;
            fprintf(festa,"%d",x.horarioInicio);
            fprintf(festa,"%d",x.horarioFim);
        }else if(escolhadia==2){
            x.horarioInicio = 18;
            x.horarioFim = 22;
            fprintf(festa,"%d",x.horarioInicio);
            fprintf(festa,"%d",x.horarioFim);
        }
    }else{
    printf("O salão funciona de 13h às 00h!\n");
    printf("Horário do início da festa(formato 24h): ");
    scanf("%d",&x.horarioInicio);
    printf("Horário do fim: ");
    scanf("%d",&x.horarioFim);
    }

    if(x.horarioFim > 00&& x.horarioFim<12){
        printf("O salão funciona até as 00:00");
        printf("Horário do fim: ");
        scanf("%d",&x.horarioFim);
    }
    if(x.horarioFim-x.horarioInicio>4||x.horarioFim-x.horarioInicio<-4){
        printf("Horário máximo de festa = 4 horas\n");
        printf("Horário do início da festa(formato 24h): ");
        scanf("%d",&x.horarioInicio);
        printf("Horário do fim: ");
        scanf("%d",&x.horarioFim);
    }
    fprintf(festa,"%d",x.horarioInicio);
    fprintf(festa,"%d",x.horarioFim);
    fprintf(exibefesta,"Horario de inicio: %d",x.horarioInicio);
    fputc(z,exibefesta);
    fprintf(exibefesta,"Horario do fim: %d",x.horarioFim);
    fputc(z,festa);
    fputc(z,exibefesta);
    printf("Tema da festa: ");
    fflush(stdin);
    gets(x.tema);
    fprintf(festa,"%s",x.tema);
    fprintf(exibefesta,"Tema da festa: %s",x.tema);
    fputc(z,festa);
    fputc(z,exibefesta);
    listaClientes();
    printf("Código do cliente: ");
    scanf("%d",&x.codigoCliente);
    fputc(z,festa);

    fprintf(festa,"%d",x.codigoCliente);
    fprintf(exibefesta,"Cliente: %d",x.codigoCliente);
    fputc(z,festa);
    fputc(z,exibefesta);
    fputc(z,festa);
    fputc(z,exibefesta);
    fclose(festa);
    fclose(exibefesta);
    int parcelas;
    printf("Quantas vezes vai pagar a festa (0 para a vista ou 1,2,3 para parcelar de 1x / 2x / 3x): ");
    scanf("%d",&parcelas);
    calculaFesta(x.quantidadeConvidados,x.diaSemana,parcelas);
    FILE*contrato;
    contrato = fopen("contratos.txt","a");
    fprintf(contrato,"Festa: %d",x.codigo);
    char w='W';
    fputc(w,contrato);
    fputc(z,contrato);
    fclose(contrato);

}
void calculaFesta(int convidados,int diaSemana,int parcelas){
    int diaEscolhido;
    float valor;
    float valorFinal;
    if (convidados<=30){
        if (diaEscolhido >=1 && diaEscolhido<=4){
            valor = 1899;
        }else{
            valor = 2099;
        }
        if(parcelas==0){
            valorFinal=valor-valor*0.1;
        }else if(parcelas==2){
            valorFinal=valor-valor*0.05;
        }else if(parcelas==3){
            valorFinal=valor-valor*0.02;
        }
    }
    else if(convidados>30 && convidados<=80){
        if (diaEscolhido >=1 && diaEscolhido<=4){
            valor = 2199;
        }else{
            valor = 2299;
        }
        if(parcelas==0){
            valorFinal=valor-valor*0.1;
        }else if(parcelas==2){
            valorFinal=valor-valor*0.05;
        }else if(parcelas==3){
            valorFinal=valor-valor*0.02;
        }
    }
    else if(convidados>80 && convidados<=100){
        if (diaEscolhido >=1 && diaEscolhido<=4){
            valor = 3199;
        }else{
            valor = 3499;
        }
        if(parcelas==0){
            valorFinal=valor-valor*0.1;
        }else if(parcelas==2){
            valorFinal=valor-valor*0.05;
        }else if(parcelas==3){
            valorFinal=valor-valor*0.02;
        }
    }else{
        if (diaEscolhido >=1 && diaEscolhido<=4){
            valor = 3799;
        }else{
            valor = 3999;
        }
        if(parcelas==0){
            valorFinal=valor-valor*0.1;
        }else if(parcelas==2){
            valorFinal=valor-valor*0.05;
        }else if(parcelas==3){
            valorFinal=valor-valor*0.02;
        }
    }
    float desconto = valorFinal - valor;
    struct contrato x;
    FILE*contrato;
    contrato = fopen("contratos.txt","a");
    FILE*codigos;
    char z  = '\n';
    codigos = fopen("numerocontrato.txt","r+");
    int c;
    int contador=0;
    while(c!=EOF){
        c=fgetc(codigos);
        if(c=='\n'){contador++;}
    }
    x.numeroContrato = contador+1;
    fputc(z,codigos);
    fprintf(codigos,"%d",x.numeroContrato);
    fclose(codigos);
    fprintf(contrato,"Numero do contrato:%d",x.numeroContrato);
    fputc(z,contrato);
    fprintf(contrato,"Valor inicial: %.2f",valor);
    fputc(z,contrato);
    fprintf(contrato,"Desconto: %.2f",desconto);
    fputc(z,contrato);
    fprintf(contrato,"Valor final: %.2f",valorFinal);
    fputc(z,contrato);
    fprintf(contrato,"Parcelas: %dx",parcelas);
    fputc(z,contrato);
    fputs("Status; ",contrato);
    fputc(z,contrato);
    fclose(contrato);
}

void listaClientes(){
    FILE*cliente;
    cliente = fopen("exibeclientes.txt","r");
    int c;
    do{
        c = fgetc(cliente);
        if(c!=EOF){
        printf("%c",c);
        }
    }while(c!=EOF);
}
//código, nome, telefone, produto fornecido
void cadastraFornecedor(struct fornecedor x){
    FILE*fornecedor;
    fornecedor = fopen("fornecedor.txt","a");
    FILE*exibe;
    exibe = fopen("exibefornecedor.txt","a");
    FILE*codigos;
    char z  = '\n';
    codigos = fopen("codigosfornecedor.txt","r+");
    int c;
    int contador=0;
    while(c!=EOF){
        c=fgetc(codigos);
        if(c=='\n'){contador++;}
    }
    x.codigo = contador+1;
    fputc(z,codigos);
    fprintf(codigos,"%d",x.codigo);
    fclose(codigos);
    fputc(z,fornecedor);
    fputc(z,exibe);
    fprintf(fornecedor,"%d",x.codigo);
    fprintf(exibe,"Codigo: %d",x.codigo);
    fputc(z,fornecedor);
    fputc(z,exibe);
    printf("Nome do fornecedor: ");
    fflush(stdin);
    gets(x.nome);
    fprintf(exibe,"Nome: %s",x.nome);
    int TamStr;
    int i;
    TamStr = strlen(x.nome);
    for(i=0; i<TamStr; i++)
    {
     x.nome[i] = toupper (x.nome[i]);
    }
    fprintf(fornecedor,"%s",x.nome);
    fputc(z,fornecedor);
    fputc(z,exibe);
    fflush(stdin);
    printf("Telefone: ");
    gets(x.telefone);
    fprintf(fornecedor,"%s",x.telefone);
    fprintf(exibe,"Contato: %s",x.telefone);
    fputc(z,fornecedor);
    fputc(z,exibe);
    printf("Produto fornecido: ");
    fflush(stdin);
    gets(x.produto);
    fprintf(fornecedor,"%s",x.produto);
    fprintf(exibe,"Produto: %s",x.produto);
    fputc(z,fornecedor);
    fputc(z,exibe);
    fclose(fornecedor);
    fclose(exibe);
}

void alteraStatus(){
    int festa;
    char z='\n';
    printf("Qual festa deseja alterar o status? Festa: ");
    scanf("%d",&festa);
    FILE*contrato;
    contrato = fopen("contratos.txt","a+");
    int tam;
    if(festa==1){
        tam=0;
    }else{
        tam = ((festa-1)*116);
    }
    char pago='p';
    int c;
    int i;
    for(i=0;i<tam;i++){
        c = fgetc(contrato);
    }
     do{
        c = fgetc(contrato);
        if(c!=';'){
        }
    }while(c!=';');
    FILE*pagos;
    pagos=fopen("pagos.txt","a+");
    do{
        c = fgetc(contrato);
        if(c!='W'){
        fputc(c,pagos);
        }
    }while(c!='W');
    fputc(z,pagos);
    fclose(pagos);
    printf("\n\nO status será alterado!\n\n");
    fclose(contrato);
}
void listaFestas(){
    FILE*festa;
    festa = fopen("exibefesta.txt","r");
    int c;
    do{
        c = fgetc(festa);
        if(c!=EOF){
        printf("%c",c);
        }
    }while(c!=EOF);
    fclose(festa);
}
void listaFunc(){
    FILE*festa;
    festa = fopen("exibefuncionarios.txt","r");
    int c;
    do{
        c = fgetc(festa);
        if(c!=EOF){
        printf("%c",c);
        }
    }while(c!=EOF);
    fclose(festa);
}
void listaForn(){
    FILE*festa;
    festa = fopen("exibefornecedor.txt","r");
    int c;
    do{
        c = fgetc(festa);
        if(c!=EOF){
        printf("%c",c);
        }
    }while(c!=EOF);
    fclose(festa);
}
void listadatas(){
    FILE*open;
    open = fopen("datas.txt","r");
    int c;
    do{
        c = fgetc(open);
        if(c!=EOF){
        printf("%c",c);
        }
    }while(c!=EOF);
    fclose(open);
}
void pesquisaCliente(){
    FILE*buscador;
    buscador = fopen("clientes.txt","r");
    char clienteBuscado[50];
    printf("Digite o nome do cliente: ");
    fflush(stdin);
    gets(clienteBuscado);
    int TamStr;
    int i;
    TamStr = strlen(clienteBuscado);
    for(i=0; i<TamStr; i++)
    {
     clienteBuscado[i] = toupper (clienteBuscado[i]);
    }
    char c;
    for(i=0;i<TamStr;i++){
    do{
        c=fgetc(buscador);
    }while(c!=clienteBuscado[i]);
    }
    char endereco[100];
    char endereco2[110];
    char endereco3[150];
    char data[10];
    printf("Cliente: %s\n",clienteBuscado);
    fscanf(buscador,"%s %s %s",&endereco,&endereco2,&endereco3);
    printf("%s %s %s",endereco,endereco2,endereco3);
    fscanf(buscador,"%s",&data);
    printf("\n%s\n",data);
    fclose(buscador);
}
