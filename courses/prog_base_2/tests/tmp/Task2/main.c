#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "lib.h"



int main() {
    library_t * Library = newLibrary();
    addBook(Library,"WarCraft");
    addBook(Library,"Lord of the Rings");
    addBook(Library,"Hobbit");
    addBook(Library,"Metro 2033");
    addBook(Library,"C++ for teapots");
    //printBooks(Library);

    //deleteBook(Library,"WarCraft");
   // printBooks(Library);
   puts("\nGet list.");
   List_t * books = getBooksList(Library);
   printList(books);

   addBookReader(Library,"WarCraft","Vlad");
   bookDeleteReader(Library,"WarCraft");
   addBookReader(Library,"WarCraft","Tom");
   printList(books);

   List_t tmpL = getNeededBooks(Library,0);
   printList(tmpL);

   List_t tmpL1 = getOldBooks(Library,1);

   printList(tmpL1);

   freeLibrary(Library);



   // printList(books);


   return 0;

}
