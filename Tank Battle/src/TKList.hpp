#pragma once
#include "TKItem.hpp"
class TKListNode
{
public:
    TKListNode(void);
    ~TKListNode(void);
    TKItem* item;
    TKListNode* next;
    TKListNode* last;
};
TKListNode::TKListNode(void)
{

}
TKListNode::~TKListNode(void)
{

}
class TKList
{
public:
    TKList(void);
    ~TKList(void);
    TKItem*                 first();
    void                    push_back(TKItem* item);
    TKItem*                 pop_back();
    void                    clear();
    TKItem*                 last();
    TKItem*                 next();
private:
    TKListNode*             head;
    TKListNode*             back;
    TKListNode*             current;
};

TKList::TKList(void)
{
    head = 0;
    back = 0;
    current = 0;
}


TKList::~TKList(void)
{
}

TKItem* TKList::first()
{
    if (head == 0)
    {
        return 0;
    }
    current = head;
    return head->item;
}

TKItem* TKList::last()
{
    if (current == 0)
    {
        return 0;
    }
    if (current->last == 0)
    {
        return 0;
    }
    current = current->last;
    return current->item;
}
TKItem* TKList::next()
{
    if (current == 0)
    {
        return 0;
    }
    if (current->next == 0)
    {
        return 0;
    }
    current = current->next;
    return current->item;
}

void TKList::push_back(TKItem* item)
{
    if (back == 0)
    {
        head = new TKListNode;
        back = head;
    }
    else
    {
        back->next = new TKListNode;
        back = back->next;
    }
    back->item = item;
    back->next = 0;
}

TKItem* TKList::pop_back()
{
    if (head == 0)
    {
        return 0;
    }
    if (head == back)
    {
        head = 0;
    }
    TKListNode* tmp = back;
    back = back->last;
    TKItem* ret = tmp->item;
    delete tmp;
    return ret;
}

void TKList::clear()
{
    while (head == 0)
    {
        TKListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}