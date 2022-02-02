#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void)
{
	char originFile[30],
		tmp[35],ext[10],
		word[20],wWord[20],cWord[20],c;
		
	printf("Please put your file in the same directory then\n"
		"Enter The name of the file that you want to modify(Includes extension): ");
	scanf("%s",originFile);

	//open the original file
	FILE* origin = fopen(originFile,"r");
	
	//modyfing temp file name
	sscanf(originFile,"%[^.]%s",tmp,ext);
	strcat(tmp,"2");
	strcat(tmp, ext);

	//make temporary file
	FILE *tmpFile = fopen(tmp,"w");


	printf("Enter the wrong word that you want to replace: ");
	scanf("%s",wWord);

	printf("Enter the correct word: ");
	scanf("%s", cWord);

	while (fscanf(origin, "%s", word) != EOF)
	{
		if (strcmp(word,wWord) == 0)
			fprintf(tmpFile,"%s ",cWord);
		else 
			fprintf(tmpFile, "%s ", word);
	}

	//close files
	fclose(origin);
	fclose(tmpFile);

	//open it again with defferint mood
	origin = fopen(originFile, "w");
	tmpFile = fopen(tmp, "r");

	while (fscanf(tmpFile,"%c",&c) != EOF)
		fprintf(origin,"%c",c);
	
	//close files
	fclose(origin);
	fclose(tmpFile);

	//remove temp file
	remove(tmp);
	printf("replacing done you can open your file now ");



	system("pause>0");
}

