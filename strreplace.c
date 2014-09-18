unsigned int strreplace(char *str,char ch,char rep)
{
	unsigned int n;
	for(n=0;*str;str++)
	{
		if(*str==ch)
		{
			*str=rep;
			n++;
		}
	}
	return n;
}
