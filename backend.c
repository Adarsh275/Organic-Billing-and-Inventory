#include"headerfile.h"

void display_stocks()
{
	system("cls");
	FILE *fp=fopen("inventory.csv","r");
	char buff[100];
	PRODUCT p[23];
	int row=0;
	int column=0;                 
	int i=0;
	while(fgets(buff,100,fp))
	{
		row++;
		column=0;
		if(row==1)
			continue;
		char *val=strtok(buff,",");
		while(val)
		{
			if(column==0)
				p[i].code=atoi(val);
			if(column==1)
				strcpy(p[i].pd_name,val);
			if(column==2)
				p[i].price=atof(val);
			if(column==3)
				p[i].stock=atof(val);
			val=strtok(NULL,",");
			column++;
		}
		i++;
	}
	fclose(fp);
	printf("----------------------------------INVENTORY----------------------------\n");
	printf("Product code       Product name                Price              Stock\n");
	for(int i=0;i<22;i++)
		printf("%-5d              %-14s              %-6.2f             %.2f\n",p[i].code,p[i].pd_name,p[i].price,p[i].stock);
}

void cal_bill(CART c,int n)
{
	FILE *fp=fopen("inventory.csv","r");
	char buff[100];
	int row=0;
	int column=0;
	PRODUCT p[23];
	int i=0;
	while(fgets(buff,100,fp))
	{
		row++;
		column=0;
		if(row==1)
			continue;
		char *val=strtok(buff,",");
		while(val)
		{
			if(column==0)
				p[i].code=atoi(val);
			if(column==1)
				strcpy(p[i].pd_name,val);
			if(column==2)
				p[i].price=atof(val);
			if(column==3)
				p[i].stock=atof(val);
			val=strtok(NULL,",");
			column++;
		}
		i++;
	}
	fclose(fp);
	float total[n],sum=0;
	int pos=0;
	for(int k=0;k<n;k++)
	{
		for(int j=0;j<23;j++)
			if(c.code[k]==p[j].code)
				pos=j;
		total[k]=c.quantity[k]*p[pos].price;
	}
	printf("\n----------------------------BILL---------------------------------\n");
	printf("\n\tProduct Name\tQuantity\tPrice\t\tTotal price\n");	
	for(int k=0;k<n;k++)
	{
		for(int j=0;j<23;j++)
			if(c.code[k]==p[j].code)
				pos=j;
		if(c.quantity[k]<p[pos].stock)
			printf(" %d   %s                %.2f          %.2f            %.2f\n",k+1,p[pos].pd_name,c.quantity[k],p[pos].price,total[k]);
	}
	for(int i=0;i<n;i++)
	{
		sum+=total[i];
	}
	printf("total payable amount is %.2f\n",sum);
	update_inventory(c,n);
	printf("                      THANK YOU\n");
}

void update_inventory(CART c,int n)
{
	FILE *fp=fopen("inventory.csv","r");
	char buff1[100];
	PRODUCT p[23];
	int row=0;
	int column=0;
	int i=0;
	while(fgets(buff1,100,fp))
	{
		row++;
		column=0;
		if(row==1)
			continue;
		char *val=strtok(buff1,",");
		while(val)
		{
			if(column==0)
				p[i].code=atoi(val);
			if(column==1)
				strcpy(p[i].pd_name,val);
			if(column==2)
				p[i].price=atof(val);
			if(column==3)
				p[i].stock=atoi(val);
			val=strtok(NULL,",");
			column++;
		}
		i++;
	}
	fclose(fp);
	int pos=0;
	FILE *temp=fopen("temp.csv","w");
	for(int k=0;k<n;k++)
	{
		for(int j=0;j<23;j++)
			if(c.code[k]==p[j].code)
				pos=j;
		if(p[pos].stock>c.quantity[k])
			p[pos].stock-=c.quantity[k];
		else
			printf("The product %s has been rejected as we are low on stock at the moment\n",p[k].pd_name);
	}
	fprintf(temp,"Product code,Product name,Price,Stock\n");
	for(int k=0;k<22;k++)
	{
		fprintf(temp,"%d,%s,%f,%f\n",p[k].code,p[k].pd_name,p[k].price,p[k].stock);
	}
	fclose(temp);
	int b=remove("inventory.csv");
	b=rename("temp.csv","inventory.csv");
}

void add_del_stock()
{
	CART c;
	int ch5;
	do
	{
		printf("Would you like to 1.add or 2.remove or 3. stop\n");
		scanf("%d",&ch5);
		
		fflush(stdin);
		if(ch5==1)
		{
			printf("Enter no.of products you would like to update about\n");
			int n=0;
			scanf("%d",&n);
			printf("enter the product code and the quantity to be added");
			for(int i=0;i<n;i++)
				scanf("%d %f",&c.code[i],&c.quantity[i]);
			update(c,n,1);
		}
		else if(ch5==2)
		{
			printf("Enter no.of products you would like to update about\n");
			int n=0;
			scanf("%d",&n);
			printf("enter the product code and the quantity to be removed");
			for(int i=0;i<n;i++)
				scanf("%d %f",&c.code[i],&c.quantity[i]);
			update(c,n,-1);
		}
		else if(ch5==3)
			break;
		else
			printf("wrong input try again");
	}while(ch5!=1 || ch5!=2);
	printf("Updated Inventory\n");
	display_stocks();
	employee_menu();
}

void update(CART c,int n,int a)
{
	FILE *fp=fopen("inventory.csv","r");
	char buff1[100];
	PRODUCT p[23];
	int row=0;
	int column=0;
	int i=0;
	while(fgets(buff1,100,fp))
	{
		row++;
		column=0;
		if(row==1)
			continue;
		char *val=strtok(buff1,",");
		while(val)
		{
			if(column==0)
				p[i].code=atoi(val);
			if(column==1)
				strcpy(p[i].pd_name,val);
			if(column==2)
				p[i].price=atof(val);
			if(column==3)
				p[i].stock=atoi(val);
			val=strtok(NULL,",");
			column++;
		}
		i++;
	}
	fclose(fp);
	int pos=0;
	FILE *temp=fopen("temp.csv","w");
	char buff2[100];
	for(int k=0;k<n;k++)
	{
		for(int j=0;j<23;j++)
			if(c.code[k]==p[j].code)
				pos=j;
		if(a==-1 && c.quantity[k]>0)
		{
			if(p[pos].stock>c.quantity[k])
				p[pos].stock-=c.quantity[k];
			else
				printf("The product %s stock is lower than required amount so it will not be changed",p[pos].pd_name);
		}
		else
			p[pos].stock+=c.quantity[k];
	}
	fprintf(temp,"Product code,Product name,Price,Stock\n");
	for(int k=0;k<22;k++)
	{
		fprintf(temp,"%d,%s,%f,%f\n",p[k].code,p[k].pd_name,p[k].price,p[k].stock);
	}
	fclose(temp);
	int b=remove("inventory.csv");
	b=rename("temp.csv","inventory.csv");
}			
		
















			
			