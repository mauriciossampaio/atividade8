typedef struct No {
    char valor;
    struct No* proximo;
} No;
void lista_adicionar_no(No** L, char valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->proximo = *L;
    *L = novo_no;
}
