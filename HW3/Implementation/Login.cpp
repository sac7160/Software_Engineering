#include "RequirementSystem.h"

/*
Function : Login
Description : Login class constructer
Return type :
Parameters  :
*/
Login::Login()
{
	LoginUi loginUi;
	loginUi.selectLogin(this);
}

/*
Function : loginMember
Description : if current member is member, return true else return false
Return type : bool
Parameters  : MemberList*, string, string
*/
bool Login::loginMember(MemberList* members, string id, string password)
{
	if (members->isMember(id, password)) return true;
	else return false;
}