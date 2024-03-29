#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int Repeat(string a);
int abc(string a);
void encoder(string a, string maiusculo);
string minus(string a);
char minus1(char a);
char maximus(char a);

// Árvore de decisão
int main(int argc, string argv[])
{
    if ((argc == 2) && (strlen(argv[1]) == 26))
    {
        int a = Repeat(argv[1]);
        if (a == 26)
        {
            a = abc(argv[1]);
            if (a == 0)
            {
                string final;
                string text = get_string("plaintext: ");
                printf("ciphertext: ");
                encoder(text, argv[1]);
                return 0;
            }
            else
            {
                printf("Error\n");
                return 1;
            }
        }
        else
        {
            printf("Error\n");
            return 1;
        }
    }
    else
    {
        printf("Error\n");
        return 1;
    }
}

// Verifica se uma das letras da chave se repete
int Repeat(string a)
{
    int c = 0;
    a = minus(a);
    for (int i = 0; i < 26; i++)
    {
        for (int o = 0; o < 26; o++)
        {
            if ((int) a[i] == (int) a[o])
            {
                c++;
            }
        }
    }
    return c;
}

// Verifica se tem número ou pontuação
int abc(string a)
{
    int c = 0;
    for (int i = 0; i < 26; i++)
    {
        if (isdigit(a[i]) || ispunct(a[i]))
        {
            c++;
        }
    }
    return c;
}

// Faz a criptografia do codigo
void encoder(string a, string maiusculo)
{
    int n = strlen(a);
    string ABC = ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    string abc = ("abcdefghijklmnopqrstuvwxyz");
    int contador = -1;
    char b, c, d;

    for (int i = 0; i < n; i++)
    {
        if (islower(a[i]))
        {
            b = a[i];
            d = abc[0];
            for (contador = 0; contador < 26; contador++)
            {
                d = abc[contador];
                if (b == d)
                {
                    break;
                }
            }
            b = maiusculo[contador];
            c = minus1(b);
            printf("%c", c);
        }
        if (isupper(a[i]))
        {
            b = a[i];
            d = ABC[0];
            for (contador = 0; contador < 26; contador++)
            {
                d = ABC[contador];
                if (b == d)
                {
                    break;
                }
            }
            b = maiusculo[contador];
            c = maximus(b);
            printf("%c", c);
        }
        if (ispunct(a[i]) || isspace(a[i]) || isdigit(a[i]) || a[i] == 39)
        {
            printf("%c", a[i]);
        }
    }
    printf("\n");
}

// Transforma em minusculo (STRING)
string minus(string a)
{
    for (int i = 0, n = strlen(a); i < n; i++)
    {
        if (isupper(a[i]))
        {
            a[i] = tolower(a[i]);
        }
    }
    return a;
}

// Transforma em maiusculo (CHAR)
char maximus(char a)
{
    if (islower(a))
    {
        a = toupper(a);
    }
    return a;
}

// Transforma em minusculo (CHAR)
char minus1(char a)
{
    if (isupper(a))
    {
        a = tolower(a);
    }
    return a;
}
