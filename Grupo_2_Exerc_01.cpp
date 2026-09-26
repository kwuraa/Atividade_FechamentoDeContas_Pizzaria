#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main()
{
	setlocale(LC_ALL, "Portuguese");
#include <iostream>
#include <string> // Necessário para usar o tipo string (opcional para o nome)

using namespace std;

int main() {
    
    float Prec_Chopp = 18.00;
    float Prec_PizzaMistaG = 65.00;
    float Prec_Cobertura = 15.00;
    float Prec_Refrigerante = 12.00;
    float Prec_Agua = 10.00;
    float Por_Gorjeta = 0.08; // 8% representado em formato decimal
    
    float Valor_Consumo;
    float Valor_Total;
    float Valor_Pessoa;

    // --- Variáveis de Quantidade (Inteiros) ---
    int Qtd_pessoas;
    int Qtd_Chopp
    int Qtd_PizzaMistaG;
    int Qtd_Cobertura;
    int Qtd_Refrigerante;
    int Qtd_Agua;

    // --- Variável de Texto (String ou Vetor de Char) ---
    char PizzariaName[50] = "Pizzaria do Bianch"; 
    
    printf("Consumo da Mesa");
    
    printf("Digite a quantidade de Chopps tomados");
    scanf("%f", &Qtd_Chopp)
    
    printf("Digite a quantidade de PizzasG consumidas");
    scanf("%f", &Qtd_PizzaMistaG)
    
    
    return 0;
}

