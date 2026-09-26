# Dicionário de Dados: Sistema de Fechamento de Contas - Pizzaria

Este documento descreve as variáveis utilizadas no sistema de cálculo de contas da pizzaria.

## 1. Preços Fixos e Taxas (Tipo `float`)

Valores pré-definidos que representam o cardápio do estabelecimento e taxas de serviço.

| Variável           | Tipo    | Valor Inicial | Descrição                                |
| :----------------- | :------ | :------------ | :--------------------------------------- |
| `price_chopp`      | `float` | `18.00`       | Preço unitário do chopp.                 |
| `price_pizza`      | `float` | `60.00`       | Preço unitário da pizza tamanho Grande.  |
| `price_cobert`     | `float` | `15.00`       | Preço unitário da cobertura/borda extra. |
| `price_refri360ml` | `float` | `12.00`       | Preço unitário do refrigerante de 360ml. |
| `price_water`      | `float` | `10.00`       | Preço unitário da garrafa de água.       |
| `porC_gorjeta`     | `float` | não inicial.  | Porcentagem da gorjeta, atribuída na lógica (`0.08 * 100` = `8`). |

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

| Variável        | Tipo    | Valor Inicial | Descrição                                                                       |
| :-------------- | :------ | :------------ | :------------------------------------------------------------------------------ |
| `value_consum`  | `float` | `0`           | Subtotal da conta (soma de todos os itens consumidos, sem a gorjeta).           |
| `gorgeta_valor` | `float` | não inicial.  | Valor da gorjeta sobre o consumo (`value_consum * porC_gorjeta`).               |
| `total`         | `float` | `0`           | Valor total a ser pago: consumo somado à gorjeta (`value_consum + gorgeta_valor`). |
| `value_pessoa`  | `float` | `0`           | Valor final que cada indivíduo da mesa deverá pagar (`total / qtd_pess`).       |

## 4. Dados Cadastrais (Tipo `char[]`)

Variáveis para manipulação de texto.

| Variável       | Tipo       | Valor Inicial        | Descrição                                                                    |
| :------------- | :--------- | :------------------- | :--------------------------------------------------------------------------- |
| `pizzariaName` | `char[50]` | `"????????????????"` | String para armazenar o nome do estabelecimento (suporta até 49 caracteres). |

## 5. Estrutura do Programa

O código está dividido em três blocos, na ordem:

1. **Definição de variáveis** — declaração e inicialização das constantes do cardápio, das quantidades e das variáveis de cálculo.
2. **Interface (inputs)** — bloco reservado para a leitura dos dados pelo usuário. _Ainda em construção (contém apenas comentários/placeholders)._
3. **Lógica** — sequência de cálculos do fechamento da conta:

| Etapa | Operação                                | Fórmula no código                                                                                                                                                    |
| :---- | :-------------------------------------- | :------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 1     | Valor total do consumo (soma dos itens) | `value_consum = (qtd_chopp * price_chopp) + (qtd_pizza * price_pizza) + (qtd_cobertura * price_cobert) + (qtd_water * price_water) + (qtd_refri * price_refri360ml)` |
| 2     | Porcentagem da gorjeta                  | `porC_gorjeta = 0.08 * 100`                                                                                                                                          |
| 3     | Valor da gorjeta                        | `gorgeta_valor = value_consum * porC_gorjeta`                                                                                                                         |
| 4     | Valor total da conta (com gorjeta)      | `total = value_consum + (value_consum * porC_gorjeta)`                                                                                                                |
| 5     | Valor por pessoa                        | `value_pessoa = total / qtd_pess`                                                                                                                                    |

## 6. Registro de Alterações

| Data       | Arquivo                | Alteração                                                                                           |
| :--------- | :--------------------- | :-------------------------------------------------------------------------------------------------- |
| 25/09/2026 | `Grupo_2_Exerc_01.cpp` | Renomeada a variável `price_pizzaG` para `price_pizza`.                                             |
| 25/09/2026 | `Grupo_2_Exerc_01.cpp` | Adicionada a variável `gorgeta` (`float`) na declaração de valores.                                 |
| 25/09/2026 | `Grupo_2_Exerc_01.cpp` | Criados os blocos `interface / inputs / outputs` (placeholder) e `logica`.                          |
| 25/09/2026 | `Grupo_2_Exerc_01.cpp` | Implementados os cálculos de `value_consum`, `gorgeta`, `total` e `value_pessoa`.                   |
| 25/09/2026 | `Grupo_2_Exerc_01.cpp` | Renomeada `gorgeta` para `gorgeta_valor`.                                                           |
| 25/09/2026 | `Grupo_2_Exerc_01.cpp` | `porC_gorjeta` deixou de ser inicializada com `0.08` e passou a ser calculada (`0.08 * 100`).        |
| 25/09/2026 | `Grupo_2_Exerc_01.cpp` | Corrigida a fórmula de `total`: agora soma o consumo com a gorjeta.                                 |
| 25/09/2026 | `README.md`            | Dicionário de dados atualizado (`price_pizza`, `gorgeta_valor`) e novas seções de estrutura e alterações. |

> **Pendências identificadas:** as quantidades (`qtd_*`) e `qtd_pess` ainda não são lidas na interface (bloco com placeholders). Além disso, `porC_gorjeta` vale `8` e não `0,08`, então `gorgeta_valor` e `total` multiplicam o consumo por 8 (gorjeta = 8× o consumo; total = 9×) em vez de aplicar 8% — para cobrar 8%, use `porC_gorjeta = 0.08` ou divida o resultado por 100.
