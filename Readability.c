#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    // Declares variables for the number of letters, words, and sentences in the text.
    float letters = 0.0;
    float words = 0.0;
    float sentences = 0.0;
    string text = get_string("Please enter text: ");
    int textlen = strlen(text);
    // Iterate over text and count the number of letters, words, and sentences and store them in the variables declared above.
    for (int i = 0; i < textlen ; i++)
    {
        if (isalpha(text[i]))
        {
            letters ++;
        }

        if (isspace(text[i]))
        {
            words ++;
        }

        if (text[i] == '?' || text[i] == '.' || text[i] == '!')
        {
            sentences ++;
        }

    }

    words = words + 1;
    // Find the average number of letters per 100 words of text.
    float L = (letters / words) * 100.0;
    // Find the average number of sentences per 100 words of text.
    float S = (sentences / words) * 100.0;
    // Plug in L and S into the Coleman-Liau index to find the reading level of the text.
    float index = 0.0588 * L - 0.296 * S - 15.8;
    // Round the reading level to the nearest integer.
    int grade = round(index);
    // prints reading level. If the grade is above 16, prints "Grade 16+" or if the grade is less than 1 then prints "Before grade 1"
    if (grade > 16)
    {
        printf("Grade 16+\n");
    }

    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }

}
