# Program is impliment in C Language . Description in points are given bellow:
•	Upon opening the application, the user will be asked to continue either as an employee of the store or as a customer.
•	Should the user have continued as an employee then he/she will have been able to do the following :
##		1.	View/edit the store's inventory.
##		2.	Access customer information.
•	However if the user chose to proceed as a customer then he/she will be able to view the inventory and make purchases as per his/her needs.
•	Customer information will be stored and retrieved from a file. 
•	The customer will then be allowed to add any number of items to their cart, once satisfied they may checkout.
•	At which point, the program will check if there is available stock of the said items, appropriate message will be displayed. 
•	The organic store's inventory will be stored and retrieved from a file.
•	The user will be prompted to apply any discount/reward points.
•	The available stock will be reduced once the customer's bill is generated.
•	Once the bill is processed and displayed it will be stored in the customer's file.


# Steps for execution 
	As the program is impliment in multiple file I created a make file named as "makefile.mk" for easy execution of the program.
	Step1: To execute make file type : mingw32-make -f makefile.mk 
	step2: above command will compile and link all file, and prodce a a.exe file 
	step3: in command prompt type: a.exe 
	step4: hint enter that will give you a list of option to choose what you want to do in billing process.
