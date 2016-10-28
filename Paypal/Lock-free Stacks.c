// Main idea: as long as no other thread has modifed stack, a thread’s modi!cation can proceed. 
int compare_and_swap(int* reg, int oldval, int newval)
{
    ATOMIC();
    int old_reg_val = *reg;
    if (old_reg_val == oldval)
        *reg = newval;
    END_ATOMIC();
    return old_reg_val;
}

void push(Stack *s, Node *n) {
    while (1) {
        Node *old_top = s->top;
        n->next = old_top;
        if (compare_and_swap(&s->top, old_top, n) == old_top)
            return;
    }
}

Node *pop(Stack *s) {
    while (1) {
        Node *old_top = s->top;
        if (old_top == NULL)
            return NULL;
        Node *new_top = old_top->next;
        if (compare_and_swap(&s->top, old_top, new_top) == old_top)
            return old_top;
    }
}

Node *pop(Stack *s) {
    while (1) {
        Node *top = s->top;
        int pop_count = s->pop_count;
        if (top == NULL)
            return NULL;
        Node *new_top = top->next;
        if (double_compare_and_swap(&s->top, top, new_top, &s->pop_count, pop_count, pop_count + 1))
            return top;
    }
}