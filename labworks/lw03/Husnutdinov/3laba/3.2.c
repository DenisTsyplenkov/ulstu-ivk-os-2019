#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    printf("Лабораторная работа №3.2 \nВыполнил Хуснутдинов А.И ИСТбд-21\n");
    pid_t pid, ppid;
    int x = 0;
    /* При успешном создании нового процесса с этого места псевдопараллельно
    начинают работать два процесса: старый и новый */
    //Узнаем идентификаторы текущего и родительского процесса
    ppid = getppid();
    pid = getpid();
    pid = fork();
    /* Перед выполнением следующего выражения значение переменной x в
    обоих процессах равно 0 */
    if (pid == 0)
        printf("Ребенок\n");
    else printf("Родитель\n");
    for (int i = 0; i<10; i++)
    {
        x++;
    // Печатаем значения PID, PPID и вычисленное значение переменной a
    printf("pid = %d, ppid = %d, result = %d\n", (int)pid, (int)ppid, x);
    }
    return 0;
}
