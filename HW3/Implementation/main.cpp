/*
Function : selectApplyInfo
Description : print applyInfo
Return type :
Parameters  : ViewApplyList*
*/
void ViewApplyListUi::selectApplyInfo(ViewApplyList* viewApplyList)
{
    fout << "4.3. 지원 정보 조회" << endl;
    int num;

    CommonMember* currentLoginMember = (CommonMember*)memberList->getNowLoginMember();

    Apply** apply = viewApplyList->showApplyList(currentLoginMember,num);

    for (int i = 0; i < num; i++)
    {
        fout << "> " << apply[i]->getCompanyName() << " " << apply[i]->getCompanyNum() << " "<< apply[i]->getWork()
            << " " << apply[i]->getNumOfPeople() << " " << apply[i]->getDeadline() << endl;
    }
    fout << endl;
}

/*
Function : selectCnacelApply
Description : print cancelApply
Return type :
Parameters  : CancelApply*
*/
void CancelApplyUi::selectCancelApply(CancelApply* cancelApply)
{
    string companyName,work,companyNum;
    fin >> companyNum;

    CommonMember* currentLoginMember = (CommonMember*)memberList->getNowLoginMember();

    fout << "4.4. 지원 취소" << endl;
    cancelApply->callCancelApply(memberList, currentLoginMember, companyName, companyNum, work);
    fout << "> " << companyName << " " << companyNum << " " << work << endl << endl;
}

/*
Function : selectCommonApplicationStat
Description : print CommonApplicationStat
Return type :
Parameters  : CommonApplicationStat*
*/
void CommonApplicationStatUi::selectCommonApplicationStat(CommonApplicationStat* commonApplicationStat)
{
    vector<pair<string, int>> applyNumforWork;
    CommonMember* currentLoginMember = (CommonMember*)memberList->getNowLoginMember();
    commonApplicationStat->getCommonApplicationStat(currentLoginMember,applyNumforWork);
    fout << "5.1. 지원 정보 통계" << endl;
    for (int i = 0; i < applyNumforWork.size(); i++)
    {
        fout << "> " << applyNumforWork[i].first << " " << applyNumforWork[i].second << endl;
    }
    fout << endl;
}
