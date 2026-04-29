#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define size_Buffer 9

struct CircularBuffer
{
    char buffer[size_Buffer];
    int head;
    int tail;
    int count;
};

    //itialize buffer
void initialize_buffer(struct CircularBuffer *cb)
{
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

    // check if buffer full or no
bool is_buffer_full(struct CircularBuffer *cb)
{
    if (cb->count == size_Buffer)
        return true;
    else
    return false;
}

    // Check if buffer empty or no
bool is_buffer_empty(struct CircularBuffer *cb)
{
    if (cb->count == 0)
        return true;
    else
        return false;
}

    // write character in buffer
void write_in_buffer(struct CircularBuffer *cb, char data)
{
    if (is_buffer_full(cb))
    {
        printf("Buffer Overflow\n");
        return;
    }
    cb->buffer[cb->tail] = data;
    cb->tail = (cb->tail + 1) % size_Buffer;
    cb->count++;
}

    // read character from buffer
char read_from_buffer(struct CircularBuffer *cb)
{
    char data;
    if (is_buffer_empty(cb))
    {
        printf("Buffer Underflow\n");
        return '\0';
    }
    data = cb->buffer[cb->head];
    cb->head = (cb->head + 1) % size_Buffer;
    cb->count--;

    return data;
}

int main()
{
    struct CircularBuffer cb;
    char name[20];
    char fulltext[50];

    initialize_buffer(&cb);

    printf("Enter your name: ");
    scanf("%s", name);

    strcpy(fulltext, name);
    strcat(fulltext, "CE-ESY");

    for (int i = 0; i < strlen(fulltext); i++)
    {
        write_in_buffer(&cb, fulltext[i]);
    }

    printf("output: ");

    while (!is_buffer_empty(&cb))
    {
         printf("%c", read_from_buffer(&cb));
    }

    printf("\n");

    if (is_buffer_empty(&cb))
        printf("Buffer is empty\n");

    return 0;
}
