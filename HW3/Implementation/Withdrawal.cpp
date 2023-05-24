#include "RequirementSystem.h"

/*
Function : WithDrawal
Description : Withdrawal class constructor
Return type :
Parameters :
*/
Withdrawal::Withdrawal()
{
	WithdrawalUi withdrawalUi;	
	withdrawalUi.selectWithdrawal(this);
}

/*
Function : callDeleteMember
Description : withdraw and return withdraw id
Return type : string
Parameters : *members
*/
string Withdrawal::callDeleteMember(MemberList* members)
{
	string withdrawalId = members->deleteMember(members->getNowLoginIndex());
	return withdrawalId;
}