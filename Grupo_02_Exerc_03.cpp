// Grupo 02 - Exercicio 03
// Fechamento de Conta de Mesa - Pizzaria Japonesa

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = (SHORT)x;
    coord.Y = (SHORT)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Apaga a mensagem de erro exibida na linha 18 do Mapa de Entrada
void limpa_erro(void)
{
    int i;
    gotoxy(2, 18);
    for (i = 0; i < 78; i++)
        printf(" ");
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");

    // Precos dos produtos (valores fixos)
    const float price_chopp = 18.00;
    const float price_pizza = 65.00;
    const float price_cobert = 15.00;
    const float price_refri360ml = 10.00;
    const float price_water = 8.00;

    // Taxa fixa de gorjeta: 8%
    const float taxa_gorjeta = 0.08;
    float perc_gorjeta = 0;

    // Faixas de desconto (valores fixos)
    const float perc_desc_ate300 = 5.2;
    const float perc_desc_ate600 = 8.3;
    const float perc_desc_acima600 = 10.0;
    const float limite_desc_1 = 300.00;
    const float limite_desc_2 = 600.00;
    const float percentual_total = 100.0;

    // Variaveis de calculo
    float value_consum = 0;
    float gorjeta_valor = 0;
    float total_conta = 0;
    float perc_desconto = 0;
    float valor_desconto = 0;
    float total_pagar = 0;
    float value_pessoa = 0;

    // Quantidades
    int qtd_pess = 0;
    int qtd_chopp = 0;
    int qtd_pizza = 0;
    int qtd_cobertura = 0;
    int qtd_refri = 0;
    int qtd_water = 0;

    // Controle do loop de processamento
    int num_mesa = 0;
    int valido = 0;
    const char *msg_erro = NULL;

    // REPETICAO DO PROCESSAMENTO - sai do programa quando a Mesa for 0
    while (1)
    {
        // ENTRADA DE DADOS
        system("cls");

        gotoxy(17, 2);
        printf("<<  Pizzaria Japonesa  >>");

        gotoxy(11, 4);
        printf("<< Consumo da Mesa: ");
        gotoxy(35, 4);
        printf("[0 = Sair] >>");
        gotoxy(31, 4);
        if (scanf("%d", &num_mesa) != 1)
        {
            printf("\nEntrada invalida.\n");
            return 1;
        }

        // Condicao de encerramento do programa
        if (num_mesa == 0)
            break;

        // Rotulos dos itens (conforme Mapa de Tela de Entrada)
        gotoxy(20, 6);
        printf("Chopps........:");
        gotoxy(20, 7);
        printf("Pizzas Mistas.:");
        gotoxy(20, 8);
        printf("Coberturas....:");
        gotoxy(20, 9);
        printf("Refrigerantes.:");
        gotoxy(20, 10);
        printf("Águas.........:");
        gotoxy(20, 12);
        printf("Pessoas na Mesa:");

        // LEITURA E VALIDACAO DOS DADOS - repete ate todos os dados serem validos
        valido = 0;
        while (!valido)
        {
            // Limpa os campos antes de solicitar os dados novamente
            gotoxy(36, 6);
            printf("   ");
            gotoxy(36, 7);
            printf("   ");
            gotoxy(36, 8);
            printf("   ");
            gotoxy(36, 9);
            printf("   ");
            gotoxy(36, 10);
            printf("   ");
            gotoxy(37, 12);
            printf("  ");

            gotoxy(36, 6);
            if (scanf("%d", &qtd_chopp) != 1)
            {
                printf("\nEntrada invalida.\n");
                return 1;
            }

            gotoxy(36, 7);
            if (scanf("%d", &qtd_pizza) != 1)
            {
                printf("\nEntrada invalida.\n");
                return 1;
            }

            gotoxy(36, 8);
            if (scanf("%d", &qtd_cobertura) != 1)
            {
                printf("\nEntrada invalida.\n");
                return 1;
            }

            gotoxy(36, 9);
            if (scanf("%d", &qtd_refri) != 1)
            {
                printf("\nEntrada invalida.\n");
                return 1;
            }

            gotoxy(36, 10);
            if (scanf("%d", &qtd_water) != 1)
            {
                printf("\nEntrada invalida.\n");
                return 1;
            }

            gotoxy(37, 12);
            if (scanf("%d", &qtd_pess) != 1)
            {
                printf("\nEntrada invalida.\n");
                return 1;
            }

            // VALIDACOES - mensagem na linha 18 do Mapa de Entrada
            msg_erro = NULL;

            if (qtd_pizza == 0 && qtd_cobertura > 0)
                msg_erro = "Informe a quantidade de Pizzas.";
            else if (qtd_cobertura == 0 && qtd_pizza > 0)
                msg_erro = "Informe a quantidade de Cobertura";
            else if (qtd_pess <= 0)
                msg_erro = "Obrigatório informar o número de Pessoas na mesa.";

            if (msg_erro != NULL)
            {
                limpa_erro();
                gotoxy(2, 18);
                printf("Erro: %s", msg_erro);
            }
            else
            {
                valido = 1;
            }
        }

        // Apaga a mensagem de erro apos a validacao
        limpa_erro();

        if (qtd_chopp < 0)
            qtd_chopp = 0;

        if (qtd_refri < 0)
            qtd_refri = 0;
        if (qtd_water < 0)
            qtd_water = 0;

        // CALCULOS
        value_consum =
            (qtd_chopp * price_chopp) +
            (qtd_pizza * price_pizza) +
            (qtd_cobertura * price_cobert) +
            (qtd_refri * price_refri360ml) +
            (qtd_water * price_water);

        gorjeta_valor = value_consum * taxa_gorjeta;
        total_conta = value_consum + gorjeta_valor;

        // Desconto automatico conforme o total da conta com gorjeta
        if (total_conta <= limite_desc_1)
        {
            perc_desconto = perc_desc_ate300;
        }
        else if (total_conta <= limite_desc_2)
        {
            perc_desconto = perc_desc_ate600;
        }
        else
        {
            perc_desconto = perc_desc_acima600;
        }

        valor_desconto = total_conta * (perc_desconto / percentual_total);
        total_pagar = total_conta - valor_desconto;
        value_pessoa = total_pagar / qtd_pess;

        // Calculo separado da exibicao, conforme orientacao do professor
        perc_gorjeta = taxa_gorjeta * percentual_total;

        // SAIDA DE DADOS
        system("cls");

        gotoxy(25, 2);
        printf("<<  Pizzaria Japonesa  >>");

        gotoxy(17, 4);
        printf("<<   Fechamento da Conta da Mesa: %2d   >>", num_mesa);

        gotoxy(19, 6);
        printf("Valor Total do Consumo....: %10.2f", value_consum);

        gotoxy(19, 7);
        printf("%% da Gorjeta do Garcom....: %2.0f", perc_gorjeta);

        gotoxy(19, 8);
        printf("Valor da Gorjeta..........: %10.2f", gorjeta_valor);

        gotoxy(19, 9);
        printf("Valor Total da conta......: %10.2f", total_conta);

        gotoxy(19, 10);
        printf("%% do desconto.............: %4.1f", perc_desconto);

        gotoxy(19, 11);
        printf("Valor do Desconto.........: %10.2f", valor_desconto);

        gotoxy(19, 13);
        printf("Valor Total a Pagar.......: %10.2f", total_pagar);

        gotoxy(19, 15);
        printf("Quantidade Pessoas na mesa: %2d", qtd_pess);

        gotoxy(19, 16);
        printf("Valor a Pagar por pessoa..: %10.2f", value_pessoa);

        gotoxy(20, 18);
        system("pause");
    }

    return 0;
}
