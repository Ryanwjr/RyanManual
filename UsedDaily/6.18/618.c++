// delete the min and show it in value
bool Del_Min(SqList &L, ElemType &value)
{
    if L
        .length == 0 return false;
    // To start,we assign value and pos/flag to 0
    value = L.data[0];
    int pos = 0;
    // The loop -- change the min's value and pos
    for (int i = 1; i < L.length; i++)
    {
        if (L.data[i] < value)
        {
            value = L.data[i];
            pos = i;
        }
        // Set the value of the original element as the last element and return the delete operation is executing true
        L.data[pos] = L.data[L.length - 1];
        return true;
    }