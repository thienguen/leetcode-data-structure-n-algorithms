#ifndef AVLTREE_H_
#define AVLTREE_H_

#include <math.h>
#include <iostream>

template <class myType>
struct nodeType {
  myType keyValue;
  int nodeHeight;
  nodeType<myType> *left;
  nodeType<myType> *right;
};

enum treeTraversalOptions {
  INORDER,
  PREORDER,
  POSTORDER,
  LEVELORDER,
  NONE
};

template <class myType>
class avlTree {
  public:
    avlTree<myType>();
    ~avlTree<myType>();
    void destroyTree();
    int countNodes() const;
    int height() const;
    bool search(myType) const;
    void printTree(treeTraversalOptions) const;
    void insert(myType);
    void deleteNode(myType);
  private:
    void destroyTree(nodeType<myType> *&);
    int countNodes(nodeType<myType> *) const;
    int height(nodeType<myType> *) const;
    nodeType<myType> *search(myType, nodeType<myType> *) const;
    void printTree(nodeType<myType> *, treeTraversalOptions) const;
    void printGivenLevel(nodeType<myType> *, int) const;
    nodeType<myType> *insert(myType, nodeType<myType> *);
    nodeType<myType> *rightRotate(nodeType<myType> *);
    nodeType<myType> *leftRotate(nodeType<myType> *);
    int getBalance(nodeType<myType> *) const;
    nodeType<myType> *deleteNode(myType, nodeType<myType> *);
    nodeType<myType> *minValueNode(nodeType<myType> *) const;
    nodeType<myType> *root;
};

template <class myType>
avlTree<myType>::avlTree()
{
  root = NULL;
}

template <class myType>
avlTree<myType>::~avlTree<myType>()
{
  destroyTree(root);
}

template <class myType>
void avlTree<myType>::destroyTree()
{
  destroyTree(root);
}

template <class myType>
int avlTree<myType>::countNodes() const
{
  return countNodes(root);
}

template <class myType>
int avlTree<myType>::height() const
{
  return height(root);
}

template <class myType>
bool avlTree<myType>::search(myType key) const
{
  nodeType<myType> *result = search(key, root);
  if(result == NULL)
    return false;
  return true;
}

template <class myType>
void avlTree<myType>::printTree(treeTraversalOptions options) const
{
  printTree(root, options);
}

template <class myType>
void avlTree<myType>::insert(myType nodeValue)
{
  root = insert(nodeValue, root);
}

template <class myType>
void avlTree<myType>::deleteNode(myType nodeValue)
{
  nodeType<myType> *find = search(nodeValue, root);
  if(find != NULL)
    root = deleteNode(nodeValue, root);
}

template <class myType>
void avlTree<myType>::destroyTree(nodeType<myType> *&node)
{
  if(node != NULL) {
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
  }
  node = NULL;
}

template <class myType>
int avlTree<myType>::countNodes(nodeType<myType> *node) const
{
  if(node == NULL)
    return 0;
  return 1 + countNodes(node->left) + countNodes(node->right);
}

template <class myType>
int avlTree<myType>::height(nodeType<myType> *node) const
{
  if(node == NULL)
    return 0;

  // if tree is not empty height is 1 + max of either path
  return 1 + std::max(height(node->left), height(node->right));
}

template <class myType>
nodeType<myType> *avlTree<myType>::search(myType key, nodeType<myType> *node) const
{
  if(node == NULL)
    return NULL;
  else if(key < node->keyValue)
    return search(key, node->left);
  else if(key > node->keyValue)
    return search(key, node->right);
  else
    return node;
}

template <class myType>
void avlTree<myType>::printTree(nodeType<myType> *node, treeTraversalOptions options) const
{
  if(node == NULL)
    return;

  switch(options) {
    case INORDER:
       printTree(node->left, options);
       std::cout << node->keyValue << " ";
       printTree(node->right, options);
    break;
    case PREORDER:
      std::cout << node->keyValue << " ";
      printTree(node->left, options);
      printTree(node->right, options);
    break;
    case POSTORDER:
      printTree(node->left, options);
      printTree(node->right, options);
      std::cout << node->keyValue << " ";
    break;
    case LEVELORDER:
      for(int i = 1; i <=  height(node); i++) {
        printGivenLevel(node, i);
        std::cout << "\n";
      }
    break;
    case NONE:
      return;
    break;
  }
}

template <class myType>
void avlTree<myType>::printGivenLevel(nodeType<myType> *node, int level) const
{
  if(node == NULL)
    return;

  if(level == 1)
    std::cout << node->keyValue << " ";
  else if(level > 1){
    printGivenLevel(node->left, level-1);
    printGivenLevel(node->right, level-1);
  }
}

template <class myType>
nodeType<myType> *avlTree<myType>::insert(myType key, nodeType<myType> *node)
{
  if(node == NULL) {
    nodeType<myType> *newNode = new nodeType<myType>;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->keyValue = key;
    return newNode;
  }else if(key < node->keyValue)
    node->left = insert(key, node->left);
  else if(key > node->keyValue)
    node->right = insert(key, node->right);

  if(node != NULL) {
    if(height(node->left) - height(node->right) > 1) {
      if(height(node->left->left) >= height(node->left->right)) {
        node = leftRotate(node);
      }else{
        node->left = rightRotate(node->left);
        node = leftRotate(node);
      }
    }else if(height(node->right) - height(node->left) > 1) {
      if(height(node->right->right) >= height(node->right->left)){
        node = rightRotate(node);
      }else{
        node->right = leftRotate(node->right);
        node = rightRotate(node);
      }
    }
  //update height of node
  node->nodeHeight = std::max(height(node->left), height(node->right)) + 1;
  }


  return node;
}

template <class myType>
nodeType<myType> *avlTree<myType>::leftRotate(nodeType<myType> *node)
{
  nodeType<myType> *otherNode;

  otherNode = node->left;
  node->left = otherNode->right;
  otherNode->right = node;
  node->nodeHeight = std::max( height(node->left), height(node->right) ) + 1;
  otherNode->nodeHeight = std::max( height(otherNode->left), height(otherNode->right) ) + 1;
  node = otherNode;

  return node;
}

template <class myType>
nodeType<myType> *avlTree<myType>::rightRotate(nodeType<myType> *node)
{
  nodeType<myType> *otherNode;

  otherNode = node->right;
  node->right = otherNode->left;
  otherNode->left = node;
  node->nodeHeight = std::max( height(node->left), height(node->right) ) + 1;
  otherNode->nodeHeight = std::max( height(otherNode->left), height(otherNode->right) ) + 1;
  node = otherNode;

  return node;
}

template <class myType>
int avlTree<myType>::getBalance(nodeType<myType> *node) const
{
  if(node == NULL) {
    return 0;
  }
  int lh = height(node->left);
  int rh = height(node->right);

  return lh - rh;
}

template <class myType>
nodeType<myType> *avlTree<myType>::deleteNode(myType key, nodeType<myType> *node)
{
  if(node == NULL)
    return node;

  if(key < node->keyValue)
    node->left = deleteNode(key, node->left);
  else if(key > node->keyValue)
    node->right = deleteNode(key, node->right);
  else{
    if((node->left == NULL) || (node->right == NULL)) {
      nodeType<myType> *oldNode = (node->left != NULL) ? node->left : node->right;

      if(oldNode == NULL) {
        oldNode = node;
        node = NULL;
      }
      else
        *node = *oldNode;

      delete oldNode;
    }else{
      nodeType<myType> *oldNode = minValueNode(node->right);

      node->keyValue = oldNode->keyValue;

      node->right = deleteNode(oldNode->keyValue, node->right);
    }
  }

  if(node == NULL)
    return node;

  if(height(node->left) - height(node->right) > 1) {
    if(height(node->left->left) >= height(node->left->right)) {
      node = leftRotate(node);
    }else{
      node->left = rightRotate(node->left);
      node = leftRotate(node);
    }
  }else if(height(node->right) - height(node->left) > 1) {
    if(height(node->right->right) >= height(node->right->left)){
      node = rightRotate(node);
    }else{
      node->right = leftRotate(node->right);
      node = rightRotate(node);
    }
  }
  //update height of node
  node->nodeHeight = std::max(height(node->left), height(node->right)) + 1;

  return node;
}

template <class myType>
nodeType<myType> *avlTree<myType>::minValueNode(nodeType<myType> *node) const
{
  nodeType<myType> *current = node;

  while(current->left != NULL)
    current = current->left;

  return current;
}

#endif
