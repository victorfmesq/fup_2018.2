#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_resultado(int cont_chutes, int n_chute ,int cash_ini, int cash, int number){
    if (cont_chutes == 0){
        printf("\nQue pena, você perdeu... o número era\t ---> \t%d\n", number);
    }else if (cont_chutes == 10){
        puts("Parece que temos um Chuck Norris! entre nós!");
    }else if (cont_chutes > 6){
        puts("Não contava com sua astúcia, Chapolim!");
    }else if (cont_chutes > 1){
        puts("Você é o Jaspion!");
    }else{
        puts("Você é um cagado!");
    }
    if(cash_ini == cash && cont_chutes == 0){
        puts("\n\tPERDEU TUDO!!! TÁ LIZO TROUXA!!\n");
    }
    cash = (((10 - n_chute) * cash) + (cash_ini - cash));
    printf("\t---> Seu saldo atual é: $%d <---\n", cash);
}


int main(){
    srand(time(NULL));
    int cont_chutes = 10; // contador de chutes do jogador;
    int n_chute = 0;
    int jog_chute = 0;
    int cash = 0;
    int cash_ini = 100;
    int number = rand() % 1001;
    puts("\n\tEsse é um jogo de apostas, voce receberá uma recompensa de acordo com sua sorte...\n");
    printf("\nSeu saldo é: $%d", cash_ini);
    puts("\nFaça sua aposta...\n");
    while(1){
        scanf("%d", &cash);
        if (cash > cash_ini){
            puts("Valor inválido... Você não é tem essa quantia em mãos...\n");
            puts("\tAposte outro valor\n");
        }else{
            break;
        }
    }
    printf("\tVocê apostou $%d.\n\tSaldo atual é: $%d.\n", cash ,cash_ini - cash);

    puts("\nBem vindo ao desafio: 'Adivinhe o numero'\nTestaremos seus psycho poderes...\nRapido.. escolha um numero entre 0 e 1000!!\n");

    while(cont_chutes != 0 || jog_chute == number){
        printf("Você tem %d chances para acertar\n", cont_chutes);
        scanf("%d", &jog_chute);
        if (jog_chute == number){
            puts("\n\tParabéns! Você acertou. ");
            break;
        }else if(jog_chute > number){
            //printf("É menor. Você tem %d chances\n", cont_chutes -1);
            puts("\tO número é menor.");
        }else{
            //printf("É maior. Você tem %d chances\n", cont_chutes -1);
            puts("\tO número é maior.");
        }
        cont_chutes--;
        n_chute++;
    }

    print_resultado(cont_chutes, n_chute, cash_ini, cash, number);

    /*
    char escolha = '\0';
    puts("\n\tDeseja continuar com o jogo?\t (Y/N)?");
    scanf("%c", escolha);
    if (escolha == 'Y' || escolha == 'y'){

    }else if (escolha == 'N' || escolha == 'n'){
        puts("Até a próxima");
        return 0;
    }else{
        puts("Comando inválido");
    }
    */
    return 0;
}