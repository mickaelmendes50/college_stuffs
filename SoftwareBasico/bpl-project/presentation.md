# Como nós fizemos o trabalho?

O desenvolvimento seguiu principalmente o exposto no BNF da linguagem. Para auxiliar no desenvolvimento, simplificamos o BNF deixando ele mais parcido com uma formatação de entrada. Assim como nos exercícios de programação que fazemos tanto aqui como online (Neps, Codeforces, URI etc).

Além disso, usamos a idéia principal do arquivo que o senhor disponibilizou na Turing e expôs na sala de aula. Ou seja, o programa lê uma linha por vez e a processa, sem armazenar as linhas lidas e sem nenhum conhecimento das linhas seguintes. Poderíamos ter utilizado um método recursivo para ficar mais semelhante a um compilador e assim termos conhecimento das linha seguintes, mas ainda assim teriamos muitos problemas com a ordem de impressão das operações ou o registro delas em um buffer de impressão. Isso porque o buffer precisaria ser implementado em uma lista encadeada já que não existe limite de linhas de entrada.

A leitura de cada linha segue o mesmo padrão do arquivo tradutor.c. Elas são lidas na função readNextLine. Nessa função é implementado um loop que lê todas as linhas até a próxima linha válida de código BPL usando a função fgets. Todas as linhas que iniciam com ‘#’ são interpretadas como comentários e são reimpressas no código traduzido. Além disso, todas as linhas em branco também são reimpressas. A função retorna 1 quando conseguiu ler uma linha válida e 0 quando chegou ao final do arquivo sem ler nenhuma linha válida.

# Como nós organizamos o código?

O código foi dividido em vários arquivos por tópico, usando um único header.h para compartilhar as declarações das funções e variáveis globais. 

As funções principais se encontram no main.c, as auxiliares em aux.c, as que processam parâmetros em param.c e assim por diante.

# Qual o fluxo de execução do programa?

O arquivo main.c contém apenas a main e a readFunc que são as duas funções que orquestram todo o processo de tradução. A main lê as linhas de declaração das funções em BPL e passa o controle para a readFunc até que não existam mais linhas na entrada. Como você pode ver aqui, as seções do arquivo assembly são impressas na main, ou seja, o programa produz apenas um arquivo assembly válido por chamada.

A função readFunc começa declarando a função em assembly (.globl e a label). Depois ela lê os parâmetros que a função recebeu e armazena os offsets deles na pilha. Ela utiliza a processParam para fazer isso, o que imprime os comentários com os offsets do parâmetros na pilha, para caso eles precisem ser salvos.

O offsets são salvos na variável global paramOffsets. Que é um vetor de inteiros com 3 posições, pois na definição da linguagem BPL têm no máximo 3 parâmetros e eles são identificados por números sequenciais começando em 1. O cálculo desses offsets é feito com a premissa de que podemos salvar o registrador inteiro na pilha, como fazemos nos laboratórios. Depois de ler os parâmetros, e readFunc chama processVars que vai ler as variáveis locais contidas no bloco def..enddef

Essa função faz a mesma coisa que a processParams, só que armazena os offsets das variáveis locais em varOffsets. varOffsets no entanto é um dicionário. Não era suficiente usar o identificador das variáveis locais como índice do array varOffsets pois o enunciado do trabalho não deu garantia nenhuma de que os identificadores eram sequenciais, e nem a range desses identificadores. 

varOffsets tem dois longs em cada posição, o primeiro é o identificador da variável e o segundo é o offset dela na pilha. Ao traduzir um identificador de variável local em BPL para assembly, como o varOffsets tem apenas 5 posições, a busca é simples. Depois disso, a readFunc chama uma função que arredonda o último offset para um múltiplo de 16.

Deste ponto em diante, só restam operações e a finalização da função. Por sorte ou bondade maior, cada linha de operação pode ser diferenciada pelo seu primeiro caracter. Assim usamos um switch case para decidir qual função deve processar a linha que foi lida. Isso processa todas as linha restantes até o final da função, sinalizado pela palavra “end”.

Assim, já foram processados a declaração da função e das variáveis locais. As próximas linhas da entrada são operações:

1. Atribuições (simples, com operação ou com chamada de função)
2. Get e Set para acessar arrays
3. Bloco if..endif
4. Retorno

As atribuições estão em attributions.c. Os acessos a arrays estão em array.c. As funções que processam o bloco if..endif estão em if.c. O arquivo aux.c é um conjunto de funções simples e compartilhada entre vários processadores, como removeNewline e expandArg.

# Como as atribuições são processadas?

A principal idéia é usar o %rax como um registrador acumulador. Ou seja, não importa qual o tipo de atribuição, a última linha assembly da tradução será movl de %eax para o destino. Assim, basta resolver o lado direito das atribuições em funções específicas e colocar o resultado em %eax.

Nas atribuições, é muito usado funções que traduzem o identificador da variável em BPL para o registrador equivalente (caso seja um parâmetro) ou para o offset na pilha (caso seja uma variável local). A tradução começa em expandArg, que identifica o tipo através do primeiro caractér para chamar as funções específicas de expansão (expandV, expandP e expandC).

expandV modifica a string recebida para endereço da pilha (no caso de arrays retorna o início do vetor) usando a variável global varOffsets. expandC só troca "ci" na string parâmetro por "$". E expandP usa o identificador do parâmetro (1,2 ou 3) para retornar o registrador equivalente (%edi, %esi e %edx) e verifica se o parâmetro é array ou não. Pois no caso de array, a função retorna o registrador inteiro ao invés de apenas os 4 últimos bytes.

No processamento da atribuição com expressão (soma, subtração, multiplicação ou divisão) ela traduz a operação passada como parâmetro e no caso da divisão ela verifica se é preciso salvar o %rdx antes de chamar a divisão. Pois como as operações envolvem inteiros, o quociente da divisão fica em %eax e o resto fica em %edx.
Lembrando que os resultados dessa operações são colocador em %eax.

Além disso, a divisão usa "idiv" pois na linguagem só existe um tipo de dado, o signed int. O último tipo de atribuição é o de chamada de função. Quando a processCallAttr é chamada ela recebe como parâmetro o número de parâmetros que a função recebeu. Para cada parâmetro recebido ela move um novo um novo valor para os registradores %rdi, %rsi e %rdx

# Como os acessos aos arrays é tratado?

Tanto no get quanto no set o acesso aos array é feito através do calculo manual do endereço do elemento acessado. Inicia-se calculando o offset em %rax e depois de adiciona o endeço de base do array a %rax. Dessa forma o endereço da índice acessado se encontra em %rax e este é usado para fazer a atribuição, como destino no caso de set ou como origem no caso de get.

# Como o bloco do if é processado?

O bloco do if não é processado de forma especial, ele apenas traduz as linhas de início do if para uma comparação usando cmpl e o traduz o “endif” para uma label. Como não há ifs aninhados na linguagem, não há a necessidade de fazer um controle muito complexo das labels. Aqui criamos uma variável global inteira para armazenar a label e a incrementamos a cada novo if. Vale notar que essa abordagem nos permite traduzir mais de um comando dentro do bloco do if.

# Como os retornos são traduzidos?

As linhas que contém retorno não tem função específica para tratá-las. Na verdade, como só existem retornos inteiros (não são retornados endereços), utilizamos a função processValIntAttr que coloca um determinado argumento em %eax. Essa metodologia é utilizada inclusive na finalização da função já que o BNF nos garante que sempre há um comando de retorno ao final da função.

# Quais são as limitações do programa?

1. Ele não trata erros da linguagem de entrada
2. Não insere return caso o arquivo BPL não possua um (também não insere leave e ret caso não tenha return)
3. Pula a primeira variável declarada caso a função não tenha uma linha "def"
4. Não traduz corretamente caso não encontre "enddef"
5. Não traduz corretamente referências à variáveis não declaradas
6. Gera assembly errado caso seja declarado um vetor com tamanho negativo
7. Gera assembly errado caso sejam declaradas duas funções com o mesmo identificador
8. Não trata arrays excessivamente grandes (acima de 64Ki)
9. Não tenta impedir a atribuição de valores a constantes
10. Não suporta variáveis locais com identificadores negativos
11. Não suporta variáveis locais com identificadores acima de LONG_MAX (9223372036854775807)
12. Gera assembly errado caso tente atribuir valores constantes fora dos limites dos inteiros (INT_MAX e INT_MIN)
13. Não move parâmetros (%edi, %esi e %edx) ou constantes direto para a memória (passa por %eax primeiro)
14. Não impede o usuário de tentar acessar posições inválidas nos arrays
15. Não realiza otimizações como pré-calcular índices ou constantes

# Quais foram os testes realizados?

Para cada possível linha da entrada forma criados teste variando os parâmetros que cada linha recebida. Ou seja, foram testados todas as combinações de parâmetros da função, os limites das variáveis, diferentes combinações de tipos de dados nas atribuições e nas chamadas de funções.

Nos acessos a arrays foram testadas acessos as arrays locais e parametros, assim como diferentes valores para serem atribuidos a eles, como constantes, locais e parametros. Da mesma forma, o if foi testado com diversos comandos diferentes do seu bloco e todos os tipos possíveis de valores para comparação.
