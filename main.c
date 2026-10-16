#include <stdio.h>
#include <locale.h> 
#include <windows.h>
//создание глобальных переменных
int current_day = 1;
int current_hour = 8;
int experience = 0; //типо стаж работы типо смешно, можно будет потом куданибудь влепить в качестве мини ачивки а можно удалить(не снижайте бал)

//два массива для хранения предметьов в интентаре

//сам инвентарь в котоый мы кладем id предметов
int inventory[10] = { 1, 2, 3, 5, 0, 8, 0, 5, 0, 5 };

//список предметов который в теории можно расширить
char* itemNames[10] = {
	"Пусто",
	"Дерево",
	"Камень",
	"Мотыга",
	"семена",
	"Морковь",
	"сено",
	"Верёвка",
	"удочка",
	"Вода"
};

//функция которая считает время работы
void workTime()
{
	int workTime;
	printf("Сколько вы хотите поработать:");
	scanf_s("%d", &workTime);

	if (workTime > 12)// почему то захотелось ограничить на 12-ти часах можно убрать эту часть кода если захочется
	{
		printf("Не стоит так много работать пожалейте себя");
		return;
	}
	if (workTime < 0)
	{
		printf("Нельзя столько работать\n");
		return;
	}
	current_hour += workTime;


	//расчет отработанных часов
	if (current_hour >= 24)
	{
		current_day += current_hour / 24;
		current_hour = current_hour % 24;
		experience = +workTime;

	}
	printf("Текущее время: день %d, время %d:00\n", current_day, current_hour);


}

// создаем отдельную фукцию для вывода меню(мне так захотелось ;) )
void main_menu()
{
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
			workTime();
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



int main()
{

	// делаем вывод консили на русском для пользователя
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	main_menu();

}