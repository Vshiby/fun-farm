#include <stdio.h>
#include <locale.h> 
#include <windows.h>
//создание глобальных переменных
int current_day = 1;
int current_hour = 8;
int main()
{

	// делаем вывод консили на русском для пользователя
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	while (1)
	{
		printf("Меню \n");
		printf(" [0] Выход \n");
		printf(" [1] Посмотреть на часы \n");
		printf(" [2] Промотать время (Поработать) \n");
		printf(" [3] Посмотреть инвентарь \n");
		printf(" [4] Положить предмет в слот \n");
		printf(" [5] Выбросить предмет \n");
		printf(" [6] Ревизия ресурсов \n");
		int choice;
		scanf_s("%d", &choice);
		switch (choice)
		{
		case(0):
		{
			return 0;
		}

		case(1):
		{
			//вроде хочется отдельной функцией а вроде и так сойдет
			printf("Текущее время: день %d, время %d:00\n", current_day, current_hour);
			break;
		}

		case(2):
		{
			break;
		}
		case(3):
		{
			break;
		}

		case(4):
		{
			break;
		}

		case(5):
		{
			break;
		}

		case(6):
		{
			break;
		}

		default: printf("Не вырный пункт меню!\n"); break;
		}


	}


}