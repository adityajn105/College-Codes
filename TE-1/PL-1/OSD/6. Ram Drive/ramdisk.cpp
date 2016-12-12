#include <iostream>
#include <stdlib.h>
#include <sys/stat.h>
#include<unistd.h>

using namespace std;

int main()
{
	struct stat fs;
	lstat("/mnt/MyRam",&fs);
	if(!S_ISDIR(fs.st_mode))
	{
		system("sudo mkdir /mnt/MyRam");
		system("sudo chmod 777 /mnt/MyRam");
		cout<<"\nVirtual RAM created"<<endl;
		cout<<"\nDisk usage....";
		system("sudo df -h");
		cout<<"Selecting tmpfs and mounting the RAM...";
		system("sudo mount -t tmpfs -o size=500M /tmpfs/mnt /mnt/MyRam");

		cout<<"\nDrive Mounted and ready for use !"<<endl;
		system("sudo df -h");
		cout<<"Executing application in VRAM..."<<endl;
		system("sudo cp /home/Nishant/calc.cpp /mnt/MyRam");
		system("sudo cp /home/Nishant/input.txt /mnt/MyRam");
		chdir("/mnt/MyRam");
		system("sudo chmod 777 input.txt");
		system("sudo chmode 777 calc.cpp");
		system("sudo g++ calc.cpp");
		system("./a.out");
		system("sudo df -h");	
	}
	else
	{
		cout<<"\nDirectory already present";
	}
	return 0;
}

