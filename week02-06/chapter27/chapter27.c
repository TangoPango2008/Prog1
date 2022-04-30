#include <stdlib.h>
#include <stdio.h>

void prnt(const char* p, const int x)
{
    printf("p is %s and x is %i \n", p, x);
}

int main()
{
    char* hello = "Hello";
    char* world = "World!";
    printf("%s %s\n", hello, world);

    prnt("foo", 7);
    prnt("nine", 9);
    prnt("ten", 10);
    return 0;
}