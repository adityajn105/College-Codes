#include <iostream>
#include <curl/curl.h>
#include <string.h>
#include <sys/resource.h>
#include <unistd.h>
#include <sstream>
#include <fstream>
using namespace std;

static bool info=false;
static size_t writeBodyFunction(void *contents, size_t size, size_t nmemb, void *userp)
{
    char* pchar=(char*)contents;
	cout<<"Body"<<endl;
	fstream body;
	body.open("body.txt");
	for(int i=0;i<nmemb;i++){
		body<<*pchar;
		pchar++;
	}
	cout<<(char*)contents;
	body.close();
    return size * nmemb;
}

int static writeHeaderFunction( void *contents, int size, int nmemb, void *userp)
{ 
	string respHead((char*)contents);
	if(!info){
		cout<<"Status Line"<<endl;
		cout<<"Version : "<<respHead.substr(5,3)<<endl;
		cout<<"Status Code : "<<respHead.substr(9,3)<<endl;
		cout<<"Phrase : "<<respHead.substr(13,2)<<endl<<endl;
		info=true;	
		cout<<"Header"<<endl;
	}
	cout<<respHead;
	std::ofstream out("header.txt");
    out << respHead;
    out.close();

    return size * nmemb; 
}

int main(void)
{
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();

    if(curl) {
    	cout<<"----Http Request----"<<endl;
    	cout<<"Request Line "<<endl;
    	cout<<"Method :GET"<<endl;
    	string url="http://www.libcurl.org";
    	cout<<"URL : "<<url<<endl;
   		cout<<"HTTP Version :1.1"<<endl<<endl;

   		cout<<"Header "<<endl;
    	string accept="Accept :text/plain";
    	string ctype="Content-Type :text/html";
    	cout<<accept<<endl<<ctype<<endl<<endl;

    	cout<<"Body \nNot Required"<<endl<<endl;

    	struct curl_slist *headers=NULL;
 		curl_slist_append(headers,ctype.c_str());
 		curl_slist_append(headers,accept.c_str());

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeBodyFunction);
        curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, writeHeaderFunction);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

       	cout<<"----Http Response----"<<endl;

        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        curl_easy_cleanup(curl);
    }
    return 0;
}