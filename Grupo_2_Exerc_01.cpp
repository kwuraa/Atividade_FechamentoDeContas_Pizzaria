#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main()
{
	setlocale(LC_ALL, "Portuguese");

	// definição de variáveis

	float price_chopp = 18.00, price_pizza = 60.00, price_cobert = 15.00, price_refri360ml = 12.00, price_water = 10.00, value_pessoa = 0, total = 0, porC_gorjeta, value_consum = 0, gorgeta_valor;
	int qtd_pess, qtd_chopp, qtd_pizza, qtd_cobertura, qtd_refri, qtd_water;

	char pizzariaName[50] = "????????????????";

	// interface / inputs / outputs

	// ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?																																												? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?
	// ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?																																												? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?
	// ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?																																												? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?
	// ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?																																												? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?
	// ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ? ?

	// interface / inputs / outputs
	printf("==================================================\n");
	printf("           FECHAMENTO DE CONTA | PIZZARIA\n");
	printf("==================================================\n\n");
	printf("Nome da pizzaria: ");
	scanf(" %49[^\n]", pizzariaName);

	printf("\n--------------------- CARDAPIO -------------------\n");
	printf("Chopp                 R$ %6.2f\n", price_chopp);
	printf("Pizza grande          R$ %6.2f\n", price_pizza);
	printf("Cobertura/borda extra R$ %6.2f\n", price_cobert);
	printf("Refrigerante 360 ml   R$ %6.2f\n", price_refri360ml);
	printf("Agua                  R$ %6.2f\n", price_water);
	printf("--------------------------------------------------\n\n");

	printf("Quantidade de pessoas na mesa: ");
	scanf("%d", &qtd_pess);
	printf("Quantidade de chopps: ");
	scanf("%d", &qtd_chopp);
	printf("Quantidade de pizzas grandes: ");
	scanf("%d", &qtd_pizza);
	printf("Quantidade de coberturas/bordas extras: ");
	scanf("%d", &qtd_cobertura);
	printf("Quantidade de refrigerantes (360 ml): ");
	scanf("%d", &qtd_refri);
	printf("Quantidade de aguas: ");
	scanf("%d", &qtd_water);

	// logica

	//! Calculo de valor do consumo = multiplica a quantidade de cada item pelo valor do mesmo e soma armazenando em uma variavel só
	value_consum = (qtd_chopp * price_chopp) + (qtd_pizza * price_pizza) + (qtd_cobertura * price_cobert) + (qtd_water * price_water) + (qtd_refri * price_refri360ml);
	porC_gorjeta = 0.08 * 100;							  //! Calculo da porcentagem
	gorgeta_valor = value_consum * porC_gorjeta;		  //! Calculo da % da gorgeta
	total = value_consum + (value_consum * porC_gorjeta); //! Calculo do valor total a ser pago, incluindo a gorgeta

	value_pessoa = total / qtd_pess;	//! Calculo do valor por pessoa da mesa

	printf("\n==================================================\n");
	printf("                  %s\n", pizzariaName);
	printf("                 FECHAMENTO\n");
	printf("==================================================\n");
	printf("Pessoas na mesa:                  %d\n", qtd_pess);
	printf("Consumo:                          R$ %8.2f\n", value_consum);
	printf("Gorjeta:                          R$ %8.2f\n", gorgeta_valor);
	printf("Total da conta:                   R$ %8.2f\n", total);
	printf("Valor por pessoa:                 R$ %8.2f\n", value_pessoa);
	printf("==================================================\n");

	return 0;
}
