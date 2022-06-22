typedef struct lnode
{
    int data;
    struct lnode *next;
} lnode;
// 利用递归思想的删除，从L到L->next
void delete (lnode *L, int x)
{
    if (L == NULL)
        return;
    lnode *p;
    if (L->data == x)
    {
        p = L;
        L = L->next;
        free(p);
        delete (L, x);
    }
}
