//1. Circular Linked List Operations

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

// Function to create a circular linked list
void create_list() {
    head = NULL;
}

// Function to insert N elements to the circular linked list
void insert(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;

    if (head == NULL) {
        head = new_node;
        new_node->next = head;
    } else {
        Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = head;
    }
    printf("Inserted %d\n", data);
}

// Function to delete elements from any position in the circular linked list
void delete(int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *temp = head;

    if (position == 1) {
        while (temp->next != head) {
            temp = temp->next;
        }
        Node *del_node = head;
        head = head->next;
        temp->next = head;
        free(del_node);
    } else {
        Node *prev = NULL;
        for (int i = 1; i < position && temp->next != head; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (temp->next == head && position != 1) {
            printf("Position out of bounds\n");
            return;
        }
        prev->next = temp->next;
        free(temp);
    }
    printf("Deleted node at position %d\n", position);
}

// Function to display elements of the circular linked list
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int n, data, position, choice;

    create_list();

    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insert(data);
    }

    while (1) {
        printf("\n1. Insert element\n2. Delete element\n3. Display list\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                delete(position);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
//2. Stack Implementation Using Array

#include <stdio.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int is_full(Stack *s) {
    return s->top == MAX - 1;
}

int is_empty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int item) {
    if (is_full(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->data[++(s->top)] = item;
    printf("Pushed %d\n", item);
}

int pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->data[(s->top)--];
}

int peek(Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->data[s->top];
}

void display(Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    display(&s);
    printf("Top item is: %d\n", peek(&s));
    printf("Popped item: %d\n", pop(&s));
    display(&s);

    return 0;
}
//3. Stack Implementation Using Linked List

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void init(Stack *s) {
    s->top = NULL;
}

int is_empty(Stack *s) {
    return s->top == NULL;
}

void push(Stack *s, int item) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = item;
    new_node->next = s->top;
    s->top = new_node;
    printf("Pushed %d\n", item);
}

int pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    Node *temp = s->top;
    int item = temp->data;
    s->top = s->top->next;
    free(temp);
    return item;
}

int top(Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->top->data;
}

void display(Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty\n");
        return;
    }
    Node *temp = s->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    display(&s);
    printf("Top item is: %d\n", top(&s));
    printf("Popped item: %d\n", pop(&s));
    display(&s);

    return 0;
}

//Check Corresponding Braces


#include <stdio.h>
#include <string.h>

int check_braces(char *str) {
    int balance = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '{') balance++;
        else if (str[i] == '}') balance--;
        if (balance < 0) return 0;
    }
    return balance == 0;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    if (check_braces(str)) {
        printf("All braces are balanced.\n");
    } else {
        printf("Braces are not balanced.\n");
    }
    return 0;
}
//Check Palindrome Using Stack


#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int is_full(Stack *s) {
    return s->top == MAX - 1;
}

int is_empty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char item) {
    if (!is_full(s)) {
        s->data[++(s->top)] = item;
    }
}

char pop(Stack *s) {
    if (!is_empty(s)) {
        return s->data[(s->top)--];
    }
    return '\0';
}

int main() {
    char str[MAX], rev[MAX];
    Stack s;
    init(&s);

    printf("Enter a string: ");
    scanf("%s", str);

    for (int i = 0; i < strlen(str); i++) {
        push(&s, str[i]);
    }

    for (int i = 0; i < strlen(str); i++) {
        rev[i] = pop(&s);
    }
    rev[strlen(str)] = '\0';

    if (strcmp(str, rev) == 0) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}





#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = new_node;
    return new_node;
}

void insert(Node** head, int data) {
    Node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = *head;
    }
}

Node* find_min_node(Node* head) {
    if (head == NULL) return NULL;
    Node* temp = head;
    Node* min_node = head;
    do {
        if (temp->data < min_node->data) {
            min_node = temp;
        }
        temp = temp->next;
    } while (temp != head);
    return min_node;
}

void merge_lists(Node** head1, Node** head2) {
    if (*head1 == NULL || *head2 == NULL) return;

    Node* min_node1 = find_min_node(*head1);
    Node* min_node2 = find_min_node(*head2);

    // Find the node before min_node1
    Node* temp = *head1;
    while (temp->next != min_node1) {
        temp = temp->next;
    }
    temp->next = min_node2;

    // Find the last node of the second list
    temp = *head2;
    while (temp->next != *head2) {
        temp = temp->next;
    }
    temp->next = min_node1->next;

    min_node1->next = min_node2;
}

void display(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;

    int n, data;
    printf("Enter the number of elements in the first circular linked list: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insert(&head1, data);
    }

    printf("Enter the number of elements in the second circular linked list: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        insert(&head2, data);
    }

    printf("First Circular Linked List: ");
    display(head1);

    printf("Second Circular Linked List: ");
    display(head2);

    merge_lists(&head1, &head2);

    printf("Merged Circular Linked List: ");
    display(head1);

    return 0;
}