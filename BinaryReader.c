#include <stdio.h>
#include <string.h>

char *ByteToBinary(unsigned char inputByte)
{
	//printf("%c:", inputByte);
	int i = inputByte;
	
	int bitplace = 128;

	char *stringplace = "0";
	char retstring[9];
	retstring[0] = '\0';	
	
	while(bitplace >= 1)
	{
		//printf("%d>%d?", i, bitplace); 
		if( i >= bitplace )
		{
			i = i - bitplace;
			stringplace = "1";
		}
		else
			stringplace = "0";
		bitplace = bitplace/2;
		strcat(retstring, stringplace);
		printf("%s",stringplace);
	}
	char* retval = retstring;
	return retval;
	
}
void ConvertToBinaryText(char* inputfilename, char* outputfilename)
{
	unsigned char buff[255];
	FILE *inputfilestream;
	int bytesread = 0;

	char *currentbyte = "\0";
	inputfilestream = fopen(inputfilename, "rb");
	while(!feof(inputfilestream))
	{
		bytesread = fread(buff, 1, sizeof(buff), inputfilestream);
		//printf("(%d)", bytesread);
		for(int i = 0; i < bytesread; i++)
		{
			//printf("%c: ", buff[i]);
			currentbyte = ByteToBinary(buff[i]);
			printf("%s ", currentbyte);
		}
	}
	fclose(inputfilestream);
}
int main(int argc, char **argv)
{

	char *inputfilename;
	char *outputfilename;

	//printf("%d:  ", argc);
	if(argc > 1)
		inputfilename = argv[1];
	else
		inputfilename = "firstfile.bin";

	if(argc > 2)
		outputfilename = argv[2];
	else
		outputfilename = "";

	ConvertToBinaryText(inputfilename, outputfilename);

	printf("\n");
  	return 0;
}
