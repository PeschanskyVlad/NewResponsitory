#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>
#include <limits.h>

#include "text.h"
#include "list.h"

int main()
{
    text_t text = textFromFile("input.txt");

    textFilter(text, 3);

    FILE * output = fopen("output.txt", "w");

    for(int i = 0; i < textGetCount(text); i++){
        sentence_t sent = textGetSentence(text, i);
        for(int j = 0; j < sentenceGetCount(sent); j++){
           fprintf(output,"%s\n",wordConvert(sentenceGetWord(sent, j)));
        }
    }

    textDelete(text);
    fclose(output);
    return 0;
}
