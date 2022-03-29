#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	int code[20];
	float quantity[20];
}CART;

typedef struct product
{
	int code;
	char pd_name[20];
	float price;
	float stock;
}PRODUCT;

void main_menu();
void customer_menu();
void employee_menu();
void display_stocks();
void update_inventory(CART, int);
void cal_bill(CART, int);
void add_del_stock();
void update(CART,int,int);