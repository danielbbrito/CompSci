#include <stdio.h>
#include <string.h>
#include <regex.h>

int validar(char* padrao, char* teste)
{
    regex_t regex;
    int resultado = regcomp(&regex, padrao, REG_EXTENDED);

    if (resultado)
    {
        printf("Nao compilou :(\n");
        return 1;
    }


    resultado = regexec(&regex, teste, 0, NULL, 0);

    if (!resultado)
    {
        regfree(&regex);
        return 0;
    }
    else if (resultado == REG_NOMATCH)
    {
        regfree(&regex);
        return 1;
    }
    else
    {
        regfree(&regex);
        return 1;
    }

    regfree(&regex);
    return 1;
}
int main()
{
    char *padrao = "[A-Z]";
    char* teste = "Linguagens1";
    if (validar(padrao, teste))
    {
        printf("Senha invalida\n");
        return 0;
    }

    padrao = "[a-z]";
    if (validar(padrao, teste))
    {
        printf("Senha invalida\n");
        return 0;
    }

    padrao = "[0-9]";
    if (validar(padrao, teste))
    {
        printf("Senha invalida\n");
        return 0;
    }

    printf("Senha valida\n");
    return 0;
}