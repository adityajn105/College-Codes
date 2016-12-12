#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//function declaration
long get_avail_mem()
{
FILE *fp; //declaration of file pointer
char buffer[1024];	//declaration of buffer
int i;
size_t bytes_read;	//size_t is int type
char* match;
long avail_mem;
//storing the display of meminfo in a file
system("cat /proc/meminfo > outfile");
//open the file in read mode (FILE *fopen(const char *path, const char *mode))

fp=fopen("outfile","r");	//return value is FILE pointer
//size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
bytes_read=fread(buffer,1,sizeof(buffer),fp);	//return value is a short item count (or zero).
fclose(fp);
buffer[bytes_read]='\0';
match=strstr(buffer,"MemFree");
if (match==NULL)
{
printf("\n Match not found\n");
exit(0);
}
//int sscanf(const char *str, const char *format, ...)
sscanf(match,"MemFree: %ld KB",&avail_mem);
return avail_mem;
}
int main()
{
printf("Avau=ilable free memory is %ld KB",get_avail_mem());
return 0;
}
