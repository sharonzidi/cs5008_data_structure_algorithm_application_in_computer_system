#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node{
      char* data;
      Node* leftChild;
      Node* rightChild;
      Node* parent;
      int visited;
};

typedef struct ll_node LL_Node;

struct ll_node{
    Node* data;
    LL_Node* next;
};

typedef struct queue Queue;

struct queue {
    LL_Node* head;
};

struct binaryTree{
      Node* root;
};

typedef struct binaryTree BinaryTree;

BinaryTree* createBinaryTree(Node* root){
    BinaryTree* bt = (BinaryTree*)malloc(sizeof(BinaryTree));
    bt->root = root;
    return bt;
}

LL_Node* createLLNode(Node* data){
    LL_Node* node = (LL_Node*)malloc(sizeof(LL_Node));

    node->data = data;
    node->next = NULL;

    return node;
}

Node* createNode(char* data){
      Node* newNode = (Node*)malloc(sizeof(Node));
      newNode->data = data;

      newNode->leftChild = NULL;
      newNode->rightChild = NULL;
      newNode->parent = NULL;
      newNode->visited = 0;
      return newNode;
}

void destroyNode(Node *node){
      if (node == NULL) return;

        destroyNode(node->leftChild);
        destroyNode(node->rightChild);
            //  destroyNode(node->parent);
            //
            //    // Destroy node
        free(node);
        }
            
 // 1 to add the node as a left child;
 // 0 to add the node as a right child.
 void addChild(Node *node, Node* child, int leftChild){
     if (leftChild){
         node->leftChild = child;
     } 
     else {
         node->rightChild = child;
         }
         child->parent = node;
}


LL_Node* addBack(LL_Node* head, LL_Node* toAdd){
    if(head == NULL){
        return toAdd;
    }

    LL_Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = toAdd;
    return head;
}

void push(Queue* q, Node* n){
    LL_Node* l = addBack(q->head, createLLNode(n));
    q->head = l;
}

void remove_q(Queue* q){
    LL_Node* l = q->head;
    if(l == NULL) return;

    LL_Node* next = l->next;
    q->head = next;
    Node* d = l->data;
    free(l);
}

Node* peek(Queue* q){
    if(q->head == NULL) return NULL;
    return q->head->data;
}

LL_Node* removeFront(LL_Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    return head->next;
}

Queue* createQueue(Node* n){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->head = createLLNode(n);
    return q;
}

int isEmpty(LL_Node* nodes){
    return nodes == NULL;
}

void levelOrderPrint(BinaryTree* tree){
    Queue* q = createQueue(tree->root);

    while(q->head != NULL){
        Node* n = peek(q);
        printf("level order print %s\n", n->data);
        Node* left = n->leftChild;
        Node* right = n->rightChild;
        if(left != NULL){
            push(q, left);
        }

        if(right != NULL){
            push(q, right);
        }
        remove_q(q);
    }

    free(q);
}

int main(){
    Node* b1n = createNode("b1n");
    Node* b2n = createNode("b2n");
    Node* b3n = createNode("b3n");

    b1n->leftChild = b2n;
    b1n->rightChild = b3n;

    b2n->parent = b1n;
    b3n->parent = b1n;

    BinaryTree* bt = createBinaryTree(b1n);

    levelOrderPrint(bt); // it works!

    free(b1n);
    free(b2n);
    free(b3n);
    free(bt);
}
