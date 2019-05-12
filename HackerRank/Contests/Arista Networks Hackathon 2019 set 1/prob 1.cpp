#include <cmath>
#include <cstdio>
#include <list>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct msg_t {
    int nodeId;
    int type;
    int len;
    string value;
    msg_t *next;
};

struct node_t {
    int nodeId;
    node_t *next;
    msg_t *msgs;
};


node_t *nodes;

void sortList( node_t *node ) {
    /* Linked list sorting */
    int curMin;
    msg_t *outer = node->msgs;
    msg_t *newL = NULL, *prev_m, *m, *cur_m, *cur_prev;


    while ( outer ) {
        curMin = outer->len;
        m = outer;
        prev_m = NULL;
        /* find the msgs with lowest length and yank it and insert into newL */
        while( m ) {
            if ( m->len <= curMin ) {
                curMin = m->len;
                cur_prev = prev_m;
                cur_m = m;
            }
            prev_m = m;

            m = m->next;
        }

        /* If we are yanking the outer node, move it to next node */
        if ( cur_m == outer ) outer = outer->next;

        /* yank the node from the original list and make it part of new */
        if ( !newL ) {
            if ( cur_prev ) cur_prev->next = cur_m->next;
            newL = cur_m;
            newL->next = NULL;
            node->msgs = newL;
        } else {
            if ( cur_prev ) cur_prev->next = cur_m->next;
            newL->next = cur_m;
            cur_m->next = NULL;
            newL = newL->next;
        }
    }
}

/* return the pointer to the node */
node_t *getNode( int nodeId )
{
    node_t *prev = NULL, *cur, *node;
    if ( !nodes ) {
        nodes = new node_t;
        nodes->nodeId = nodeId;
        return nodes;
    }

    cur = nodes;
    while( cur ) {
        /* return if matching node is found, else allocate one, insert at the right p\
lace and return */
        if ( cur->nodeId == nodeId ) {
            return cur;
        } else if ( cur->nodeId < nodeId ) {
            prev = cur;
            cur = cur->next;
        } else {
            break;
        }
    }
    /* we need to insert the node here */
    node = new node_t;
    node->nodeId = nodeId;
    node->msgs = NULL;
    node->next = cur;
    if( !prev ) {
        nodes = node;
    } else {
        prev->next = node;
    }

    return node;

}



/* Insert the message based on nodeId, coalesce based on type */
void msg_rcv(int nodeId, int type, int length, string value) {
    node_t *node = getNode(nodeId*type);

    if(node->msgs == NULL) {
        msg_t *msg = new msg_t;
        msg->nodeId = nodeId;
        msg->type = type;
        msg->len = length;
        msg->value = value;

        node->msgs = msg;
    }
    else{
        node->msgs->len += length;
        node->msgs->value += value;
    }


}

/* All insertions are done. Sort the messages. You can use the sort function provided in the header part of the function */
void msg_pack(){

}


void printMsgs(FILE *f) {
    node_t *node=nodes;
    msg_t *msg;

    while(node) {
        msg = node->msgs;
        while(msg) {
            fprintf(f, "{ %d,%d,%d,%s }\n", msg->nodeId, msg->type, msg->len, msg->value.c_str());
            msg = msg->next;
        }
        node=node->next;
    }
}

int main() {
    FILE *f = fopen(getenv("OUTPUT_PATH"), "w");

    int _A_n_msgs = 0;
    int i;
    int nodeId, type, len;
    char s[80];
    msg_t *msgs;


    scanf("%d\n", &_A_n_msgs);

    for (i=0; i < _A_n_msgs; i++) {
        scanf("%d,%d,%d,%s", &nodeId, &type, &len, s );
        msg_rcv(nodeId, type, len, string(s));
    }

    msg_pack();
    printMsgs(f);

    fclose(f);
    return 0;
}