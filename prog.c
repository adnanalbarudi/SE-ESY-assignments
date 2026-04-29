#include <stdio.h>

struct CB_Struct {
    char buf[10]; 
    int head; // Head
    int tail; // Tail
    int count; // Count 
};
//تهيئة
void init_cb(struct CB_Struct *cb) {
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}
//فحص امتلاء
int isFull(struct CB_Struct *cb) {
    if (cb->count == 10) return 1; 
    return 0;
}
//فحص فراغ  
int isEmpty(struct CB_Struct *cb) {
    if (cb->count == 0) return 1; 
    return 0;
}
void put_char(struct CB_Struct *cb, char d) {
    if (isFull(cb) == 1) {
        printf("\nBuffer Overflow! lost: %c", d);
    } else {
        cb->buf[cb->tail] = d;
        cb->tail = cb->tail + 1;
        if (cb->tail == 10) cb->tail = 0; 
        cb->count = cb->count + 1;
    }
}

char get_char(struct CB_Struct *cb) {
    if (isEmpty(cb) == 1) {
        printf("\nBuffer Underflow!");
        return '\0';
    } else {
        char d = cb->buf[cb->head];
        cb->head = cb->head + 1;
        if (cb->head == 10) cb->head = 0; 
        cb->count = cb->count - 1;
        return d;
    }
}

int main() {
    struct CB_Struct my_cb;
    init_cb(&my_cb);

    char username[100];
    printf("Enter the name: ");
    scanf("%s", username);

    int i = 0;
    while (username[i] != '\0') i++;
    
  
    username[i] = 'C';
    username[i+1] = 'E';
    username[i+2] = '-';
    username[i+3] = 'E';
    username[i+4] = 'S';
    username[i+5] = 'Y';
    username[i+6] = '\0';

    printf("the string: %s\n", username);

    int j = 0;
    while (username[j] != '\0') {
        put_char(&my_cb, username[j]);
        j++;
    }

    printf("Output: ");
    while (isEmpty(&my_cb) == 0) {
        char out = get_char(&my_cb); 
        if (out != '\0') printf("%c", out);
    }

    printf("\n count in buffer: %d\n", my_cb.count);
    return 0;
}
