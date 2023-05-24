#include "RequirementSystem.h"

/*
Function : CompanyApplicationStat
Description : CompanyApplicationStat class constructer
Return type :
Parameters  :
*/
CompanyApplicationStat::CompanyApplicationStat()
{
	CompanyApplicationStatUi companyApplicationStatUi;
	companyApplicationStatUi.selectCompanyApplicationStat(this);
}

/*
Function : getCompanyApplicaitonStat
Description : get statistics of application
Return type :
Parameters  : Company*, vector<pair<string, int>>&
*/
void CompanyApplicationStat::getCompanyApplicaitonStat(Company* company, vector<pair<string, int>>& applyNumforWork)
{
	EmploymentList* employmentList = company->getEmploymentList();
	int employmentNum = employmentList->getNumOfEmployment();
	Employment** employment = employmentList->listEmployments();

	for (int i = 0; i < employmentNum; i++)
	{
		string work = employment[i]->getWork();
		if (i == 0) applyNumforWork.push_back(make_pair(work, employment[0]->getApplyNum()));
		int size = applyNumforWork.size();
		for (int j = 1; j < size; j++)	//회사의 employment 종류 여러개라면
		{
			if (applyNumforWork[j].first == work)	//업무가 같다면
			{
				applyNumforWork[j].second += employment[i]->getApplyNum();
				break;
			}
			if (j == size - 1)
			{
				applyNumforWork.push_back(make_pair(work, employment[i]->getApplyNum()));
			}
		}
	}
}