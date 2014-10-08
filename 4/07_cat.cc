#include <iostream>

/* C-ben

   // kernel -> buffer(egy sor)
   // EOF==-1
   // char + kell extermalis ertek

   int ch;
   while((ch=getchar())!=EOF)
      putchar(ch);

*/
int main() {
    char ch;
    // iomanipulator -> noskipws, endl, flush
    // setprecision, setbase, setw (width), setfill (fill character)
    while(std::cin>>std::noskipws>>ch) {
        std::cout<<ch;
        // std::cout<<ch + '\0' -> ASCII kod
    }
    return 0;
}

/*
 * std::cin>>std::noskipws>>ch -> std::cin
 * cin -> bool converzio? nincs
 * cin -> void * converzio!
 *
 * ha lenne bool konverzio, akkor ez valid lenne:
 *
 * char c;
 * while(std::cin << c) {
 * }
 *
 */
