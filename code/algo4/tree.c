#include <stdlib.h>
#include <stdio.h> 
#include "item.h"
#include "list.h"

void in_order(link now){
    if(now == NULL){
        return;
    }
    else{
        printf("%c", now->item);
        in_order(now->l);
        in_order(now->r);
    }
}

void post_order(link now){
    if(now == NULL){
        return;
    }
    else{
        post_order(now->l);
        post_order(now->r);
        printf("%c", now->item);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2){
        printf("You have not entered enough arguments: N required!\n ");
    }
    else {
        link root, left, right;
        char *str = argv[1];
        // 汎用的なものでなく *+a**bc+def だけに対応

        // * 
        root = new_node(*str, NULL, NULL);
        str++;

        //  
        add_left_leaf(root, *str);
        left = root->l; str++;

        add_left_leaf(left, *str);
        str++;

        add_right_leaf(left, *str);
        str++; right = left->r;

        add_left_leaf(right, *str);
        str++; left = right->l;

        add_left_leaf(left, *str);
        str++;

        add_right_leaf(left, *str);
        str++;

        add_right_leaf(right, *str);
        str++; right = right->r;

        add_left_leaf(right, *str);
        str++;

        add_right_leaf(right, *str);
        str++;

        add_right_leaf(root, *str);

        //
        link inorder_root = root, postorder_root = root;

        printf("inorder: ");
        in_order(inorder_root);
        printf("\n");

        printf("postorder: ");
        post_order(postorder_root);
        printf("\n");
    }
    return 0;
}