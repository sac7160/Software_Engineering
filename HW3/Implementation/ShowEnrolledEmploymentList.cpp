#include "RequirementSystem.h"

/*
Function : ShowEnrolledEmploymentList
Description : ShowEnrolledEmploymentList class constructor
Return type :
Parameters :
*/
ShowEnrolledEmploymentList::ShowEnrolledEmploymentList()
{
	ShowEnrolledEmploymentListUi showEnrolledEmploymentListUi;
	showEnrolledEmploymentListUi.selectLookUpList(this);
}

/*
Function : showList
Description : show employment list
Return type : Employment**
Parameters : *company, &num
*/
Employment** ShowEnrolledEmploymentList::showList(Company* company, int &num)
{
	EmploymentList* employmentList = company->getEmploymentList();
	num = employmentList->getNumOfEmployment();	
	Employment** employments = employmentList->listEmployments();
	return employments;
}