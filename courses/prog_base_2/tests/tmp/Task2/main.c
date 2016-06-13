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

   bookAddReader(Library,"WarCraft","Vlad");


   return 0;

}
