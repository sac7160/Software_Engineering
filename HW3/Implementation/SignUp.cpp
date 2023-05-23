#include <iostream>
#include <fstream>
#include "RequirementSystem.h"

/*
Function : Signup
Description : Signup class constructor
Return type :
Parameters :
*/
SignUp::SignUp()
{
	SignUpUi signUpUi;	
	signUpUi.selectSignUp(this);
}

/*
Function : newMember
Description : call function of addNewMembers
Return type : void
Parameters : *members, int, string, string, string, string
*/
void SignUp::newMember(MemberList* members, int menu_level_3, string arg1, string arg2, string id, string password)
{
	members->addNewMembers(menu_level_3, arg1, arg2, id, password);
}

