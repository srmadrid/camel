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


CML_Status cml_btnode_init(void *element, u32 stride, CML_BTree *tree, CML_BTNode *node) {
    if (node == NULL) {
        return CML_ERR_NULL_PTR;
    }

    node->data = tree->allocator->malloc(stride, tree->allocator->context);
    if (node->data == NULL) {
        return CML_ERR_MALLOC;
    }
    memcpy(node->data, element, stride);
    node->left = NULL;
    node->right = NULL;
    node->tree = tree;

    return CML_SUCCESS;
}


CML_Status _cml_btree_init(void *element, u32 stride, CML_Allocator *allocator, void (*destroyFn)(void *element), CML_BTree *btree) {
    if (btree == NULL || allocator == NULL) {
        return CML_ERR_NULL_PTR;
    }

    if (element == NULL) {
        btree->root = NULL;
    } else {
        CML_BTNode *newNode = allocator->malloc(sizeof(CML_BTNode), allocator->context);
        if (newNode == NULL) {
            return CML_ERR_MALLOC;
        }
        btree->root = newNode;
        cml_btnode_init(element, stride, btree, btree->root);
    }
    btree->stride = stride;
    btree->allocator = allocator;
    btree->destroyFn = destroyFn;

    return CML_SUCCESS;
}


void cml_btnode_destroy(CML_BTNode *node) {
    if (node != NULL) {
        if (node->left != NULL) {
            cml_btnode_destroy(node->left);
            node->tree->allocator->free(node->left, node->tree->allocator->context);
        }

        if (node->right != NULL) {
            cml_btnode_destroy(node->right);
            node->tree->allocator->free(node->right, node->tree->allocator->context);
        }

        if (node->tree->destroyFn != NULL) {
            node->tree->destroyFn(node->data);
        }
        node->tree->allocator->free(node->data, node->tree->allocator->context);
        node->data = NULL;
        node->left = NULL;
        node->right = NULL;
        node->tree = NULL;
    }
}


void cml_btree_destroy(CML_BTree *btree) {
    if (btree != NULL) {
        cml_btnode_destroy(btree->root);
        btree->allocator->free(btree->root, btree->allocator->context);
        btree->root = NULL;
        btree->allocator = NULL;
        btree->stride = 0;
    }
}


CML_Status cml_btnode_insert(void *element, b8 left, CML_BTNode *out) {
    if (out == NULL) {
        return CML_ERR_NULL_PTR;
    }

    CML_BTNode *newNode = out->tree->allocator->malloc(sizeof(CML_BTNode), out->tree->allocator->context);
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
