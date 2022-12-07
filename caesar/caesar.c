#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool only_digits(string key);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Counting Command-Line Arguments
    if (argc < 2 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Checking the Key
    bool is_digit = only_digits(argv[1]);
    if (is_digit == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Converts argv[1] to an int
    int key = atoi(argv[1]);

    // Get plain text
    string text = get_string("plaintext: ");

    // Enchiper text
    printf("ciphertext: ");
    for (int i = 0; i < strlen(text); i++)
    {

        printf("%c", rotate(text[i], key));
    }
    printf("\n");
}

bool only_digits(string key)
{

    for (int i = 0; i < strlen(key); i++)
    {
        if (isdigit(key[i]) == false)
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int i)
{
    if (isupper(c))
    {
        c = c - 65;

        char letter = (c + i) % 26;
        letter = letter + 65;
        return letter;
    }
    else if (islower(c))
    {
        c = c - 97;

        char letter = (c + i) % 26;
        letter = letter + 97;
        return letter;
    }

    return c;


}