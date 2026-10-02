#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#ifdef _WIN32
#include <windows.h>

// Função gotoxy usando API do Windows
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = (SHORT)x;
    coord.Y = (SHORT)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
#else
// Versão portátil do gotoxy para Linux/Compiladores Online
void gotoxy(int x, int y)
{
    printf("\033[%d;%dH", y + 1, x + 1);
    fflush(stdout);
}
#endif

int main()
{
	setlocale(LC_ALL, "Portuguese");
 
	// definição de variáveis
 
	const float price_chopp = 18.00, price_pizza = 60.00, price_cobert = 15.00, price_refri360ml = 12.00, price_water = 10.00;
	const float taxa_gorjeta = 0.08; // 8% da gorjeta
	
	float value_pessoa = 0, total = 0, value_consum = 0, gorgeta_valor;
	int qtd_pess, qtd_chopp, qtd_pizza, qtd_cobertura, qtd_refri, qtd_water;
 
	char pizzariaName[50] = "????????????????";
 
	// interface / inputs / outputs
 
	gotoxy(20, 1); printf("==================================================");
	gotoxy(20, 2); printf("           FECHAMENTO DE CONTA | PIZZARIA");
	gotoxy(20, 3); printf("==================================================");
 
	gotoxy(20, 5); printf("Nome da pizzaria: ");
	gotoxy(39, 5); scanf(" %49[^\n]", pizzariaName);
 
	gotoxy(20, 7);  printf("--------------------- CARDAPIO -------------------");
	gotoxy(20, 8);  printf("Chopp                 R$ %6.2f", price_chopp);
	gotoxy(20, 9);  printf("Pizza grande          R$ %6.2f", price_pizza);
	gotoxy(20, 10); printf("Cobertura/borda extra R$ %6.2f", price_cobert);
	gotoxy(20, 11); printf("Refrigerante 360 ml   R$ %6.2f", price_refri360ml);
	gotoxy(20, 12); printf("Agua                  R$ %6.2f", price_water);
	gotoxy(20, 13); printf("--------------------------------------------------");
 
	gotoxy(20, 15); printf("Quantidade de pessoas na mesa: ");
	gotoxy(52, 15); scanf("%d", &qtd_pess);
 
	gotoxy(20, 16); printf("Quantidade de chopps: ");
	gotoxy(42, 16); scanf("%d", &qtd_chopp);
 
	gotoxy(20, 17); printf("Quantidade de pizzas grandes: ");
	gotoxy(50, 17); scanf("%d", &qtd_pizza);
 
	gotoxy(20, 18); printf("Quantidade de coberturas/bordas extras: ");
	gotoxy(60, 18); scanf("%d", &qtd_cobertura);
 
	gotoxy(20, 19); printf("Quantidade de refrigerantes (360 ml): ");
	gotoxy(58, 19); scanf("%d", &qtd_refri);
 
	gotoxy(20, 20); printf("Quantidade de aguas: ");
	gotoxy(42, 20); scanf("%d", &qtd_water);
 
	// logica
 
	value_consum = (qtd_chopp * price_chopp) + (qtd_pizza * price_pizza) + (qtd_cobertura * price_cobert) + (qtd_water * price_water) + (qtd_refri * price_refri360ml);
	
	gorgeta_valor = value_consum * taxa_gorjeta;
	total = value_consum + gorgeta_valor;
 
	if (qtd_pess <= 0)
		qtd_pess = 1;
 
	value_pessoa = total / qtd_pess;
 
	// Resultado
 
	gotoxy(20, 22); printf("==================================================");
	gotoxy(20, 23); printf("                  %s", pizzariaName);
	gotoxy(20, 24); printf("                 FECHAMENTO");
	gotoxy(20, 25); printf("==================================================");
	gotoxy(20, 26); printf("Pessoas na mesa:                  %d", qtd_pess);
	gotoxy(20, 27); printf("Consumo:                          R$ %8.2f", value_consum);
	gotoxy(20, 28); printf("Gorjeta:                          R$ %8.2f", gorgeta_valor);
	gotoxy(20, 29); printf("Total da conta:                   R$ %8.2f", total);
	gotoxy(20, 30); printf("Valor por pessoa:                 R$ %8.2f", value_pessoa);
	gotoxy(20, 31); printf("==================================================");
 
	return 0;
}