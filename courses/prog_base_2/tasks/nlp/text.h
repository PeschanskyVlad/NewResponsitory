#ifndef NLP_H_INCLUDED
#define NLP_H_INCLUDED
#define maxLength 100000
#define wordLength 100

typedef struct text_s * text_t;
typedef struct sentence_s * sentence_t;
typedef struct word_s * word_t;

word_t wordNew();
sentence_t sentenceNew();
void textDelete(text_t self);
void textAddSentence(text_t self, unsigned int index, sentence_t sentence);
sentence_t textGetSentence(text_t self, unsigned int index);
sentence_t textDeleteSentence(text_t self, unsigned int index);
text_t textFromFile(const char * file);
void sentenceAddWord(sentence_t self, unsigned int index, word_t word);
word_t sentenceGetWord(sentence_t self, int index);
int textGetCount(text_t self);
void textFilter(text_t self,  int leftB);
void textSort(text_t self);
void sentenceDelete(sentence_t self);
word_t sentenceRemoveWord(sentence_t self, unsigned int index);
void Sentence_parse(sentence_t self, const char * sent);
int sentenceGetCount(sentence_t self);
void wordDelete(word_t self);
void Word_parse(word_t self, const char * word);
const char * wordConvert(word_t self);

#endif // NLP_H_INCLUDED
