
#include<stdio.h>
#include<string.h>
void hexa(char bno[10],char binary1[20][4]);
void binary(char bno[10],char binary2[17]);
struct data
{
    char ch[10];
   	char binarycode[17];
};
//assumed spaces instead of commas
//asssumed loop names don't end with a number
//int flag=0;
main()
{
	struct data d[100];
	struct data e[100];
	int i=0,j=0,x,y,z=0,k=0,it=0,b=0,flag=0;
	FILE *f1,*f2,*f3,*f4;
    char ar1[10],ar2[10],cr,s,binary1[20][4],binary2[17],tmp[5],file1[20];
    
	printf("\nEnter the source file name :-");
	scanf("%s",file1);
	f1 = fopen( file1, "r");
    f2 = fopen( "instructions.txt", "r");
    f3 = fopen( "binary.txt","w");
    f4 = fopen( "symboltable","r");
	
	if(f1==NULL)
	{
	   printf("File code.txt Not Found\n");
	   return 0;
    }
    
	if(f2==NULL)
	{
	   printf("File instructions.txt Not Found\n");
	   return 0;
    }
    
	if(f4==NULL)
	{
	   printf("File symboltable Not Found\n");
	   return 0;
    }
    
    while(fscanf(f2,"%s",ar1)!=EOF)
    {
		strcpy(d[i].ch,ar1);
    	fscanf(f2,"%s",&d[i].binarycode);
    	i++;
    }
    
	while(fscanf(f4,"%s",ar1)!=EOF)
    {
	//	it=0;
		strcpy(e[z].ch,ar1);
    	fscanf(f4,"%s",tmp);
    	printf("%s ",tmp);
    	binary(tmp,e[z].binarycode);
    	for(j=0;j<16;j++)
    	printf("%d",e[z].binarycode[j]);
		printf("\n");
		z++;
	
    }
    
	while( fscanf(f1,"%s",ar2)!= EOF )
    {      
		s=ar2[strlen(ar2)-1];
	/*	for(j=0;j<=s;j++)
		{
			if(ar2[j]==',')
			{
				cm++;
			}
		}
	*/	
		x=s;
		if(x==104)    //hex value for 'h'
		{
			hexa(ar2,binary1);
			fprintf(f3,"\n%s",binary1);
		}
		
		else if(x>47 && x<58)    //hex values for numbers 0-9
		{
			fprintf(f3," ");
			binary(ar2,binary2);
			for(y=0;y<16;y++)
			fprintf(f3,"%d",binary2[y]);
		}
		
		else
		{
			j=0,k=0;
			for(j=0;j<i;j++)
			{
		//printf("%s \n",ar2);
		//		if(ar2=="PRINT")
		//		{
		//			flag=1;
		//		}
				if(strcmp(ar2,d[j].ch)==0)
				{
					fprintf(f3,"%s",d[j].binarycode); 
					break;        
				}
			}
			for(k=0;k<i;k++)
			{	
				if(strcmp(ar2,e[k].ch)==0)
				{
					//printf("%s %s\n",ar2,e[j].ch);
					b=0;
					fprintf(f3,"\n");
					for(b=0;b<16;b++)
						fprintf(f3,"%d",e[k].binarycode[b]); 
					break;        
				}
	 		}
		}
	
/*	else
	{
		j=0;
		while(ar2[j]!='\0')
		{
			if(ar2[j]!=',')
		
		}
	}
*/
		if((cr=getc(f1))=='\n')
		fprintf(f3,"\n");
	}
	printf("\n\n######### BINARY CODE COMPLETED ##########\n\n");
	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);
}

void hexa(char bno[10],char binary1[20][4])
{  
	int i=0,j=0,x;
	char temp[20][4];
	
	while(i<(strlen(bno)-1))
	{
		
		switch(bno[i])
		{
			case 'A':	strcpy(temp[i],"1010");
						break;
			case 'B':	strcpy(temp[i],"1011");
						break;
			case 'C':	strcpy(temp[i],"1100");
						break;
			case 'D':	strcpy(temp[i],"1101");
						break;
			case 'E':	strcpy(temp[i],"1110");
						break;
			case 'F':	strcpy(temp[i],"1111");
						break;
			case '0':	strcpy(temp[i],"0000");
						break;
			case '1':	strcpy(temp[i],"0001");
						break;
			case '2':	strcpy(temp[i],"0010");
						break;
			case '3':	strcpy(temp[i],"0011");
						break;
			case '4':	strcpy(temp[i],"0100");
						break;
			case '5':	strcpy(temp[i],"0101");
						break;
			case '6':	strcpy(temp[i],"0110");
						break;																										
			case '7':	strcpy(temp[i],"0111");
						break;
			case '8':	strcpy(temp[i],"1000");
						break;
			case '9':	strcpy(temp[i],"1001");
						break;						
			default:	i--;
						x=1;
						break;
		}
		i++;
		if(x==1)
		break;
	}
//	if(flag!=1)
//	{
	if(i!=4)
	{
		for(j=0;j<4-i;j++)
		strcpy(binary1[j],"0000");
		for(j=4-i;j<4;j++)
		strcpy(binary1[j],temp[j-i]);
	}
	else
	{
		for(j=0;j<4;j++)
		strcpy(binary1[j],temp[j]);
	}
		
/*	else
	{
		for(j=0;j<4;j++)
		strcpy(binary1[j],temp[j]);
	}
*/		
}

void binary(char bno[5],char binary2[17])
{  
	int i=0,j=0,x,s,y=0,z;
	int num,temp[16];
	for(j=0;j<16;j++)
	temp[j]=0;
	j=0;
	s=strlen(bno)-1;
	
	for(i=0;i<=s;i++)
	{
		x=bno[i];
		z=x-48;
		num=y*10+z;
		y=num;
	}
	
	while(num!=0)
	{
		temp[j]=num%2;
		num=num/2;
		j++;
	}
	
	j=0;
	for(j=0;j<16;j++)
	binary2[j]=temp[15-j];
}
