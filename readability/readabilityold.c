#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

float count_letters(string text);
float count_words(string text);
float count_sentences(string text);

int main(void)
{
    string input = get_string("Text: ");
    float output_letters = count_letters(input);
    float output_words = count_words(input);
    float output_sentences = count_sentences(input);

    float avr_letters = output_letters / output_words * 100;
    float avr_sentences = output_sentences / output_words * 100;
    float grade = (0.0588 * avr_letters) - (0.296 * avr_sentences) - 15.8;
    int rgrade = round(grade);



    if (rgrade > 16)
    {
        printf("Grade 16+\n");
    }
    else if (rgrade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n",rgrade);
    }


}

float count_letters(string text)
{
    int dontcount[] = {33, 45, 39, 46, 34, 44, 63, 59, 58, 32};
    int count = 0;
    for (int letters = 0, inputlet = strlen(text); letters < inputlet; letters++)
    {
            count += 1;
            for (int check = 0; check < inputlet; check++)
            {
                if (text[letters] == dontcount[check])
                {
                    count -= 1;
                }
            }

    }
    return count;
}

float count_words(string text)
{
    int count = 1;
    for (int letters = 0, inputlet = strlen(text); letters < inputlet; letters++)
    {
        if (text[letters] == 32)
        {
            count += 1;
        }
    }
    return count;
}

float count_sentences(string text)
{
    int count = 0;
    for (int letters = 0, inputlet = strlen(text); letters < inputlet; letters++)
    {
        if (text[letters] == 33 || text[letters] == 46 || text[letters] == 63)
        {
            count += 1;
        }
    }
    return count;
}