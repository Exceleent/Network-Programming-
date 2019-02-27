#include <stdbool.h>
#include <stdio.h>

bool drukowalne(const char *buf);
bool drukowalne_2(const char *buf);


int main()
{
    char MY_BUFOR[5] = {'A', 'B', 'C', 'D', 'E'};
    bool state;
    state = drukowalne(MY_BUFOR);
    state = drukowalne_2(MY_BUFOR);
}


bool drukowalne(const char *buf)
{
    int i = 0;
    while (*(buf + i) != 0)
    {
        if ((32 <= (*(buf + i))) && ((*(buf + i)) <= 126))
        {
            printf("%c", *(buf + i));
            i++;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool drukowalne_2(const char *buf)
{
    const char *p;
    p = buf;
    while (*p != 0)
    {
        printf("%c", *p);
        p++;
    }
    return true;
}