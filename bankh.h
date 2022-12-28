#ifndef BANKH_H_
#define BANKH_H_


#include "std_types.h"


typedef struct node
{
	Uint8 name[50];
	Uint8 addr[50];
	Uint8 accountStatus[20];
	Uint8 NationalID[15];
	Uint8 GurdianID[15];
	Uint8 password[11];

	Sint8 bankAccountID[11];
	
	Uint32 age;
	Uint32 balance;
	

	struct node* next;
}str_node_t;


typedef struct 
{
	str_node_t* head;
	Uint32 size;
	
}str_nodeInfo_t;




/*-------------------------------------------------<CREATE NODE>------------------------------------------*/
void create_node(str_nodeInfo_t* );



void create_data(str_nodeInfo_t*, Uint8*, Uint8* );



Uint8* Is_userNameFound(str_nodeInfo_t* , Uint8* );




void Is_BankAccountIDFound(str_nodeInfo_t* , Sint8* ,Uint32);




void display_AccountInfo(str_nodeInfo_t* );




void display_BankAccountIDS(str_nodeInfo_t* );




Uint8* enter_password();




Sint8* randomPasswordGeneration();



Sint8* randomAccountIDGeneration();




void vidChangeAccountStatus(str_nodeInfo_t* );




void createNewAccount(str_nodeInfo_t* );




void vidLogin(str_nodeInfo_t*);




void vidClientLogin(str_nodeInfo_t*);




str_node_t* CurrentNode(str_nodeInfo_t* , Uint8* );




void vidGetCash(str_nodeInfo_t* );




void vidDeposit(str_nodeInfo_t* );




void vidMakeTransaction(str_nodeInfo_t*);




void vidChangePasswordNod(str_nodeInfo_t*);




#endif 