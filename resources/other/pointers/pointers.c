#include<stdio.h>

typedef struct node Node;

struct node {
    int data;
    int* p_data;
};

int main(){
    char* s1 = "pointer";
    char s2[] = "pointer";
     
    printf("s1 is %s\n", s1);
    printf("s2 is %s\n", s2);
    
    int i = 1;
    int* ip = &i;

    printf("i is %d\n", i);
    printf("ip is %d\n", *(ip));
    
    Node n1 = {5, &i};
    printf("n1 data is %d\n", n1.data);
    printf("n1 p_data is %d\n", *(n1.p_data));
    printf("n1 converting to pointer is %d\n", *((&n1)->p_data));

    Node* p1 = &n1;

    printf("p1 data is %d\n", p1->data);
    printf("p1 p_data is %d\n", *(p1->p_data));

    printf("p1 data2 is %d\n", (*p1).data);
    printf("p1 p_data2 id %d\n", *((*p1).p_data));
}
