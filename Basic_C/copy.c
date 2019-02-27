#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{
    int kopiowany;
    int nowy;
    char buf[1];
    int r_przeczytanych = 0;

    if (argc != 3)
    {
        printf("Nie poprawna ilosc argumentow - podaj nazwe pliku kopiowanego i nowego pliku");
        exit(0);
    }
    else
    {
        kopiowany = open(argv[1], O_RDONLY | O_CREAT);
        nowy = open(argv[2], O_WRONLY | O_CREAT);
        if (kopiowany == -1 || nowy == -1)
        {
            perror("Program");
        }
        else
        {
            while (r_przeczytanych = read(kopiowany, buf, 1), r_przeczytanych > 0)
            {
                char *zapisane_wskaznik = buf;
                //printf("Z pliku odczytano %c \n", *buf);
                int r_zapisanych = 0;
                while (r_zapisanych = write(nowy, zapisane_wskaznik, 1))
                {
                    if(r_zapisanych == -1) {
                        perror("Program");
                    }
                    if(r_zapisanych == 0) {
                        break;
                    }
                    //printf("Do pliku zapisano %c \n", *zapisane_wskaznik);
                    r_przeczytanych -=r_zapisanych;
                    if(r_przeczytanych ==0 ) break;
                }
                if (r_przeczytanych == -1)
                {
                    perror("Program");
                }
            }
        }
        if (close(kopiowany) < 0 && close(nowy) < 0)
        {
            perror("Program");
        }
    }
}
