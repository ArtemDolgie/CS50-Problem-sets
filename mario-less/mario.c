#include <cs50.h>
#include <stdio.h>

void PyramidBulder(int height);

int main(void)
{
    int height;

    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    PyramidBulder(height);
}

void PyramidBulder(int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int space = height - i; space > 1; space--)
        {
            printf(" ");
        }

        for (int dash = 0; dash <= i; dash++)
        {
            printf("#");
        }
        printf("\n");
    }
}

