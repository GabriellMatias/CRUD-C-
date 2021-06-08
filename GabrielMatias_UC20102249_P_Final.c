#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<locale.h> 
#include<windows.h>  
#include<conio.h>
#include<string.h>

//funcao para cores
enum DOS_COLORS{
 preto, azul, verde, CYAN, vermelho, MAGENTA, castanho,
 cizento_claro, cizento_escuro, azul_claro, verde_claro, CYAN_claro,
 vermelho_claro, MAGENTA_claro, amarelo, branco
};


void textcolor(int iColor){
 HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
 CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
 BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
 bufferInfo.wAttributes &= 0x00F0;
 SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}

//funcao principal
int main(void)
{
    //variaveis para o sistema de menu
    int menuPrincipal;
    //para cadastrar o voo
    int Qntassentos;
    char nomeVoo[30], destinoVoo[30], origemvoo[30];
    float preco=0;
    //variaveis para cadastrar informacoes do usuario
    char nomeCliente[30], cpf[12];
    int idade, Id=0, matrizid[10][20];
    //variaveis para verificar disponibilidade de assentos
    char letra[10][20];
    int i = 0, j = 0, contador = 0, poltronas[10][20], assentoescolhido;
    //confirmar reservas
    int contadorreservas=0, contadordisponiveis=0, contadorconfirmada=0;//resumo de informacoes
    float precototal=0;
    //cancelar reservas
    int idcliente;
   
    do//retornar o menu
    {
        
    
        //menu
        textcolor(branco);
        printf("+-------------------------------------------------+\n");
        printf("|  BEM VINDO AO SISTEMAS SALUMAR LINHAS AEREAS    |\n");
        printf("+-------------------------------------------------+\n");
        printf("\n");
        printf("+-------------------------------------------------+\n");
        printf("|                       MENU                      |\n");
        printf("+-------------------------------------------------+\n");
        printf("|             OPCAO                ||    CODIGO   |\n");
        printf("+-------------------------------------------------+\n");
        printf("| CADASTRAR VOO                    ||      1      |\n");
        printf("+-------------------------------------------------+\n");
        printf("| CADASTRAR INFORMACOES DO CLIENTE ||      2      |\n");
        printf("+-------------------------------------------------+\n");
        printf("| DISPONIBILIDADE DE ASSENTOS      ||      3      |\n");
        printf("+-------------------------------------------------+\n");
        printf("| REALIZAR RESERVA                 ||      4      |\n");
        printf("+-------------------------------------------------+\n");
        printf("| CONFIRMAR RESERVA                ||      5      |\n");
        printf("+-------------------------------------------------+\n");
        printf("| CANCELAR RESERVA                 ||      6      |\n");
        printf("+-------------------------------------------------+\n");
        printf("| INFORMACOES DA PASSAGEM          ||      7      |\n");
        printf("+-------------------------------------------------+\n");
        printf("| SAIR DO PROGRAMA                 ||      8      |\n");
        printf("+-------------------------------------------------+\n");
        printf("| DIGITE SUA OPCAO: \n");
        scanf("%d", &menuPrincipal);
        fflush(stdin);
        


    switch (menuPrincipal)
    {

    case 1://CADASTRAR VOO 
        system("cls");
        printf("+-------------------------------------------------+\n");
        printf("|   BEM VINDO AO SISTEMA DE CADASTRO DE VOOS      |\n");
        printf("+-------------------------------------------------+\n");
        printf("|   DIGITE AS INFORMACOES REQUERIDAS ABAIXO       |\n");
        printf("+-------------------------------------------------+\n");

        //informacoes do voo com validacoes
        printf("DIGITE O NOME DO VOO\n");
        fflush(stdin);
        do
        {
            fgets(nomeVoo, 30, stdin);
            if (strlen(nomeVoo)<3)
            {
                printf("NOME INVALIDO, POR FAVOR DIGITE NOVAMENTE:\n");
            }
            
        } while (strlen(nomeVoo)<3);
        printf("DIGITE A ORIGEM DO VOO:");
        do
        {
            fgets(origemvoo, 30, stdin);
            if (strlen(origemvoo)<3)
            {
                printf("ORIGEM INVALIDO, POR FAVOR DIGITE NOVAMENTE:\n");
            }
            
        } while (strlen(origemvoo)<3);
        printf("DIGITE O DESTINO DO VOO:");
        do
        {
            fgets(destinoVoo, 30, stdin);
            if (strlen(destinoVoo)<3)
            {
                printf("DESTINO INVALIDO, POR FAVOR DIGITE NOVAMENTE:\n");
            }
            
        } while (strlen(destinoVoo)<3);

        printf("INFORME A QUANTIDADE DE ASSENTOS NESSE VOO:\n");
        do
        {
            scanf("%i", &Qntassentos);
            fflush(stdin);
            if (Qntassentos < 90 || Qntassentos > 200)
            {
                printf("QUANTIDADE DE ASSENTOS INFORMADA INVALIDA, POR FAVOR DIGITE A QUANTIDADE NOVAMENTE: \n");
            }
            

        } while (Qntassentos < 90 || Qntassentos > 200);
        printf("INFORME O PRECO DA PASSAGEM: \n");
        do
        {
            scanf("%f", &preco);
            if (preco <0)
            {
                printf("VALOR MINIMO NAO ALCANCADO, POR FAVOR INFORME O PRECO NOVAMENTE\n");
            }
            
        } while (preco<0);
        system("pause");
        //matriz para a questao da poutronas de cada aviao, por isso esta no cadastro do voo
        for ( i = 0; i < 10; i++)
        {
            for ( j = 0; j < 20; j++)
            {
               contador++;
               poltronas[i][j]=contador;
            }  
        }
        for ( i = 0; i < 10; i++)
        {
            for ( j = 0; j < 20; j++)
            {
               if (poltronas[i][j] <= Qntassentos)
               {
                   letra[i][j] = 'D';//todos os assentos estao disponiveis no comeco, entao o default e a letra D
               }
            }  
        }
    break;
    case 2://CADASTRAR CLIENTE
        printf("+-------------------------------------------------+\n");
        printf("|  BEM-VINDO AO SISTEMA DE CADASTRO DE CLIENTES   |\n");
        printf("+-------------------------------------------------+\n");
        printf("DIGITE O NOME DO CLIENTE: \n");
        //informacoes do cliente para o voo, e o preco com a idade <5
        do
        {
            fgets(nomeCliente, 30, stdin);
            if (strlen(nomeCliente) < 3 )
            {
                printf("NOME INVALIDO, POR FAVOR DIGITE NOVAMENTE:\n");
            }
            
        } while (strlen(nomeCliente) < 3  );
        printf("DIGITE O CADASTRO DE PESSOA FISICA (CPF) DO CLIENTE:\n");      
        do
        {
            fgets(cpf, 12, stdin);
            if (strlen(cpf) != 11)
            {
                printf("NUMERO INVALIDO, POR FAVOR DIGITE NOVAMENTE OS 11 DIGITOS DO CPF:\n");
            }
        } while (strlen(cpf) != 11);
        printf("INFORME A IDADE DO CLIENTE:\n");
        do
        {
            scanf("%d", &idade);
            if (idade < 1 || idade > 200)
            {
                printf("IDADE ACIMA DOS NIVEIS DE RESTRICAO, POR FAVOR DIGITE A IDADE NOVAMENTE: \n");
            }
        } while (idade < 1 || idade > 200);
        
        if (idade <= 5)
        {
            preco = preco/2;
        }
    
        system("pause");
    break;

    case 3://verificar se os assentos estao disponiveis 
        system("cls");
        printf("+--------------------------------------------------------------------+\n");
        printf("| BEM VINDO AO SISTEMA DE VERIFICACAO DE DISPONIBILIDADE DE LUGARES  |\n");
        printf("+--------------------------------------------------------------------+\n");
        system("pause");

        //printar assentos disponiveis
        for(j=0;j<20;j++){
        for(i=0;i<10;i++){
            if(poltronas[i][j]<=contador && (letra[i][j]=='D' || letra[i][j]=='R' || letra[i][j]=='C')){
                if (letra[i][j]=='R')//caso esteja reservado printa a letra R e cor vermelha
                {
                    textcolor(vermelho);
                    printf("%.3d ", poltronas[i][j]);
                    printf("%c ", letra[i][j]);
                    textcolor(verde_claro);
                } else if (letra[i][j]=='D'){//caso esteja disponivel printa a letra  D e cor verde
                    textcolor(verde_claro);
                    printf("%.3d ", poltronas[i][j]);
                    printf("%c ", letra[i][j]);
                    textcolor(branco);
                } else if (letra[i][j]=='C')//caso esteja confirmado a reserva printa a letra C e cor Azul
                {
                    textcolor(azul);
                    printf("%.3d ", poltronas[i][j]);
                    printf("%c ", letra[i][j]);
                    textcolor(branco);
                }
                
                } 
            } 
        printf("\n");       
        }
        printf("\n");
        textcolor(vermelho);
        printf("RESERVADO  ");
        textcolor(azul);
        printf("CONFIRMADO  ");
        textcolor(verde);
        printf("DISPONIVEL  \n");
        textcolor(branco);
        
          
        system("pause");
    break;

    case 4://realizar reserva
        system("cls");
        printf("+-------------------------------------------------+\n");
        printf("|  BEM VINDO AO CADASTRAMENTO DE RESERVAS SALUMAR |\n");
        printf("+-------------------------------------------------+\n");
        Id++;//cada vez que faz uma reserva ele adiciona +1 ao id e correlaciona ele com o numero do assento
        textcolor(branco);
        //printar os lugares
        for(j=0;j<20;j++){
        for(i=0;i<10;i++){
            if(poltronas[i][j]<= Qntassentos && (letra[i][j]=='D' || letra[i][j]=='R' || letra[i][j]=='C')){
                if (letra[i][j]=='R')
                {
                    textcolor(vermelho);
                    printf("%.3d ", poltronas[i][j]);
                    printf("%c ", letra[i][j]);
                    textcolor(verde_claro);
                }else if (letra[i][j]=='D')
                {
                    textcolor(verde_claro);
                    printf("%.3d ", poltronas[i][j]);
                    printf("%c ", letra[i][j]);
                } else if (letra[i][j]=='C')
                        {
                        textcolor(azul);
                        printf("%.3d ", poltronas[i][j]);
                        printf("%c ", letra[i][j]);
                        textcolor(branco);
                        }
                }
            } 
        printf("\n");       
        }
        textcolor(branco);
        printf("DIGITE O ASSENTO QUE O CLIENTE DESEJA ESCOLHER:\n");//cadastrar a reserva
        scanf("%d", &assentoescolhido);
        system("cls");
        textcolor(verde_claro);
        fflush(stdin);
        for(j=0;j<20;j++){
        for(i=0;i<10;i++){
            if(poltronas[i][j] == assentoescolhido){
                letra[i][j] = 'R';
                matrizid[i][j]= Id;//id fica relacionado ao assento escolhido
                } 
            }       
        }
        
        for(j=0;j<20;j++){
        for(i=0;i<10;i++){
            if(poltronas[i][j]<= Qntassentos && (letra[i][j]=='D' || letra[i][j]=='R' || letra[i][j]=='C')){
                if (letra[i][j]=='R')
                {
                    textcolor(vermelho);
                    printf("%.3d ", poltronas[i][j]);
                    printf("%c ", letra[i][j]);
                    textcolor(verde_claro);
                }else if (letra[i][j]=='D')
                {
                    textcolor(verde_claro);
                    printf("%.3d ", poltronas[i][j]);
                    printf("%c ", letra[i][j]);
                } else if (letra[i][j]=='C')
                        {
                        textcolor(azul);
                        printf("%.3d ", poltronas[i][j]);
                        printf("%c ", letra[i][j]);
                        textcolor(branco);
                        }
                }
            } 
        printf("\n");       
        }
        textcolor(vermelho);
        printf("## ATENCAO AS INFORMACOES, ANOTE SEU ID POIS SERA NECESSARIO PARA CONFIRMAR OU CANCELAR ALGUMA RESERVA ##\n");
        printf("                                        ASSENTO ESCOLHIDO: %d \n", assentoescolhido);
        printf("                                         ID DA RESERVA: %d\n", Id);
        printf("                 ## ESSAS INFORMACOES NAO SERAO INFORMADAS NOVAMENTE, GUARDE-AS! ##\n");
        textcolor(branco);



        system("pause");
    break;
    case 5://confirmar reservas
        system("cls"); 
        printf("+--------------------------------------------------+\n");
        printf("| BEM VINDO AO SISTEMA DE CONFIRMACOES DE RESERVAS |\n");
        printf("+--------------------------------------------------+\n");
        printf("DIGITE O NUMERO IDENTIFICADOR DO CLIENTE (ID) PARA CONFIRMAR A RESERVA: \n");//id de cada reserva deve ser digitado para confirmar a reserva
        do
        {
            scanf("%d", &idcliente);
            if (idcliente > Id)//validacao para que o ID inserido exista
            {
                printf("ID NAO CADASTRADO, POR FAVOR DIGITE NOVAMENTE:\n");
            }
            
        } while (idcliente > Id);  

        //conforme digitar o id corretamente, passa de reservado para confirmado
        for(j=0;j<20;j++){
            for(i=0;i<10;i++){
                if(matrizid[i][j] == idcliente && letra[i][j]== 'R'){
                    letra[i][j] = 'C';
                    } 
                }       
            }//printa dnovo o mapa dos assentos
        for(j=0;j<20;j++){
                for(i=0;i<10;i++){
                    if(poltronas[i][j]<=contador && (letra[i][j]=='D' || letra[i][j]=='R' || letra[i][j]=='C')){
                        if (letra[i][j]=='R')
                        {
                            textcolor(vermelho);
                            printf("%.3d ", poltronas[i][j]);
                            printf("%c ", letra[i][j]);
                            textcolor(verde_claro);
                        } else if (letra[i][j]=='D'){
                            textcolor(verde_claro);
                            printf("%.3d ", poltronas[i][j]);
                            printf("%c ", letra[i][j]);
                            textcolor(branco);
                        } else if (letra[i][j]=='C')
                        {
                            textcolor(azul);
                            printf("%.3d ", poltronas[i][j]);
                            printf("%c ", letra[i][j]);
                            textcolor(branco);
                        }
                        
                        } 
                    } 
                printf("\n");       
                }
        

    break;

    case 6://cancelar reserva
        system("cls");
        printf("+--------------------------------------------------+\n");
        printf("| BEM VINDO AO SISTEMA DE CANCELAMENTO DE RESERVAS |\n");
        printf("+--------------------------------------------------+\n");
        printf("DIGITE O NUMERO IDENTIFICADOR DO CLIENTE (ID) PARA CANCELAR A RESERVA: \n");//id de cada reserva deve ser digitado para cancelar a reserva
        do
        {
            scanf("%d", &idcliente);
            if (idcliente > Id)
            {
                printf("ID NAO CADASTRADO, POR FAVOR DIGITE NOVAMENTE:\n");
            }
            
        } while (idcliente > Id);  

        //caso o id seja corretamente digitado, o assento volta a estar disponivel e a reserva e cancelada
        for(j=0;j<20;j++){
            for(i=0;i<10;i++){
                if(matrizid[i][j] == idcliente && (letra[i][j]== 'R' ||letra[i][j]== 'C')){
                    letra[i][j] = 'D';
                    
                    } 
                }       
            }
        for(j=0;j<20;j++){
                for(i=0;i<10;i++){
                    if(poltronas[i][j]<=contador && (letra[i][j]=='D' || letra[i][j]=='R' || letra[i][j]=='C')){
                        if (letra[i][j]=='R')
                        {
                            textcolor(vermelho);
                            printf("%.3d ", poltronas[i][j]);
                            printf("%c ", letra[i][j]);
                            textcolor(verde_claro);
                        } else if (letra[i][j]=='D'){
                            textcolor(verde_claro);
                            printf("%.3d ", poltronas[i][j]);
                            printf("%c ", letra[i][j]);
                            textcolor(branco);
                        } else if (letra[i][j]=='C')
                        {
                            textcolor(azul);
                            printf("%.3d ", poltronas[i][j]);
                            printf("%c ", letra[i][j]);
                            textcolor(branco);
                        }
                        
                        } 
                    } 
                printf("\n");       
                }
        system("pause");
    break;
    case 7://printar informacoes na tela
        system("cls");
        printf("+--------------------------------------------------+\n"); 
        printf("|            INFORMACOES DA PASSAGEM               |\n");
        printf("+--------------------------------------------------+\n");
        printf("|DESTINO: %s\n", destinoVoo);
        printf("+--------------------------------------------------+\n");
        printf("|ORIGEM: %s\n", origemvoo);
        printf("+--------------------------------------------------+\n");

        for(j=0;j<20;j++){
                for(i=0;i<10;i++){
                    if(poltronas[i][j]<=contador && (letra[i][j]=='D' || letra[i][j]=='R' || letra[i][j]=='C')){
                        if (letra[i][j]=='R')
                        {
                            textcolor(vermelho);
                            printf("%.3d ", poltronas[i][j]);
                            printf("%c ", letra[i][j]);
                            contadorreservas++;
                            textcolor(verde_claro);
                        } else if (letra[i][j]=='D'){
                            textcolor(verde_claro);
                            printf("%.3d ", poltronas[i][j]);
                            printf("%c ", letra[i][j]);
                            contadordisponiveis++;
                            textcolor(branco);
                        } else if (letra[i][j]=='C')
                        {
                            textcolor(azul);
                            printf("%.3d ", poltronas[i][j]);
                            printf("%c ", letra[i][j]);
                            contadorconfirmada++;
                            precototal  += preco;
                            textcolor(branco);
                        }
                        
                        } 
                    } 
                printf("\n");       
                }
                printf("+--------------------------------------------------+\n");
                printf("| QUANTIDADE DE POLTRONAS DISPONIVEIS:%d\n", contadordisponiveis);
                printf("+--------------------------------------------------+\n");
                printf("| QUANTIDADE DE POLTRONAS RESERVADAS:%d\n", contadorreservas);
                printf("+--------------------------------------------------+\n");
                printf("| QUANTIDADE DE POLTRONAS COM VENDA CONFIRMADAS:%d\n", contadorconfirmada);
                printf("+--------------------------------------------------+\n");
                printf("| PRECO POR PASSAGEM: %.2lf\n", preco);
                printf("+--------------------------------------------------+\n");
                printf("| VALOR TOTAL DE VENDAS DE ASSENTOS: %.2lf\n", precototal);
                printf("+--------------------------------------------------+\n");
                system("pause");

    break;
    case 8://sair do programa
        system("cls");
                textcolor(verde);
                printf("                                       ######\n");
                printf("                                    ############\n");
                printf("                                  ###############\n");
                printf("                               ########       ######\n");
                printf("                            #######           #######\n");
                printf("                         #######\n");
                printf("                      #######\n");
                printf("                    #######\n");
                printf("                    #######\n");
                printf("                      #######\n");
                printf("                          #######\n");
                printf("                             #######\n");
                printf("                                #######\n");
                textcolor(branco);
                printf("|| SALUMAR LINHAS AEREAS AGRADECE POR UTILIZAR UM DOS NOSOS PROGRAMAS ||\n");
                textcolor(verde);
                printf("                                    #######\n");
                printf("                                   #######\n");
                printf("                                  #######\n");
                printf("                                #######\n");
                printf("           #########          #######\n");
                printf("             #######        #######\n");
                printf("                 #############\n");
                printf("                   #########\n");
                printf("                     #####\n");
                textcolor(branco);
        fflush(stdin);
        system("pause");
        exit(1);
    
    break;
    
    default: printf("OPCAO DIGITADA INVALIDA");
        break;
    }

    } while (menuPrincipal >= 1 && menuPrincipal < 9);
    

    return 0;
}
