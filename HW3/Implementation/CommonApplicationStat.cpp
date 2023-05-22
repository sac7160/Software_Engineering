#include "RequirementSystem.h"

/*
Function : CommonApplicationStat
Description : CommonApplicationStat class constructer
Return type :
Parameters  :
*/
CommonApplicationStat::CommonApplicationStat()
{
	CommonApplicationStatUi commonApplicationStatUi;
	commonApplicationStatUi.selectCommonApplicationStat(this);
}

/*
Function : getCompanyApplicaitonStat
Description : get statistics of application
Return type :
Parameters  : CommonMember * , vector<pair<string, int>>&
*/
void CommonApplicationStat::getCommonApplicationStat(CommonMember* commonMember, vector<pair<string, int>>& applyNumforWork)
{
	ApplyList* applyList = commonMember->getApplyList();
	int applyNum = applyList->getNumOfApply();
	Apply** apply = applyList->listApplies();

	for (int i = 0; i < applyNum; i++)
	{
		string work = apply[i]->getWork();
		if (i == 0) applyNumforWork.push_back(make_pair(work, 1));	//첫 apply vector에 추가
		int size = applyNumforWork.size();
		for (int j = 1; j < size; j++)
		{
			if (applyNumforWork[j].first == work)	//업무가 같다면
			{
				applyNumforWork[j].second++;
				break;
			}
			if (j == applyNumforWork.size() - 1)
			{
				applyNumforWork.push_back(make_pair(work, 1));
			}
		}
	}
}