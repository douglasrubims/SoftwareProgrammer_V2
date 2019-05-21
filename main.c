#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int inicio(FILE *arq){
    if(fprintf(arq, "#include <stdio.h>\n#include <stdlib.h>\nint main(){\n")){
        return 1;
    }else{
        return 0;
    }
}
int variaveis(FILE *arq){
    int opcao, tamanho;
    char var[MAX];
    printf("--------------------\n\tTIPO\n--------------------\n0- Voltar.\n1- Inteiro.\n2- Real.\n3- Caracter.\n4- String.\n>");
    scanf("%d",&opcao);
    usleep(250000);
    switch(opcao){
        case 0:
            printf("Voltando...\n");
            return 1;
        break;
        case 1:
            printf("Digite o(s) nome(s) da(s) variavel(s) [separados por virgula]:\n>");
            setbuf(stdin, NULL);
            gets(var);
            if(fprintf(arq, "int %s;\n",var)){
                return 1;
            }else{
                return 0;
            }
        break;
        case 2:
            printf("Digite o(s) nome(s) da(s) variavel(s) [separados por virgula]:\n>");
            setbuf(stdin, NULL);
            gets(var);
            if(fprintf(arq, "float %s;\n",var)){
                return 1;
            }else{
                return 0;
            }
        break;
        case 3:
            printf("Digite o(s) nome(s) da(s) variavel(s) [separados por virgula]:\n>");
            setbuf(stdin, NULL);
            gets(var);
            if(fprintf(arq, "char %s;\n",var)){
                return 1;
            }else{
                return 0;
            }
        break;
        case 4:
            printf("Digite o nome da variavel:\n>");
            setbuf(stdin, NULL);
            gets(var);
            usleep(250000);
            printf("Digite o tamanho do vetor de caracteres:\n>");
            scanf("%d",&tamanho);
            if(fprintf(arq, "char %s[%d];\n",var,tamanho)){
                return 1;
            }else{
                return 0;
            }
        break;
        default:
            printf("Opcao invalida.\n");
            return 0;
        break;
    }
}
int saida(FILE *arq){
    int opcao;
    char var[MAX], vars[MAX];
    printf("--------------------\n\tSAIDA\n--------------------\n0- Voltar.\n1- Sem inclusao de variaveis.\n2- Incluindo variaveis.\n>");
    scanf("%d",&opcao);
    usleep(250000);
    switch(opcao){
        case 0:
            printf("Voltando...\n");
            return 1;
        break;
        case 1:
            printf("Digite a saida:\n>");
            setbuf(stdin, NULL);
            gets(var);
            if(fprintf(arq, "printf(\"%s\");\n", var)){
                return 1;
            }else{
                return 0;
            }
        break;
        case 2:
            printf("Digite a saida (use %%'x' | 'x' deve ser a letra correspondente ao tipo de variavel a ser incluida):\n>");
            setbuf(stdin, NULL);
            gets(var);
            usleep(250000);
            printf("Digite o(s) nome(s) da(s) variavel(s) que sera(ao) incluida(s):\n>");
            gets(vars);
            if(fprintf(arq, "printf(\"%s\",%s);\n", var, vars)){
                return 1;
            }else{
                return 0;
            }
        break;
        default:
            printf("Opcao inexistente.\n");
            return 0;
        break;
    }
}
int entrada(FILE *arq){
    char var[MAX], formato[MAX];
    printf("--------------------\n\tENTRADA\n--------------------\nDigite o formato da leitura em relacao a quantidade de variaveis (Exemplo: '%%d %%d'.):\n>");
    setbuf(stdin, NULL);
    gets(formato);
    usleep(250000);
    printf("Digite o(s) nome(s) da(s) variavel(s) a ser(rem) lida(s) (seguida(s) de '&' e separadas por virgula):\n>");
    setbuf(stdin, NULL);
    gets(var);
    if(fprintf(arq, "scanf(\"%s\",%s);\n", formato, var)){
        return 1;
    }else{
        return 0;
    }
}
int condicao(FILE *arq){
    int opcao, x = 0, y = 0, z = 0;
    char var[MAX], var1[MAX], condicao[MAX];
    printf("--------------------\n\tCONDICAO\n--------------------\n0- Voltar.\n1- Se.\n2- Se...Senao.\n3- Escolha.\n>");
    scanf("%d",&opcao);
    usleep(250000);
    switch(opcao){
        case 0:
            printf("voltando...\n");
            return 1;
        break;
        case 1:
            printf("Digite sua(s) condicao(oes):\n>");
            setbuf(stdin, NULL);
            gets(condicao);
            usleep(250000);
            printf("Digite o(s) comando(s) (separando-os por ';'):\n>");
            setbuf(stdin, NULL);
            gets(var);
            if(fprintf(arq, "if(%s){\n%s\n}\n", condicao, var)){
                return 1;
            }else{
                return 0;
            }
        break;
        case 2:
            printf("Digite sua(s) condicao(oes):\n>");
            setbuf(stdin, NULL);
            gets(condicao);
            usleep(250000);
            printf("Digite o(s) comando(s) (separando-os por ';'):\n>");
            setbuf(stdin, NULL);
            gets(var);
            usleep(250000);
            printf("Digite o(s) comando(s) do caso contrario(Senao) (separando-os por ';'):\n>");
            setbuf(stdin, NULL);
            gets(var1);
            if(fprintf(arq, "if(%s){\n%s\n}else{\n%s\n}\n", condicao, var, var1)){
                return 1;
            }else{
                return 0;
            }
        break;
        case 3:
            printf("Digite o nome da variavel a ser utilizada na estrutura condicional de multipla escolha:\n>");
            setbuf(stdin, NULL);
            gets(var);
            y++;
            if(fprintf(arq, "switch(%s){\n", var)){
                z++;
            }
            usleep(250000);
            do{
                printf("0- Voltar.\n1- Adicionar caso.\n");
                if(x==0){
                    printf("2- Caso contrario.\n>");
                }else{
                    printf(">");
                }
                scanf("%d",&opcao);
                usleep(250000);
                if(opcao == 0){
                    printf("Voltando...\n");
                }else if(opcao == 1){
                    printf("Digite o valor a ser verificado no caso:\n>");
                    setbuf(stdin, NULL);
                    gets(condicao);
                    usleep(250000);
                    printf("Digite o(s) comando(s) do caso (separando-os por ';'):\n>");
                    setbuf(stdin, NULL);
                    gets(var);
                    y++;
                    if(fprintf(arq, "case %s:\n%s\nbreak;\n", condicao, var)){
                        z++;
                    }
                }else if(x == 0){
                    if(opcao == 2){
                        x++;
                        printf("Digite o(s) comando(s) do caso contrario (separando-os por ';'):\n>");
                        setbuf(stdin, NULL);
                        gets(var);
                        y++;
                        if(fprintf(arq, "default:\n%s\nbreak;\n", var)){
                            z++;
                        }
                    }
                }
            }while(opcao != 0);
            y++;
            if(fprintf(arq, "}\n")){
                z++;
            }
            if(y==z){
                return 1;
            }else{
                return 0;
            }
        break;
    }
}
int repeticao(FILE *arq){
    int opcao;
    char var[MAX], inicializacao[MAX], condicao[MAX], incremento[MAX];
    printf("--------------------\n\tREPETICAO\n--------------------\n0- Voltar.\n1- Enquanto.\n2- Fazer...Enquanto.\n3- Para.\n>");
    scanf("%d",&opcao);
    usleep(250000);
    switch(opcao){
        case 0:
            printf("Voltando...\n");
            return 1;
        break;
        case 1:
            printf("Digite a(s) condicao(oes) do ciclo:\n>");
            setbuf(stdin, NULL);
            gets(condicao);
            usleep(250000);
            printf("Digite o(s) comando(s) que do ciclo:\n>");
            setbuf(stdin, NULL);
            gets(var);
            if(fprintf(arq, "while(%s){\n%s\n}\n", condicao, var)){
                return 1;
            }else{
                return 0;
            }
        break;
        case 2:
            printf("Digite o(s) comando(s) do ciclo:\n>");
            setbuf(stdin, NULL);
            gets(var);
            usleep(250000);
            printf("Digite a(s) condicao(oes) do ciclo:\n>");
            setbuf(stdin, NULL);
            gets(condicao);
            if(fprintf(arq, "do{\n%s\n}while(%s);\n", var, condicao)){
                return 1;
            }else{
                return 0;
            }
        break;
        case 3:
            printf("Digite a inicializacao:\n>");
            setbuf(stdin, NULL);
            gets(inicializacao);
            usleep(250000);
            printf("Digite a condicao:\n>");
            setbuf(stdin, NULL);
            gets(condicao);
            usleep(250000);
            printf("Digite o incremento:\n>");
            setbuf(stdin, NULL);
            gets(incremento);
            usleep(250000);
            printf("Digite o(s) comando(s) do ciclo:\n>");
            gets(var);
            if(fprintf(arq, "for(%s;%s;%s){\n%s\n}\n", inicializacao, condicao, incremento, var)){
                return 1;
            }else{
                return 0;
            }
        break;
    }
}
int fim(FILE *arq){
    if(fprintf(arq, "return 0;\n}\n")){
        return 1;
    }else{
        return 0;
    }
}
void erro(){
    usleep(250000);
	printf("Ocorreu um erro, tente novamente...\n");
}
void main(){
	char var[MAX], arquivo[MAX], x;
	int opcao, linhas=0;
    FILE *arq;
    system("cls || clear");
    usleep(200000);
	printf("        `;;;          ;;;                                      ::::                                                                   \n");
	usleep(200000);
	printf("    ;;;;         `;;; ``                                   ;;;;;,                                                                     \n");
	usleep(200000);
	printf("   .;;           `;:  ;;                                   ;;`.;;                                                                     \n");
	usleep(200000);
	printf("   `;;     ,;;.  :;;::;;:.:: :: .:, .;:::  :: ;  ,;;       ;;  ;;  ::.;  :;;   `;:::. :: ;  :;`::  :: ;; :;`  ::.;: ;;   .;;   :: ;   \n");
	usleep(200000);
	printf("    ;;;   .;;;;` ;;;;;;;; ;; ;; ;;  ;;;;;  ;;;; `;;;;      ;;.;;;  ;;;; ;;;;;  ;;;;;. :;:; `;;;;;  ;;;;;;;;;  ;;;;;;;;:  ;;;;  ;;;;   \n");
	usleep(200000);
	printf("     ;;;  ;; `;; `;:  ;;  ;; ;;`;; `;; ;;  ;;:  ;; `;.     ;;;;;   ;;   ;; :;. ;; ;;. :;;  :;, ;;  ;; ;;,`;;  ;; ;;`:;: :;  ;, ;;:    \n");
	usleep(200000);
	printf("      ;;; ;;  ;; `;:  ;;  ,;.;;,;: .;: ;;  ;;   ;;;;;:     ;;`     ;;   ;; :;:`;: :;. :;`  ;;  ;;  ;; :;. ;;  ;; ;; .;: ;;;;;: ;;     \n");
	usleep(200000);
	printf("      `;; ;;  ;; `;:  ;;   ;;;;;;` `;: ;;  ;;   ;;         ;;      ;;   ;; :;, ;; ;;. :;`  :;` ;;  ;; :;. ;;  ;; ;; .;: ;;     ;;     \n");
	usleep(200000);
	printf("    ;;;;: :;;;;: `;:  ;;   ;;,.;;   ;;:;;  ;;   :;`,;      ;;      ;;   ;;:;;  ;;;;;. :;`  ,;;:;;  ;; :;. ;;  ;; ;; .;: ,;..;` ;;     \n");
	usleep(200000);
	printf("    ;;;;   ;;;;  `;:  ;;   :;  ;;   ;;;;;  ;;    ;;;;      ;;      ;;   .;;;:  ,;;:;. :;`   ;;;;;  ;; :;. ;;  ;; ;; .;:  ;;;;  ;;     \n");
	usleep(200000);
	printf("                                                                                  :;`                                                 \n");
	usleep(200000);
	printf("                                                                               ;;;;;                                                  \n");
	usleep(200000);
	printf("                                                                                ;;:        V2.0                                       \n");
	usleep(200000);
	printf("Digite o nome do arquivo a ser criado(adicione a extensao '.c'): ");
	setbuf(stdin, NULL);
	gets(arquivo);
    arq = fopen(arquivo, "w");
    usleep(250000);
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo...\n");
    }else{
        if(inicio(arq) == 0){
            printf("Ocorreu um erro, tente novamente...\n");
        }
	    do{
        	printf("========================================\n\t\tMENU\n========================================\n0- Sair.\n1- Nomear Variaveis.\n2- Inserir comando de saida.\n3- Inserir comando de entrada.\n4- Inserir condicao.\n5- Inserir comando de repeticao.\n>");
        	scanf("%d",&opcao);
        	usleep(250000);
        	switch(opcao){
        		case 0:
        			printf("Encerrando...\n");
        		break;
        		case 1:
        			if(variaveis(arq) == 0)
        			    erro();
        		break;
        		case 2:
        			if(saida(arq) == 0)
        			    erro();
        		break;
        		case 3:
        			if(entrada(arq) == 0)
        			    erro();
        		break;
        		case 4:
        			if(condicao(arq) == 0)
        			    erro();
        		break;
        		case 5:
        			if(repeticao(arq) == 0)
        			    erro();
        		break;
        		default:
        		    printf("Opcao Inexistente.\n");
        	}
	    }while(opcao!=0);
	    usleep(250000);
	    if(fim(arq) == 0){
	        printf("Ocorreu um erro, tente novamente...\n");
        }
        fclose(arq);
        arq = fopen(arquivo, "r");
        usleep(250000);
        if(arq == NULL){
            printf("Erro ao abrir o arquivo...\n");
        }else{
            while((x=fgetc(arq))!=EOF){
                if(x=='\n'){
                    linhas++;
                }
            }
        }
        fclose(arq);
        printf("Quantidade de linhas programadas: %d.\n", linhas);
        #ifdef __linux__
        usleep(250000);
        printf("Compilando...\n");
        sprintf(var, "gcc %s -o %s.o", arquivo, arquivo);
        system(var);
        usleep(250000);
        printf("Executando o programa...\n\n========================================\n\n");
        usleep(250000);
        sprintf(var, "./%s.o", arquivo);
        system(var);
        #endif
        printf("\n\n===================|>By: Douglas Rubim.|\n");
    }
}