
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char str[100];
    int i = 0;

    char keywords[][10] = {
        "int", "float", "char", "if", "else",
        "while", "for", "return", "void", "double"
    };

    int n = 10;

    printf("Enter Expression: ");
    fgets(str, sizeof(str), stdin);

    while(str[i] != '\0')
    {
        if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        {
            i++;
            continue;
        }

        if(isalpha(str[i]) || str[i] == '_')
        {
            char identifier[50];
            int j = 0;

            while(isalnum(str[i]) || str[i] == '_')
            {
                identifier[j++] = str[i++];
            }

            identifier[j] = '\0';

            int flag = 0;

            for(int k = 0; k < n; k++)
            {
                if(strcmp(identifier, keywords[k]) == 0)
                {
                    flag = 1;
                    break;
                }
            }

            if(flag)
                printf("%s : Keyword\n", identifier);
            else
                printf("%s : Identifier\n", identifier);
        }
        else if(isdigit(str[i]))
        {
            char number[50];
            int j = 0;

            while(isdigit(str[i]))
            {
                number[j++] = str[i++];
            }

            number[j] = '\0';
            printf("%s : Number\n", number);
        }
        else if (str[i]==',' || str[i]==';')
        {
            printf("%c : Delimeter\n", str[i]);
            i++;
        }
        else
        {
            printf("%c : Operator\n", str[i]);
            i++;
        }
    }

    return 0;
}
