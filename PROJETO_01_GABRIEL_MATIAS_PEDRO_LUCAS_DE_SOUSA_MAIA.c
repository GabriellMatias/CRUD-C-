
//PROJETO_01_PE; DUPLA: GABRIEL MATIAS & PEDRO LUCAS DE SOUSA MAIA;

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<time.h>
#include<conio.h>
#include<windows.h>

//define matriz
#define TAMANHO 30
#define QUANTUSERS 1000
//FUNCAO PARA CORES 
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
//VARIAVEIS GLOBAIS
char nome[QUANTUSERS][TAMANHO], email[QUANTUSERS][TAMANHO], sexo[QUANTUSERS][TAMANHO], endereco[QUANTUSERS][TAMANHO], vacina[QUANTUSERS];
bool vacinado[QUANTUSERS];
double altura[QUANTUSERS];
int Id[QUANTUSERS], backupId[QUANTUSERS];
int i;
//funcoes cadastro
void Cadastro(int quant_Pessoas);
void leValidaNome();
void leValidaEmail();
void leValidaSexo();
void leValidaEndereco();
void leValidaAltura();
void leValidaVacina();
void imprimir();
void imprimirLogo();//impressao da arte final
void buscarEmail(int quant_Pessoas);
void buscarId(int quantPessoas);
void geraId();
//funcao editar
void editarUsuario(int quantUsuarios);
//backup
void backup(int quantUser);
//excluir
void excluirUsuario(int quantUsuarios);

//FUNCAO MAIN
int main(void)
{
    int opcao_Menu, quantPessoas=0;

    do
    {
        printf("|             BEM VINDO AO MENU                 |\n");
        printf("+-----------------------------------------------+\n");
        printf("|         SELECIONE A OPCAO DESEJADA            |\n");
        printf("+-----------------------------------------------+\n");
        printf("| INCLUIR USUARIO [MAX 1000]      ||   [01]     |\n");
        printf("+-----------------------------------------------+\n");
        printf("| EDITAR DADOS DE UM USUARIO      ||   [02]     |\n");
        printf("+-----------------------------------------------+\n");
        printf("| EXCLUIR USUARIO                 ||   [03]     |\n");
        printf("+-----------------------------------------------+\n");
        printf("| BUSCAR USUARIO [PELO ID]        ||   [04]     |\n");
        printf("+-----------------------------------------------+\n");
        printf("| BUSCAR USUARIO [PELO E-MAIL]    ||   [05]     |\n");
        printf("+-----------------------------------------------+\n");
        printf("| IMPRIMIR USUARIOS CADASTRADOS   ||   [06]     |\n");
        printf("+-----------------------------------------------+\n");
        printf("| MENU BACKUP                     ||   [07]     |\n");
        printf("+-----------------------------------------------+\n");
        printf("| SAIR DO PROGRAMA                ||   [08]     |\n");
        printf("+-----------------------------------------------+\n");
        scanf("%i", &opcao_Menu);
        system("cls");

        switch (opcao_Menu)
        {
        case 1://CADASTRA   
        printf("Digite a quantidade de usuarios que deseja cadastrar [MAX: 1000]:\n");
            do
            {
                scanf("%i", &quantPessoas);
                if (quantPessoas < 0 || quantPessoas > 1000 && isalpha(quantPessoas))
                {
                    textcolor(vermelho);
                    printf("            ##ATENCAO, RESPEITE OS LIMITES##        \n");
                    printf("Limite Excedido, Digite a quantidade de usuarios novamente:\n");
                    textcolor(branco);
                }
                
            } while (quantPessoas < 0 || quantPessoas > 1000 && isalpha(quantPessoas));
            srand(time(NULL));//ID RANDOMICO (PEGANDO O HORARIO PARA USAR NA FUNCAO RAND)
            system("cls");
            Cadastro(quantPessoas);
            
            break;
        case 2://edita
            editarUsuario(quantPessoas);

            break;
        case 3://exclui
            excluirUsuario(quantPessoas);

            break;
        case 4://busca pelo ID

            buscarId(quantPessoas);
            break;
        case 5://busca pelo email

            buscarEmail(quantPessoas);
        

            break;
        case 6://imprimir

            imprimir(quantPessoas);
        
        
            break;
        case 7://backup
            backup(quantPessoas);

            break;
        case 8:
            imprimirLogo();
            exit(1);
            break;
       
        default: printf("Opcao desejada invalida! Por favor digite a opcao de acordo com o menu\n");
            break;
        }
    } while (opcao_Menu != 8);
    return 0;
}

//DECLARACAO DE FUNCAO


void Cadastro(int quant_Pessoas){
    
    
    
    fflush(stdin);
    for (i = 0; i < quant_Pessoas; i++)
    {
        
        leValidaNome();//NOME

        leValidaEmail();//EMAIL
        
        leValidaSexo();//SEXO
        
        leValidaEndereco();//ENDERECO

        leValidaAltura(); //ALTURA

        leValidaVacina();//VACINA

        geraId();//GERAR ID RANDOMICO

        system("pause");
        system("cls");
    }    
}


void leValidaNome(){
    
    printf("Digite o nome do usuario numero [%i]: \n", i);//nome e validacao
    do
        {
            fflush(stdin);
            fgets(nome[i], 30, stdin);
            if (strlen(nome[i]) < 2)
            {
                textcolor(vermelho);
                printf("Nome Informado invalido, por favor Digite um nome Valido: \n");
                textcolor(branco);
            }    
        } while (strlen(nome[i]) < 2);
}          


void leValidaEmail(){
    
    printf("Digite o E-mail do usuario numero [%i]: \n", i);//Email
    do
        {
            fflush(stdin);
            textcolor(branco);
            fgets(email[i], 30, stdin);
            if (strchr(email[i], '@')==0)
            {
                textcolor(vermelho);
                printf("##                                 ATENCAO                                    ##\n");
                printf("Endereco E-mail fornecido sem o caracter [@], por favor, digite um Email valido:\n");
            }
        } while (strchr(email[i], '@')==0);
                
}       


void leValidaSexo(){
    textcolor(vermelho);
    printf("##                  ATENCAO               ##\n");//Validacao Sexo
    textcolor(branco);
    printf("|| PARA INFORMAR O SEXO, ESCREVA POR EXTENSO ||\n");
    printf("    [Masculino / Feminino / Nao declarar]   \n");
    printf("Digite o Sexo do usuario numero [%i]: \n", i);
        do
        {
            fflush(stdin);
            fgets(sexo[i], 30, stdin);
            if (strcmp(sexo[i], "Masculino\n")!=0 && strcmp(sexo[i], "Feminino\n")!=0 && strcmp(sexo[i], "Nao declarar\n")!=0)
            {
                textcolor(vermelho);
                printf("Escolha do sexo Incorreta, por favor respeite as orientacoes!\n");
                printf("|| PARA INFORMAR O SEXO, ESCREVA POR EXTENSO ||\n");
                printf("    [Masculino / Feminino / Nao declarar]   \n");
                printf("        Digite o Sexo novamente: \n");
                textcolor(branco);
            }  
        } while (strcmp(sexo[i], "Masculino\n")!=0 && strcmp(sexo[i], "Feminino\n")!=0 && strcmp(sexo[i], "Nao declarar\n")!=0);
                        
}


void leValidaEndereco(){
    
    printf("Digite o Endereco do usuario numero [%i]\n", i);//Endereco
        do
        {
            fflush(stdin);
            fgets(endereco[i], 30, stdin);
            if (strlen(endereco[i]) < 3)
            {
                textcolor(vermelho);
                printf("Endereco Informado Muito Curto, por favor Digite um Endereco Valido: \n");
                textcolor(branco);
            }
            
        } while (strlen(endereco[i]) < 3);           
}


void leValidaAltura(){
    
    printf("Digite a altura do usuario numero [%i]\n", i);//Altura
    do
        {
            fflush(stdin);
            scanf("%lf", &altura[i]);
            if (altura[i] < 1 || altura[i] > 2 )
                {
                    textcolor(vermelho);
                    printf("Limite de altura!, por favor respeite as orientacoes\n");
                    printf("             [Max 2 Metro/ Min 1 Metro]     \n");
                    printf("             Digite a altura novamente:     \n");
                    textcolor(branco);
                }
        } while (altura[i] < 1 || altura[i] > 2);
                        
}


void leValidaVacina(){

    printf("Usuario ja foi Vacinado? [S/N] \n");//Vacinacao
    fflush(stdin);
    do
    {
        scanf("%s", &vacina[i]);
        vacina[i]=toupper(vacina[i]);
        if (vacina[i] != 'S' && vacina[i] != 'N')
            {
            textcolor(vermelho);
            printf("##                           ATENCAO                       ##\n");
            printf("Por favor digite apenas [S/N], nao aceitamos outros caracteres!\n");
            printf("Informe a vacinacao Novamente: \n");
            textcolor(branco);
            }
    } while (vacina[i] != 'S' && vacina[i] != 'N');

    if (vacina[i] == 'S')
    {
        vacinado[i]=1;
    }
    if (vacina[i] == 'N')
    {
        vacinado[i]=0;
    }   
}


void geraId(){
    
    Id[i] += rand() %1000;
    printf("\n");
    textcolor(verde_claro);
    printf("+-----------------------------------------+\n");
    printf("| Id gerado para esse Usuario:    [%i]\n", Id[i]);
    printf("+-----------------------------------------+\n");
    textcolor(branco);
    printf("\n");
}


void buscarId(int quantPessoas){
    int buscaID;
    printf("Digite o Id do Usuario que deseja Buscar:\n");
    
        scanf("%i", &buscaID);
        for ( i = 0; i < quantPessoas; i++)
        {
            if (buscaID == Id[i])
            {
                textcolor(verde);
                printf("##           Usuario encontrado!          ##\n");
                textcolor(branco);
                printf("##      IMPRIMINDO INFORMACOES NA TELA    ##\n");
                printf("+------------------------------------------+\n");
                printf("|   Id/Matricula:      ||     %i            \n", Id[i]);
                printf("+------------------------------------------+\n");
                printf("|   Nome:              ||     %s", nome[i]);
                printf("+------------------------------------------+\n");
                printf("|   Email:             ||     %s", email[i]);
                printf("+------------------------------------------+\n");
                printf("|   Sexo:              ||     %s", sexo[i]);
                printf("+------------------------------------------+\n");
                printf("|   Endereco:          ||     %s ", endereco[i]);
                printf("+------------------------------------------+\n");
                printf("|   Altura:            ||     %.2lf         \n", altura[i]);
                fflush(stdin);
                if (vacinado[i] == (true))
                {
                textcolor(verde);
                printf("+------------------------------------------+\n");
                printf("|               USUARIO VACINADO           |\n");
                printf("+------------------------------------------+\n");
                textcolor(branco);
                }else if (vacinado[i] == (false))
                {
                textcolor(vermelho);
                printf("+------------------------------------------+\n");
                printf("|            USUARIO NAO VACINADO          |\n");
                printf("+------------------------------------------+\n");
                textcolor(branco);
                }
                printf("\n\n");
                system("pause");
                system("cls");
            }

        }
    
}


void imprimir(int quantPessoas){
    if (quantPessoas == 0)
    {
        textcolor(vermelho);
        printf("Por favor, cadastre o usuarios primeiro ! [NAO HA NADA PARA IMPRIMIR]\n");
        textcolor(branco);
        system("pause");
        system("cls");
        return;
    } else
    
    for (i = 0; i < quantPessoas; i++)
    {
        if (Id[i]==0)
        {
            textcolor(vermelho);
            printf("\n");
            printf("[HOUVE USUARIO(S) DELETADO(S)]\n");
            textcolor(branco);
            break;
        } else
        
        textcolor(azul);
        printf("\n\n");
        printf("+------------------------------------------+\n");
        printf("|      DADOS DO  USUARIO NUMERO [%i]        |\n", i);
        printf("+------------------------------------------+\n");
        textcolor(branco);
        printf("\n");
        printf("##      IMPRIMINDO INFORMACOES NA TELA    ##\n");
        printf("+------------------------------------------+\n");
        printf("|   Id/Matricula:      ||     %i            \n", Id[i]);
        printf("+------------------------------------------+\n");
        printf("|   Nome:              ||     %s", nome[i]);
        printf("+------------------------------------------+\n");
        printf("|   Email:             ||     %s", email[i]);
        printf("+------------------------------------------+\n");
        printf("|   Sexo:              ||     %s", sexo[i]);
        printf("+------------------------------------------+\n");
        printf("|   Endereco:          ||     %s", endereco[i]);
        printf("+------------------------------------------+\n");
        printf("|   Altura:            ||     %.2lf         \n", altura[i]);
        
        fflush(stdin);
        if (vacinado[i] == (true))
        {
        textcolor(verde);
        printf("+------------------------------------------+\n");
        printf("|               USUARIO VACINADO           |\n");
        printf("+------------------------------------------+\n");
        textcolor(branco);
        }
        if (vacinado[i] == (false))
        {
        textcolor(vermelho);
        printf("+------------------------------------------+\n");
        printf("|            USUARIO NAO VACINADO          |\n");
        printf("+------------------------------------------+\n");
        textcolor(branco);
        }
        fflush(stdin);
    }
        system("pause");
        system("cls");
}


void buscarEmail(int quant_Pessoas){

    char lerEmail[50];
    printf("Digite o E-mail do usuario cadastrado:\n");
    do
        {
            fflush(stdin);
            fgets(lerEmail, 50, stdin);
            if (strchr(lerEmail, '@')==0)
            {
                textcolor(vermelho);
                printf("##                                 ATENCAO                                    ##\n");
                printf("Endereco E-mail fornecido sem o caracter [@], por favor, digite um Email valido:\n");
                textcolor(branco);
            }
        } while (strchr(lerEmail, '@')==0);

    for ( i = 0; i < quant_Pessoas; i++)
    {
        if (lerEmail == email[i])
        {
            textcolor(verde);
            printf("##           Usuario encontrado!          ##\n");
            textcolor(branco);
            printf("##      IMPRIMINDO INFORMACOES NA TELA    ##\n");
            printf("+------------------------------------------+\n");
            printf("|   Id/Matricula:      ||     %i            \n", Id[i]);
            printf("+------------------------------------------+\n");
            printf("|   Nome:              ||     %s", nome[i]);
            printf("+------------------------------------------+\n");
            printf("|   Email:             ||     %s", email[i]);
            printf("+------------------------------------------+\n");
            printf("|   Sexo:              ||     %s", sexo[i]);
            printf("+------------------------------------------+\n");
            printf("|   Endereco:          ||     %s", endereco[i]);
            printf("+------------------------------------------+\n");
            printf("|   Altura:            ||     %.2lf         \n", altura[i]);
            
            fflush(stdin);
            if (vacinado[i] == (true))
            {
            textcolor(verde);
            printf("+------------------------------------------+\n");
            printf("|               USUARIO VACINADO           |\n");
            printf("+------------------------------------------+\n");
            textcolor(branco);
            }else if (vacinado[i] == (false))
            {
            textcolor(vermelho);
            printf("+------------------------------------------+\n");
            printf("|            USUARIO NAO VACINADO          |\n");
            printf("+------------------------------------------+\n");
            textcolor(branco);
            }
            printf("\n\n");
            system("pause");
            system("cls");
        }
    }
    
}
//ARRUMAR


void editarUsuario(int quantUsuarios){
    int opcao, buscarUsuario;
    char novoNome[30], novoEmail[30], novoSexo[30], novoEndereco[30], novaVacina;
    double novaAltura;
    int novoID;
    
        printf("|            BEM VINDO AO MENU EDITA            |\n");
        printf("+-----------------------------------------------+\n");
        printf("|        SELECIONE O DADO DESEJA EDITAR         |\n");
        printf("+-----------------------------------------------+\n");
        printf("|        NOME                ||        [01]     |\n");
        printf("+-----------------------------------------------+\n");
        printf("|        E-MAIL              ||        [02]     |\n");
        printf("+-----------------------------------------------+\n");
        printf("|        SEXO                ||        [03]     |\n");
        printf("+-----------------------------------------------+\n");
        printf("|        ENDERECO            ||        [04]     |\n");
        printf("+-----------------------------------------------+\n");
        printf("|        ALTURA              ||        [05]     |\n");
        printf("+-----------------------------------------------+\n");
        printf("|        VACINADO            ||        [06]     |\n");
        printf("+-----------------------------------------------+\n");
        printf("|        ID/MATRICULA        ||        [07]     |\n");
        printf("+-----------------------------------------------+\n");
        printf("|        TODOS OS DADOS      ||        [08]     |\n");
        printf("+-----------------------------------------------+\n");
        printf("| RETORNAR AO MENU PRINCIPAL ||        [09]     |\n");
        printf("+-----------------------------------------------+\n");
        scanf("%i", &opcao);
        fflush(stdin);
    	
    do
    {
     
        switch (opcao)
        {
        case 1:
            printf("Digite o ID do usuario que deseja alterar o [NOME]:\n");
            scanf("%i", &buscarUsuario);
            fflush(stdin);
            for ( i = 0; i < quantUsuarios; i++)
                {
                    if (buscarUsuario == Id[i])
                    {
                        textcolor(verde);
                        printf("[ Usuario encontrado! ]\n");
                        textcolor(branco);
                        printf("Nome atual: %s", nome[i]);
                        printf("Digite o Novo Nome desse usuario: \n");
                        fflush(stdin);
                        do
                        {
                            fflush(stdin);
                            fgets(novoNome, 30, stdin);
                            if (strlen(novoNome) < 3)
                            {
                                textcolor(vermelho);
                                printf("Nome Informado invalido, por favor Digite um nome Valido: \n");
                                textcolor(branco);
                            }
                            
                        } while (strlen(novoNome) < 3);
                        strcpy(nome[i], novoNome);
                        textcolor(verde);
                        printf("[ Alteracao feita com sucesso! ] \n");
                        textcolor(branco);
                        printf("Nome alterado para: %s\n", novoNome);

                        system("pause");
                        system("cls");
                        return;
                    }
                }
            break;
        case 2:
            printf("Digite o ID do usuario que deseja alterar o [EMAIL]:\n");
            scanf("%i", &buscarUsuario);
            fflush(stdin);
            for ( i = 0; i < quantUsuarios; i++)
                {
                    if (buscarUsuario == Id[i])
                    {
                        textcolor(verde);
                        printf("[ Usuario encontrado! ]\n");
                        textcolor(branco);
                        printf("Email atual: %s\n", email[i]);
                        printf("Digite o Novo Email desse usuario: \n");
                        fflush(stdin);
                        do
                        {
                            fflush(stdin);
                            textcolor(branco);
                            fgets(novoEmail, 30, stdin);
                            if (strchr(novoEmail, '@')==0)
                            {
                                textcolor(vermelho);
                                printf("##                                 ATENCAO                                    ##\n");
                                printf("Endereco E-mail fornecido sem o caracter [@], por favor, digite um Email valido:\n");
                                textcolor(branco);
                            }
                        } while (strchr(novoEmail, '@')==0);
                        strcpy(email[i], novoEmail);
                        textcolor(verde);
                        printf("[ Alteracao feita com sucesso! ] \n");
                        textcolor(branco);
                        printf("Email alterado para: %s\n", novoEmail);

                        system("pause");
                        system("cls");
                        return;
                    }
                }
            
            break;
        case 3:
            printf("Digite o ID do usuario que deseja alterar o [SEXO]:\n");
            scanf("%i", &buscarUsuario);
            fflush(stdin);
            for ( i = 0; i < quantUsuarios; i++)
                {
                    if (buscarUsuario == Id[i])
                    {
                        textcolor(verde);
                        printf("[ Usuario encontrado! ]\n");
                        textcolor(branco);
                        printf("Sexo atual: %s", sexo[i]);
                        printf("Digite o Novo Sexo desse usuario: \n");
                        do
                        {
                            fflush(stdin);
                            fgets(novoSexo, 30, stdin);
                            if (strcmp(novoSexo, "Masculino\n")!=0 && strcmp(novoSexo, "Feminino\n")!=0 && strcmp(novoSexo, "Nao declarar\n")!=0)
                            {
                                textcolor(vermelho);
                                printf("Escolha do sexo Incorreta, por favor respeite as orientacoes!\n");
                                printf("|| PARA INFORMAR O SEXO, ESCREVA POR EXTENSO ||\n");
                                printf("    [Masculino / Feminino / Nao declarar]   \n");
                                printf("        Digite o Sexo novamente: \n");
                                textcolor(branco);
                            }  
                        } while (strcmp(novoSexo, "Masculino\n")!=0 && strcmp(novoSexo, "Feminino\n")!=0 && strcmp(novoSexo, "Nao declarar\n")!=0);

                        strcpy(sexo[i], novoSexo);
                        textcolor(verde);
                        printf("[ Alteracao feita com sucesso! ] \n");
                        textcolor(branco);
                        printf("Sexo alterado para: %s\n", novoSexo);

                        system("pause");
                        system("cls");
                        return;
                    }
                }
        
            
            break;
        case 4:
            printf("Digite o ID do usuario que deseja alterar o [ENDERECO]:\n");
            scanf("%i", &buscarUsuario);
            fflush(stdin);
            for ( i = 0; i < quantUsuarios; i++)
                {
                    if (buscarUsuario == Id[i])
                    {
                        textcolor(verde);
                        printf("[ Usuario encontrado! ]\n");
                        textcolor(branco);
                        printf("Endereco atual: %s", endereco[i]);
                        printf("Digite o Novo Endereco desse usuario: \n");
                        fflush(stdin);
                        do
                        {
                            fflush(stdin);
                            fgets(novoEndereco, 30, stdin);
                            if (strlen(novoEndereco) < 3)
                            {
                                textcolor(vermelho);
                                printf("Endereco Informado Muito Curto, por favor Digite um Endereco Valido: \n");
                                textcolor(branco);
                            }
                        } while (strlen(novoEndereco) < 3);
                        strcpy(endereco[i], novoEndereco);
                        textcolor(verde);
                        printf("[ Alteracao feita com sucesso! ] \n");
                        textcolor(branco);
                        printf("Endereco alterado para: %s\n", novoEndereco);

                        system("pause");
                        system("cls");
                        return;
                    }
                }
            
            break;
        case 5:
            printf("Digite o ID do usuario que deseja alterar o [ALTURA]:\n");
            scanf("%i", &buscarUsuario);
            fflush(stdin);
            for ( i = 0; i < quantUsuarios; i++)
                {
                    if (buscarUsuario == Id[i])
                    {
                        textcolor(verde);
                        printf("[ Usuario encontrado! ]\n");
                        textcolor(branco);
                        printf("Altura atual: %lf\n", altura[i]);
                        printf("Digite a Nova Altura desse usuario: \n");
                        fflush(stdin);
                        do
                        {
                            fflush(stdin);
                            scanf("%lf", &novaAltura);
                            if (novaAltura < 1 || novaAltura > 2 )
                                {
                                    textcolor(vermelho);
                                    printf("Limite de altura!, por favor respeite as orientacoes\n");
                                    printf("             [Max 2 Metro/ Min 1 Metro]     \n");
                                    printf("             Digite a altura novamente:     \n");
                                    textcolor(branco);
                                }
                        } while (novaAltura < 1 || novaAltura > 2);
                        altura[i] = novaAltura;
                        textcolor(verde);
                        printf("[ Alteracao feita com sucesso! ] \n");
                        textcolor(branco);
                        printf("Altura alterada para: %lf\n", novaAltura);

                        system("pause");
                        system("cls");
                        return;
                    }
                }
            
            break;
        case 6://vacina
                printf("Digite o ID do usuario que deseja alterar os dados da [VACINACAO]:\n");
                scanf("%i", &buscarUsuario);
                fflush(stdin);
                for ( i = 0; i < quantUsuarios; i++)
                    {
                        if (buscarUsuario == Id[i])
                    {
                        textcolor(verde);
                        printf("[ Usuario encontrado! ]\n");
                        textcolor(branco);
                        printf("\n             [ATUAL SITUACAO DO USUARIO]      \n");
                            if (vacinado[i] == (true))
                            {
                            textcolor(verde);
                            printf("              [ USUARIO VACINADO ]         \n");
                            textcolor(branco);
                            }else if (vacinado[i] == (false))
                            {
                            textcolor(vermelho);
                            printf("              [ USUARIO NAO VACINADO ]         \n");
                            textcolor(branco);
                            }
                            fflush(stdin);
                        printf("Digite a nova situacao dos dados de vacinacao do usuario [S/N]\n");
                        fflush(stdin);
                        do
                        {
                        scanf("%c", &novaVacina);
                        novaVacina=toupper(novaVacina);
                        if (novaVacina != 'S' && novaVacina != 'N')
                            {
                            textcolor(vermelho);
                            printf("##                           ATENCAO                       ##\n");
                            printf("Por favor digite apenas [S/N], nao aceitamos outros caracteres!\n");
                            printf("Informe a vacinacao Novamente: \n");
                            textcolor(branco);
                            }
                        } while (novaVacina != 'S' && novaVacina != 'N');

                        if (novaVacina == 'S')
                        {
                            vacinado[i]==true;
                        } else if (novaVacina == 'N')
                        {
                            vacinado[i]==false;
                        }
                        textcolor(verde);
                        printf("[ Alteracao feita com sucesso! ] \n");
                        textcolor(branco);
                        printf("\nSituacao alterada para: \n");
                        if (vacinado[i] == (true))
                            {
                            textcolor(verde);
                            printf("              [ USUARIO VACINADO ]         \n");
                            textcolor(branco);
                            }else if (vacinado[i] == (false))
                            {
                            textcolor(vermelho);
                            printf("              [ USUARIO NAO VACINADO ]         \n");
                            textcolor(branco);
                            }
                            fflush(stdin);
                    }
                    }
                    
            
            break;
        case 7:
            printf("Digite o ID do usuario que deseja alterar o [ID]:\n");
            scanf("%i", &buscarUsuario);
            fflush(stdin);
            for ( i = 0; i < quantUsuarios; i++)
                {
                    if (buscarUsuario == Id[i])
                    {
                        textcolor(verde);
                        printf("[ Usuario encontrado! ]\n");
                        textcolor(branco);
                        printf("ID atual: %i\n", Id[i]);
                        printf("Digite o novo ID desse usuario: \n");
                        do
                        {
                            fflush(stdin);
                            scanf("%i", &novoID);
                            if (novoID == Id[i])
                            {
                                textcolor(vermelho);
                                printf("Esse ID ja esta em uso, por favor escolha outro\n");
                                textcolor(branco);
                            }
                        } while (novoID == Id[i]);
                        Id[i] = novoID;
                        textcolor(verde);
                        printf("[ Alteracao feita com sucesso! ] \n");
                        textcolor(branco);
                        printf("ID alterado para: %i\n", novoID);

                        system("pause");
                        system("cls");
                        return;
                    }
                }
            break;
        case 8:
            printf("Digite o ID do usuario que deseja alterar [TODOS OS DADOS]:\n");
            scanf("%i", &buscarUsuario);
            fflush(stdin);
            for ( i = 0; i < quantUsuarios; i++)
                {
                    if (buscarUsuario == Id[i])
                    {
                        textcolor(verde);
                        printf("[ Usuario encontrado! ]\n");
                        textcolor(branco);
                        printf("Nome atual: %s\n", nome[i]);
                        printf("Digite o Novo Nome desse usuario: \n");
                        fflush(stdin);
                        do
                        {
                            fflush(stdin);
                            fgets(novoNome, 30, stdin);
                            if (strlen(novoNome) < 3)
                            {
                                textcolor(vermelho);
                                printf("Nome Informado invalido, por favor Digite um nome Valido: \n");
                                textcolor(branco);
                            }
                            
                        } while (strlen(novoNome) < 3);
                        strcpy(nome[i], novoNome);
                        textcolor(verde);
                        printf("[ Alteracao feita com sucesso! ] \n");
                        textcolor(branco);
                        printf("Nome alterado para: %s\n", novoNome);
                        textcolor(vermelho);
                        printf("\n[ALTERANDO EMAIL]\n");
                        textcolor(branco);
                        printf("Digite o Novo Email desse usuario: \n");
                        fflush(stdin);
                        do
                        {
                            fflush(stdin);
                            textcolor(branco);
                            fgets(novoEmail, 30, stdin);
                            if (strchr(novoEmail, '@')==0)
                            {
                                textcolor(vermelho);
                                printf("##                                 ATENCAO                                    ##\n");
                                printf("Endereco E-mail fornecido sem o caracter [@], por favor, digite um Email valido:\n");
                                textcolor(branco);
                            }
                        } while (strchr(novoEmail, '@')==0);
                        strcpy(email[i], novoEmail);
                        textcolor(verde);
                        printf("[ Alteracao feita com sucesso! ] \n");
                        textcolor(branco);
                        printf("Email alterado para: %s\n", novoEmail);
                        textcolor(vermelho);
                        printf("\n[ALTERANDO SEXO]\n");
                        textcolor(branco);
                        printf("Digite o Novo Sexo desse usuario: \n");
                        do
                        {
                            fflush(stdin);
                            fgets(novoSexo, 30, stdin);
                            if (strcmp(novoSexo, "Masculino\n")!=0 && strcmp(novoSexo, "Feminino\n")!=0 && strcmp(novoSexo, "Nao declarar\n")!=0)
                            {
                                textcolor(vermelho);
                                printf("Escolha do sexo Incorreta, por favor respeite as orientacoes!\n");
                                printf("|| PARA INFORMAR O SEXO, ESCREVA POR EXTENSO ||\n");
                                printf("    [Masculino / Feminino / Nao declarar]   \n");
                                printf("        Digite o Sexo novamente: \n");
                                textcolor(branco);
                            }  
                        } while (strcmp(novoSexo, "Masculino\n")!=0 && strcmp(novoSexo, "Feminino\n")!=0 && strcmp(novoSexo, "Nao declarar\n")!=0);

                        strcpy(sexo[i], novoSexo);
                        textcolor(verde);
                        printf("[ Alteracao feita com sucesso! ] \n");
                        textcolor(branco);
                        printf("Sexo alterado para: %s\n", novoSexo);
                        textcolor(vermelho);
                        printf("\n[ALTERANDO ENDERECO]\n");
                        textcolor(branco);
                        printf("Digite o Novo Endereco desse usuario: \n");
                        fflush(stdin);
                        do
                        {
                            fflush(stdin);
                            fgets(novoEndereco, 30, stdin);
                            if (strlen(novoEndereco) < 3)
                            {
                                textcolor(vermelho);
                                printf("Endereco Informado Muito Curto, por favor Digite um Endereco Valido: \n");
                                textcolor(branco);
                            }
                        } while (strlen(novoEndereco) < 3);
                        strcpy(endereco[i], novoEndereco);
                        textcolor(verde);
                        printf("[ Alteracao feita com sucesso! ] \n");
                        textcolor(branco);
                        printf("Endereco alterado para: %s\n", novoEndereco);
                        textcolor(vermelho);
                        printf("\n[ALTERANDO ALTURA]\n");
                        textcolor(branco);
                        printf("Digite a Nova Altura desse usuario: \n");
                        fflush(stdin);
                        do
                        {
                            fflush(stdin);
                            scanf("%lf", &novaAltura);
                            if (novaAltura < 1 || novaAltura > 2 )
                                {
                                    textcolor(vermelho);
                                    printf("Limite de altura!, por favor respeite as orientacoes\n");
                                    printf("             [Max 2 Metro/ Min 1 Metro]     \n");
                                    printf("             Digite a altura novamente:     \n");
                                    textcolor(branco);
                                }
                        } while (novaAltura < 1 || novaAltura > 2);
                        altura[i] = novaAltura;
                        textcolor(verde);
                        printf("[ Alteracao feita com sucesso! ] \n");
                        textcolor(branco);
                        printf("Altura alterada para: %lf\n", novaAltura);
                        textcolor(vermelho);
                        printf("\n[ALTERANDO ID]\n");
                        textcolor(branco);
                        printf("Digite o novo ID desse usuario: \n");
                        do
                        {
                            fflush(stdin);
                            scanf("%i", &novoID);
                            if (novoID == Id[i])
                            {
                                textcolor(vermelho);
                                printf("Esse ID ja esta em uso, por favor escolha outro\n");
                                textcolor(branco);
                            }
                        } while (novoID == Id[i]);
                        Id[i] = novoID;
                        textcolor(verde);
                        printf("[ Alteracao feita com sucesso! ] \n");
                        textcolor(branco);
                        printf("ID alterado para: %i\n", novoID);
                        printf("\n[ALTERANDO DADOS DA VACINACAO]\n");
                        printf("\n             [ATUAL SITUACAO DO USUARIO]        \n");
                            if (vacinado[i] == (true))
                            {
                            textcolor(verde);
                            printf("              [ USUARIO VACINADO ]         \n");
                            textcolor(branco);
                            }else if (vacinado[i] == (false))
                            {
                            textcolor(vermelho);
                            printf("              [ USUARIO NAO VACINADO ]         \n");
                            textcolor(branco);
                            }
                            fflush(stdin);
                        printf("Digite a nova situacao dos dados de vacinacao do usuario [S/N]\n");

                        do
                        {
                        scanf("%c", &novaVacina);
                        novaVacina=toupper(novaVacina);
                        if (novaVacina != 'S' && novaVacina != 'N')
                            {
                            textcolor(vermelho);
                            printf("##                           ATENCAO                       ##\n");
                            printf("Por favor digite apenas [S/N], nao aceitamos outros caracteres!\n");
                            printf("Informe a vacinacao Novamente: \n");
                            textcolor(branco);
                            }
                        } while (novaVacina != 'S' && novaVacina != 'N');

                        if (novaVacina == 'S')
                        {
                            vacinado[i]==true;
                        } else if (novaVacina == 'N')
                        {
                            vacinado[i]==false;
                        }
                        textcolor(verde);
                        printf("[ Alteracao feita com sucesso! ] \n");
                        textcolor(branco);
                        printf("\nSituacao alterada para: \n");
                        if (vacinado[i] == (true))
                            {
                            textcolor(verde);
                            printf("              [ USUARIO VACINADO ]         \n");
                            textcolor(branco);
                            }else if (vacinado[i] == (false))
                            {
                            textcolor(vermelho);
                            printf("              [ USUARIO NAO VACINADO ]         \n");
                            textcolor(branco);
                            }
                            fflush(stdin);


                        system("pause");
                        system("cls");
                        return;
                    }
                }
            
            break;
        case 9:
            printf("\n## Retornando ao [MENU PRINCIPAL] ##\n");
            system("pause");
            system("cls");
            return;
            
            break;

        default: 
        textcolor(vermelho);
        printf("\n## OPCAO DESEJADA INVALIDA, POR FAVOR DIGITE UMA OPCAO VALIDA! ##\n");
        textcolor(branco);
            break;
        }
    } while (opcao != 9);
   
}


void excluirUsuario(int quantUsuarios){

    int excluirID;

    printf("## Bem vindo ao sistema de exclusao de usuarios ## \n");
    printf("    Digite o ID do Usuario que deseja deletar:  \n");
    scanf("%i", &excluirID);
    

    for ( i = 0; i < quantUsuarios; i++)
    {
        fflush(stdin);
        if (excluirID==Id[i])
        {
            for ( i = i; i < quantUsuarios; i++)
            {
                
            Id[i] = Id[i+1];
            strcpy(nome[i], nome[i+1]);
            strcpy(endereco[i], endereco[i+1]);
            strcpy(sexo[i], sexo[i+1]);
            vacinado[i] = vacinado[i+1];
            altura[i] = altura[i+1];
            strcpy(email[i], email[i+1]);
            textcolor(verde);
            printf("[USUARIO DELETADO COM SUCESSO!]\n");
            textcolor(branco);
            system("pause");
            system("cls");
            }
        }
    }
}


void backup(int quantUser){

    fflush(stdin);
    int opcaoBackup;
    char backupNome[QUANTUSERS][TAMANHO], backupEmail[QUANTUSERS][TAMANHO], backupSexo[QUANTUSERS][TAMANHO], backupEndereco[QUANTUSERS][TAMANHO];
    bool backupVacinado[QUANTUSERS];
    double backupAltura[QUANTUSERS];

    
    do
    {
        printf("##         Bem vindo ao menu Backup        ##\n");
        printf("##        SELECIONE A OPCAO DESEJADA       ##\n");
        printf("+------------------------------------------+\n");
        printf("|  REALIZAR BACKUP              ||    [1]  |\n");
        printf("+------------------------------------------+\n");
        printf("|  RESTAURAR DADOS DO BACKUP    ||    [2]  |\n");
        printf("+------------------------------------------+\n");
        printf("|  RETORNAR AO MENU PRINCIPAL   ||    [3]  |\n");
        printf("+------------------------------------------+\n");
        scanf("%i", &opcaoBackup);
        fflush(stdin);

        switch (opcaoBackup)
        {
        case 1:
            
            printf("[REALIZANDO BACKUP DOS DADOS]\n\n");
            for ( i = 0; i < quantUser; i++)
            {
                backupId[i]=0;
                fflush(stdin);
                backupId[i]=Id[i];
                strcpy(backupNome[i], nome[i]);
                strcpy(backupEmail[i], email[i]);
                strcpy(backupSexo[i], sexo[i]);
                strcpy(backupEndereco[i], endereco[i]);
                backupAltura[i] = altura[i];
                backupVacinado[i] = vacinado[i];
                fflush(stdin);
                textcolor(verde);
                printf("[BACKUP REALIZADO COM SUCESSO]\n");
                textcolor(branco);
                system("pause");
                system("cls");
            }
            
            
            break;
        case 2:

            printf("[RESTAURANDO ARQUIVOS DO BACKUP]\n\n");
            for ( i = 0; i < quantUser; i++)
            {
                fflush(stdin);
                Id[i]=backupId[i];
                strcpy(nome[i], backupNome[i]);
                strcpy(email[i], backupEmail[i]);
                strcpy(sexo[i], backupSexo[i]);
                strcpy(endereco[i], backupEndereco[i]);
                altura[i] = backupAltura[i];
                vacinado[i] = backupVacinado[i];
                textcolor(verde);
                fflush(stdin);
                printf("[RESTAURACAO REALIZADA COM SUCESSO]\n");
                textcolor(branco);
                system("pause");
                system("cls");
            }

            break;

        case 3:
            printf("## Retornando ao menu Principal ##\n");
            system("pause");
            system("cls");
            return;

            break;
        
        default:
            textcolor(vermelho);
            printf("OPCAO INVALIDA, POR FAVOR SIGA AS ORIENTACOES!\n");
            textcolor(branco);
            break;
        }
    } while (opcaoBackup != 3);
}


void imprimirLogo(){
    fflush(stdin);
    printf("|#| [AGRADECEMOS POR UTILIZAR UM DOS NOSSOS PROGRAMAS] |#|\n");
    textcolor(azul);
    printf("##########################################################\n");
    printf("         ############################################     \n");
    printf("             #################################            \n");
    printf("                ##########################                \n");
    printf("             ################################             \n");
    textcolor(branco);
    
}