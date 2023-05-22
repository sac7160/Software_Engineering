#include "RequirementSystem.h"

/*
Function : ViewApplyList
Description : ViewApplyList class constructor
Return type :
Parameters :
*/
ViewApplyList::ViewApplyList()
{
	ViewApplyListUi viewApplyListUi;
	viewApplyListUi.selectApplyInfo(this);
}


/*
Function : showApplyList
Description : get apply list
Return type : Apply**
Parameters : *commonMember, int&
*/
Apply** ViewApplyList::showApplyList(CommonMember* commonMember, int &num)
{
	num = commonMember->getApplyList()->getNumOfApply();
	return commonMember->getApplyList()->listApplies();
}