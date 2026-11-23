// Grupo 02 - ABNER MARTINS; BRYAN FRANCA; MATHEUS MORAIS; ISABELLY OGURI; ALFREDO FERNANDO;

// Exercicio 04: Fechamento de Conta de Mesa em uma Pizzaria (com Vetor e Faturamento)

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

// Apaga a mensagem de erro na linha 23 do mapa (y = 22 no console Windows)
void limpa_erro(void)
{
    int i;
    gotoxy(1, 22);
    for (i = 0; i < 79; i++)
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

    // Vetor de faturamento acumulado das 10 mesas e totalizadores do dia
    const int total_mesas = 10;
    float faturamento_mesa[10] = {0};
    float total_dia = 0;
    float media_mesa = 0;

    // Variaveis de calculo da mesa
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

    // Controle de loops
    int num_mesa = 0;
    int i = 0;

    // REPETICAO DO PROCESSAMENTO - encerra quando Numero da Mesa == 0
    // O mapa usa linhas a partir de 1 e colunas a partir de 1; gotoxy usa base 0.
    while (1)
    {
        // ENTRADA DE DADOS
        system("cls");

        gotoxy(17, 1);
        printf("<<  Pizzaria  >>");

        gotoxy(11, 3);
        printf("<< Consumo da Mesa:    [0 = Sair] >>");

        // Leitura e validacao do Numero da Mesa (1 a 10, ou 0 para sair)
        gotoxy(31, 3);
        if (scanf("%d", &num_mesa) != 1)
        {
            printf("\nEntrada invalida.\n");
            return 1;
        }

        while (num_mesa < 0 || num_mesa > 10)
        {
            limpa_erro();
            gotoxy(1, 22);
            printf("Erro: ");
            gotoxy(7, 22);
            printf("Número da Mesa deve estar entre 1 e 10, inclusive.");

            gotoxy(31, 3);
            printf("   ");
            gotoxy(31, 3);
            if (scanf("%d", &num_mesa) != 1)
            {
                printf("\nEntrada invalida.\n");
                return 1;
            }
        }
        limpa_erro();

        // Condicao de encerramento do movimento do dia
        if (num_mesa == 0)
            break;

        // Rotulos dos itens (conforme Mapa de Tela de Entrada)
        gotoxy(20, 5);
        printf("Chopps........:");
        gotoxy(20, 6);
        printf("Pizzas Mistas.:");
        gotoxy(20, 7);
        printf("Coberturas....:");
        gotoxy(20, 8);
        printf("Refrigerantes.:");
        gotoxy(20, 9);
        printf("Águas.........:");
        gotoxy(20, 11);
        printf("Pessoas na Mesa:");

        // 1. Leitura de Chopps
        gotoxy(36, 5);
        if (scanf("%d", &qtd_chopp) != 1)
        {
            printf("\nEntrada invalida.\n");
            return 1;
        }
        if (qtd_chopp < 0)
            qtd_chopp = 0;

        // 2. Leitura e Validacao de Pizzas e Coberturas
        gotoxy(36, 6);
        if (scanf("%d", &qtd_pizza) != 1)
        {
            printf("\nEntrada invalida.\n");
            return 1;
        }

        gotoxy(36, 7);
        if (scanf("%d", &qtd_cobertura) != 1)
        {
            printf("\nEntrada invalida.\n");
            return 1;
        }

        // Impede quantidades negativas
        if (qtd_pizza < 0)
            qtd_pizza = 0;

        if (qtd_cobertura < 0)
            qtd_cobertura = 0;

        while ((qtd_pizza == 0 && qtd_cobertura > 0) ||
               (qtd_cobertura == 0 && qtd_pizza > 0))
        {
            limpa_erro();
            gotoxy(1, 22);
            printf("Erro: ");
            gotoxy(7, 22);

            if (qtd_pizza == 0 && qtd_cobertura > 0)
                printf("Informe a quantidade de Pizzas.");
            else
                printf("Informe a quantidade de Cobertura.");

            // Limpa apenas Pizzas e Coberturas e solicita novamente
            gotoxy(36, 6);
            printf("   ");
            gotoxy(36, 7);
            printf("   ");

            gotoxy(36, 6);
            if (scanf("%d", &qtd_pizza) != 1)
            {
                printf("\nEntrada invalida.\n");
                return 1;
            }

            gotoxy(36, 7);
            if (scanf("%d", &qtd_cobertura) != 1)
            {
                printf("\nEntrada invalida.\n");
                return 1;
            }

            if (qtd_pizza < 0)
                qtd_pizza = 0;

            if (qtd_cobertura < 0)
                qtd_cobertura = 0;
        }
        limpa_erro();

        // 3. Leitura de Refrigerantes e Aguas
        gotoxy(36, 8);
        if (scanf("%d", &qtd_refri) != 1)
        {
            printf("\nEntrada invalida.\n");
            return 1;
        }
        if (qtd_refri < 0)
            qtd_refri = 0;

        gotoxy(36, 9);
        if (scanf("%d", &qtd_water) != 1)
        {
            printf("\nEntrada invalida.\n");
            return 1;
        }
        if (qtd_water < 0)
            qtd_water = 0;

        // 4. Leitura e Validacao de Pessoas na Mesa
        gotoxy(37, 11);
        if (scanf("%d", &qtd_pess) != 1)
        {
            printf("\nEntrada invalida.\n");
            return 1;
        }

        while (qtd_pess <= 0)
        {
            limpa_erro();
            gotoxy(1, 22);
            printf("Erro: ");
            gotoxy(7, 22);
            printf("Obrigatório informar o número de Pessoas na mesa.");

            // Limpa apenas o campo de Pessoas na Mesa e solicita novamente
            gotoxy(37, 11);
            printf("   ");
            gotoxy(37, 11);

            if (scanf("%d", &qtd_pess) != 1)
            {
                printf("\nEntrada invalida.\n");
                return 1;
            }
        }
        limpa_erro();

        // CALCULOS DA CONTA DA MESA
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
        perc_gorjeta = taxa_gorjeta * percentual_total;

        // Acumula o Valor Total Pago (com Desconto) no vetor da respectiva mesa
        faturamento_mesa[num_mesa - 1] += total_pagar;

        // TELA DE SAIDA DE DADOS 1 - Fechamento da Conta da Mesa
        system("cls");

        gotoxy(25, 1);
        printf("<<  Pizzaria  >>");

        gotoxy(17, 3);
        printf("<<   Fechamento da Conta da Mesa: %2d   >>", num_mesa);

        gotoxy(19, 5);
        printf("Valor Total do Consumo....: %10.2f", value_consum);

        gotoxy(19, 6);
        printf("%% da Gorjeta do Garcom....: %5.2f", perc_gorjeta);

        gotoxy(19, 7);
        printf("Valor da Gorjeta..........: %10.2f", gorjeta_valor);

        gotoxy(19, 8);
        printf("Valor Total a Pagar.......: %10.2f", total_conta);

        gotoxy(19, 9);
        printf("%% de desconto.............: %5.2f", perc_desconto);

        gotoxy(19, 10);
        printf("Valor do desconto.........: %10.2f", valor_desconto);

        gotoxy(19, 12);
        printf("Valor Total com Desconto..: %10.2f", total_pagar);

        gotoxy(19, 14);
        printf("Quantidade Pessoas na mesa: %2d", qtd_pess);

        gotoxy(19, 15);
        printf("Valor a Pagar por pessoa..: %10.2f", value_pessoa);

        gotoxy(20, 18);
        system("pause");
    }

    // CALCULO DO FATURAMENTO TOTAL DO DIA
    for (i = 0; i < total_mesas; i++)
    {
        total_dia += faturamento_mesa[i];
    }

    // TELA DE SAIDA DE DADOS 2 - Fechamento do Faturamento
    system("cls");

    gotoxy(25, 1);
    printf("<<  Pizzaria  >>");

    gotoxy(19, 3);
    printf("<<   Fechamento do Faturamento   >>");

    if (total_dia == 0)
    {
        // Item 11: Se nao houve faturamento no dia, nao mostrar nenhum valor
        gotoxy(15, 22);
        printf("Atenção! NÃO houve Faturamento neste dia!");
    }
    else
    {
        media_mesa = total_dia / total_mesas;

        gotoxy(22, 5);
        printf("Num. Mesa      Tot. Faturado");

        for (i = 0; i < total_mesas; i++)
        {
            gotoxy(25, 7 + i);
            printf("%2d           %10.2f", i + 1, faturamento_mesa[i]);
        }

        gotoxy(19, 19);
        printf("Total do Faturamento do dia..: R$ %11.2f", total_dia);

        gotoxy(19, 21);
        printf("Média do Faturamento por Mesa: R$ %11.2f", media_mesa);
    }

    gotoxy(20, 23);
    system("pause");

    return 0;
}