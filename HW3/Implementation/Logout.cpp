#include "RequirementSystem.h"

/*
Function : Logout
Description : Logout class constructer
Return type :
Parameters  :
*/
Logout::Logout()
{
	LogoutUi logoutUi;
	logoutUi.selectLogout(this);
}

/*
Function : logoutMember
Description : get id to logout
Return type : string
Parameters  : MemberList*
*/
string Logout::logoutMember(MemberList* members)
{
	string id = members->getNowLoginId();
	return id;
}
