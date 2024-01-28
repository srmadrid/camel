/**
 * @file btree.c
 * 
 * @brief Implementation for the binary tree data structure.
 *
 * @author Sergio Madrid
 * @date 16/1/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */


#include "../../../include/core/dstructs/btree.h"


CML_BTNode *cml_btnode_new() {
    CML_BTNode *node = (CML_BTNode*)malloc(sizeof(CML_BTNode));

    return node;
}


CML_Status cml_btnode_init(void *element, u32 stride, CML_BTree *tree, CML_BTNode *node) {
    if (node == NULL) {
        return CML_ERR_NULL_PTR;
    }

    node->data = malloc(stride);
    if (node->data == NULL) {
        return CML_ERR_MALLOC;
    }
    memcpy(node->data, element, stride);
    node->left = NULL;
    node->right = NULL;
    node->tree = tree;

    return CML_SUCCESS;
}


CML_BTree *cml_btree_new() {
    CML_BTree *tree = (CML_BTree*)malloc(sizeof(CML_BTree));

    return tree;
}


CML_Status _cml_btree_init(void *element, u32 stride, void (*freeFn)(void *element), CML_BTree *btree) {
    if (btree == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (element == NULL) {
        btree->root = NULL;
    } else {
        CML_BTNode *newNode = malloc(sizeof(CML_BTNode));
        if (newNode == NULL) {
            return CML_ERR_MALLOC;
        }
        btree->root = newNode;
        cml_btnode_init(element, stride, btree, btree->root);
    }
    btree->stride = stride;
    btree->freeFn = freeFn;

    return CML_SUCCESS;
}


void cml_btnode_destroy(CML_BTNode *node) {
    if (node != NULL) {
        if (node->left != NULL) {
            cml_btnode_destroy(node->left);
            free(node->left);
        }

        if (node->right != NULL) {
            cml_btnode_destroy(node->right);
            free(node->right);
        }

        if (node->tree->freeFn != NULL) {
            node->tree->freeFn(node->data);
        }
        free(node->data);
        node->data = NULL;
        node->left = NULL;
        node->right = NULL;
        node->tree = NULL;
    }
}


void cml_btree_destroy(CML_BTree *btree) {
    if (btree != NULL) {
        cml_btnode_destroy(btree->root);
        free(btree->root);
        btree->root = NULL;
        btree->stride = 0;
    }
}


void cml_btnode_free(CML_BTNode *node) {
    if (node) {
        free(node);
    }
}


void cml_btree_free(CML_BTree *btree) {
    if (btree) {
        free(btree);
    }
}


CML_Status cml_btnode_insert(void *element, b8 left, CML_BTNode *out) {
    if (out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    CML_BTNode *newNode = malloc(sizeof(CML_BTNode));
    if (newNode == NULL) {
        return CML_ERR_MALLOC;
    }

    cml_btnode_init(element, out->tree->stride, out->tree, newNode);

    if (left) {
        out->left = newNode;
    } else {
        out->right = newNode;
    }

    return CML_SUCCESS;
}
