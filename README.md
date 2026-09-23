# Dicionário de Dados: Sistema de Fechamento de Contas - Pizzaria

Este documento descreve as variáveis utilizadas no sistema de cálculo de contas da pizzaria.

## 1. Preços Fixos e Taxas (Tipo `float`)

Valores pré-definidos que representam o cardápio do estabelecimento e taxas de serviço.

| Variável           | Tipo    | Valor Inicial | Descrição                                |
| :----------------- | :------ | :------------ | :--------------------------------------- |
| `price_chopp`      | `float` | `18.00`       | Preço unitário do chopp.                 |
| `price_pizzaG`     | `float` | `60.00`       | Preço unitário da pizza tamanho Grande.  |
| `price_cobert`     | `float` | `15.00`       | Preço unitário da cobertura/borda extra. |
| `price_refri360ml` | `float` | `12.00`       | Preço unitário do refrigerante de 360ml. |
| `price_water`      | `float` | `10.00`       | Preço unitário da garrafa de água.       |
| `porC_gorjeta`     | `float` | `0.08`        | Taxa de serviço/gorjeta padrão (8%).     |

## 2. Variáveis de Consumo / Quantidades (Tipo `int`)

Variáveis destinadas a armazenar a entrada do usuário referente aos itens pedidos na mesa.

| Variável        | Tipo  | Descrição                                           |
| :-------------- | :---- | :-------------------------------------------------- |
| `qtd_pess`      | `int` | Quantidade de pessoas na mesa para dividir a conta. |
| `qtd_chopp`     | `int` | Quantidade de chopps consumidos.                    |
| `qtd_pizza`     | `int` | Quantidade de pizzas grandes solicitadas.           |
| `qtd_cobertura` | `int` | Quantidade de coberturas/bordas extras solicitadas. |
| `qtd_refri`     | `int` | Quantidade de refrigerantes (360ml) consumidos.     |
| `qtd_water`     | `int` | Quantidade de águas consumidas.                     |

## 3. Variáveis de Cálculo e Faturamento (Tipo `float`)

Variáveis que armazenarão os resultados das operações matemáticas de fechamento da conta.

| Variável       | Tipo    | Valor Inicial | Descrição                                                                 |
| :------------- | :------ | :------------ | :------------------------------------------------------------------------ |
| `value_consum` | `float` | `0`           | Subtotal da conta (soma de todos os itens consumidos, sem a gorjeta).     |
| `total`        | `float` | `0`           | Valor total absoluto da conta (subtotal + taxa de serviço).               |
| `value_pessoa` | `float` | `0`           | Valor final que cada indivíduo da mesa deverá pagar (`total / qtd_pess`). |

## 4. Dados Cadastrais (Tipo `char[]`)

Variáveis para manipulação de texto.

| Variável       | Tipo       | Valor Inicial        | Descrição                                                                    |
| :------------- | :--------- | :------------------- | :--------------------------------------------------------------------------- |
| `pizzariaName` | `char[50]` | `"????????????????"` | String para armazenar o nome do estabelecimento (suporta até 49 caracteres). |
