// Crie uma função que receba dois argumentos e retorne a soma dos mesmos.
function soma(x, y) {
    return x + y;
}

// Declare uma variável que receba a invocação da função criada acima, passando dois números quaisquer por argumento, e somando `5` ao resultado retornado da função.
var soma = soma(5, 10) + 5;

// Qual o valor atualizado dessa variável?
soma === 20;

// Declare uma nova variável, sem valor.
var valor;

/*
Crie uma função que adicione um valor à variável criada acima, e retorne a string:
    O valor da variável agora é VALOR.
Onde VALOR é o novo valor da variável.
*/
function valor(valor) {
    valor = 15;
    return "O valor da variável é " + valor;
}

// Invoque a função criada acima.
valor(valor);

// Qual o retorno da função? (Use comentários de bloco).
/*
 * O valor da variável agora é 15.
 */

/*
Crie uma função com as seguintes características:
1. A função deve receber 3 argumentos;
2. Se qualquer um dos três argumentos não estiverem preenchidos, a função deve retornar a string:
    Preencha todos os valores corretamente!
3. O retorno da função deve ser a multiplicação dos 3 argumentos, somando `2` ao resultado da multiplicação.
*/
function newFunction(x, y, z) {
    if (x == null || y == null || z == null) {
        return "Preencha todos os campos corretamente";
    } else {
        return (x * y * z) + 2;
    }
}

// Invoque a função criada acima, passando só dois números como argumento.
newFunction(15, 4);

// Qual o resultado da invocação acima? (Use comentários para mostrar o valor retornado).
// 1. Preencha todos os campos corretamente

// Agora invoque novamente a função criada acima, mas passando todos os três argumentos necessários.
newFunction(1, 2, 3);

// Qual o resultado da invocação acima? (Use comentários para mostrar o valor retornado).
// 8

/*
Crie uma função com as seguintes características:
1. A função deve receber 3 argumentos.
2. Se somente um argumento for passado, retorne o valor do argumento.
3. Se dois argumentos forem passados, retorne a soma dos dois argumentos.
4. Se todos os argumentos forem passados, retorne a soma do primeiro com o segundo, e o resultado, dividido pelo terceiro.
5. Se nenhum argumento for passado, retorne o valor booleano `false`.
6. E ainda, se nenhuma das condições acima forem atendidas, retorne `null`.
*/
function math(x, y , z) {
    if (x == undefined) {
        return false;
    }
    if (y == undefined) {
        return x;
    }
    if (z == undefined) {
        return x + y;
    }
    if (z != undefined) {
        return (x + y)/z;
    }
    return null;
}

// Invoque a função acima utilizando todas as possibilidades (com nenhum argumento, com um, com dois e com três.) Coloque um comentário de linha ao lado da função com o resultado de cada invocação.
math(); // false || null
math(1); // 1
math(2, 1); // 3
math(3, 2, 1); // 5