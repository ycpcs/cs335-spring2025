#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int x = 100;

struct Vector3
{
    float x, y, z;
};

void foo(int a, int b)
{
    int x, y;

    x = a + b;
    y = a - b;
}

void log_cs335_joke()
{
    printf("%s\n", "I am a programmer and I write bugs !");
}

void log_user_input(char *input)
{
    char buffer[5];
    strcpy(buffer, input);
}

int main(int argc, char *argv[])
{
    log_user_input(argv[1]);
    printf("%s\n", argv[1]);

    int a = 2;
    float b = 3.141592;

    struct Vector3 v;
    v.x = 10;
    v.y = 11;
    v.z = 12;

    static int y;

    int array[10];
    for (int i = 0; i < 10; i++)
    {
        array[i] = i;
    }

    foo(8, 5);

    int *ptr = (int *)malloc(2 * sizeof(int));
    ptr[0] = 10;
    ptr[1] = 20;

    free(ptr);

    return 1;
}