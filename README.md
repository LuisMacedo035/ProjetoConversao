# Conversor de Bases Numéricas

## 👥 Dupla
- Luís Miguel Macedo  
- Mirella Militani  

## 💻 Linguagem
- C++

---

## 📌 Sobre o projeto

Sistema que converte números entre bases:

- Binário (2)
- Octal (8)
- Decimal (10)
- Hexadecimal (16)

Inclui também:
- modo passo a passo
- modo batch (arquivo)
- modo quiz
- calculadora de máximo de bits
- suporte a fracionários (até 16 casas)

---

## 🚀 Como compilar

```bash
g++ main.cpp binario.cpp durelli.cpp -o programa
```

# Como executar o projeto

Para executar o programa, siga os passos abaixo:

1. Compile todos os arquivos do projeto:

g++ main.cpp binario.cpp durelli.cpp -o programa

2. Execute o programa gerado:

programa.exe

3. Ao iniciar, o sistema exibirá um menu com as opções disponíveis. Basta digitar o número da opção desejada e seguir as instruções na tela.

4. Caso utilize o modo batch, certifique-se de que o arquivo entrada.csv esteja na mesma pasta do executável, com o formato:
valor base_origem base_destino

5. O arquivo saida.csv será gerado automaticamente após a execução do modo batch.

# Exemplos de uso do programa

## ▶️ Execução
Após compilar e rodar o programa, o menu aparece na tela. O usuário escolhe uma opção digitando um número.

---

## 🔢 Exemplo 1 - Conversão normal

Entrada:
- Número: 1011
- Base de origem: 2
- Base de destino: 10

Saída:
- Resultado: 11

---

## 🪜 Exemplo 2 - Passo a passo

Entrada:
- Número: 13 (decimal)

Saída:
- 13 / 2 = 6 resto 1
- 6 / 2 = 3 resto 0
- 3 / 2 = 1 resto 1
- 1 / 2 = 0 resto 1

Resultado final: 1101

---

## 📂 Exemplo 3 - Batch (arquivo)

entrada.csv:

1011 2 10  
45 10 2  
1A 16 10  

saida.csv gerado:

1011;2;11;10  
45;10;101101;2  
1A;16;26;10  

---

## 🎮 Exemplo 4 - Quiz

Sistema mostra:

Converta: 1011 (base 2) para base 16

Resposta do usuário:
B

Resultado:
Correto!

---

## 🧠 Exemplo 5 - Máximos

Entrada:
k = 8

Saída:
Decimal: 255  
Binário: 11111111  
Octal: 377  
Hexadecimal: FF

# Limitações do sistema

- O modo batch só aceita números inteiros, não funcionando corretamente com valores fracionários.
- Os arquivos `entrada.csv` e `saida.csv` precisam estar na mesma pasta do executável.
- O sistema não possui validação avançada de erros no arquivo de entrada (linhas inválidas podem gerar comportamento incorreto).
- O modo quiz usa geração aleatória simples com `rand()`, podendo repetir números ou padrões.
