// #include <iostream>
// using namespace std;

// // Function to calculate GCD using Euclidean algorithm
// int gcd(int a, int b)
// {
//     while (b != 0)
//     {
//         int temp = b;
//         b = a % b;
//         a = temp;
//     }
//     return a;
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int a, b;
//         cout << "Enter two integers: ";
//         cin >> a >> b;

//         int result = gcd(a, b);
//         cout << "The GCD of " << a << " and " << b << " is " << result << endl;
//     }

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
   
} node;
node *start = NULL;

void create(int n)
{
    int ele;
    node *p, *rear = NULL;

    for (int i = 1; i <= n; i++)
    {
        printf("enter the element");
        scanf("%d", &ele);
        p = (node *)malloc(sizeof(node));
        p->info = ele;
        p->next = NULL;

        if (start == NULL)
        {
            start = rear = p;
            p->prev = NULL;
        }
        else
        {
            rear->next = p;
            p->prev = rear;
            rear = p;
        }
    }
}

void display(node *s)
{

    while (s != NULL)
    {

        printf("%d", s->info);
        s = s->prev;
    }
}

//void insert(int new_element, int pos, node *s)
{
    int ele;
    node *p = start;

    for (int i = 1; i <= pos - 1; i++)
    {
        s = s->next;
    }
    p->info = ele;
    p->next = s->next;
    p->next = s;
}

void reverse(node *s)
{
    node* prev;
    node* current;
    node *rnext;
    prev = s;
    current = s->next;
    rnext = current->next;

    if (prev == s)
    {
        prev->next = NULL;
    }

    while (current != NULL)
    {
        current->next = prev;
        prev = current;
        current = rnext;

        if (current != NULL)
        {
            rnext = current->next;
        }
    }
}

int main()
{

    int n;
    scanf("%d", &n);
    int new_element;
    int pos;
    create(n);
    // printf("enter the element to be inserted");
    // scanf("%d",&new_element);
    // printf("enter the position at which the element needs to be inserted :");
    // scanf("%d",&pos);
    // insert(new_element,pos,start);
    reverse(start);
    display(start);

    return 0;
}
