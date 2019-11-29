/* Linked list that can store any data? --> store a void pointer that points to your data */

typedef struct {
  void * data;
  struct llnode * next;
} llnode;

typedef struct {
  struct llnode * head;
} ll;

struct ll* ll_Create(){
  ll *new = malloc(sizezof(ll));
  new->head = NULL;
  return new;
}

void addToFront(ll* l, void* elem){
  llnode* n = malloc(sizeof(llnode));
  n->data = elem;
  n->next = ll-> head;
  ll->head = n;
}

void 