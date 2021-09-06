#include <stdio.h>
#include <string.h>
typedef unsigned char byte;
byte alphabet[]=
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789+/";
byte *to_base64(byte data[], int size)
{
	byte *b64;
	asprintf (&b64, "");
	int i=0;
	for(;i<size;i++)
	{
		byte b=data[i];
		byte c1=b>>2;
		asprintf(&b64, "%s%c", b64, alphabet[c1]);
		byte c2=b<<6;
		c2=c2>>2;
		i++;
		if(i>=size){
			asprintf(&b64, "%s%c", b64, alphabet[c2]);
			break;
		}
		byte bb=data[i];
		byte c3=bb>>4;
		c2+=c3;
		asprintf(&b64, "%s%c", b64, alphabet[c2]);
		byte c4=bb<<4;
		c4=c4>>2;
		i++;
		if(i>=size){
			asprintf(&b64, "%s%c", b64, alphabet[c4]);
			break;
		}
		byte bbb=data[i];
		byte c5=bbb>>6;
		c4+=c5;
		asprintf(&b64, "%s%c", b64, alphabet[c4]);
		byte c6=bbb<<2;
		c6=c6>>2;
		asprintf(&b64, "%s%c", b64, alphabet[c6]);
	}
	if(strlen(b64)%4!=0)asprintf (&b64, "%s%c", b64, '=');
	if(strlen(b64)%4!=0)asprintf (&b64, "%s%c", b64, '=');
	return b64;
}
int main()
{
	byte inpt[500];
	scanf("%[^\n]%*c", inpt);
	printf("str: \"%s\"\nlength: %lu\nbase64: \"%s\"\n", 
		inpt, 
		strlen(inpt),
		to_base64(inpt, strlen(inpt)));

	return 0;
}
