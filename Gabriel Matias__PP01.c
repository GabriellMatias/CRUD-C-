//Gabriel Matias_UC20102249_Ciencia da computacao
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
    int sessao, opcao, Pessoas, sexoF = 0, sexoM = 0, contadorP = 0, idade;//delcarando variaveis e deixando algumas com valores
    int idoso = 0, adulto = 0, crianca = 0, adolescente = 0, MaioridadeF = 0, MaioridadeM = 0;
    char nomefilme[30], sexo;

    
    printf(" ##########################\n");//tela de inicio (interacao com o usuario)
    printf("## Bem vindo ao CineMarts ##\n");
    printf(" ##########################\n");
    fflush(stdin);
        do//loop para o menu inicial do programa
        {
            printf(" ______________\n");//menu estetico para melhor interacao com o usuario
            printf("| Menu inicial |\n");
            printf("|______________|\n");
            fflush(stdin);//limpando cache
            printf("Opcao 1: Inicializar cadastros\nOpcao 2: Sair do programa\nPor favor, digite sua opcao:");//opcoes do menu
            scanf("%d", &opcao);
            system("Cls");//limpando a tela
            switch (opcao)//para o usuario escolher entre cadastrar e sair do programa(com validacao caso ele nao escolha nenhuma das alternativas)
            {
            case 1:
                printf("\nInforme a quantidade de sessoes:");//sessoes com validacao de duas apenas
                fflush(stdin);
                do
                {
                    scanf("%d", &sessao);
                if (sessao != 2)
                {
                printf("\nNumero de sessao invalida, Digite o numero novamente:");
                }
                } while (sessao != 2);
                fflush(stdin);
                //nome do filme, e faça a validação, não aceitando o nome “vazio”
                    printf("\nInforme o nome do filme:");//nome do filme, nao podendo estar vazio
                do
                {
                fgets(nomefilme, 30, stdin);
                if (strlen(nomefilme) < 2)//validando para ler a quantidade de caracteres e nao deixar passar menos de dois!
                {
                    printf("Nome do filme invalido, por favor digite novamente:");//msg de erro
                } 

                } while (strlen(nomefilme) < 2);
                //Quantidade de pessoas que assistiram ao filme, não podendo aceitar valor inferior a 10 (dez)
                printf("\nInforme a quantidade de pessoas que assistiram o filme:");//quantidade de pessoas que assistiram ao filme, nao podendo <10
                do
                {
                scanf("%i", &Pessoas);
                if (Pessoas <= 10)//condicao para quantidade minima de pessoas
                {
                printf("\nQuantidade minima de pessoas nao alcancada!, por favor digite novamente:");
                }
                } while (Pessoas <= 10);//validacao para pessoas ser maior que 10 
                fflush(stdin);
                printf("------------------------------------------------------------------------------------------------\n");
                printf("||Por favor siga as instrucoes e digite a idade seguida do sexo de cada participante da sessao||\n");   
                printf("------------------------------------------------------------------------------------------------\n");
                fflush(stdin);
                do//usando o contadorP(no while) para repeticao das perguntas de idade e sexo
                {
                    do//para idade
                {
                    
                    printf("\nInforme a idade:");
                    scanf("%d", &idade);
                    fflush(stdin);
                    if (idade <3 || idade > 100 )//validacao da idade geral
                    {
                        printf("Idade invalida, por favor digite a idade novamente:\n");// msg de erro
                    }

                    } while (idade <3 || idade > 100 );//para idade
                    
                    do//para sexo
                    {
                    printf("\nInforme o Sexo [M/F]: ");//ler e gravar quais os sexos dos participantes
                    scanf("%c", &sexo);
                    fflush(stdin);

                    sexo = toupper(sexo);//colocando as letras do sexo em maiuscula

                    if  (sexo == 'F')
                    {
                            sexoF = sexoF + 1;//para guardar essas info nas tabelas
                    }
                    else if ( sexo == 'M')
                    {
                            sexoM = sexoM + 1;//para guardar essas info nas tabelas
                    }else if (sexo != 'M' && sexo != 'F')
                    {
                        printf("Sexo invalido, digite o sexo novamente [M/F]:\n");
                    }
                    fflush(stdin);
                    if (idade >=18 && sexo == 'M')//para validar a maioridade de acordo com o sexo
                    {
                        MaioridadeM = MaioridadeM +1;//para guardar essas info nas tabelas
                    }
                    if (idade >=18 && sexo == 'F')
                    {
                        MaioridadeF = MaioridadeF +1;//para guardar essas info nas tabelas
                    }
                    
                } while (sexo != 'M' && sexo != 'F');//para sexo nao ser diferente de M/F
                if (idade >= 64 && idade <100)// para classificar os participantes pela idade
                {
                    idoso = idoso + 1;//para guardar essas info nas tabelas
                }
                if (idade >= 18 && idade < 64)// para classificar os participantes pela idade
                {
                    adulto = adulto + 1;//para guardar essas info nas tabelas
                }
                if (idade >= 14 && idade < 17)// para classificar os participantes pela idade
                {
                    adolescente = adolescente + 1;//para guardar essas info nas tabelas
                }
                fflush(stdin);//limpando cache
                if (idade >= 3 && idade < 13)// para classificar os participantes pela idade
                {
                    crianca = crianca + 1;//para guardar essas info nas tabelas
                }
                contadorP = contadorP + 1;//para repetir as perguntas de idade e sexo de acordo com a quantidade de pessoas presentes na sessao
                } while (contadorP < Pessoas);


                system("Cls");//limpar tela
                fflush(stdin);//limpar cache
                //tabela pra informacoes na tela!
                
                fflush(stdin);//limpando cache
                printf("           ||Nome do Filme em cartaz: %s ||            \n", &nomefilme);
                fflush(stdin);
                printf("--------------------------------------------------------------\n");
                printf("|                Sexo        ||        Quantidade            |\n");
                printf("--------------------------------------------------------------\n");
                printf("|            Masculino(M)    ||           %d                 |\n", sexoM);
                printf("|            Feminino(F)     ||           %d                 |\n", sexoF);
                printf("--------------------------------------------------------------\n") ;
                fflush(stdin);//limpando cache
                system("pause\n");//pausa em uma tabela
                printf("             #Tabela para classificacao de idades#          \n");
                printf("------------------------------------------------------------\n");//mostrando informacoes em modo tabela
                printf("|     Idade      ||     Classificacao    ||   Quantidade   |\n");
                printf("------------------------------------------------------------\n");
                printf("|   03 ate 13    || Crianca              ||       %d       |\n", crianca);
                printf("|   14 ate 17    || Adolescente          ||       %d       |\n", adolescente);
                printf("|   18 ate 64    || Adultos              ||       %d       |\n", adulto);
                printf("|   65 ate 100   || Idosos               ||       %d       |\n", idoso);
                printf("------------------------------------------------------------\n");
                system("pause\n");//pausa em uma tabela
                fflush(stdin);//limpando cache
                printf("            #Tabela para classificar maiores de idade#        \n");
                printf("-----------------------------------------------------------------\n");//mostrando informacoes em modo tabela
                printf("|    Sexo         ||      Classificacao     ||     Quantidade   |\n");
                printf("-----------------------------------------------------------------\n");
                fflush(stdin);//limapndo cache
                printf("|   Masculino(M)  ||        +18             ||        %d        |\n", MaioridadeM);
                printf("|   Feminino(F)   ||        +18             ||        %d        |\n", MaioridadeF);
                printf("-----------------------------------------------------------------\n"); 
                printf("|  Total de pessoas presentes na sessao: %d                   |", &Pessoas);   
                printf("-----------------------------------------------------------------\n");
                
                
                break;//terminando caso 1
                case 2://caso o usuario queira sair do programa
                system("Cls");//limpar tela
                fflush(stdin);//limpar cache
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
                printf("|| Matias Enterprises agradece por utilizar um dos nossos programas ||\n");
                printf("                                    #######\n");
                printf("                                   #######\n");
                printf("                                  #######\n");
                printf("                                #######\n");
                printf("           #########          #######\n");
                printf("             #######        #######\n");
                printf("                 #############\n");
                printf("                   #########\n");
                printf("                     #####\n");
                fflush(stdin);
                system("pause");//pausar o programa
                exit(1);//para que se o usuario digitar enter ele saia
                break;
            
            default:printf("||Opcao desejada invalida!, Por favor digite novamente||\n");//msg de erro caso o usuario nao digite as opcoes requeridas
                break;
            }
        } while (opcao !=1 ||opcao !=2);//caso o usuario nao digite nem 1 nem 2 essa msg aparece e repete a pergunta do menu
        
    
//fim da funcao
return 0;
}
