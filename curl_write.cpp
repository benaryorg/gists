#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include <curl/curl.h>

size_t curl_write(void *buffer,size_t size,size_t nmemb,void *userp)
{
	char **data=(char **)userp;
	if(!*data)
	{
		*data=(char *)malloc(nmemb*size+5);
		//assert(*data);
		if(!*data)
		{
			fprintf(stderr,"Shieeet. I did not get the memory I wanted!\n");
			exit(-1);
		}
		*((int *)*data)=0;
	}
	else
	{
		char *tmp=(char *)malloc(nmemb*size+*((int *)*data)+5);
		//assert(tmp);
		if(!tmp)
		{
			fprintf(stderr,"Shieeet. I did not get the memory I wanted!\n");
			free(*data);
			exit(-1);
		}
		memcpy(tmp,*data,*((int *)*data)+4);
		free(*data);
		*data=tmp;
	}
	memcpy(*data+*((int *)*data)+4,buffer,nmemb*size);
	*((int *)*data)+=nmemb*size;
	(*data)[*((int *)*data)+4]=0;
	return nmemb*size;
}

/*
int main(int argc,char **argv)
{
	if(argc!=2)
	{
		fprintf(stderr,"Usage: %s url\n",*argv);
		return -1;
	}

	char *data=0;

	curl_global_init(CURL_GLOBAL_ALL);
	CURL *handle=curl_easy_init(); 
	assert(handle);

	curl_easy_setopt(handle,CURLOPT_URL,argv[1]);
	curl_easy_setopt(handle,CURLOPT_WRITEDATA,&data);
	curl_easy_setopt(handle,CURLOPT_WRITEFUNCTION,curl_write);

	int ret=curl_easy_perform(handle);

	printf("%s",data+4);

	free(data);
	//assert(!ret);
	return ret;
}
*/
