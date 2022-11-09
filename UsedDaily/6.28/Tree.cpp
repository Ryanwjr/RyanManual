#include <iostream>
using namespace std;
// find the common ancestor node
// The main idea of processing tree is to *or/ 2
struct Tree
{
    int data = [ 1, -1, 2, 3, 4, 5, 6, 7 ];
};

int Common(Tree t, int i, int j)
{
    if (t.data[i] != -1 && t.data[j] != -1)
    {
        while (i != j)
        {
            if (i > j)
                i /= 2;
            else
                j /= 2;
        }
        return t.data[i];
    }
    return -1;
}
int main()
{
    Tree t;
    int ans = Common(t, 3, 6);
    return 0;
}