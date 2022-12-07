#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int get_index(int letters, int words, int sentences);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    int index = get_index(letters, words, sentences);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index > 1 && index < 16)
    {
        printf("Grade %i\n", index);
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
}

int count_letters(string text)
{
    int l = 0; //number of letters;
    int i = 0;

    while (text[i] != '\0') //while it's not end of a string
    {
        if (isalpha(text[i]))
        {
            l++; //Add 1 letter
        }

        i++;
    }

    return l;
}

int count_words(string text)
{
    int w = 0; //number of words
    int i = 0;

    while (text[i] != '\0') //while it's not end of a string
    {
        if (isspace(text[i]))
        {
            w++; //Add 1 word
        }
        i++;
    }

    return w + 1;
}

int count_sentences(string text)
{
    int s = 0; //number of sentences
    int i = 0;

    while (text[i] != '\0') //while it's not end of a string
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            s++; //sentences
        }
        i++;
    }

    return s;
}

int get_index(int letters, int words, int sentences)
{
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    index = round(index);

    return index;
}

