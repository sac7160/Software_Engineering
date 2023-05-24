#include "RequirementSystem.h"

/*
Function : ShowEmploymentList
Description : ShowEmploymentList class constructor
Return type :
Parameters :
*/
ShowEmploymentList::ShowEmploymentList()
{
	ShowEmploymentListUi showEmploymentListUi;
	showEmploymentListUi.searchEmploymentList(this);
}

/*
Function : ShowEmploymentList
Description : get employment list
Return type : Employment**
Parameters : memberList, companyName, &num, &companyNum
*/
Employment** ShowEmploymentList::showEmployments(MemberList* memberList, string companyName, int &num, string &companyNum)
{
	Member** members = memberList->getMembers();
	
	for (int i = 0; i < memberList->getMemberNum(); i++)
	{
		if (members[i]->getIsCompany() == true)
		{
			Company* company = (Company*)members[i];
			if (company->getCompanyName() == companyName)
			{
				companyNum = company->getCompanyNumber();
				num = company->getEmploymentList()->getNumOfEmployment();
				Employment** employments = company->getEmploymentList()->listEmployments();
				return employments;
			}
		}
	}
}