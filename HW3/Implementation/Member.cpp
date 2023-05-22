#include "RequirementSystem.h"

/*
Function : Member
Description : Member class constructor
Return type :
Parameters : string, string, bool
*/
Member::Member(string id, string password, bool company)
{
	this->isCompany = company;
	this->id = id;
	this->password = password;
}

/*
Function : getId
Description : get member id
Return type : string
Parameters :
*/
string Member::getId()
{
	return id;
}

/*
Function : getPassword
Description : get member password
Return type : string
Parameters :
*/
string Member::getPassword()
{
	return password;
}

/*
Function : getIsCompany
Description : get member isCompanyMember
Return type : bool
Parameters :
*/
bool Member::getIsCompany()
{
	return isCompany;
}
