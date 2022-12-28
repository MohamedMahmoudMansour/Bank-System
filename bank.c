
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "std_types.h"
#include "bankh.h"


/*------------------------------------MACROS-----------------------------------------*/

// #define passwordGenerate						5
// #define N										                                5
#define MAX_NO_Bank_AccountID_Generator			8


/*-------------------------------------MAIN------------------------------------------*/

int main(void)
{
	Uint8 MainOption[12];
	Uint8 Option[12];
	str_nodeInfo_t dataBase1;

	create_node(&dataBase1);


	while(1)
	{
		system("cls");
		
		printf(" [ 1 ]  to open Admin window\n");
		printf(" [ 2 ] to open client window\n");
		printf("--->   ");
		scanf("%s", MainOption);
		
		
		
		if (!strcmp(MainOption, "1"))
		{
			while (1)
			{
				system("cls");
				printf("\n");
				printf("--> [ 1 ]	to create new account						                \n");
				printf("--> [ 2 ] 	if u have already an existing account 	        	\n");
				printf("--> [ 3 ]	to display information of all bank members 	\n");
				printf("--> [ 0 ]  to return	(admin menu will be terminated)	\n");
				printf("--> ");
				scanf("%s", Option);
				if(!strcmp(Option, "1"))
				{
					system("cls");
					createNewAccount(&dataBase1);
					sleep(10);
				}
				else if(!strcmp(Option, "2"))
				{
					vidLogin(&dataBase1);
				}
				else if(!strcmp(Option, "3"))
				{
					display_AccountInfo(&dataBase1);
					sleep(10);
				}
				else if(!strcmp(Option, "0"))
				{
					break;
				}
				else 
				{
					//MISRA RULES
				}
				// system("timeout /t 5000");
			
				
			}
		}
		else if(!strcmp(MainOption, "client"))
		{
			system("cls");
			while (1)
			{
				system("cls");
				printf("\n");
				printf(">> [1]	        to login to your account			 	        	\n");
				printf(">> [0]  	        client menu will be terminated				\n");
				printf(">> ");
				scanf("%s", Option);
				if(!strcmp(Option, "[1]"))
				{
					vidClientLogin(&dataBase1);
				}
			}
		}
		else 
		{

		}
	}
	return 0;
}



void createNewAccount(str_nodeInfo_t* strNode)
{
	Uint8* myPass;
	Uint8* bankAccount_ID;
	myPass = randomPasswordGeneration(); 
	bankAccount_ID = randomAccountIDGeneration();
	create_data(strNode, myPass, bankAccount_ID);
	printf("you sucessfully created new account :) and \n");
	printf("your password is: %s \n", myPass);
	printf("your Bank Account ID is: %s \n", bankAccount_ID);
}




void vidLogin(str_nodeInfo_t* strNode)
{
	Uint8 userName[15];
	Uint8* passWord ;
	Uint8* myPass;
	Uint8 Choice[12];
	Uint8 count = 0, flag = 0;

	printf("Username >> ");
	scanf("%s", userName);
	myPass = Is_userNameFound(strNode,userName);
	while (myPass == NULL)
	{
		printf("Invalid username \n");
		printf("Username >> ");
		scanf("%s", userName);
		myPass = Is_userNameFound(strNode,userName);
	}
	printf("Password >> ");
	passWord = enter_password();
	while (count <= 3 && !flag)
	{
		count++;
		if(!strcmp(myPass, passWord))
		{
			system("cls");
			printf("\n\n------------------------------------------------------\n");
			printf("you are loggned in :) \n");
			printf("------------------------------------------------------\n\n");
			system("timeout /t 5");
			while (1)
			{
				system("cls");
				printf(">> < 1 > 	to make transaction 		\n");
				printf(">> < 2 > 	to change account status 	\n");
				printf(">> < 3 > 	\tto get cash 				\n");
				printf(">> < 4 > 	to deposite in account 		\n");
				printf(">> < 0 > 	return to main menu 		\n");
				printf(">> ");
				scanf("%s", Choice);

				if (!strcmp(Choice, "1"))
				{
					vidMakeTransaction(strNode);
				}
				else if(!strcmp(Choice, "2"))
				{
					vidChangeAccountStatus(strNode);
				}
				else if(!strcmp(Choice, "3"))
				{
					vidGetCash(strNode);
				}
				else if(!strcmp(Choice, "4"))
				{
					vidDeposit(strNode);
				}
				else if(!strcmp(Choice, "0"))
				{
					break;
				}
				else {/*MISRA RULES*/}
				system("timeout /t 500");
			}

			flag = 1;
		}
		else if(strcmp(myPass, passWord) != 0 && count<3)
		{
			printf("\n----------Wrong password ..try again----------\n");
			printf("Password >> ");
			passWord = enter_password();
		}
	}

	if(count == 4){ printf("\n"); printf("\n #### your account is terminated #### \n"); }
}


void vidClientLogin(str_nodeInfo_t* strNode)
{
	Uint8 userName[15];
	Uint8* passWord ;
	Uint8* myPass;
	Uint8 Choice[12];
	Uint8 count = 0, flag = 0;

	printf("Username >> ");
	scanf("%s", userName);
	myPass = Is_userNameFound(strNode,userName);
	while (myPass == NULL)
	{
		printf("Invalid username \n");
		printf("Username >> ");
		scanf("%s", userName);
		myPass = Is_userNameFound(strNode,userName);
	}
	printf("Password >> ");
	passWord = enter_password();
	while (count <= 3 && !flag)
	{
		count++;
		if(!strcmp(myPass, passWord))
		{
			system("cls");
			printf("\n\n------------------------------------------------------\n");
			printf("you are loggned in :) \n");
			printf("------------------------------------------------------\n\n");
			system("timeout /t 5");
			while (1)
			{
				system("cls");
				printf(">> <transaction> 		to make transaction 		\n");
				printf(">> <changePassword>	 	to change password 			\n");
				printf(">> <cash> 	\tto get cash 				\n");
				printf(">> <deposit> 		to deposite in account 		\n");
				printf(">> <return> 		return to main menu 		\n");
				printf(">> ");
				scanf("%s", Choice);

				if (!strcmp(Choice, "transaction"))
				{
					vidMakeTransaction(strNode);
				}
				else if(!strcmp(Choice, "changePassword"))
				{
					vidChangePasswordNod(strNode);
				}
				else if(!strcmp(Choice, "cash"))
				{
					vidGetCash(strNode);
				}
				else if(!strcmp(Choice, "deposit"))
				{
					vidDeposit(strNode);
				}
				else if(!strcmp(Choice, "return"))
				{
					break;
				}
				else {/*MISRA RULES */}
				system("timeout /t 500");
			}

			flag = 1;
		}
		else if(strcmp(myPass, passWord) != 0 && count<3)
		{
			printf("\n----------Wrong password ..try again----------\n");
			printf("Password >> ");
			passWord = enter_password();
		}
	}

	if(count == 4){ printf("\n"); printf("\n #### your account is terminated #### \n"); }
}




str_node_t* CurrentNode(str_nodeInfo_t* strNode, Uint8* u8BankIDCopy)
{
	str_node_t* local_strCurrntNode = strNode->head;
	Uint8 local_u8Flag = 0;

	while(local_strCurrntNode)
	{

		if(!strcmp(local_strCurrntNode->bankAccountID,u8BankIDCopy))
		{
			local_u8Flag = 1;
			return local_strCurrntNode;
		}
		else 
		{
			local_strCurrntNode = local_strCurrntNode->next;
		}
	}
	if (local_u8Flag == 0) { return NULL; }
}



void vidChangePasswordNod(str_nodeInfo_t* strNode)
{
	Uint8 local_pu8MyBankID[15];
	Uint8 local_u8MyNewPassword[15];
	str_node_t* local_strCurrntNode;

	printf("What is your Bank ID >> ");
	scanf("%s", local_pu8MyBankID);

	printf("What is your new password >> ");
	scanf("%s", local_u8MyNewPassword);
	local_strCurrntNode = CurrentNode(strNode, local_pu8MyBankID);

	strcpy(local_strCurrntNode->password, local_u8MyNewPassword);
}


void vidChangeAccountStatus(str_nodeInfo_t* strNode)
{
	Uint8 local_pu8AccountStatus[15];
	Uint8 local_pu8MyBankID[15];
	str_node_t* local_strCurrntNode;

	printf("choose the following status 				\n");
	printf("<active> 		Active your account  		\n");
	printf("<restricted>		Restrict your account   	\n");
	printf("<closed> 		Close your account 			\n");
	printf("Account status >> ");
	
	

	printf("What is your Bank ID >> ");
	scanf("%s", local_pu8MyBankID);
	printf("Change the status to >> ");
    scanf("%s", local_pu8AccountStatus);

	local_strCurrntNode = CurrentNode(strNode, local_pu8MyBankID);
	strcpy(local_strCurrntNode->accountStatus, local_pu8AccountStatus);
}




void vidGetCash(str_nodeInfo_t* strNode)
{
	Uint32 local_u16CashNo;
	Uint8 local_u8Flag = 0;
	Uint8 local_pu8MyBankID[15];
	str_node_t* local_strCurrntNode;

	printf("What is your Bank ID >> ");
	scanf("%s", local_pu8MyBankID);
	printf("What amount of money to be withdrawn >> ");
	scanf("%u", &local_u16CashNo);
	
	local_strCurrntNode = CurrentNode(strNode, local_pu8MyBankID);

	if(local_strCurrntNode == NULL)
	{
		printf("Invalid bank ID");
	}
	else 
	{
		if(local_strCurrntNode->balance >= local_u16CashNo)
		{
			local_strCurrntNode->balance -=  local_u16CashNo;
			printf("\nYou withdrawed : %u , and your Account balance : %u \n", local_u16CashNo, local_strCurrntNode->balance);
		}
		else if(local_strCurrntNode->balance < local_u16CashNo)
		{
			printf("you don't have enough money\n");
		}
		else 
		{
			//MISRA RULES
		}
	}
}





void vidDeposit(str_nodeInfo_t* strNode)
{
	Uint32 local_u16DepNo;
	Uint8 local_pu8MyBankID[15];
	Uint8 local_u8Flag = 0;
	str_node_t* local_strCurrntNode;

	printf("What is your Bank ID >> ");
	scanf("%s", local_pu8MyBankID);
	printf("What amount of money to be deposited >> ");
	scanf("%u", &local_u16DepNo);
	local_strCurrntNode = CurrentNode(strNode, local_pu8MyBankID);

	if(local_strCurrntNode == NULL)
	{
		printf("Invalid bank ID");
	}
	else 
	{
		if(!strcmp(local_strCurrntNode->accountStatus, "active"))
		{
			local_strCurrntNode->balance += local_u16DepNo;
			printf("\nYou deposited : %u , and your Account balance : %u \n", local_u16DepNo, local_strCurrntNode->balance);
		}
		else if(!strcmp(local_strCurrntNode->accountStatus, "restricted"))
		{
			printf("this account is restricted");
		}
		else if(!strcmp(local_strCurrntNode->accountStatus, "closed"))
		{
			printf("this account is closed");
		}
		else 
		{
			//MISRA RULES
		}
	}
}



void vidMakeTransaction(str_nodeInfo_t* strNode)
{
	Sint8 local_pu8BankAccountID[MAX_NO_Bank_AccountID_Generator];
	
	Uint32 local_u8MoneyAmount;

	printf("\t\tHello there :)\n\n");
	printf("There are all IDS on our system \n");
	printf("------------------------------------------\n");
	display_BankAccountIDS(strNode);
	printf("------------------------------------------\n");
	printf("please enter Bank Account ID that you want to transfer money to >> ");
	scanf("%s", local_pu8BankAccountID);
	printf("please enter amount of money >> ");
	scanf("%u", &local_u8MoneyAmount);
	Is_BankAccountIDFound(strNode, local_pu8BankAccountID, local_u8MoneyAmount);

	printf("There are all IDS on our system \n");
	printf("------------------------------------------\n");
	display_BankAccountIDS(strNode);
	printf("------------------------------------------\n");
}



Uint8* enter_password()
{
	Uint8 i = 0;
	Uint8 ch;
	static Uint8 pwd[10];
	
	
	
	while ( (ch = _getch()) != 13 )
	{
		pwd[i] = ch;
		i++;
		printf("*");
	}
	pwd[i] = '\0';
	
	return pwd;
}




Sint8* randomPasswordGeneration()
{
  
    Uint32 i = 0;
  
    Sint32 randomizer = 0;
  
 
    srand((Sint32)(time(NULL)));
  
    // Array of numbers
    Sint8 numbers[] = "0123456789";
  
    // Array of small alphabets
    Sint8 letter[] = "abcdefghijklmnoqprstuvwyzx";
  
    // Array of capital alphabets
    Sint8 LETTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
  
    
  
    // Stores the random password
    static Sint8 password[N];
  
   
    randomizer = rand() % 3;
  
    
    for (i = 0; i < N; i++) {
  
        if (randomizer == 1) {
            password[i] = numbers[rand() % 10];
            randomizer = rand() % 4;
        }
        
        else if (randomizer == 2) {
            password[i] = LETTER[rand() % 26];
            randomizer = rand() % 4;
        }
        else {
            password[i] = letter[rand() % 26];
            randomizer = rand() % 4;
        }
    }
	

	return password;
}






Sint8* randomAccountIDGeneration()
{
	
    Sint32 i = 0;
  
   
    srand((Sint8)(time(NULL)));
  
    // Array of numbers
    Sint8 numbers[] = "0123456789";

    
    static Sint8 AccountID[MAX_NO_Bank_AccountID_Generator];
  
    for (i = 0; i < MAX_NO_Bank_AccountID_Generator; i++) 
	{
		AccountID[i] = numbers[rand() % 10];
    }

	return AccountID;
}