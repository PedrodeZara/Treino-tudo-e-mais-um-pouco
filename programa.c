#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//Observa as vari�veis para a maior entre elas
int maiorNumero(int num1, int num2, int num3) {
    if (num1 > num2 && num1 > num3) {
        return num1;
    }
    
    else if (num2 > num3) {
        return num3;
    }

    else {
        return num3;
    }
} 

//Observa as vari�veis para a menor entre elas
int menorNumero(int num1, int num2, int num3) {
    if (num1 < num2 && num2 < num3) {
        return num1;
    }

    else if (num2 < num3) {
        return num2;
    }

    else {
        return num3;
    }
}

//Calculadora
//Adi��o
int adi(int num1, int num2) {
    num1 += num2;
    return num1;
}

//Subtra��o
int sub(int num1, int num2) {
    num1 -= num2;
    return num1;
}

//Multiplica��o
int mult(int num1, int num2) {
    num1 *= num2;
    return num1;
}

//Divis�o
int divi(int num1, int num2) {
    if (num2 == 0) {
        printf("N�mero indivis�vel");
    }

    else {
        num1 /= num2;
    }
}

void main() {
    setlocale(LC_ALL, "Portuguese");
    int op, num1, num2, num3, op_vol = 0;

    printf("Bem vindo\n\nOque deseja fazer:");

    while(op_vol != 1) {
    printf("\n\n1.Numero maior e menor\n2.Calculadora\n3.Temporizador reverso");
    printf("\n\nSelecione: ");
    scanf("%d",&op);

        if (op == 1) {
            printf("\n=========================\n\tMaior e menor\n=========================\n\nEscolha tr�s n�meros: ");

            scanf("%d %d %d",&num1, &num2, &num3);

            int maior = maiorNumero(num1,num2,num3);
            int menor = menorNumero(num1,num2,num3);

            printf("\n\nSeu maior n�mero � igual a: %d\nSeu menor n�mero � igual a: %d",maior,menor);
        }

        else if (op == 2) {
            printf("\n=========================\n\tCalculadora\n=========================\n\nEscreva dois n�meros: ");
            scanf("%d %d", &num1, &num2);
            printf("Qual opera��o deseja utilizar: \n\n1.Adi��o\n2.Subtra��o\n3.Multiplica��o\n4.Divis�o\n\n");
            
            int escolha;
            
            scanf("%d", &escolha);

            if (escolha == 1) {
                int resultado = adi(num1, num2);
                printf("\n\nResultado: %d",resultado);
            }

            else if (escolha == 2) {
                int resultado = sub(num1, num2);
                printf("\n\nResultado: %d",resultado);
            }

            else if (escolha == 3) {
                int resultado = mult(num1, num2);
                printf("\n\nResultado: %d",resultado);
            }

            else if (escolha == 4) {
                int resultado = divi(num1, num2);
                printf("\n\nResultado: %d",resultado);
            }
        }

        else if (op == 3) {
            int segundos = 0;
            printf("\n=========================\n\tRel�gio\n=========================\n\nQuantos segundos:  ");
            scanf("%d", &segundos);

            while (segundos > 0) {
                int h = segundos / 3600; 
                int m = (segundos % 3600) / 60;
                int s = segundos % 60;

                printf("\r%0.2d:%0.2d:%0.2d", h, m, s);

                time_t parar = clock() + CLOCKS_PER_SEC;

                while (clock() < parar) { }

                segundos--;
            }

            printf("\rFim da atividade");
        }

        else {
            printf("\n\nN�mero inv�lido");
        }

    printf("\n\nDeseja executar novamente?\n1.N�o\n2.Sim\n");
    scanf("%d", &op_vol);
    }
}
