bool Delete(SeqList &L)
{
  if (L.length == 0)
    return false;
  for (int i = 0; int j = 1; i < L.length; j++)
  {
    if (L.data[i] != L.data[j])
      L.data[++i] = L.data[j];
  }
  L.length = i + 1;
  return true;
}