//========================================================================================
/*                                                                                      *
 *                              REVERSE GROUPS IN SIZE OF K                             *
 *                                                                                      */
//========================================================================================
struct node *reverse(struct node *head, int k)
{
    if (!head)
        return head;

    node *prev = NULL, *curr = head, *next = NULL;

    int count = 0;

    while (curr != NULL and count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    head->next = reverse(curr, k);

    return prev;
}