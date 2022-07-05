class Solution
{
public
    int lengthOfLastWord(String s)
    {
        int res = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s.charAt(i) == ' ' && res != 0)
            {
                break;
            }
            if (s.charAt(i) != ' ')
            {
                res++;
            }
        }
        return res;
    }
}