# Geradores de Analisadores Sintáticos YACC e Bison

Os arquivos `calc.lex` e `calc.yacc` são os arquivos de entrada para o analisador Léxico LEX e Sintático YACC/Bison respectivamente, que descrevem a gramática que gera operações matemáticas.

## Requisitos:

- Instale o lex com o comando:

```
$ sudo apt install flex
```

- Instaler o yacc com o comando:

```
$ sudo apt install byacc
```

## Execução:

Compile os arquivos de entrada em seus respectivos programas:

```
$ lex -d calc.lex
$ yacc -d calc.yacc
```

O arquivo `lex.yy.c` será gerado pelo Lex e os arquivos `y.tab.c` e `y.tab.h` serão gerados pelo YACC/Bison.

Compile os arquivos de saída utilizando o comando `cc`:

```
$ cc lex.yy.c y.tab.c
```

A saída será o arquivo `a.out` que reconhece a gramática proposta. Pode ser executado da seguinte forma:

```
$ ./a.out
```
