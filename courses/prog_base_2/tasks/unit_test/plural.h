#ifndef PLURAL_H_INCLUDED
#define PLURAL_H_INCLUDED

typedef struct plural_s plural_t;

plural_t * plural_new(int size, int *totalPos);
void plural_fill_range(plural_t * self, int *totalPos, int rangeStart, int rangeEnd);
int plural_print(const plural_t * self, int *totalPos);
void plural_random(plural_t * self, int *totalPos);
void plural_free(plural_t * self);
void plural_addElement(plural_t * self, int *totalPos);
void plural_deleteElement(plural_t * self, int *totalPos);
int plural_intersection(plural_t * self, int plur[10]);
int plural_association(plural_t * self, int plur[10]);
int plural_symmetric_difference(plural_t * self, int plur[10]);


#endif // PLURAL_H_INCLUDED
