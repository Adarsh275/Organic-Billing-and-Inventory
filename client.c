#include"headerfile.h"
void main()
{
	main_menu();
}

void main_menu()
{
	system("cls");
	printf("MAIN MENU\nSelect mode of operation:\n");
	printf("1. Customer\n2. Employee\n");
	int ch1;
	scanf("%d",&ch1);
	switch(ch1)
	{
		case 1:
			system("cls");
			customer_menu();
			break;
		case 2:
			system("cls");
			employee_menu();
			break;
		default:printf("wrong input");
			main_menu();
	}
}

void customer_menu()
{
	printf("Customer Menu\n");
	display_stocks();
	int ch2;int i=0;
	CART cart;
	printf("Enter the required product using the code along with the quantity in kgs\n");
	do
	{
		scanf("%d %f",&cart.code[i],&cart.quantity[i]);
		printf("Add one more product?(5/0):");
		//fflush(stdin);
		scanf("%d",&ch2);
		fflush(stdin);
		i++;
	}
	while(ch2==5);
	cal_bill(cart,i);
	int ch3;
	do
	{
		printf("1. Back to Main Menu\n2. Exit application\n");
		scanf("%d",&ch3);
		switch(ch3)
		{
			case 1:
				main_menu();
			case 2:
				printf("Thank you");
				break;
			default:
				printf("Invalid input\nEnter again\n");
		}
	}while(ch3>2 || ch3<1);
}

void employee_menu()
{
	printf("Employee Menu\n");
	int ch4;
	do
	{
		printf("1. Inventory\n2. Add or Remove stocks\n3. Back to Main Menu\n4. Exit application \n");
		scanf("%d",&ch4);		
		switch(ch4)
		{
			case 1:
				display_stocks();
				break;
			case 2:
				display_stocks();
				add_del_stock();
				break;
			case 3:
				main_menu();
				break;
			case 4:
				printf("Have a good day");
				break;
			default:
				printf("Invalid input try again");
		}
	}while(ch4>4 || ch4<1);
}

























	
	