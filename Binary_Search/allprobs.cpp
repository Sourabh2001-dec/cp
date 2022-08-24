//========================================================================================
/*                                                                                      *
 *                          SEARCH IN SORTED AND ROTATED ARRAY                          *
 *                                                                                      */
//========================================================================================

int search(int A[], int l, int h, int key)
{
    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        if (A[mid] == key)
            return mid;

        if (A[mid] >= A[l])
        {
            // left is sorted
            if (key >= A[l] and key <= A[mid]) // is key present in left array?
            {
                h = mid - 1;
            }
            else // key not present so move to other array
            {
                l = mid + 1;
            }
        }
        else
        {
            if (key >= A[mid] and key <= A[h])
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
    }

    return -1;
}
