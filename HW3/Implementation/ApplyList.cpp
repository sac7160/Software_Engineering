#include "RequirementSystem.h"

/*
Function : addApply
Description : add apply information to list of apply
Return type : Apply*
Parameters  : string, string, string, int, string
*/
Apply* ApplyList::addApply(string companyName, string companyNum, string work, int num, string deadline)
{
	Apply* apply= new Apply(companyName,companyNum,work,num,deadline);
	ownedApply[numOfApply++] = apply;
	return apply;
}

/*
Function : getNumofAppply
Description : return numofapply
Return type :int
Parameters  :
*/
int ApplyList::getNumOfApply()
{
	return numOfApply;
}

/*
Function : listApplites
Description : return owendApply
Return type : Apply**
Parameters  :
*/
Apply** ApplyList::listApplies()
{
	return ownedApply;
}

/*
Function : deleteApply
Description : delete Apply object 
Return type :
Parameters  : int
*/
void ApplyList::deleteApply(int canceledApplyIndex)
{
	Apply* cancelApply = ownedApply[canceledApplyIndex];
	delete cancelApply;
	numOfApply--;
}