#include <stdio.h>

int main()
{
    char esteira[32][32];
    int i, j;
    for (int a = 0; a < 32; a++)
    {
        for (int b = 0; b < 32; b++)
        {
            esteira[a][b] = getchar();
            getchar();
            if (esteira[a][b] == '[')
            {
                i = a;
                j = b + 1;
            }
        }
        scanf("%*[^\r\n]s");
        scanf("%*[\r\n]s");
    }

    
    while(esteira[i][j] != ']')
    {
        if (esteira[i][j] == '>')
        {
            esteira[i][j] = '.';
            if (esteira[i][j+1] == '#')
            {
                j++;
            }
            j++;
            if (esteira[i][j] == '#')
            {
                j++;
            }
        }
        else if (esteira[i][j] == 'v')
        {
            esteira[i][j] = '.';
            if (esteira[i+1][j] == '#')
            {
                i++;
            }
            i++;
            if (esteira[i][j] == '#')
            {
                i++;
            }
        }
        else if (esteira[i][j] == '<')
        {
            esteira[i][j] = '.';
            if (esteira[i][j-1] == '#')
            {
                j--;
            }
            j--;
            if (esteira[i][j] == '#')
            {
                j--;
            }
        }
        else if (esteira[i][j] == '^')
        {
            esteira[i][j] = '.';
            if (esteira[i-1][j] == '#')
            {
                i--;
            }
            i--;  
            if (esteira[i][j] == '#')
            {
                i--;
            } 
        }
        else if (esteira[i][j] == '.')
        {
            printf("Loop infinito.\n");
            break;
        }
        else if (esteira[i][j] == ' ')
        {
            printf("Falha na esteira.\n");
            break;
        }              
        else
        {
            printf("Falha na esteira.\n");
            break;
        }
    }
    if (esteira[i][j] == ']')
    {
        printf("Ok.\n");
    }

    
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            printf("%c ", esteira[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}