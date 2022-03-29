app.exe:client.o backend.o
	gcc client.o backend.o
client.o:client.c headerfile.h
	gcc -c client.c
backend.o:backend.c headerfile.h
	gcc -c backend.c