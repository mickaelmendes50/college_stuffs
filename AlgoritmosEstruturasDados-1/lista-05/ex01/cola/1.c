#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define c *C
#define b *C2
#define size (*C)->n
#define sizeb (*C2)->n

typedef struct conj conjunto;

int criaConjunto(conjunto* c);

int conjuntoVazio(conjunto* c);

int insereElementoConjunto(int x, conjunto* c);

int excluirElementoConjunto(int x, conjunto* c);

int tamanhoConjunto(conjunto* c);

int maior(int x, conjunto* c);

int menor(int x, conjunto* c);

int pertenceConjunto(int x, conjunto* c);

int conjuntosIdenticos(conjunto* c, conjunto* b);

int subconjunto(conjunto* c, conjunto* b);

conjunto* complemento(conjunto* c, conjunto* b);

conjunto* uniao(conjunto* c, conjunto* b);

conjunto* interseccao(conjunto* c, conjunto* b);

conjunto* diferenca(conjunto* c, conjunto* b);

conjunto* conjuntoPartes(conjunto* c);

void mostraConjunto(conjunto* c, char ordem[]);

int copiarConjunto(conjunto* c, conjunto* b);

int destroiConjunto(conjunto* c);

//-------------

void bubbleCresc(conjunto* c);

void bubbleDecresc(conjunto* c);

//-------------

struct conj
{
	int v[1000];
	int n;
};

conjunto c[100];
int k = 0;

int criaConjunto(conjunto* c)
{
	c = (conjunto *)malloc(sizeof(conjunto));
	if(c==NULL)
		return 0;
	return 1; 
}

int conjuntoVazio(conjunto* c)
{	

	if(size == 0)
		return 1;
	return 0;
}

int insereElementoConjunto(int x, conjunto* c)
{
	for(int i = 0; i < size; i++)	
		if((c)->v[i] == x)
			return 0;
	(c)->v[size] = x;
	size++;
	return 1;
}

int excluirElementoConjunto(int x, conjunto* c)
{
	for(int i = 0; i < size; i++)
	{	
		if((c)->v[i] == x)
		{
			for(int j = i+1; j < size; j++)
				(c)->v[j-1] = (c)->v[j];
			size--;
			return 1;
		}
	}
	return 0;
}

int tamanhoConjunto(conjunto* c)
{
	return size;
}

int maior(int x, conjunto* c)
{
	int cont = 0;
	for(int i = 0; i < size; i++)
	{
		if((c)->v[i] > x)
			cont++;
	}
	return cont;
}

int menor(int x, conjunto* c)
{
	int cont = 0;
	for(int i = 0; i < size; i++)
	{
		if((c)->v[i] < x)
			cont++;
	}
	return cont;
}

int pertenceConjunto(int x, conjunto* c)
{	
	for(int i = 0; i < size; i++)
		if((c)->v[i] == x)
			return 1;
	return 0;
}

int conjuntosIdenticos(conjunto* c, conjunto* b)
{
	int ok;
	if(size!=sizeb)
		return 0;
	for(int i = 0; i < size; i++)
	{
		ok = 0;
		for(int j = 0; j < size; j++)
		{
			if((b)->v[j] == (c)->v[i])
			{
				ok = 1;
				break;
			}
		}
		if(ok == 0)
			return 0;
	}
	return 1;
}

int subconjunto(conjunto* c, conjunto* b) // verificar se c é subconj de b
{
	int ok;
	if(size > sizeb)
		return 0;
	for(int i = 0; i < size; i++)
	{
		ok = 0;
		for(int j = 0; j < sizeb; j++)
		{
			if((c)->v[i] == (b)->v[j])
			{
				ok = 1;
				break;
			}
		}
		if(!ok)
			return 0;
	}
	return 1;
}

conjunto* complemento(conjunto* c, conjunto* b) //complemento de c em relação a b
{
	int contido;
	conjunto *comp = (conjunto*)malloc(sizeof(conjunto));
	for(int i = 0; i < sizeb; i++)
	{
		contido = 0;
		for(int j = 0; j < size; j++)
		{
			if((c)->v[j] == (b)->v[i])
			{
				contido = 1;
				break;
			}
		}
		if(contido == 0)
			comp->v[comp->n++] = (b)->v[i];
	}
	return comp;
}

conjunto* uniao(conjunto* c, conjunto* b)
{
	int contido;
	conjunto *u = (conjunto*)malloc(sizeof(conjunto));
	for(int i = 0; i < size; i++)
		u->v[u->n++] = (c)->v[i];
	for(int i = 0; i < sizeb; i++)
	{
		contido = 0;
		for(int j = 0; j < u->n; j++)
		{
			if((b)->v[i] == u->v[j])
				contido = 1;
		}
		if(!contido)
			u->v[u->n++] = (b)->v[i];
	}
	return u;
}

conjunto* interseccao(conjunto* c, conjunto* b)
{
	conjunto *inter = (conjunto*)malloc(sizeof(conjunto));
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < sizeb; j++)
		{
			if((c)->v[i] == (b)->v[j])
			{
				inter->v[inter->n++] = (c)->v[i];
				break;
			}
		}
	}
	return inter;
}

conjunto* diferenca(conjunto* c, conjunto* b) //elementos que estao em c mas não em b
{
	int contido;
	conjunto *dif = (conjunto*)malloc(sizeof(conjunto));
	for(int i = 0; i < size; i++)
	{
		contido = 0;
		for(int j = 0; j < sizeb; j++)
		{
			if((c)->v[i] == (b)->v[j])
			{
				contido = 1;
				break;
			}
		}
		if(contido == 0)
			dif->v[dif->n++] = (c)->v[i];
	}
	return dif;	
}

conjunto* conjuntoPartes(conjunto* c)
{
	conjunto *p = (conjunto*)malloc(sizeof(conjunto));
	for(int i = 1; i < (1<<size); i++)
	{
		for(int j = 0; j < size; j++)
		{
			if((1<<j)&i)
				p->v[p->n++] = (c)->v[j];
		}
	}
	return p;
}

void mostraConjunto(conjunto* c, char ordem[])
{
	if(strcmp(ordem, "CRESCENTE") == 0)
	{	
		for(int i = 0; i < size-1; i++)
		{
			for(int j = 0; j < size-i-1; j++)
			{
				if((c)->v[j] > (c)->v[j+1])
				{
					int aux = (c)->v[j];
					(c)->v[j] = (c)->v[j+1];
					(c)->v[j+1] = aux;  
				}
			}
		}
	}
	else if(strcmp(ordem, "DECRESCENTE") == 0)
	{
		for(int i = 0; i < size-1; i++)
		{
			for(int j = 0; j < size-i-1; j++)
			{
				if((c)->v[j] < (c)->v[j+1])
				{
					int aux = (c)->v[j];
					(c)->v[j] = (c)->v[j+1];
					(c)->v[j+1] = aux;  
				}
			}
		}
	}
	for(int i = 0; i < size; i++)
		printf("%d ", (c)->v[i]);
	printf("\n");
}

int copiarConjunto(conjunto* c, conjunto* b)
{
	if(c == NULL || b == NULL)
		return 0;
	sizeb = size;
	for(int i = 0; i < size; i++)
		(b)->v[i] = (c)->v[i];
	return 1;
}

int destroiConjunto(conjunto* c)
{
	if(c != NULL)
	{
		free(c);
		return 1;
	}
	return 0;
}

//-----------------

int perguntaConj()
{
	int x;
	printf("Qual o numero do conjunto para o qual deseja realizar a acao?\n");
	scanf("%d",&x);
	return x;
}

int perguntaConj2(int *x, int *y)
{
	printf("Para quais conjuntos deseja realizar a acao?\n");
	scanf("%d %d",x,y);
}

int getX()
{
	int x;
	printf("Qual o valor de x ?\n");
	scanf("%d",&x);
	return x;
}

//-----------------

int main()
{
	int opt,at,x,y;
	char s[30];
	while(1)
	{
		printf("Escolha uma opcao :\n");
		printf("(1) Criar novo conjunto\n");
		printf("(2) Verificar se um conjunto e vazio\n");
		printf("(3) Incluir elemento em um conjunto\n");
		printf("(4) Excluir elemento de um conjunto\n");
		printf("(5) Tamanho de um conjunto\n");
		printf("(6) Quantidade de elementos maiores que x\n");
		printf("(7) Quantidade de elementos menores que x\n");
		printf("(8) Verificar se x pertence a um conjunto\n");
		printf("(9) Verificar se dois conjuntos sao iguais\n");
		printf("(10) Verificar se x e subconjunto de y\n");
		printf("(11) Gerar o complemento do conjunto x em relacao a y\n");
		printf("(12) Gerar a uniao entre dois conjuntos\n");
		printf("(13) Gerar interseccao entre dois conjuntos\n");
		printf("(14) Gerar o conjunto de diferenca entre x e y\n");
		printf("(15) Gerar conjunto das partes de um conjunto\n");
		printf("(16) Listar elementos de um conjunto\n");
		printf("(17) Copiar conjunto x para y\n");
		printf("(18) Destruir um conjunto\n");
		printf("(0) Finalizar o programa\n");
		scanf("%d",&opt);
		system("@cls||clear");
		switch(opt)
		{
			case 1:
				if(criaConjunto(&C[k++]))
					printf("Conjunto C%d criado\n", k-1);
				else
					printf("Nao foi possivel criar novo conjunto\n");
				break;
			case 2:
				at = perguntaConj();
				if(conjuntoVazio(&C[at]))
					printf("O conjunto esta vazio\n");
				else
					printf("O conjunto nao esta vazio\n");
				break;
			case 3:
				at = perguntaConj();
				printf("Qual elemento deseja incluir?\n");
				scanf("%d",&x);
				if(insereElementoConjunto(x,&C[at]))
					printf("Elemento adicionado\n");
				else
					printf("Erro : elemento ja presente no conjunto\n");
				break;
			case 4:
				at = perguntaConj();
				printf("Qual elemento deseja excluir?\n");
				scanf("%d",&x);
				if(excluirElementoConjunto(x,&C[at]))
					printf("Elemento excluido\n");
				else
					printf("Erro : elemento não presente no conjunto\n");
				break;
			case 5:
				at = perguntaConj();
				x = tamanhoConjunto(&C[at]);
				if(x == 0)
					printf("Conjunto vazio\n");
				else
					printf("O tamanho do conjunto e %d\n",x);
				break;
			case 6:
				at = perguntaConj();
				x = getX();
				y = maior(x,&C[at]);
				printf("Ha %d elementos maiores que %d\n",y,x);
				break;
			case 7:
				at = perguntaConj();
				x = getX();
				y = menor(x,&C[at]);
				printf("Ha %d elementos menores que %d\n",y,x);
				break;
			case 8:
				at = perguntaConj();
				x = getX();
				if(pertenceConjunto(x,&C[at]))
					printf("O elemento pertence ao conjunto\n");
				else
					printf("O elemento nao pertence ao conjunto\n");
				break;
			case 9:
				perguntaConj2(&x,&y);
				if(conjuntosIdenticos(&C[x],&C[y]))
					printf("Os conjuntos sao identicos\n");
				else
					printf("Os conjuntos sao diferentes\n");
				break;
			case 10:
				perguntaConj2(&x,&y);
				if(subconjunto(&C[x],&C[y]))
					printf("O conjunto C%d e subconjunto de C%d\n",x,y);
				else
					printf("O conjunto C%d nao e subconjunto de C%d\n",x,y);
				break;
			case 11:
				perguntaConj2(&x,&y);
				C[k++] = complemento(&C[x],&C[y]);
				if(C[k-1]!=NULL)
					printf("Conjunto complemento C%d criado\n", k-1);
				else
					printf("Erro ao criar o conjunto\n");
				break;
			case 12:
				perguntaConj2(&x,&y);
				C[k++] = uniao(&C[x],&C[y]);
				if(C[k-1]!=NULL)
					printf("Conjunto uniao C%d criado\n", k-1);
				else
					printf("Erro ao criar o conjunto\n");
				break;
			case 13:
				perguntaConj2(&x,&y);
				C[k++] = interseccao(&C[x],&C[y]);
				if(C[k-1]!=NULL)
					printf("Conjunto interseccao C%d criado\n", k-1);
				else
					printf("Erro ao criar o conjunto\n");
				break;
			case 14:
				perguntaConj2(&x,&y);
				C[k++] = diferenca(&C[x],&C[y]);
				if(C[k-1]!=NULL)
					printf("Conjunto de diferenca C%d criado\n", k-1);
				else
					printf("Erro ao criar o conjunto\n");
				break;
			case 15:
				at = perguntaConj();
				C[k++] = conjuntoPartes(&C[at]);
				if(C[k-1]!=NULL)
					printf("Conjunto das partes C%d criado\n",k-1);
				else
					printf("Erro ao criar o conjunto\n");
				break;
			case 16:
				at = perguntaConj();
				printf("Em qual ordem deseja listar os elementos? Escolha entre CRESCENTE e DECRESCENTE\n");
				getchar();
				scanf("%s",s);
				mostraConjunto(&C[at],s);
				break;
			case 17:
				perguntaConj2(&x,&y);
				if(copiarConjunto(&C[x],&C[y]))
					printf("Conjunto C%d copiado para C%d\n", x,y);
				else
					printf("Nao foi possivel copiar o conjunto\n");
				break;
			case 18:
				at = perguntaConj();
				if(destroiConjunto(&C[at]))
					printf("Conjunto C%d destruido\n",at);
				else
					printf("Erro ao destruir conjunto\n");
				break;
			default:
				for(int i = 0; i < k; i++)
					if(C[i] != NULL)
						free(C[i]);
				return 0;
		}
	}
	return 0;
}