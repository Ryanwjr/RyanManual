typedef struct squeue
{
    int data[Max];
    int f, r, tag;
} squeue;
bool enters(squeue $s, int x)
{
    if (s.f == s.r && s.tag == 1)
    {
        cout << "full" << endl;
        return false;
    }
    s.data[s, r] = x;
    s.r = (s.r + 1) % Max;
    s.tag = 1;
    return true;
}
bool outs(squeue $s, int x)
{
    if (.f == s.r && s.tag == 1)
    {
        cout << "null" << endl;
        return false;
    }
    x = s.data[s, f] s.f = (s.f + 1) % Max;
    s.tag = 0;
    return 1;
}
int main()
{
    squeue s;
    s.f, s.r, tag = 0;
    for (int i = 1; i < n; i++)
    {
        enters(s, i);
        outs(s, x);
    }
}