size_t strreplace(char *str,char ch,char rep)
{
	size_t n;
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
