#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
     int coef;
     int expon;
     struct _Node* next;
} Node;
typedef struct{
  Node* tail;
  int len;
} Polynomial;

void InitPoly(Polynomial *a){
  a->tail = (Node *)malloc(sizeof(Node));
  a->tail->next = NULL;
  a->len = 0;
}
int IsEmpty(Polynomial *a){return a->len == 0;}

void Insert(Polynomial *a, Node *b){
  if(IsEmpty(a)){
    b->next = b;
    a->tail = b;
  }
  else{
    b->next = a->tail->next;
    a->tail->next = b;
    a->tail = b;
  }
  a->len ++;
}
void PrintList(Polynomial* plist){
  Node* cur;
  int i, flag=0;
	for (i=0, cur = plist->tail->next;!flag ; i++,cur = cur->next){//i<plist->len
		printf("%d^%d ", cur->coef, cur->expon);
    if(cur == plist->tail)  flag = 1;
  }
  printf("\n");
}

void AddPoly(Polynomial *a, Polynomial *b, Polynomial *c){
  int flag = 0, flag2 = 0;
  Node *cur_a=a->tail->next, *cur_b=b->tail->next, *cur_c = c->tail->next, *addition;
  addition = (Node *)malloc(sizeof(Node));
  while (!flag){
    if(cur_a == a->tail || cur_b == b->tail)  flag = 1;
    if(cur_a->expon == cur_b->expon){
      addition->expon = cur_a->expon;
      addition->coef = cur_a->coef + cur_b->coef;
      Insert(c, addition);
      cur_a = cur_a->next;
      cur_b = cur_b->next;
      printf("case 1\n");
    }
    else{
      if(cur_a->expon < cur_b->expon){
        addition->expon = cur_b->expon;
        addition->coef = cur_b->coef;
        Insert(c, addition);
        cur_b = cur_b->next;
        printf("case 2\n");
      }
      else{
        Insert(c, cur_a);
        cur_a = cur_a->next;
        printf("case 3\n");
      }
    }
  }
  if(cur_a == a->tail){
    for( ; !flag2; cur_b = cur_b->next){
      printf("case 4\n");
      Insert(c, cur_b);
      if(cur_b == a->tail) flag2 = 1;
    }
  }
  else{
    while(!flag2){
      printf("case 5\n");
      addition->expon = cur_a->expon;
      addition->coef = cur_a->coef;
      Insert(c, addition);
      if(cur_a == a->tail) flag2 = 1;
      cur_a = cur_a->next;
    }
  }
}

int main(){
  Polynomial d, e, f;
  Node *cur1, *cur2, *cur3, *cur4, *cur5, *cur6;
  cur1 = (Node *)malloc(sizeof(Node));
  cur2 = (Node *)malloc(sizeof(Node));
  cur3 = (Node *)malloc(sizeof(Node));
  cur4 = (Node *)malloc(sizeof(Node));
  cur5 = (Node *)malloc(sizeof(Node));
  cur6 = (Node *)malloc(sizeof(Node));
  InitPoly(&d);
  InitPoly(&e);
  InitPoly(&f);

  cur1->expon = 14; cur1->coef = 3;

  Insert(&d, cur1);

  cur2->expon = 7; cur2->coef = 2;

  Insert(&d, cur2);

  cur3->expon = 0; cur3->coef = 2;

  Insert(&d, cur3);

  cur4->expon = 14; cur4->coef = 5;

  Insert(&e, cur4);

  cur5->expon = 8; cur5->coef = -3;

  Insert(&e, cur5);

  cur6->expon = 6; cur6->coef = 7;

  Insert(&e, cur6);

  printf("무한루프 시작\n");
  AddPoly(&d, &e, &f);

  PrintList(&d);
  PrintList(&e);
  PrintList(&f);
  free(cur1);
  free(cur2);
  free(cur3);
  free(cur4);
  free(cur5);
  free(cur6);
  return 0;
}
