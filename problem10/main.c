#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>




struct primes_array
{
    struct primes_array *next;
    unsigned long long int number;

};

struct primes_array *insert_number(struct primes_array *, unsigned long long int);

struct primes_array *insert_number(struct primes_array *head, unsigned long long int num)
{
       struct primes_array *current=NULL;
       struct primes_array *newnode=NULL;

        current=head;
        newnode= (struct primes_array *) malloc(sizeof(struct primes_array));
            if(newnode== NULL);
                printf("OUT of memory\n");
        if(head==NULL)
        {
            newnode->next=NULL;
            newnode->number=num;
            head=newnode;

            return head;
        }
        else
        {
            while(current->next !=NULL)
                current=current->next;
            newnode->next=NULL;
            newnode->number=num;
            current->next=newnode;
        }

        return head;

}


int main()
{

    struct primes_array *head=NULL;
    struct primes_array *current=NULL;
    unsigned long long int sum=0;
    unsigned long long int i,j;
    head=insert_number(head,2);
    head=insert_number(head,3);
    for(i=4;i<10;i++)
    {
        current=head;

        for(j=current->number;current->next==NULL;current=current->next);
        {
            if((i%j) != 0)
            {
                head=insert_number(head,i);
                break;
            }
        }
    }
    current=head;
    for(j=current->number; (current->next) == NULL; current=(current->next));
    {
            sum+=j;
    }
    printf("Sum is %ld",sum);

    return 0;
}

