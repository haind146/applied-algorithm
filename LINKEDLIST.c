//
// Created by nguye on 4/13/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct _Node {
    int data;
    struct _Node * next;
};
typedef struct _Node Node;
Node * insertToHead(Node *head,int _data) {
    Node * tempNode = (Node *)malloc(sizeof(Node));
    tempNode->next = head;
    tempNode->data = _data;
    return tempNode;
}

Node * insertToLast(Node *head, int _data) {
    Node * tempNode = (Node *)malloc(sizeof(Node));
    tempNode->data = _data;
    tempNode->next = NULL;
    Node * iter;
    if(head == NULL) {
        return tempNode;
    }
    iter = head;
    while (iter->next != NULL) {
        iter = iter->next;
    }
    iter->next = tempNode;
    return head;
}

Node * insertByIndex(Node * head, int index, int _data) {
    Node * tempNode = (Node *)malloc(sizeof(Node));
    tempNode->data = _data;
    int count = 0;
    Node * iter = head;
    if (index == 0) {
        return insertToHead(head, _data);
    }
    do {
        if (count == index-1) {
            tempNode->next = iter->next;
            iter->next = tempNode;
            return head;
        } else {
            iter = iter->next;
            count++;
        }
    }
    while (iter->next != NULL);

    iter->next = tempNode;
    tempNode->next = NULL;
    return head;
}
void printDS(Node * head) {
    Node * iter;
    iter = head;
    while (iter->next!= NULL) {
        printf("%d ", iter->data);
        iter = iter->next;
    }
    printf("%d ", iter->data);
}

void updateByIndex(Node * head, int index,  int _data) {
    int count = 0;
    Node * iter = head;
    while (iter->next != NULL || count == index) {
        if (count++ == index) {
            iter->data = _data;
            return;
        }
        iter = iter->next;
    }
}

Node * sortEvenToOdd(Node * head) {
    Node * iter, *first, *lastEven;
    first = head;
    iter = head;
    if(first->data%2 == 0) {
        lastEven = first;
    } else {
        lastEven = NULL;
    }
    while (iter != NULL) {
        if (iter->next == NULL) return first;
        if (iter->data %2 == 0 && iter->next->data%2 ==0) {
            iter = iter->next;
            lastEven = iter;
            continue;
        }
        if (iter->next->data%2 == 0) {
            Node *temp = iter->next;
            iter->next = iter->next->next;
            if (lastEven == NULL) {
                temp->next = first;
                first=temp;
                lastEven = temp;

            } else {
                temp->next = lastEven->next;
                lastEven->next = temp;
                lastEven = temp;
            }
            continue;
        }
        iter = iter->next;
    }
    return first;
}

Node * sortEx10(Node * head) {
    Node * iter, *first, *lastEven = NULL;
    first = head;
    int count = 1;
    iter = head;
    while (iter->next!= NULL) {
        if(count%2 == 1) {
            Node *temp = iter->next;
            iter->next = iter->next->next;
            if(lastEven == NULL) {
                temp->next = first;
                first = temp;
                lastEven = temp;
            } else {
                temp->next = lastEven->next;
                lastEven->next = temp;
                lastEven = temp;
            }

        } else {
            iter = iter->next;
        }
        count++;
    }

    return first;
}

int main() {
    Node * ds = NULL;


    ds = insertToHead(ds, 7);
    ds = insertToHead(ds, 6);
    ds = insertToHead(ds, 5);
    ds = insertToHead(ds, 4);
    ds = insertToHead(ds, 3);
    ds = insertToHead(ds, 2);
    ds = insertToHead(ds, 8);
    ds = insertToLast(ds, 1);
    ds = insertToLast(ds, 2);
    ds = insertToLast(ds, 3);

    printDS(ds);
    printf("\n");
    printDS(sortEvenToOdd(ds));
}

