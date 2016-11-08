#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct PNode{
    int coef; //系数
    int expon; //指数
    struct PNode *next;
}*PolyNomial;

PolyNomial read(){
    int n;
    cin>>n;
    PolyNomial P,temp,cur;
    P = (PolyNomial)malloc(sizeof(struct PNode)); //创建头结点，便于插入节点
    P->next = NULL;
    cur = P;
    while(n--){
        temp = (struct PNode*)malloc(sizeof(struct PNode));
        temp->next = NULL;
        cin>>temp->coef>>temp->expon;
        cur->next = temp;
        cur = temp;
    }

    //将头结点删去
    temp = P;
    P = P->next;
    free(temp);
    return P;
}

void PrintPoly(PolyNomial P){
    if(!P){
        cout<<0<<" "<<0;
    }
    while(P){
        if(P->next)
            cout<<P->coef<<" "<<P->expon<<" ";
        else
            cout<<P->coef<<" "<<P->expon;
        P = P->next;
    }
}

void Attach(int coef,int expon,PolyNomial *rear){
    PolyNomial temp = (PolyNomial)malloc(sizeof(struct PNode));
    temp->coef = coef;
    temp->expon = expon;
    temp->next = NULL;
    (*rear)->next = temp;
    *rear = temp;
}

PolyNomial addPoly(PolyNomial p1,PolyNomial p2){
    PolyNomial p = (PolyNomial)malloc(sizeof(struct PNode));
    p->next = NULL;
    PolyNomial rear = p;
    while(p1 && p2){
        if(p1->expon>p2->expon){
            Attach(p1->coef,p1->expon,&rear);
            p1 = p1->next;
        }else if(p1->expon<p2->expon){
            Attach(p2->coef,p2->expon,&rear);
            p2 = p2->next;
        }else{
            if(p1->coef+p2->coef != 0){
                Attach(p1->coef+p2->coef,p1->expon,&rear);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    if(p1){
        while(p1){
            Attach(p1->coef,p1->expon,&rear);
            p1 = p1->next;
        }
    }else {
        while(p2){
            Attach(p2->coef,p2->expon,&rear);
            p2 = p2->next;
        }
    }
    PolyNomial temp = p;
    p = p->next;
    free(temp);
    return p;
}

PolyNomial multiOne(PolyNomial p,PolyNomial q){
    PolyNomial front1 = (PolyNomial)malloc(sizeof(struct PNode));
    front1->next = NULL;
    PolyNomial rear = front1,temp;
    while(p){
        PolyNomial cur = (PolyNomial)malloc(sizeof(struct PNode));
        cur->coef = (p->coef)*(q->coef);
        cur->expon = (p->expon)+(q->expon);
        cur->next = NULL;
        rear->next = cur;
        rear = cur;
        p = p->next;
    }
    temp = front1;
    front1 = front1->next;
    free(temp);
    return front1;
}

PolyNomial multiPoly(PolyNomial p1,PolyNomial p2) {
    PolyNomial r1 = multiOne(p1,p2),r2;
    p2 = p2->next;
    while(p2) {
        r2 = multiOne(p1,p2);
        r1 = addPoly(r1,r2);
        p2 = p2->next;
    }
    return r1;
}

int main() {
    PolyNomial p1 = read();
    PolyNomial p2 = read();
    PolyNomial P = addPoly(p1,p2);
    PolyNomial Q = multiPoly(p1,p2);
    PrintPoly(Q);
    cout<<endl;
    PrintPoly(P);

}
