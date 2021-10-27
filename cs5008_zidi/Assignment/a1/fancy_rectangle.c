#include <stdio.h>
/*
 * This function prints an empty rectangle of the specified width and height. 
 *
 */
void PrintRectangle(int width, int height, char c, int fill)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0 || j == width - 1 || i == 0 || i == height - 1 || fill == 1)
            {
                printf("%c", c);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main()
{
    PrintRectangle(4, 6, '+', 0);
    printf("\n");
    PrintRectangle(4, 6, '+', 1);
    printf("\n");
    PrintRectangle(4, 6, '*', 0);
    printf("\n");
    PrintRectangle(4, 6, '*', 1);
    return 0;
}
