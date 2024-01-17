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


CML_Status cml_btnode_init(void *element, u32 stride, CML_BTNode *node) {
    if (node == NULL) {
        return CML_ERR_NULL_PTR;
    }

    node->data = malloc(stride);
    if (node->data == NULL) {
        return CML_ERR_NULL_PTR;
    }
    memcpy(node->data, element, stride);
    node->left = NULL;
    node->right = NULL;
    node->stride = stride;

    return CML_SUCCESS;
}


CML_Status _cml_btree_init(void *element, u32 stride, CML_BTree *btree) {
    if (btree == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (element == NULL) {
        btree->root = NULL;
    } else {
        CML_BTNode *newNode = malloc(sizeof(CML_BTNode));
        if (newNode == NULL) {
            return CML_ERR_NULL_PTR;
        }
        btree->root = newNode;
        cml_btnode_init(element, stride, btree->root);
    }
    btree->stride = stride;

    return CML_SUCCESS;
}


void cml_btnode_free(CML_BTNode *node, void (*freeFn)(void *element)) {
    if (node != NULL) {
        if (node->left != NULL) {
            cml_btnode_free(node->left, freeFn);
            free(node->left);
        }

        if (node->right != NULL) {
            cml_btnode_free(node->right, freeFn);
            free(node->right);
        }

        if (freeFn != NULL) {
            freeFn(node->data);
        }
        free(node->data);
        node->data = NULL;
        node->left = NULL;
        node->right = NULL;
    }
}


void cml_btree_free(CML_BTree *btree, void (*freeFn)(void *element)) {
    if (btree != NULL) {
        cml_btnode_free(btree->root, freeFn);
        free(btree->root);
        btree->root = NULL;
        btree->stride = 0;
    }
}


CML_Status cml_btnode_insert(void *element, b8 left, CML_BTNode *out) {
    if (out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    CML_BTNode *newNode = malloc(sizeof(CML_BTNode));

    cml_btnode_init(element, out->stride, newNode);

    if (left) {
        out->left = newNode;
    } else {
        out->right = newNode;
    }

    return CML_SUCCESS;
}
