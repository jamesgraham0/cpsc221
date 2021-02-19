#include "chain.h"
#include <cmath>
#include <iostream>


// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain() {
    clear();
}

/**
 * Inserts a new node after the node pointed to by p in the
 * chain (so p->next is the new node) and returns a pointer to
 * the newly created node.
 * If p is NULL, inserts a new head node to the chain.
 * This function **SHOULD** create a new Node and increase length_.
 *
 * @param p = The new node should be pointed to by p->next.
 *            If p is NULL, the new node becomes the head of the chain.
 * @param ndata = The data to be inserted.
 */
Chain::Node * Chain::insertAfter(Node * p, const Block &ndata) {
    Node *temp = new Node(ndata);
    if (p == NULL) {
        head_ = temp;
    }
        
    else {
        Node *temp2 = p->next;
        p->next = temp;
        temp->prev = p;
        temp->next = temp2;
        
        if (temp2 != NULL) {
        temp2->prev = temp;
        }
    }
    length_++;
    return temp;
}



/**
 * Swaps the position in the chain of the two nodes pointed to
 * by p and q.
 * If p or q is NULL or p==q, do nothing.
 * Change the chain's head pointer if necessary.
 */
void Chain::swap(Node *p, Node *q) {
  Node *p_prev = p->prev;
  Node *p_next = p->next;
  Node *q_prev = q->prev;
  Node *q_next = q->next;
  if (p != NULL && q != NULL && p != q) {
    if (p->next == q) {
      p_prev->next = q;
      q->prev = p_prev;
      q->next = p;
      p->next = q;
      p->next = q_next;
      q_next->prev = p;
    } else if (q->next == p) {
      q_prev->next = p;
      p->prev = q_prev;
      p->next = q;
      q->next = p;
      q->next = p_next;
      p_next->prev = q;
    } else {
      p_prev->next = q;
      q->prev = p_prev;
      q->next = p_next;
      p_next->prev = q;
      p_next->next = q_prev;
      q_prev->prev = p_next;
      q_prev->next = p;
      p->prev = q_prev;
      p->next = q_next;
      q_next->prev = p;
    }
  }
}
        
    

/**
 * Destroys all dynamically allocated memory associated with the
 * current Chain class.
 */
void Chain::clear() {
   Node *temp = head_ -> next;
   delete head_;
   while (temp != NULL) {
       Node *next = temp->next;
       delete temp;
       temp = next;
   }
   length_ =0;
}

/**
 * Makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */
void Chain::copy(Chain const &other) {
  //  clear();
  //  Node* curr = other.head_;
    
  //  while (curr->next != NULL) {
  //      curr = curr->next;
  //  }
    
  //  while (curr != NULL){
  //      (* this).insertAfter(this->head_, curr->data);
  //      curr = curr->prev;
  //  }

}
   

/* Modifies the current chain: 
 * 1) Find the node with the first (leftmost) block in the unscrambled
 *    image and move it to the head of the chain.
 *	This block is the one whose closest match (to the left) is the
 *	largest.  That is, the distance (using distanceTo) to this block 
 *	is big for all other blocks.
 *	For each block B, find the distanceTo B from every other block
 *	and take the minimum of these distances as B's "value".
 *	Choose the block B with the maximum value over all blocks and
 *	swap its node to the head of the chain.
 *
 * 2) Starting with the (just found) first block B, find the node with
 *    the block that is the closest match to follow B (to the right)
 *    among the remaining blocks, move (swap) it to follow B's node,
 *    then repeat to unscramble the chain/image.
 */
void Chain::unscramble() {
  /* your code here */
}
