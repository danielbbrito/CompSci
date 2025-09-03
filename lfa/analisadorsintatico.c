#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

int pos;
char* string;

// Prototipação das funções
bool Expr();
bool Termo();
bool Fator();
char pos_atual();
bool match(char esperado);

// Função que retorna o caractere atual
char pos_atual() {
    return string[pos];
}

// Verifica se o caractere atual é o esperado e avança
bool match(char esperado) {
    if (pos_atual() == esperado) {
        pos++;
        return true;
    }
    return false;
}

// Fator → (Expr) | num
bool Fator() {
    if (match('(')) {
        if (!Expr())
            return false;
        return match(')');
    } else if (isdigit(pos_atual())) {
        while (isdigit(pos_atual()))
            pos++;
        return true;
    }
    return false;
}

// Termo → Fator {* Fator}
bool Termo() {
    if (!Fator())
        return false;

    while (match('*')) {
        if (!Fator()) return false;
    }

    return true;
}

// Expr → Termo {+ Termo}
bool Expr() {
    if (!Termo())
        return false;

    while (match('+')) {
        if (!Termo()) return false;
    }

    return true;
}

// Função principal de análise
bool analisar(char* str) {
    string = str;
    pos = 0;

    if (Expr()) {
        if (pos_atual() == '\0') return true;
    }
    return false;
}

int main() {
    char expressao[100]; // Agora está alocado corretamente

    printf("Forneça a expressao: ");
    scanf("%s", expressao);

    if (analisar(expressao)) {
        printf("Expressao valida\n");
    } else {
        printf("Expressao invalida\n");
    }

    return 0;
}
