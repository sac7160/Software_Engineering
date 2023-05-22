#include "RequirementSystem.h"

/*
Function : CommonMember
Description : CommonMember class constructer
Return type :
Parameters  : string, string, string, string, bool
*/
CommonMember::CommonMember(string name, string residentNumber, string id, string password,bool company) : Member(id, password,company)
{
	this->name = name;
	this->residentNumber = residentNumber;
}

/*
Function : getApplyList
Description : get list of apply
Return type : ApplyList*
Parameters  : 
*/
ApplyList* CommonMember::getApplyList()
{
	return &applyCollection;
}