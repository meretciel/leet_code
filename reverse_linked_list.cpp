//
//  reverse_linked_list.cpp
//  leet_code
//
//  Created by Ruikun Hong on 8/4/15.
//  Copyright (c) 2015 Ruikun Hong. All rights reserved.
//

#include <stdio.h>

#include <iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    
    ListNode *_head;
    
    ListNode* reverseList(ListNode* head) {
        if (!head) {return NULL; }
        
        _reverseList(head);
        
        return _head;
        
    }
    
    ListNode* _reverseList(ListNode* head) {
        
        if (!head->next) {_head = head; return head;}
        
        ListNode *pt = _reverseList(head->next);
        pt->next = head;
        
        head->next = NULL;
        
        return head;
        
    }
};