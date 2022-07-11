#include<stdio.h>
#include<conio.h>
#include<stdlib.h> 
#include<string.h>
struct student
{
	int roll_number;
	char first_name[30];
	char secound_name[40];
	char date[20];
	int grade;
};
struct staff
{
	int id_number;
	char firse_name[50];
	char secound_name[50];
	int date[20];
	int phone_number;
	
};
void student_data()
{
	
	system("cls");
	struct student data;
	int enter1;
	printf("\n\t________ manage student data__________");
	printf("\n\n\n\tPRESS 1: TO SAVE STUDENT DATA");
	printf("\n\n\tPRESS 2: TO DISPLAY STUDENT DATA");
	printf("\n\n\tPRESS 3: TO SEARCH STUDENT DATA");
	printf("\n\n\tPRESS 4: TO DETELE STUDENT DATA");
	printf("\n\n\tPRESS 5: TO UPDATA STUDENT ROLL NUMBBER");
	printf("\n\n\tPRESS 6: FOR EXIST");
	printf("\n\n\tENTER...");
	scanf("%d",&enter1);
	switch(enter1)
	{
		case 1:
			system("cls");
			FILE *fp;
			fp = fopen("student_data.txt","a");
				printf("\n\t______ save student data ________");
				printf("\n\n\tENTER FIRST NAME...");
				scanf("%s",&data.first_name);
				fprintf(fp,"\n%s",data.first_name);
				printf("\n\n\tENTER SECOUND NAME...");
				scanf("%s",&data.secound_name);
				fprintf(fp,"\n%s",data.secound_name);
				printf("\n\n\tENTER ROLL NUMBER...");
				scanf("%d",&data.roll_number);
				fprintf(fp,"\n%d",data.roll_number);
				printf("\n\n\tENTER GRADE...");
				scanf("%d",&data.grade);
				fprintf(fp,"\n%d",data.grade);
				printf("\n\n\tENTER TODAY DATE...");
				scanf("%s",&data.date);
				fprintf(fp,"\n%s",data.date);
				if(fp==NULL)
				{
					printf("\nfile can not open");
				}
			    {
			    	system("cls");
			    	printf("\n\t\tone student data save successfully!");
		printf("\n\t__________________________________________________");
			    	printf("\n\n\tfirst name     :%s",data.first_name);
			    	printf("\n\n\tsecound name   :%s",data.secound_name);
			    	printf("\n\n\troll number    :%d",data.roll_number);
			    	printf("\n\n\tgrade          :%d",data.grade);
			    	printf("\n\n\trecord date    :%s",data.date);
			    	
			    	fclose(fp);
			    	
				}
			break;
			case 2:
				{
				system("cls");
              FILE *fp;
              fp = fopen("student_data.txt","r");
              if(fp == NULL)
              {
              	printf("\n file can not be open");
			  }
              while(fread(&data,sizeof(struct student),1,fp))
              {
              	system("cls");
              	printf("\n\t\tdata display successfully!!");
              		printf("\n\n\tfirst name     :%s",data.first_name);
			    	printf("\n\n\tsecound name   :%s",data.secound_name);
			    	printf("\n\n\troll number    :%d",data.roll_number);
			    	printf("\n\n\tgrade          :%d",data.grade);
			    	printf("\n\n\trecord date    :%s",data.date);
			    	printf("\n_____________________________________");
			  }
        fclose(fp);
  
}
  
				break;
				case 3:
					{
					system("cls");
					int number;
					FILE *fp;
					fp = fopen("student_data.txt","r");
					printf("\n\t\t______ search student data _____");
					printf("\n\n\n\t\tENTER ROLL NUMBER...");
					scanf("%d",&number);
					while(fread(&data,sizeof(struct student),1,fp))
					{
						if(number  == data.roll_number)
						{
					printf("\n\n\tfirst name     :%s",data.first_name);
			    	printf("\n\n\tsecound name   :%s",data.secound_name);
			    	printf("\n\n\troll number    :%d",data.roll_number);
			    	printf("\n\n\tgrade          :%d",data.grade);
						}
						else
						{
							printf("\nyou enter wrong roll number");
						}
						fclose(fp);
					}
				}
				
					break;
					case 4:
						{
						system("cls");
						int roll, found = 0;
						FILE *fp1, *fp;
						fp = fopen("student_data.txt","r");
						fp1 = fopen("tem.txt","w");
			printf("\n\t_________ detele student record___________");
			printf("\n\n\n\tENTER ROLL NUMBER");
			scanf("%d",&roll);			
			while(fread(&data,sizeof(struct student),1,fp))
			{
				if(roll == data.roll_number)
				{
					found = 1;
				}
				else
				{
					fwrite(&data,sizeof(struct student),1,fp1);
				}
				fclose(fp);
				fclose(fp1);
						}			
					if(found)
					{
						remove("student_data.txt");
						rename("tem.txt","student_data.txt");
						printf("\n\tdata detele successfully");
						}	
						
					}
						break;
						case 5:
						{
						
							int found = 0;
							FILE *fp, *fp1;
							int enter1;
							fp = fopen("student_data.txt","r+");
							fp1 = fopen("tempp.txt","w+");
							printf("\n\tENTER THE ROLL NUMBER YOU WANT TO UPDATE");
							printf("\n\t\tENTER...");
							scanf("%d",&enter1);
							if(fp == NULL)
							{
								printf("file can not be open");
							}
							while(fread(&data,sizeof(struct student),1,fp))
							{
								if(data.roll_number != enter1);
								found = 1;
							}
				fwrite(&data,sizeof(struct student),1,fp1);
					  fclose(fp1);
			   fclose(fp);
					  if(found)
					        {
					    	remove("student_data.txt");
					  	rename("tempp.txt","student_data.txt");	printf("\n\tone student data updated successfully!!");
							}
						}
						break;
							case 6:
								{
								main();
							}
								break;
								default:
									printf("\n\tyou enter wrong option");
	}
	
	
}
void staff_data()
{
	struct staff data;
		system("cls");
	int enter2;
	printf("\n\t________ manage staff data__________");
	printf("\n\n\n\tPRESS 1: TO SAVE STAFF DATA");
	printf("\n\n\tPRESS 2: TO DISPLAY STAFF DATA");
	printf("\n\n\tPRESS 3: TO SEARCH STAFF DATA");
	printf("\n\n\tPRESS 4: TO DETELE STAFF DATA");
	printf("\n\n\tPRESS 5: TO EXIST");	
	printf("\n\n\tENTER...");
	scanf("%d",&enter2);
	switch(enter2)
	{
		case 1:
			{
				system("cls");

			FILE *fp;
			fp = fopen("staff_data.txt","a");
			printf("\n\t______save staff data_______");
			printf("\n\n\t\tENTER FIRST NAME...");
			scanf("%s",&data.firse_name);
			printf("\n\n\t\tENTER SECOUND NAME...");
			scanf("%s",&data.secound_name);
			printf("\n\n\t\tENTER PHONE NUMBER...");
			scanf("%d",&data.phone_number);
			printf("\n\n\t\tENTER ID...");
			scanf("%d",&data.id_number);
			printf("\n\n\t\tENTER DATE...");
			scanf("%s",&data.date);
			if(fp == NULL)
			{
				printf("\n file can not open");
			}
			fwrite(&data,sizeof(struct staff),1,fp);
			{
				    printf("\n\t\tdata has been saved successfully");
				  	printf("\n\n\tfirst name     :%s",data.firse_name);
			    	printf("\n\n\tsecound name   :%s",data.secound_name);
			    	printf("\n\n\tphone number   :%d",data.phone_number);
			    	printf("\n\n\tID             :%d",data.id_number);
			    	printf("\n\n\trecord date    :%s",data.date);
			    	printf("\n_____________________________________");
			    	fclose(fp); 
			}
			break;
			case 2:
				{
					system("cls");
					FILE *fp;
					fp = fopen("staff_data.txt","r");
					printf("\n\n\t________ staff data display successfully ________");
					while(fread(&data,sizeof(struct staff),1,fp))
				{
					printf("\n\n\tfirst name     :%s",data.firse_name);
			    	printf("\n\n\tsecound name   :%s",data.secound_name);
			    	printf("\n\n\tphone number   :%d",data.phone_number);
			    	printf("\n\n\tID             :%d",data.id_number);
			    	printf("\n\n\trecord date    :%s",data.date);
			    	printf("\n_____________________________________");
				}
					fclose(fp);
					
				}
				break;
				case 3:
					{
						system("cls");
						int enter2;
						FILE *fp;
						fp = fopen("staff_data.txt","r");
						printf("\n\t\t________search staff data_________");
						printf("\n\n\tENTER THE STAFF ID NUMBER");
						printf("\n\n\tENTER...");
						scanf("%d",&enter2);
						while(fread(&data,sizeof(struct staff),1,fp))
						{
							if(enter2 == data.id_number)
							{
					printf("\n\t\t______ search successful_______");
					printf("\n\n\tfirst name     :%s",data.firse_name);
			    	printf("\n\n\tsecound name   :%s",data.secound_name);
			    	printf("\n\n\tphone number   :%d",data.phone_number);
			    	printf("\n\n\tID             :%d",data.id_number);
			    	printf("\n\n\trecord date    :%s",data.date);
			    	printf("\n_____________________________________");
							}
							else
							{
								int one;
								printf("\n\n\tyou enter wrong id");
								printf("\n\n\tpress 1: to try again...");
								scanf("%d",&one);
								if(one == 1)
								{
								void staff_data();	
								}
							}
						}
						
						
						
						
						
						
					}
					break;
					case 4:
						{
					system("cls");	
					int enter3, found =0;
					FILE *fp,*fp1;
					fp = fopen("staff_data.txt","r");
					fp1 = fopen("tempp.txt","w");
					printf("\n\t\t_______detele staff data________");
					printf("\n\n\tENTER THE ID OF THE STAFF DATA YOU WANT OF DETELE");
					printf("\n\n\tENTER...");
					scanf("%d",&enter3);
					while(fread(&data,sizeof(struct staff),1,fp))
					{
						found = 1;
					}
					fwrite(&data,sizeof(struct staff),1,fp1);
					fclose(fp1);
					fclose(fp);
					
						if(found)
						{
							remove("staff_data.txt");
							rename("tempp.txt","staff_data.txt");
							printf("\n\tone staff data has been deteled successfully!!");
						}
					}
						
						break;
	}
	}
}
	int main()
	{
	system("cls");
	int num = 123;
	printf("\n\n\tENTER THE SCHOOL CODE TO LONGIN THE DATA BASE");
	printf("\n\n\tENTER...");
     	scanf("%d",&num);
	 
	if(num == 123)
	{
	
		int enter,back;
	do{ 
	struct staff data1;
	struct 	student data;
	system("cls");
	printf("\n\n\t\tWELCOME TO SVIET MANAMEGEMENT SYSTEM");
	printf("\n\t________________________________________________");
	printf("\n\n\t\t\tMENU");
	printf("\n\n\tPRESS 1: TO MANAGEMENT STUDENT DATA");
	printf("\n\n\tPRESS 2: TO MANAGEMENT STAFF DATA");
	printf("\n\n\tPRESS 3: FOR EXIST");
	printf("\n\n\tENTER...");
	scanf("%d",&enter);
	switch(enter)
	{
	case 1:
		
		do{
		student_data();
			printf("\n____________________________________");
	    	printf("\npress 1: for MENU");
			printf("\npress 2: to management student data");
			printf("\nENTER...");
	     	scanf("%d",&back);
	}while(back == 2);
	//	main();

		break;
		case 2:
			do{
		staff_data();
			printf("\n____________________________________");
	    	printf("\npress 1: for MENU");
			printf("\npress 2: to management student data");
			printf("\nENTER...");
	     	scanf("%d",&back);
	}while(back == 2);
			break;
			case 3:
				system("cls");
				printf("\n\n\tTHANK YOU FOR YOUR VISIT");
				break;
				default:
					printf("\n\tyou selete wrong option");
		
	}
}while(back == 1);
}
else
{
	printf("\n\tyou enter wrong code");
	printf("\n\n\t contant the developer 9988596591");
}
	return 0;
}
