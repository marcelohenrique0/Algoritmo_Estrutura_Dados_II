#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Definição da estrutura de informações
struct Info {
    char nome[100];
    int mat;
    int turma;
    float nota;
};

// Definição da estrutura do nó da árvore
struct Node {
    struct Info info;
    struct Node *esq;
    struct Node *dir;
};

// Funções para manipulação da estrutura
struct Info criarInfo(char *nome, int mat, int turma, float nota);
struct Node* criarNode(struct Info info);
int comparar(struct Info a, struct Info b);
struct Node* inserir(struct Node *raiz, struct Info info);
void preOrdem(struct Node *raiz);
void inOrdem(struct Node *raiz);
void posOrdem(struct Node *raiz);
int calcularProfundidade(struct Node *raiz, char *nome, int profundidade);
struct Node* buscar(struct Node *raiz, char *nome);
struct Node* buscarPai(struct Node *raiz, struct Node *no, struct Node *pai);
void imprimirInfo(struct Info info);

// Função principal
int main() {
    srand(time(0)); // Inicializa a semente para números aleatórios

    // Dados dos colegas
    struct Info colegas[] = {
        criarInfo("ALEX BRUNO DUARTE", 1, 1, rand() % 11),
        criarInfo("AMANDA DE QUEIROZ SANTIAGO", 2, 1, rand() % 11),
        criarInfo("ANAILTON ARTUR FERNANDES", 3, 1, rand() % 11),
        criarInfo("ANTHONY MATHEUS NASCIMENTO FREITAS", 4, 1, rand() % 11),
        criarInfo("DIEGO NASCIMENTO DE OLIVEIRA", 5, 1, rand() % 11),
        criarInfo("FABRICIO ANDREY LEANDRO DAMIAO", 6, 1, rand() % 11),
        criarInfo("FERNANDO UMBILINO ALVES", 7, 1, rand() % 11),
        criarInfo("FRANCISCO RYAM FEITOSA DINIZ", 8, 1, rand() % 11),
        criarInfo("GUILHERME DE FRANCA VASCONCELOS", 9, 1, rand() % 11),
        criarInfo("HARLEY LUCAS DE SOUZA BATISTA", 10, 1, rand() % 11),
        criarInfo("JOSE FERREIRA SOUSA NETO", 11, 1, rand() % 11),
        criarInfo("JOSE VERISSIMO DE OLIVEIRA QUEIROZ", 12, 1, rand() % 11),
        criarInfo("LUIS IZAÍAS VALENTIM DE AQUINO", 13, 1, rand() % 11),
        criarInfo("MEL CAMILY MONTENEGRO CARDOSO", 14, 1, rand() % 11),
        criarInfo("PABLO GERALDO LINHARES DO NASCIMENTO LEITE", 15, 1, rand() % 11),
        criarInfo("STHEFFANY DA CÂMARA GUILHERMINO", 16, 1, rand() % 11),
        criarInfo("THALLYS ARAUJO DE MORAIS", 17, 1, rand() % 11),
        criarInfo("TÚLIO GOMES DE ARAÚJO FEITOSA", 18, 1, rand() % 11),
        criarInfo("VICENTE BENTO DA SILVA NETO", 19, 1, rand() % 11),
        criarInfo("ANTONIO ERICK DA SILVEIRA FARIAS OLIVEIRA", 1, 2, rand() % 11),
        criarInfo("ANTONIO NOGUEIRA DA SILVA NETO", 2, 2, rand() % 11),
        criarInfo("DANIEL NERES VIEIRA", 3, 2, rand() % 11),
        criarInfo("EDUARDO PEREIRA ABRANTES", 4, 2, rand() % 11),
        criarInfo("EVERSON ALISSON QUEIROZ SILVA", 5, 2, rand() % 11),
        criarInfo("GUSTAVO KESLEY DE FONTES NUNES", 6, 2, rand() % 11),
        criarInfo("JEAN RICHARDSON GONCALVES MARCOS", 7, 2, rand() % 11),
        criarInfo("JOAO GUSTAVO SOUZA LIMA", 8, 2, rand() % 11),
        criarInfo("JOSE MATHEUS GOMES SILVA", 9, 2, rand() % 11),
        criarInfo("LEANDRO CARLOS MARTINS DE CARVALHO", 10, 2, rand() % 11),
        criarInfo("NATTAN FERREIRA LOPES", 11, 2, rand() % 11),
        criarInfo("PEDRO LUCAS DE SOUSA FERREIRA", 12, 2, rand() % 11),
        criarInfo("RUBENS ALEXANDRE DE SOUSA FERREIRA", 13, 2, rand() % 11),
        criarInfo("SAMUEL DE ALMEIDA SATURNO", 14, 2, rand() % 11),
        criarInfo("WESLLEY EMANOEL SILVA SOARES", 15, 2, rand() % 11),
        criarInfo("ALLAN GABRIEL SILVA DE FREITAS", 1, 3, rand() % 11),
        criarInfo("ALLYSON DA SILVA FELIX", 2, 3, rand() % 11),
        criarInfo("ANA BEATRIZ ALMEIDA DA SILVA", 3, 3, rand() % 11),
        criarInfo("ANTONIO JOAQUIM DE LIRA NETO", 4, 3, rand() % 11),
        criarInfo("ANTONIO VINICIUS OLIVEIRA LIMA", 5, 3, rand() % 11),
        criarInfo("ARTUR CARVALHO GAMA", 6, 3, rand() % 11),
        criarInfo("CARLOS HENRIQUE DUARTE ABRANTES", 7, 3, rand() % 11),
        criarInfo("DINARTE RODRIGUES DE OLIVEIRA FILHO", 8, 3, rand() % 11),
        criarInfo("ERIK THADEU SALES PRAXEDES", 9, 3, rand() % 11),
        criarInfo("EVELYN CRISTINA DE OLIVEIRA GOMES", 10, 3, rand() % 11),
        criarInfo("FABIO QUEIROZ VIEIRA", 11, 3, rand() % 11),
        criarInfo("FRANCIER EDUARDO DA SILVA LUZ", 12, 3, rand() % 11),
        criarInfo("FRANCISCO ADRIAN VINICIUS CHAVES SAMPAIO", 13, 3, rand() % 11),
        criarInfo("FRANCISCO LAILSON DE ALMEIDA", 14, 3, rand() % 11),
        criarInfo("GUSTAVO RODRIGUES DOS REIS", 15, 3, rand() % 11),
        criarInfo("HILLARY DINIZ SALDANHA", 16, 3, rand() % 11),
        criarInfo("JOSE KAYQUE LIMA LOPES", 17, 3, rand() % 11),
        criarInfo("JUANNY THAYSSA GUEDES DE FREITAS", 18, 3, rand() % 11),
        criarInfo("KAUE VALENTIM DE CARVALHO", 19, 3, rand() % 11),
        criarInfo("LEONARDO AUGUSTO SILVA DE SOUSA", 20, 3, rand() % 11),
        criarInfo("LETICIA MARIA GONCALVES DE MORAIS", 21, 3, rand() % 11),
        criarInfo("LETICIA VIEIRA GONCALVES", 22, 3, rand() % 11),
        criarInfo("LEVITICO RIMON PEREZ ANDRADE ALVES", 23, 3, rand() % 11),
        criarInfo("LUIZ EDUARDO DE ALMEIDA RODRIGUES", 24, 3, rand() % 11),
        criarInfo("MARCELO AUGUSTO DA SILVA FERNANDES", 25, 3, rand() % 11),
        criarInfo("MARCELO HENRIQUE MESSIAS CAVALCANTE", 26, 3, rand() % 11),
        criarInfo("MARIA CLARA SARAIVA LEAL", 27, 3, rand() % 11),
        criarInfo("MARIA EDUARDA DA SILVA SOUZA", 28, 3, rand() % 11),
        criarInfo("MARIA EDUARDA RODRIGUES BEZERRA", 29, 3, rand() % 11),
        criarInfo("MARIA ISABELLY LIMA DE SOUSA", 30, 3, rand() % 11),
        criarInfo("PEDRO HENRIQUE ANDRADE DA CONCEICAO", 31, 3, rand() % 11),
        criarInfo("SAMUEL IAGO DE FARIAS CABRAL", 32, 3, rand() % 11),
        criarInfo("SHAMYRA DE FATIMA SARAIVA CARVALHO", 33, 3, rand() % 11),
        criarInfo("THYAGO FABRICIO MELO COSTA", 34, 3, rand() % 11),
        criarInfo("TOBIAS FERNANDES FIGUEIREDO", 35, 3, rand() % 11)
    };

    // Criação da árvore binária
    struct Node* raiz = NULL;
    int n = sizeof(colegas) / sizeof(colegas[0]);
    for (int i = 0; i < n; i++) {
        raiz = inserir(raiz, colegas[i]);
    }

    // Realizando as listagens
    printf("Pre-Ordem:\n");
    preOrdem(raiz);
    printf("\nIn-Ordem:\n");
    inOrdem(raiz);
    printf("\nPos-Ordem:\n");
    posOrdem(raiz);

    // Nome a ser buscado (substitua pelo seu nome)
    char meuNome[] = "MARCELO HENRIQUE MESSIAS CAVALCANTE";

    // Calculando profundidade do nó que contém o meu nome
    int profundidade = calcularProfundidade(raiz, meuNome, 0);
    printf("\nProfundidade do nó com meu nome: %d\n", profundidade);

    // Buscando o nó que contém o meu nome
    struct Node* meuNo = buscar(raiz, meuNome);

    // Buscando o nó pai
    struct Node* pai = buscarPai(raiz, meuNo, NULL);
    if (pai != NULL) {
        printf("Pai do nó com meu nome:\n");
        imprimirInfo(pai->info);
    } else {
        printf("Nó com meu nome não tem pai (é a raiz).\n");
    }

    // Imprimindo informações dos nós filhos
    if (meuNo->esq != NULL) {
        printf("Filho esquerdo do nó com meu nome:\n");
        imprimirInfo(meuNo->esq->info);
    } else {
        printf("Nó com meu nome não tem filho esquerdo.\n");
    }

    if (meuNo->dir != NULL) {
        printf("Filho direito do nó com meu nome:\n");
        imprimirInfo(meuNo->dir->info);
    } else {
        printf("Nó com meu nome não tem filho direito.\n");
    }

    return 0;
}

// Funções auxiliares
struct Info criarInfo(char *nome, int mat, int turma, float nota) {
    struct Info res;
    strcpy(res.nome, nome);
    res.mat = mat;
    res.turma = turma;
    res.nota = nota;
    return res;
}

struct Node* criarNode(struct Info info) {
    struct Node* res = (struct Node*)malloc(sizeof(struct Node));
    res->info = info;
    res->esq = NULL;
    res->dir = NULL;
    return res;
}

int comparar(struct Info a, struct Info b) {
    return strcmp(a.nome, b.nome);
}

struct Node* inserir(struct Node *raiz, struct Info info) {
    if (raiz == NULL) {
        return criarNode(info);
    }
    int cmp = comparar(raiz->info, info);
    if (cmp < 0) {
        raiz->dir = inserir(raiz->dir, info);
    } else if (cmp > 0) {
        raiz->esq = inserir(raiz->esq, info);
    }
    return raiz;
}

void preOrdem(struct Node *raiz) {
    if (raiz != NULL) {
        imprimirInfo(raiz->info);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void inOrdem(struct Node *raiz) {
    if (raiz != NULL) {
        inOrdem(raiz->esq);
        imprimirInfo(raiz->info);
        inOrdem(raiz->dir);
    }
}

void posOrdem(struct Node *raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        imprimirInfo(raiz->info);
    }
}

int calcularProfundidade(struct Node *raiz, char *nome, int profundidade) {
    if (raiz == NULL) {
        return -1;
    }
    if (strcmp(raiz->info.nome, nome) == 0) {
        return profundidade;
    }
    int esq = calcularProfundidade(raiz->esq, nome, profundidade + 1);
    if (esq != -1) {
        return esq;
    }
    return calcularProfundidade(raiz->dir, nome, profundidade + 1);
}

struct Node* buscar(struct Node *raiz, char *nome) {
    if (raiz == NULL || strcmp(raiz->info.nome, nome) == 0) {
        return raiz;
    }
    if (comparar(raiz->info, criarInfo(nome, 0, 0, 0)) < 0) {
        return buscar(raiz->dir, nome);
    }
    return buscar(raiz->esq, nome);
}

struct Node* buscarPai(struct Node *raiz, struct Node *no, struct Node *pai) {
    if (raiz == NULL) {
        return NULL;
    }
    if (raiz == no) {
        return pai;
    }
    struct Node *esq = buscarPai(raiz->esq, no, raiz);
    if (esq != NULL) {
        return esq;
    }
    return buscarPai(raiz->dir, no, raiz);
}

void imprimirInfo(struct Info info) {
    printf("Nome: %s\n", info.nome);
    printf("Mat: %d\n", info.mat);
    printf("Turma: %d\n", info.turma);
    printf("Nota: %.2f\n", info.nota);
}
