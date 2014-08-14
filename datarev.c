void datarev(void *data,unsigned int nmemb,unsigned int size)
{
	int i,j;
	for(i=0;i<nmemb/2;i++)
	{
		char *a=((char *)data)+(i*size);
		char *b=((char *)data)+((nmemb-i-1)*size);
		for(j=0;j<size;j++)
		{
			*(a+j)^=*(b+j);
			*(b+j)^=*(a+j);
			*(a+j)^=*(b+j);
		}
	}
}

/*
int main(void)
{
	int arr[]={1,2,3,4};
	dataref(arr,4,sizeof(int));
	int i;
	for(i=0;i<4;i++)
	{
		printf("%d",arr[i]);
	}
	return 0;
}
*/
