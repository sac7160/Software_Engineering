#include "RequirementSystem.h"

/*
Function : Appliance
Description : Appliance class constructer
Return type :
Parameters  :
*/
Appliance::Appliance()
{
	ApplianceUi applianceUi;
	applianceUi.selectAppliance(this);
}


/*
Function : newApply
Description : call addApply
Return type : Apply*
Parameters : CommonMember*, MemberList*, string 
*/
Apply* Appliance::newApply(CommonMember* currentLoginMember, MemberList* memberList, string companyNum)
{
	Member** members = memberList->getMembers();
	int numOfMembers = memberList->getMemberNum();
	for (int i = 0; i < numOfMembers; i++)
	{
		if (members[i]->getIsCompany())	//if member is company
		{
			Company* company = (Company*)members[i];
			if (company->getCompanyNumber() == companyNum)	//해당 member가 지원한 company라면
			{
				string companyName = company->getCompanyName();
				
				Employment * employment = (company->getEmploymentList()->listEmployments())[0]; //classroom Q&A-> 하나의 채용정보만 생성
				string work = employment->getWork();
				string deadline = employment->getDeadline();
				int num = employment->getNumOfPeople();

				employment->plusApplyNum();	//company 통계 위해 해당 employment의 지원자수 증가
				ApplyList* applyList = currentLoginMember->getApplyList();	//지원자의 applylist 받아옴
				Apply* apply = applyList->addApply(companyName, companyNum, work, num, deadline);
				return apply;
			}
		}
	}
}