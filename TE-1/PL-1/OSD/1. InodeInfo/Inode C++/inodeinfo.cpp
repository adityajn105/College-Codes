#include<iostream>
#include<sys/types.h>
#include <sys/stat.h>
#include<stdlib.h>
#include <time.h>
using namespace std;

int main(int argc, char *argv[]){
	struct stat fs;

	for(int i=1;i<argc;i++){
		cout<<i<<". File Name: "<<argv[i]<<endl;
		int res=stat(argv[i],&fs);
		if(res==-1) -1;
		
		cout<<"             ID of Device containing file :"<<fs.st_dev<<"\n";
		cout<<"             Inode No: "<<fs.st_ino<<endl;
				
		if(S_ISREG(fs.st_mode)){
			cout<<"             File Type: Regular File"<<endl;
		}
		else if(S_ISDIR(fs.st_mode)){
			cout<<"             File Type: Directory"<<endl;
		}
		else if(S_ISLNK(fs.st_mode)){
			cout<<"             File Type: Symbolic Link"<<endl;		
		}
		else if(S_ISCHR(fs.st_mode)){
			cout<<"             File Type: Character File"<<endl;
		}
		else if(S_ISBLK(fs.st_mode)){
			cout<<"             File Type: Block File"<<endl;
		}
		else if(S_ISFIFO(fs.st_mode)){
			cout<<"             File Type: FIFO File"<<endl;
		}
		cout<<"             No of Links: "<<fs.st_nlink<<"\n";
		cout<<"             Owner's User ID: "<<fs.st_uid<<"\n";
		cout<<"             Owner's Group ID:"<<fs.st_gid<<endl;
		cout<<"             Size of File :"<<fs.st_blksize<<endl;
		cout<<"             Blocks count: "<<fs.st_blocks<<endl;
		cout<<"             Last Access Time: "<<ctime(&fs.st_atime);
		cout<<"             Last Modification Time:"<<ctime(&fs.st_mtime);
		cout<<"             Last Change Time:"<<ctime(&fs.st_ctime);
		cout<<"___________________________________________________________________"<<endl;;			
	}
	return 0;
}
