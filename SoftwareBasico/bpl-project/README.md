# SwB-Bruno-BPL

Trabalho desenvolvido como atividade avaliativa da disciplina de Software Básico para o curso de Ciências da Computação da UFG.
Desenvolvido em Janeiro de 2023.

O enunciado do trabalho é o arquivo PDF na raiz do repositório e a pasta tradutor (também na raiz) contém código de exemplo fornecido pelo professor para orientar no desenvolvimento do trabalho. 

Para executar o código e testar com os testes padrões utilize:
```
gcc src/*.c -o tests/main -lm
cd tests
sh test.sh
```

## O que este projeto não faz ?
1. Ele não trata erros da linguagem de entrada
1. Não insere return caso o arquivo BPL não possua um (também não insere leave e ret caso não tenha return);
2. Pula a primeira variável declarada caso a função não tenha uma linha "def"
2. Não traduz corretamente caso não encontre "enddef"
3. Não traduz corretamente referências à variáveis não declaradas
4. Gera assembly errado caso seja declarado um vetor com tamanho negativo
5. Gera assembly errado caso sejam declaradas duas funções com o mesmo identificador
6. Não trata arrays excessivamente grandes (acima de 64Ki)
7. Não tenta impedir a atribuição de valores a constantes
8. Não suporta variáveis locais com identificadores negativos
9. Não suporta variáveis locais com identificadores acima de LONG_MAX (9223372036854775807)
10. Gera assembly errado caso tente atribuir valores constantes fora dos limites dos inteiros (INT_MAX e INT_MIN)
11. Não move parâmetros (%edi, %esi e %edx) ou constantes direto para a memória (passa por %eax primeiro)
12. Não impede o usuário de tentar acessar posições inválidas nos arrays
13. Não realiza otimizações como pré-calcular índices ou constantes 

## Um resumo do BNF da linguagem BPL
```
<prog>:
	function f<num> pi<num> pa<num> ...
	def
	var vi<num>
	vet va<num> size ci<snum>
	enddef
	vi<num> = <valint>
	vi<num> = <valint> <op> <valint>
	vi<num> = call f<num> <arg> ...
	get <array> index ci<snum> to vi<num>
	set <array> index ci<snum> with <valint>
	if <valint>
	<body>
	endif
	return <valint>
	end
	<prog>
```
```
<num>:
	[números]
<snum>:
	[números com sinal]
<valint>:
	vi<num> | pi<num> | ci<snum>
<arg>:
	vi<num> | pi<num> | ci<snum> | va<num> | pa<num>
<op>:
	+ | - | * | /
```

> Observações

1. Após `f<num>` podem haver de 0 a 3 parâmetros `pi<num` ou `pa<num`
2. Entre `def` e `enddef` podem haver de 0 a 5 linhas declarando variáveis `vi<num` ou `va<num>`
3. Entre `enddef` e `end` pode haver qualquer quantidade e combinação dos comandos exemplificados no resumo
4. `call f<num>` é seguido de 0 a 3 argumentos `<arg>` 
4. `<body>` contém apenas um comando
5. Pode ou não haver outro `<prog>` após `end`

## Traduções
```
vi<num> = <valint>:
	movl <valint>, %eax
	movl %eax, vi<num>
```
```
vi<num> = <valint1> <op> <valint2>:
  movl <valint1>, %eax

  op == '+':
    addl <valint2>, %eax
  op == '-':
    subl <valint2>, %eax
  op == '*':
    imull <valint2>, %eax
  op == '/':
    [Salva %rdx]
    cltd
    idivl <valint2>
    [Recupera %rdx]
  
  movl %eax, vi<num>
```
```
vi<num> = call f<num> <arg> ...:
  [Salva parâmetros recebidos pela função]
  mov(q/l) <arg1>, %(r/e)di
  mov(q/l) <arg2>, %(r/e)si
  mov(q/l) <arg3>, %(r/e)dx
  call f<num>
  movl %eax, vi<num>
  [Recupera parâmetros recebidos pela função]
```
```
get <array> index ci<snum> to vi<num>:
  movq ci<snum>, %rax
  imulq $4, %rax

  <array> == va<num>:
    leaq <array>, %r8
    addq %r8, %rax
  <array> == pa<num>:
    addq <array>, %rax

  movl (%rax), %r8d
  movl %r8d, vi<num>
```
```
set <array> index ci<snum> with <valint>:
  movq ci<snum>, %rax
  imulq $4, %rax

  <array> == va<num>:
    leaq <array>, %r8
    addq %r8, %rax
  <array> == pa<num>:
    addq <array>, %rax

  <valint> == vi<num>:
    movl <valint>, %r8d
    movl %r8d, (%rax)
  <valint> == (pi<num> | ci<snum>):
    movl <valint>, (%rax)
```
```
if <valint>
<body>
endif:
  cmpl $0, <valint>
  je .L[X]
    <body>
  .L[X]:
```
```
return <valint>:
  movl <valint>, %eax
  leave
  ret
```