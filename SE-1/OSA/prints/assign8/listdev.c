#include<stdlib.h>
#include<stdio.h>
main()
{
	printf("\n Display the list of devices and their physical names and number of instances ");
	printf("\n Column I - No. of instances ");
	printf("\n Column II - User ");
	printf("\n Column III - Terminal type ");
	printf("\n Column IV - Major number ");
	printf("\n Column V - Minor number ");
	printf("\n I II    III     IV  V   Devic name \n");
	system("ls -l /dev | cut -c12-34,48-60 | more ");
	exit(0);
}
