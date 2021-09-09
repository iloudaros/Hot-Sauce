#include <stdio.h>
#include <stdlib.h>

int main() {

//	system("clear");
	printf("\t=============\n\nDo you wanna compile the input \"test\" using hotsauce?[y/n]\n");
	char choice;
	char dump;
	do{


		scanf("%s",&choice);
		dump=getchar();

		if ((choice!='y') && (choice!='n')) printf("\nChoose sth between y or n\n");

	}while((choice!='y') && (choice!='n'));


	if (choice=='y') 
	{
		system("clear");
		system("./hotsauce test.hotsauce.txt");
	}
	else
	{
		system("clear");
		printf("\n\n*****************************************************************\n|  ✅  Hotsauce is ready for use.                               |\n|  📣  test.hotsauce.txt has been copied in the local directory.|\n*****************************************************************\n");
	}

}
