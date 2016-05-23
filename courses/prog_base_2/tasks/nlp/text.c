#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>
#include <limits.h>
#include "text.h"

#include "list.h"



struct word_s{
    char word[wordLength];
};

struct sentence_s{
    List_t words;
};

struct text_s{
    List_t sentences;
    long int wordsNum;
};

text_t textNew(){
    text_t self = (text_t)malloc(sizeof(struct text_s));
    self->sentences = List_new();
    self->wordsNum = 0;
    return self;
}

void textDelete(text_t self){
    List_deepDelete(self->sentences, sentenceDelete);
    free(self);
}

void textAddSentence(text_t self, unsigned int index, sentence_t sentence){
    List_add(self->sentences, index, sentence);
    self->wordsNum += List_getSize(self->sentences);
}

sentence_t textGetSentence(text_t self, unsigned int index){
    return List_get(self->sentences, index, NULL);
}

sentence_t textDeleteSentence(text_t self, unsigned int index){
    self->wordsNum -= List_getSize(self->sentences);
    return List_remove(self->sentences, index, NULL);
}

text_t textFromFile(const char * file){

    FILE * input = fopen(file, "r");

    char * strText = (char *) malloc(LONG_MAX/10);
    for(int i = 0; !feof(input); i++){
        strText[i] = getc(input);
    }

    text_t self = (text_t)malloc(sizeof(struct text_s));
    self->sentences = List_new();
    self->wordsNum = 0;

    char * buff = (char *) malloc(LONG_MAX/10);
    strcpy(buff, strText);
    char * toks[maxLength];

    int toksNum = 0;
    for(char * tok = strtok(buff, "?!."); tok != NULL; tok = strtok(NULL, "?!.")){
        toks[toksNum] = tok;
        toksNum++;
    }

    for(int i = 0; i < toksNum; i++){
        sentence_t sent = sentenceNew();
        Sentence_parse(sent, toks[i]);
        List_add(self->sentences, i, sent);
    }

    free(buff);
    free(strText);
    fclose(input);
    return self;
}


int textGetCount(text_t self){
    return List_getSize(self->sentences);
}

void textSort(text_t self){
    word_t words[maxLength];
    int k = 0;
    int sentsNum = List_getSize(self->sentences);


    for(int i = 0; i < sentsNum; i++){
        sentence_t sent = textGetSentence(self, i);
        int wordsNum = sentenceGetCount(sent);
        for(int j = 0; j < wordsNum; j++){
            words[k] = sentenceGetWord(sent, j);
            k++;
        }
    }

    int qsortFun(const void * * a, const void * * b){
        return strlen(wordConvert(*a)) - strlen(wordConvert(*b));
    }

    qsort(words, k, sizeof(char *), qsortFun);

    k = 0;
    for(int i = 0; i < sentsNum; i++){
        sentence_t sent = textGetSentence(self, i);
        int wordsNum = sentenceGetCount(sent);
        List_clear(sent->words);
        for(int j = 0; j < wordsNum; j++){
            sentenceAddWord(sent, j, words[k]);
            k++;
        }
    }
}

void textFilter(text_t self, int border){
    int sentsNum = textGetCount(self);
    self->wordsNum = 0;
    for(int i = 0; i < sentsNum; i++){
        sentence_t s = textGetSentence(self, i);

        int wordsNum = sentenceGetCount(s);
        int j = 0;
        for(int i = 0; i < wordsNum; i++, j++){
            int wordLen = strlen(wordConvert(sentenceGetWord(s, j)));
                if( wordLen < border){
                sentenceRemoveWord(s, j);
                j--;
            }
        }
        self->wordsNum += sentenceGetCount(s);
    }

    textSort(self);
}

sentence_t sentenceNew(){
    sentence_t self = (sentence_t)malloc(sizeof(struct sentence_s));
    self->words = List_new();
    return self;
}

void sentenceDelete(sentence_t self){
    List_deepDelete(self->words, wordDelete);
    free(self);
}

void sentenceAddWord(sentence_t self, unsigned int index, word_t word){
    List_add(self->words, index, word);
}

word_t sentenceGetWord(sentence_t self, int index){
    return List_get(self->words, index, NULL);
}

word_t sentenceRemoveWord(sentence_t self, unsigned int index){
    return List_remove(self->words, index, NULL);
}

int sentenceGetCount(sentence_t self){
    return List_getSize(self->words);
}

void Sentence_parse(sentence_t self, const char * sent){
    char buff[maxLength];
    strcpy(buff, sent);

    int i = 0;
    for(char * tok = strtok(buff, " (){}[],:.;-\"'\t\n"); tok != NULL; tok = strtok(NULL, " (){}[],:.;-\"'\t\n")){
        word_t word = wordNew();
        Word_parse(word, tok);
        List_add(self->words, i, word);

        i++;
    }
}

void Sentence_leaveWordWithSpecLen(sentence_t self, unsigned int leftB, unsigned int rightB){
    int wordsNum = sentenceGetCount(self);
    int j = 0;
    for(int i = 0; i < wordsNum; i++, j++){
        int wordLen = strlen(wordConvert(sentenceGetWord(self, j)));

        if( wordLen < leftB || wordLen >= rightB ){
            sentenceRemoveWord(self, j);

            j--;
        }
    }
}

word_t wordNew(){
    word_t self = (word_t)malloc(sizeof(struct word_s));
    strcpy(self->word, "");
    return self;
}

void wordDelete(word_t self){
    free(self);
}

void Word_parse(word_t self, const char * word){
    strcpy(self->word, word);
}

const char * wordConvert(word_t self){
    return self->word;
}
