#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    printf("Лабораторная работа №4.2\n");
    printf("Выполнил студент группы ИСТбд-21 Ионов Р.Д\n");
	int fd[2], result;
	size_t size;
	char string[] = "Hello, world!";//Строка для записи
	char resstring[14];//Строка для чтения
	int er = pipe(fd);//Создаем pipe
    if (er == 0)//Проверка на успешность операции
    {
        result = fork();//Порождаем новый процесс
        if (result > 0)//Работает родительский процесс
        {
            printf("Работу начал родительский процесс\n");// Родитель записывает строку в канал через входной поток
            close(fd[0]); //Входной поток данных родителя не понадобится
            printf("Запись строки в поток\n");
            size = write(fd[1],string, 14); // Запись строки в поток
            close(fd[1]);// Закрываем выходной поток данных и завершаем работу родителя
            printf("Parent exit\n");
        }
        else//Работает порожденный процессе
         {
            printf("Работу начал дочерний процесс\n");// Ребенок читает строку из канала и печатает ее
            close(fd[1]); //Выходной поток данных ребенка не понадобится
            printf("Чтение строки из канала\n");
            size = read(fd[0], resstring, 14); // Чтение строки из канала
            printf("%s\n", resstring);// Печать прочитанной строки
            close(fd[0]);// Закрыть входной поток и завершить работу
            printf("Child exit\n");
         }
	}
	else printf("Операция не выполнена\n");
    return 0;
}
