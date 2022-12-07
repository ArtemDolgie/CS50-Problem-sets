#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool key_check(string key);
bool repeated_letters(string key);
string cipher(string text, string key);

int main(int argc, string argv[])
{

    string key = argv[1];

    // Counting Command-Line Arguments
    if (argc < 2 || argc > 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Check key length 26 and alpabetic charactrs only
    if (key_check(key) == false)
    {
        printf("Key must contain 26 characters. \n");
        return 1;
    }

    // Check for repeated letters
    if (repeated_letters(key) == false)
    {
        printf("Usage: ./substitution key \n");
        return 1;
    }

    // Get plain text
    string text = get_string("plaintext: ");

    // Get cipher text
    string ciphertext = cipher(text, key);
    printf("ciphertext: %s\n", ciphertext);
}

bool key_check(string key)
{
    int length = strlen(key);

    // Cheking each letter for alpha
    for (int i = 0; i < length; i++)
    {
        if (isalpha(key[i]) == false)
        {
            return false;
        }
    }

    // Checking key length
    if (length != 26)
    {
        return false;
    }

    return true;
}

// Cheking repeated letters
bool repeated_letters(string key)
{
    int length = strlen(key);
    int letters[26] = {0};

    for (int i = 0; i < length; i++)
    {
        letters[i] = toupper(key[i]);
    }

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (letters[i] == letters[j])
            {
                return false;
            }
        }
    }

    return true;
}

// Cipher for text with key
string cipher(string text, string key)
{
    int text_length = strlen(text);
    int key_length = strlen(key);
    string ciphertext = text;

    for (int i = 0; i < key_length; i++)
    {
        if (islower(key[i]))
        {
            key[i] = key[i] - 32; // a(97) -> A(65)
        }
    }

    for (int i = 0; i < text_length; i++)
    {
        if (isupper(text[i]))
        {
            int letter = text[i] - 65; // A(65) - 65 = 0
            ciphertext[i] = key[letter]; // Letter in the key(0 = first letter in the key)
        }
        else if (islower(text[i]))
        {
            int letter = text[i] - 97; //a(97) - 97 = 0
            ciphertext[i] = key[letter] + 32; // Letter in the key + 32
        }
        else
        {
            ciphertext[i] = text[i];
        }
    }

    return ciphertext;
}


