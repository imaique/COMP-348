#include <stdio.h>
#include <stdlib.h>

typedef enum { ATOM, LIST } eltype;
typedef char atom;
struct _listnode;
typedef struct {
    eltype type;
    union {
        atom a;
        struct _listnode* l;
    };
} element;
typedef struct _listnode {
    element el;
    struct _listnode* next;
} * list;
const element NIL = { .type=LIST, .l=NULL };

element aasel(atom a);
element lasel(list l);
list cons(element e, list l);
list append(list l1, list l2);
void print(element e);
element car(element e);
list copy_list(list l);
list cdr(element e);
list cddr(element e);
void lfree(list l);
int main() {
    element a = aasel('a');
    element b = aasel('b');
    element c = aasel('c');
    element d = aasel('d');
    element e = aasel('e');
    list bc = NULL;
    bc = (list) malloc(sizeof (struct _listnode));
    if (bc == NULL) {
        return 1;
    }
    bc->el = b;
    bc->next = (list) malloc(sizeof (struct _listnode));
    bc->next->el = c;
    bc->next->next = NULL;
    //printf("%c",bc->el.a);
    //printf("%c",bc->next->el.a);

    element bc_asel = lasel(bc);
    //printf("\n%c",bc_asel.l->el.a);



    //printf("\n%c",car(lasel(bc)).a);
    print(lasel(bc));


    list de = NULL;
    de = (list) malloc(sizeof (struct _listnode));
    if (de == NULL) {
        return 1;
    }
    de->el = d;
    de->next = (list) malloc(sizeof (struct _listnode));
    de->next->el = e;
    de->next->next = NULL;

    list newcons = cons(bc_asel,de);
    printf("\n");
    print(lasel(newcons));

    newcons = cons(a,newcons);
    printf("\n");
    print(lasel(newcons));
    printf("\n%c%", car(lasel(newcons)).a);
    printf("\n");
    print(lasel(cdr(lasel(newcons))));
    printf("\n");
    print(car(car(lasel(newcons))));

    printf("\n");
    lfree(newcons);
    return 0;
}
element aasel(atom a){
    element element1 = {ATOM, .a = a};
    return element1;
}
element lasel(list l){
    element element1 = {LIST, .l = l};
    return element1;
}
element copy_element(element e){
    if(e.type==ATOM){
        element copy = {ATOM, .a = e.a};
        return copy;
    }
    else if (e.type==LIST){
        element copy = {LIST, .l = copy_list(e.l)};
        return copy;
    }
}


list copy_tail(list l,list* tail){
    if(l==NULL) return NULL;

    list head = NULL;
    head = (list) malloc(sizeof (struct _listnode));
    if(head==NULL){
        exit(1);
    }

    head->el = copy_element(l->el);

    list new_list = head;
    l = l->next;

    while (l!=NULL){
        new_list->next = NULL;
        new_list->next = (list) malloc(sizeof (struct _listnode));
        if(new_list->next==NULL){
            exit(1);
        }

        new_list->next->el = copy_element(l->el);

        new_list = new_list->next;
        l = l->next;
    }
    new_list->next = NULL;
    if(tail!=NULL) *tail = new_list;

    return head;
}
list copy_list(list l){
    return copy_tail(l,NULL);
}
void lfree(list l){
    /*
    if(l->next!=NULL){
        lfree(l->next);
    }
    if(l->el.type==ATOM){
        free(l);
    }

    else if(l->el.type==LIST) {
        lfree(l->el.l);
        free(l);
    }
*/

    list temp;
    while (l != NULL){
        temp = l;
        l = l->next;
        if(temp->el.type==LIST) lfree(temp->el.l);
        free(temp);
    }



}
list cons(element e, list l){

    list new_list =  NULL;
    new_list = (list) malloc(sizeof (struct _listnode));
    if(new_list==NULL){
        exit(1);
    }

    new_list->el = e;
    new_list->next = l;

    return new_list;
}
list append(list l1, list l2){
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;

    list temp = l1;
    while (temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = l2;
    return l1;
    /*
     * deep copy implementation
     *
    list new_list;
    new_list = (list) malloc(sizeof (struct _listnode));
    if(new_list==NULL){
        exit(1);
    }
    list l1tail;
    new_list = copy_tail(l1, &l1tail);
    l1tail->next = copy_list(l2);

    return new_list;
    */
}
element car(element e){
    if(e.type==ATOM){
        return NIL;
    }
    if (e.type == LIST){
        return e.l->el;
    }
}
list cdr(element e){
    if(e.type==ATOM){
        return NULL;
    }
    else if (e.type==LIST){
        return e.l->next;
    }
}
list cddr(element e){
    if(e.type==ATOM || e.l->next ==NULL){
        return NULL;
    }
    if (e.type== LIST){
        return e.l->next->next;
    }
}
void print(element e){
    if(e.type==ATOM){
        printf(" %c ", e.a);
    }
    else if (e.type==LIST){
        if(e.l == NULL){
            printf(" NIL ");
        }
        else{
            list ptr = e.l;
            printf("(");
            while (ptr!=NULL){
                print(ptr->el);
                ptr = ptr->next;
            }
            printf(")");
        }
    }
}

/* replaced by copy list
    while (l!=NULL){
        new_list_ptr->next = NULL;
        new_list_ptr->next = (list) malloc(sizeof (struct _listnode));
        if(new_list_ptr->next==NULL){
            return 1;
        }

        new_list_ptr->next->el = l->el;
        new_list_ptr = new_list_ptr->next;
        l = l->next;
    }

    new_list_ptr->next = NULL;
     */