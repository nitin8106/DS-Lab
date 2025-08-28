#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front;
    struct node *rear;
};

struct queue *create_queue();
struct queue *insert(struct queue *, int);
struct queue *delete_element(struct queue *);
void display(struct queue *);
int peek(struct queue *);

int main() {
    struct queue *q = create_queue();
    int val, option;

    do {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. INSERT");
        printf("\n 2. DELETE");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\n Enter the number to insert in the queue: ");
                scanf("%d", &val);
                q = insert(q, val);
                break;
            case 2:
                q = delete_element(q);
                break;
            case 3:
                val = peek(q);
                if(val != -1)
                    printf("\n The value at front of queue is : %d", val);
                break;
            case 4:
                display(q);
                break;
            case 5:
                printf("\n Exiting...");
                break;
            default:
                printf("\n Invalid option! Please try again.");
        }
    } while(option != 5);

    getch();
    return 0;
}

struct queue *create_queue() {
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

struct queue *insert(struct queue *q, int val) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->next = NULL;

    if(q->front == NULL) {
        q->front = q->rear = ptr;
    } else {
        q->rear->next = ptr;
        q->rear = ptr;
    }
    return q;
}

void display(struct queue *q) {
    struct node *ptr = q->front;
    if(ptr == NULL) {
        printf("\n QUEUE IS EMPTY");
        return;
    }

    printf("\n Queue elements: ");
    while(ptr != NULL) {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
}

struct queue *delete_element(struct queue *q) {
    if(q->front == NULL) {
        printf("\n UNDERFLOW");
        return q;
    }

    struct node *ptr = q->front;
    printf("\n The value being deleted is : %d", ptr->data);
    q->front = q->front->next;
    free(ptr);

    // If the queue becomes empty, update rear as well
    if(q->front == NULL) {
        q->rear = NULL;
    }

    return q;
}

int peek(struct queue *q) {
    if(q->front == NULL) {
        printf("\n QUEUE IS EMPTY");
        return -1;
    }
    return q->front->data;
}

