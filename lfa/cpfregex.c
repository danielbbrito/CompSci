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
        printf("CPF valido\n");
        regfree(&regex);
        return 0;
    }
    else if (resultado == REG_NOMATCH)
    {
        printf("CPF invalido\n");
        regfree(&regex);
        return 1;
    }
    else
    {
        printf("Ocurreu um erro\n");
        regfree(&regex);
        return 1;
    }

    return 1;
}
int main()
{
    char *padrao = "^[0-9]{3}\\.[0-9]{3}\\.[0-9]{3}-[0-9]{2}$";
    char* teste = "123.456.789-09";
    return validar(padrao, teste);
}