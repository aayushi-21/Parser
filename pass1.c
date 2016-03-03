#include <stdio.h>
#include <string.h>
#define SIZE 1000
main()
{
	FILE *f1,*f2;
	char file1[SIZE],file2[SIZE];
	//printf("Enter the source file name:");
	//scanf("%s",file1);
 		f1=fopen("code.txt","r");
	//printf("Enter the designation file name:");
	//scanf("%s",file2);
		f2=fopen("symboltable","w");
	int ilc=0,len=0,i,j,flag1,flag2,temp;
	char arr[SIZE],arr1[SIZE];
	char opcode[13][10]={"LVI","MVI","ADDI","SUBI","MULI","DIVI","STORE","LOAD","GZ","GNZ","GC","GNC","GOTO"};
	while(fgets(arr,SIZE,f1)!=NULL)
	{
	 	flag1=0;j=0;flag2=0;
		len=strlen(arr);
		for(i=0;i<len;i++)
			arr1[i]='\0';
		for(i=0;i<len;i++)
		{
			if(arr[i]==':')
			{
				flag1=1;
				temp=i;
				i=i+1;
				while((arr[i]==' '||arr[i]=='\t'))
					i++;
				while((arr[i]!=' ')&&(arr[i]!='\t'))
				{
					arr1[j]=arr[i];
					j++;
					i++;
				}
				for(j=0;j<13;j++)
				{
					if(strcmp(arr1,opcode[j])==0)
					{
						flag2=1;
						break;
					}
				}
				break;
			}
		}
		if(flag1==1)
		{
			for(j=0;j<temp;j++)
			fprintf(f2,"%c",arr[j]);
			fprintf(f2," %d\n",ilc);
		}
		if(flag1==0)
		{
			i=0;j=0;
			while((arr[i]==' ')||(arr[i]=='\t'))
			i++;
			arr1[j]=arr[i];
			j++;
			i++;
			while((arr[i]!=' ')&&(arr[i]!='\t'))
			{
				arr1[j]=arr[i];
				j++;
				i++;
			}
			for(j=0;j<13;j++)
			{
				if(strcmp(arr1,opcode[j])==0)
				{
					flag2=1;
					break;
				}
			}
		}
		if(flag2==0)
		ilc=ilc+1;
		else
		ilc=ilc+2;
	}
	fclose(f1);
	fclose(f2);
}
