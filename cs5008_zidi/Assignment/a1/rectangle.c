#include <stdio.h>
/*
 * This function prints an empty rectangle of the specified width and height. 
 *
 */
void PrintRectangle(int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        if (i == 0 || i == height - 1)
        {
            for (int j = 0; j < width; j++)
            {
                printf("-");
            }
            printf("\n");
        }
        else
        {
            for (int j = 0; j < width; j++)
            {
                if (j == 0 || j == width - 1)
                {
                    printf("-");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
}

int main()
{
    PrintRectangle(10, 5);
    return 0;
}
