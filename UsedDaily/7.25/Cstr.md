# 725W04

Write a program from scratch that

- Reads a string of at most 79 characters, supposing that in the input stream a NEWLINE character specifies the end of the input string.
- Has a function which is used for getting the reversed string of the input string. For example, if the input string is "ABCD", the reversed string is "DCBA". You should use the array notation for this function.
- Has a function which is used for getting a new string that contains and only contains all alphabetic characters of the input string, in the order of appearance. For example, if the input string is "A1 bX", the new string is "AbX". You should use the pointer notation for this function. You should _not_ use any library functions from `ctype.h` such as `isalpha`, `islower`, `isupper`.
- Finally, prints out the 3 strings, one on each line, in the above order.

```shell
[user@sahara ~]$ ls
hello.c  subdir1
[user@sahara ~]$ gcc -Wall -0 hello hello.c
gcc: error: unrecognized command-line option '-0'
[user@sahara ~]$ gcc -Wall -o hello hello.c
[user@sahara ~]$ ls
hello  hello.c  subdir1
[user@sahara ~]$ ./hello
Hello, world!
[user@sahara ~]$
```

```cpp
for(int i = 0; str[i] != '\0'; ++i)
    {
        while (!( (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '\0') )
        {
            for(j = i; str[j] != '\0'; ++j)
            {
                str[j] = str[j+1];
            }
            str[j] = '\0';
        }
    }
```

限定固定字符

```cpp
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 79
void swap(char *a, char *b);
void reverseString(char *s, int sSize);

int main(int argc, char *argv[]){
 char str[MAX_NAME_LEN + 1];
 gets(str);
 printf("%s\n", str);
 reverseString(str,strlen(str));
 printf("%s\n", str);
 reverseString(str,strlen(str));
   for(int i = 0; str[i] != '\0'; ++i)
    {
        while (!( (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '\0') )
        {
            int j = i;
            for(j; str[j] != '\0'; ++j)
            {
                str[j] = str[j+1];
            }
            str[j] = '\0';
        }
    }
 printf("%s\n", str);
}

void swap(char *a, char *b) {
    char t = *a;
    *a = *b, *b = t;
}

void reverseString(char *s, int sSize) {
    for (int left = 0, right = sSize - 1; left < right; ++left, --right) {
        swap(s + left, s + right);
    }}
```

---

LC344 反转字符串

```cpp
void swap(char *a, char *b) {
    char t = *a;
    *a = *b, *b = t;
}

void reverseString(char *s, int sSize) {
    for (int left = 0, right = sSize - 1; left < right; ++left, --right) {
        swap(s + left, s + right);
    }}
```
