#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void main(void){
    printf("-----Gerador de refeições-----\n");
    short int dias = 0;
    short int refeicoes;
    int nivel[3] = {0,0,0};
    short int repbuffer;
    char alfabeto[] = {'C','B','A'};

    //E/S dos dias
    printf("Digite o número de dias (1 = Seg; 3 = Seg, Ter, Quar...)\n-->");
    scanf("%hd",&dias);
    refeicoes = dias*2;
    printf("São [%d] refeições totais\n\n", refeicoes);

    printf("Distribua os níveis\n A - Refeições simples e fáceis\n B - Refeições saúdaveis e mais saborosas mas mais trabalhoasas\n C - Gostosas e Trabalhosas\n");
    printf("------Opções-----\n");
    printf("(1)\"Normal\" - Almoços A e B; jantares A e B; 4 refeições C\n");
    printf("(2)\"Apertada\" - Todos os almoços A; Todos os jantares B; e Fim de semana com jantares C\n");
    printf("(3) Personalizado - Selecione as quantidades\n--> ");
    
    scanf("%hi",&repbuffer);
    

    switch(repbuffer)
    {
    case 1:
        //Normal
        break;
    
    case 2:
        //Apertada
        break;

    case 3:
        //Personalizado
        for(int i = 0; i < 3; i++){
            int reftotais = 0;
            for(int j = 0; j<3;j++ ) reftotais += nivel[j];
            printf("Digite o número de refeições %c \nRefeições disponíveis %hi\n",alfabeto[i],refeicoes - reftotais);
            scanf("%hi",&repbuffer);
            nivel[i] += repbuffer;
            printf("%hi",nivel[i]);
            if(refeicoes - reftotais != 0)
            {   printf("Ainda há refeições, escreva as adicionais (o valor será somado ao existente)\n");
                i = 0;
            }else if(refeicoes - reftotais <= 0 ){
                exit(1);
            }
        }
    default:
        break;
    }










}

void arquivo(void){
    FILE *banco;
    
    banco = fopen("banco.txt","r");
    if(banco == NULL){
        printf("Erro ao abrir o arquivo\n");
    }
}