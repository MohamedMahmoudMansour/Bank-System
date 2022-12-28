#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "bankh.h"




void create_node(str_nodeInfo_t* strPtr)
{
    str_nodeInfo_t* pn = strPtr;
    pn -> head = NULL;
    pn -> size = 0;
}


void create_data(str_nodeInfo_t* strPtr1, Uint8* pass, Uint8* u8BankAccountID)
{
    str_node_t* pn = (str_node_t*) malloc(sizeof(str_node_t));
	Uint8 flag=1;
	Uint8 local_ID[15];
    strcpy(pn->accountStatus, "active");
    strcpy(pn->password, pass);
    strcpy(pn->bankAccountID, u8BankAccountID);

	printf("Enter your name    >> ");
    scanf("%s", &pn->name); 
    printf("Enter your address >> ");
    scanf("%s", &pn->addr);
    printf("Enter your age     >> ");
    scanf("%u", &pn->age);

    if(pn->age < 21)
    {
		
		while(flag!=0)
		{
			
			printf("Enter Gurdian National ID >> ");
			scanf("%s", local_ID);
			strcpy(pn->GurdianID,local_ID);
			if((strlen(pn->GurdianID))!=14)
			{
				printf("Invalid ID , Please Try Again , ID Must Be 14 Numbers\n");
				
			}
			else
			{
				flag=0;
			}
			
		}

		
    }
    else if(pn->age >= 21)
    {
		while(flag!=0)
		{
			
			printf("Enter National ID >> ");
			scanf("%s", local_ID); 
			strcpy(pn->NationalID ,local_ID);
			if((strlen(pn->NationalID))!=14)
			{
				printf("Invalid ID , Please Try Again , ID Must Be 14 Numbers\n");
				
			}
			else
			{
				flag=0;
			}
			
		}
       
    }
    else 
    {
        //MISRA RULES
    }
    printf("Enter your Account balance >> ");
    scanf("%u", &pn->balance);

    pn->next = strPtr1->head;
    strPtr1->head  = pn;

    strPtr1->size+=1;
}


Uint8* Is_userNameFound(str_nodeInfo_t* nd, Uint8* name)
{
    Uint8* password = "";
    str_node_t* count = nd->head;
    while(count)
    {
        if(!strcmp(count->name, name))
        {
            password = count->password;
            break;
        }
        else if(strcmp(count->name, name) != 0)
        {
            password = NULL;
            count = count->next;
        }
        else
        {
            //MISRA RULES
        } 
    }

    return password;
}


void Is_BankAccountIDFound(str_nodeInfo_t* str_nd, Sint8* s8_BankAccountIDCopy, Uint32 u32_MoneyAmountCopy)
{
    
    str_node_t* local_strCount = str_nd->head;
    Uint16 flag = 0;
    Uint8 local_pu8MyBankID[15];
    str_node_t* local_strCurrntNode;

    printf("What is your Bank ID >> ");
	scanf("%s", local_pu8MyBankID);

    local_strCurrntNode = CurrentNode(str_nd, local_pu8MyBankID);
    
    while(local_strCount)
    {
        if( ( !strcmp(local_strCount->bankAccountID, s8_BankAccountIDCopy) ) && ( local_strCurrntNode->balance > u32_MoneyAmountCopy ) )
        {
            flag = 1;
            
            if (!strcmp(local_strCount->accountStatus, "active"))
            {
                local_strCount->balance += u32_MoneyAmountCopy;
                local_strCurrntNode->balance -= u32_MoneyAmountCopy;
            }
            else if(!strcmp(local_strCount->accountStatus, "restricted"))
            {
                printf("this account is restricted you can't transfer money\n");
            }
            else if (!strcmp(local_strCount->accountStatus, "closed"))
            {
                printf("this account is closed you can't transfer money\n");
            }
            else 
            {
				//MISRA RULES
            }
            break;
        }
        else
            local_strCount = local_strCount->next;
    }
    if (flag == 0)
    {
        printf("Account ID doesn't exist");
    }

   

}






void display_AccountInfo(str_nodeInfo_t* str_nodeCopy)
{
    str_node_t* local_strCount = str_nodeCopy->head;
    Uint8 local_u8Count = 0;
    while(local_strCount != NULL)
    {
        local_u8Count += 1;
        printf("----------------------------------- client %d information -----------------------------\n", local_u8Count);
        printf("Name                : %s \n",  local_strCount->name );
        printf("Address             : %s \n",  local_strCount->addr);
        printf("Bank Account Status : %s \n ", local_strCount->accountStatus);
        printf("Bank Account ID     : %s \n",  local_strCount->bankAccountID);
        printf("Age                 : %u \n ", local_strCount->age);
        if(local_strCount->age < 21)
        {
            printf("Gurdian national ID : %u \n", local_strCount->GurdianID);
        }
        else if(local_strCount->age >= 21)
        {
            printf("National ID         : %u \n", local_strCount->NationalID);
        }
        else { /*MISRA RULES*/}

        printf("Account balance     : %u \n", local_strCount->balance);

        printf("---------------------------------------------------------------------------------------\n\n");
        
        local_strCount = local_strCount->next;
    } 
}


void display_BankAccountIDS(str_nodeInfo_t* str_nodeCopy)
{
  	str_node_t* local_strCount = str_nodeCopy->head;
    Uint8 local_u8Count = 0;

    while(local_strCount)
    {
        local_u8Count += 1;
        printf("----------------------------------- client %d ID and his balance -----------------------------\n", local_u8Count);
        printf("%s Banck Account ID is %s \n", local_strCount->name ,local_strCount->bankAccountID);
        printf("%s 's balance on his account is %u \n",local_strCount->name , local_strCount->balance);
        printf("---------------------------------------------------------------------------------------\n\n");
        local_strCount = local_strCount->next;
    }  
}