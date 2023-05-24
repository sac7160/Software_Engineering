/*
Function : selectApplyInfo
Description : print applyInfo
Return type :
Parameters  : ViewApplyList*
*/
void ViewApplyListUi::selectApplyInfo(ViewApplyList *viewApplyList)
{
    fout << "4.3. ???? ???? ???" << endl;
    int num;

    CommonMember *currentLoginMember = (CommonMember *)memberList->getNowLoginMember();

    Apply **apply = viewApplyList->showApplyList(currentLoginMember, num);

    for (int i = 0; i < num; i++)
    {
        fout << "> " << apply[i]->getCompanyName() << " " << apply[i]->getCompanyNum() << " " << apply[i]->getWork()
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
void CancelApplyUi::selectCancelApply(CancelApply *cancelApply)
{
    string companyName, work, companyNum;
    fin >> companyNum;

    CommonMember *currentLoginMember = (CommonMember *)memberList->getNowLoginMember();

    fout << "4.4. ???? ???" << endl;
    cancelApply->callCancelApply(memberList, currentLoginMember, companyName, companyNum, work);
    fout << "> " << companyName << " " << companyNum << " " << work << endl
         << endl;
}

/*
Function : selectCommonApplicationStat
Description : print CommonApplicationStat
Return type :
Parameters  : CommonApplicationStat*
*/
void CommonApplicationStatUi::selectCommonApplicationStat(CommonApplicationStat *commonApplicationStat)
{
    vector<pair<string, int>> applyNumforWork;
    CommonMember *currentLoginMember = (CommonMember *)memberList->getNowLoginMember();
    commonApplicationStat->getCommonApplicationStat(currentLoginMember, applyNumforWork);
    fout << "5.1. ???? ???? ???" << endl;
    for (int i = 0; i < applyNumforWork.size(); i++)
    {
        fout << "> " << applyNumforWork[i].first << " " << applyNumforWork[i].second << endl;
    }
    fout << endl;
}

/*
Function : selectSignup
Description : print signup form
Return type :
Parameters  : signUp*
*/
void SignUpUi::selectSignUp(SignUp *signUp)
{

    string id, password, companyName, name, residentNumber, companyNumber;
    int menu_level_3;

    fin >> menu_level_3;

    cout << "menu3 : " << menu_level_3;

    if (menu_level_3 == 1)
    {
        fin >> companyName >> companyNumber >> id >> password;
        signUp->newMember(memberList, menu_level_3, companyName, companyNumber, id, password);

        fout << "1.1. ???????" << endl;
        fout << "> " << menu_level_3 << ' ' << companyName << ' ' << companyNumber << ' ' << id << ' ' << password << endl
             << endl;
    }

    else if (menu_level_3 == 2)
    {
        fin >> name >> residentNumber >> id >> password;
        signUp->newMember(memberList, menu_level_3, name, residentNumber, id, password);

        fout << "1.1. ???????" << endl;
        fout << "> " << menu_level_3 << ' ' << name << ' ' << residentNumber << ' ' << id << ' ' << password << endl
             << endl;
    }
}

/*
Function : selectWithdrwal
Description : print withdrawal form
Return type :
Parameters  : withdrawal*
*/
void WithdrawalUi::selectWithdrawal(Withdrawal *withdrawal)
{
    string withdrawalId = withdrawal->callDeleteMember(memberList);

    fout << "1.2. ??????" << endl;
    fout << "> " << withdrawalId << endl
         << endl;
    ;
}

/*
Function : selectLogin
Description : print login form
Return type :
Parameters  : login*
*/
void LoginUi::selectLogin(Login *login)
{
    string id, password;
    fin >> id >> password;
    if (login->loginMember(memberList, id, password))
    {
        fout << "2.1. ?¥á???" << endl;
        fout << "> " << id << ' ' << password << endl
             << endl;
    }
}

/*
Function : selectLogout
Description : print logout
Return type : 
Parameters  : Logout*
*/
void LogoutUi::selectLogout(Logout* logout)
{
    fout << "2.2. 로그아웃" << endl;
    string logoutId = logout->logoutMember(memberList);
    fout << "> " << logoutId << endl << endl;
}

/*
Function : selectAddEmployment
Description : print addemployment
Return type :
Parameters  : AddEmployment*
*/
void AddEmploymentUi::selectAddEmployment(AddEmployment* addEmployment)
{
    string work, deadline;
    int num;

    fin >> work >> num >> deadline;

    Company* currentLoginMember = (Company*)memberList->getNowLoginMember();

    fout << "3.1. 채용 정보 등록" << endl;
    addEmployment->addNewEmployment(currentLoginMember, work, num, deadline);
    
    fout << "> " << work << " " << num << " " << deadline << endl << endl;
}

/*
Function : selectLookUpList
Description : print enrolledemploymentlist
Return type :
Parameters  : ShowEnrolledEmploymentList*
*/
void ShowEnrolledEmploymentListUi::selectLookUpList(ShowEnrolledEmploymentList* showEnrolledEmploymentList)
{
    Company* currentLoginMember = (Company*)memberList->getNowLoginMember();
    
    int num=0;

    fout << "3.2. 등록된 채용 정보 조회" << endl;
    Employment** employments = showEnrolledEmploymentList->showList(currentLoginMember,num);    //개수 참조매개변수로 받음

    for(int index=0; index<num; index++)
    {   
        fout << "> " << employments[index]->getWork() << " " << employments[index]->getNumOfPeople()
            << ' ' << employments[index]->getDeadline() << endl << endl;
    }
}
