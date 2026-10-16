#include <stdio.h>
#include <locale.h> 
#include <windows.h>
//создание глобальных переменных
int current_day = 1;
int current_hour = 8;
int experience = 0; //типо стаж работы типо смешно, можно будет потом куданибудь влепить в качестве мини ачивки а можно удалить(не снижайте бал)

//два массива для хранения предметьов в интентаре

//сам инвентарь в котоый мы кладем id предметов
int inventory[10] = { 0, 2, 3, 5, 4, 6, 7, 5, 7, 5 };

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

//добавляем проверку на число, как я понял если он успешно читает то 1 а если не число то -1
int readInt()
{
	int value;
	if (scanf_s("%d", &value) != 1)
	{
		while (getchar() != '\n');
		return -1;
	}
	while (getchar() != '\n');
	return value;
}
//замена цвета(может понадобиться для красивого оформления)
void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//функция которая считает время работы
void workTime()
{

	printf("Сколько вы хотите поработать:");
	int workTime = readInt();
	if (workTime > 12)// почему то захотелось ограничить на 12-ти часах можно убрать эту часть кода если захочется
	{
		printf("Не стоит так много работать, пожалейте себя");
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
		experience += workTime;

	}
	setColor(10);
	printf("=== День %d, %02d:00 ===\n", current_day, current_hour);
	setColor(7);


}

void Inventory()
{
	//просто перебор массива инвентаря, выводит слот инвентаря и предмет в нем
	for (int i = 0; i < 10; i++)
	{
			printf("Слот %d: %s\n", i, itemNames[inventory[i]]);

	}


}


void changeItem()
{

	int slot, item;
	//показываем весь инвентарь
	Inventory();
	printf("Выберите слот который хотете заменить:\n");
	slot = readInt();
	if (slot < 0 || slot > 9) { printf("Неверный номер слота!\n"); return; }
	//показываем все доступные предметы
	for (int i = 0; i < 10; i++)
	{
		printf("Предмет %d: %s\n", i, itemNames[i]);
	}
	printf("Выберите предмет который хотете положить в слот:\n");
	item = readInt();
	if (item < 0 || item > 9) { printf("Неверный ввод\n"); return; }
	inventory[slot] = item;
	printf("В слот %d положен предмет %s\n", slot, itemNames[item]);
}


void dropItem()
{
	//вывод инвентаря для удобства
	Inventory();
	int slot;
	printf("Выберите прдемт который хотите выбросить: \n");
	slot = readInt();
	if (slot < 0 || slot > 9) { printf("Неверный номер слота!\n"); return; }
	inventory[slot] = 0;
	printf("Предмет безвозвратно выброшен(((\n");
}
//функция для перебора инвентаря и поиска предмета в слотах
void resourceAudit()
{
	int id;
	for (int i = 0; i < 10; i++)
	{
		printf("Предмет %d: %s\n", i, itemNames[i]);
	}
	printf("Введите ID предмета: \n");
	id = readInt();

	int count = 0;// сколько раз встретился
	int slots[10];// сюда будем записывать, в каких слотах лежит
	int slotCount = 0;// сколько слотов уже записали

	for (int i = 0; i < 10; i++)
	{
		if (inventory[i] == id)
		{
			count++;
			slots[slotCount] = i;
			slotCount++;
		}
	}

	if (count == 0)
	{
		printf("Предмет с ID %d не найден в инвентаре.\n", id);
	}
	else
	{
		printf("Предмет %s встречается %d раз(а)\n", itemNames[id], count);
		printf("Лежит в слотах: ");
		for (int i = 0; i < slotCount; i++)
		{
			printf("%d ", slots[i]);
		}
		printf("\n");
	}
}


// создаем отдельную фукцию для вывода меню(мне так захотелось ;) )
void main_menu()
{
	while (1)
	{
		setColor(14);
		printf("====== МЕНЮ ========\n");
		setColor(7);
		printf(" [0] Выход \n");
		printf(" [1] Посмотреть на часы \n");
		printf(" [2] Промотать время (Поработать) \n");
		printf(" [3] Посмотреть инвентарь \n");
		printf(" [4] Положить предмет в слот \n");
		printf(" [5] Выбросить предмет \n");
		printf(" [6] Ревизия ресурсов \n");
		int choice = readInt();
		switch (choice)
		{
		case(0):
		{
			return;
		}

		case(1):
		{
			system("cls");
			//вроде хочется отдельной функцией а вроде и так сойдет
			setColor(10);
			printf("=== День %d, %02d:00 ===\n", current_day, current_hour);
			setColor(7);
			break;
		}

		case(2):
		{
			system("cls");
			workTime();
			break;
		}
		case(3):
		{
			system("cls");
			Inventory();
			break;
		}

		case(4):
		{
			system("cls");
			changeItem();
			break;
		}

		case(5):
		{
			system("cls");
			dropItem();
			break;
		}

		case(6):
		{
			system("cls");
			resourceAudit();
			break;
		}

		default: printf("Не верный пункт меню!\n"); break;
		}


	}




}



int main()
{

	// делаем вывод консили на русском для пользователя
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	SetConsoleTitleA("fun Farm");//немного оформления работе
	main_menu();
	//функция main получилась какой то маленькой я не уверен что это норм
}