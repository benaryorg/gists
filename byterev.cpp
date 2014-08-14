#define byterev(data,len) _byterev((data),(data),((len)>0)?(len):0)

void _byterev(char *base,char *data,const unsigned int len)
{
	if(data-len<=base)
	{
		char ch=*data;
		_datarev(base,data+1,len);
		base[(base-data)+len]=ch;
	}
}
