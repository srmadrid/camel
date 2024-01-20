/**
 * @file btree.h
 * 
 * @brief Declaration for the binary tree data structure.
 *
 * @author Sergio Madrid
 * @date 16/1/2024
 * 
 * @copyright Copyright (c) 2023 Sergio Madrid. All rights reserved. Licensed 
 *            under the MIT License. See LICENSE in the project root for license
 *            information.
 */

#ifndef CAMEL_BINTREE
#define CAMEL_BINTREE

#include <stdlib.h>

#include "../macros.h"
#include "../err.h"


/**
 * @brief Represents a binary tree node.
 */
typedef struct CML_BTNode {
    /** @brief Pointer to the data of the node. */
    void *data;
    /** @brief Pointer to the left child of the node. */
    struct CML_BTNode *left;
    /** @brief Pointer to the right child of the node. */
    struct CML_BTNode *right;
    /** @brief Tree the node belongs to. */
    struct CML_BTree *tree;
} CML_BTNode;


/**
 * @brief Represents a binary tree.
 */
typedef struct CML_BTree {
    /** @brief Pointer to the root node of the tree. */
    CML_BTNode *root;
    /** @brief Size of each element in the tree in bytes. */
    u32 stride;
    /** @brief Freeing function for the elements of the tree. */
    void (*freeFn)(void *element);
} CML_BTree;


/**
 * @brief Initializes a CML_BTNode with the input element.
 * 
 * @param element Pointer to the element to be stored in the node.
 * @param stride  Size of the element in bytes.
 * @param tree    Pointer to the CML_BTree the node belongs to.
 * @param node    Pointer to the CML_BTNode to be initialized.
 * 
 * @return Status code.
 */
CML_Status cml_btnode_init(void *element, u32 stride, CML_BTree *tree, CML_BTNode *node);


/**
 * @brief Initializes a CML_BTree with the input stride.
 * 
 * @param element Pointer to the element to be stored in the root node.
 * @param stride  Size of each element in the tree in bytes.
 * @param freeFn  Freeing function for the elements of the tree.
 * @param btree   Pointer to the CML_BTree to be initialized.
 * 
 * @return Status code.
 */
CML_Status _cml_btree_init(void *element, u32 stride, void (*freeFn)(void *element), CML_BTree *btree);


/**
 * @brief Initializes a CML_BTree with the input type and root element.
 * 
 * @param element Pointer to the element to be stored in the root node.
 * @param type    Type of the tree.
 * @param freeFn  Freeing function for the elements of the tree.
 * @param btree   Pointer to the CML_BTree to be initialized.
 * 
 * @return Status code.
 */
#define cml_btree_init(element, type, freeFn, btree) _cml_btree_init(element, sizeof(type), freeFn, btree)


/**
 * @brief Frees the memory allocated by the input CML_BTNode and its subtrees 
 *        using the freeing function stored in the CML_BTree the node belongs
 *        to.
 * 
 * @param node Pointer to the CML_BTNode to be freed.
 * 
 * @return void.
 */
void cml_btnode_free(CML_BTNode *node);


/**
 * @brief Frees the memory allocated by the input CML_BTree.
 * 
 * @param btree  Pointer to the CML_BTree to be freed.
 * 
 * @return void.
 */
void cml_btree_free(CML_BTree *btree);


/**
 * @brief Inserts a child node to the left or right of the input node.
 * 
 * @param element Pointer to the element to be stored in the child node.
 * @param left    Whether to insert the child node to the left or right of the
 *                input node.
 * @param node    Pointer to the CML_BTNode to insert the child node to.
 * 
 * @return Status code.
 */
CML_Status cml_btnode_insert(void *element,  b8 left, CML_BTNode *out);


#endif /* CAMEL_BINTREE */
