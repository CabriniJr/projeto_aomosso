//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Funções (fazer header dps)
void escolha_personalizado(void);

//Váriaveis globais
short int dias = 0;
short int refeicoes;
int nivel[3] = {0,0,0};
short int repbuffer;
char alfabeto[] = {'C','B','A'};


void main(void){
    printf("-----Gerador de refeições-----\n");
    

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
        system("clear");
        escolha_personalizado();

        
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

void escolha_personalizado(void){
    for(int i = 0; i < 3; i++){
        //Refeições totais
        int reftotais = 0;
        //Refeições disponíveis
        int refdip = 0;
        
        
        //Soma dos elementos para o acumulador Refeições totais
        for(int j = 0; j<3;j++ ) reftotais += nivel[j];
        refdip = refeicoes - reftotais;
        //Pergunta os números de Refeições para o nível do loop
        
        printf("Refeições disponíveis %hi\nDigite o número de refeições %c \n",refdip,alfabeto[i]);
        scanf("%hi",&repbuffer);
        //Refeições disponíveis menos a resposta
        refdip -= repbuffer;

        //Se for inputado um valor que seja maior que o total, ele vai adicionar o as refdip no nível e fechar o loop
        if(refdip <= 0){
            printf("Sem refeições disponíveis, resto aplicado ao nível\n");
            nivel[i] += repbuffer+refdip;
            printf("===> nível %c = %i\n",alfabeto[i],nivel[i]);
            break;
        }else{nivel[i] += repbuffer;}
        
        
        
        
        printf("%hi\n",nivel[i]);
        
        //Se a diferença das refeições e as refeições postas nos níveis serem maiores que 0 ele reinicia o loop 
        if(i == 2 && refdip > 0)i = -1;
        
    }
}