// 헤더 선언
#include <fstream>
#include <iostream>
#include "RequirementSystem.h"

using namespace std;

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void doTask();
void join();
void withdrawal();
void logIn();
void logOut();
void enrollEmployment();
void showEnrolledEmploymentList();
void showEmploymentList();
void apply();
void showApplyList();
void cancelApply();
void viewStat();
void program_exit();

// 변수 선언
ifstream fin;
ofstream fout;
MemberList* memberList;
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
/*
Function : selectAppliance
Description : print Appliance
Return type :
Parameters  : Appliance*
*/
void ApplianceUi::selectAppliance(Appliance* appliance)
{
    string companyNum;
    fin >> companyNum;

    CommonMember* currentLoginMember = (CommonMember*)memberList->getNowLoginMember();

    fout << "4.2. 채용 지원" << endl;
    Apply* apply = appliance->newApply(currentLoginMember, memberList, companyNum);
    fout << "> " << apply->getCompanyName() << " " << apply->getCompanyNum() << " " << apply->getWork() << endl << endl;
}
/*
Function : searchEmploymentList
Description : print searchEmploymentList
Return type :
Parameters  : ShowEmploymentList*
*/
void ShowEmploymentListUi::searchEmploymentList(ShowEmploymentList* showEmploymentList)
{
    string companyName;
    fin >> companyName;

    int num = 0;
    string companyNum;
    cout << "num : " << num << endl;
    fout << "4.1. 채용 정보 검색" << endl;
    Employment** employments = showEmploymentList->showEmployments(memberList, companyName, num, companyNum);

    cout << "num : " << num << endl;

    for (int index = 0; index < num; index++)
    {
        cout << "while문 안";
        fout << "> " << companyName << " " << companyNum << " " << employments[index]->getWork() << " " << employments[index]->getNumOfPeople()
            << ' ' << employments[index]->getDeadline() << endl << endl;
    }
}
/*
Function : selectCompanyApplicationStat
Description : print CompanyApplicaitonStat
Return type :
Parameters  :CompanyApplicationStat*
*/
void CompanyApplicationStatUi::selectCompanyApplicationStat(CompanyApplicationStat* companyApplicationStat)
{
    vector<pair<string, int>> applyNumforWork;
    Company* currentLoginMember = (Company*)memberList->getNowLoginMember();

    companyApplicationStat->getCompanyApplicaitonStat(currentLoginMember, applyNumforWork);
    fout << "5.1. 지원 정보 통계" << endl;
    for (int i = 0; i < applyNumforWork.size(); i++)
    {
        fout << "> " << applyNumforWork[i].first << " " << applyNumforWork[i].second << endl;
    }
    fout << endl;
}

int main()
{
    fin.open(INPUT_FILE_NAME);
    fout.open(OUTPUT_FILE_NAME);
    
    memberList = new MemberList;

    doTask();
 
    delete memberList;
    return 0;
}

void doTask()
{
    // 메뉴 파싱을 위한 level 구분을 위한 변수
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    while (!is_program_exit)
    {
        // 입력파일에서 메뉴 숫자 2개를 읽기
        fin >> menu_level_1 >> menu_level_2;

        // 메뉴 구분 및 해당 연산 수행
        switch (menu_level_1)
        {
        case 1:
        {
            switch (menu_level_2)
            {
            case 1:   // "1.1. 회원가입“ 메뉴 부분
            {
                // join() 함수에서 해당 기능 수행
                join();

                break;
            }
            case 2:
            {
                withdrawal();
                break;
            }
            }
            break;
        }
        case 2:
        {
            switch (menu_level_2)
            {
            case 1:
            {
                logIn();
                break;
            }
            case 2:
                logOut();
                break;
            }
            break;
        }
        case 3:
        {
            switch (menu_level_2)
            {
            case 1:
            {
                enrollEmployment();
                break;
            }
            case 2:
            {
                showEnrolledEmploymentList();
                break;
            }
            }
            break;
        }
        case 4:
        {
            switch (menu_level_2)
            {
            case 1:
            {
                showEmploymentList();
                break;
            }
            case 2:
            {
                apply();
                break;
            }
            case 3:
            {
                showApplyList();
                break;
            }
            case 4:
            {
                cancelApply();
                break;
            }
            }
            break;
        }
        case 5:
        {
            switch (menu_level_2)
            {
            case 1:
            {
                viewStat();
                break;
            }
            }
            break;
        }
        case 6:
        {
            switch (menu_level_2)
            {
            case 1:   // "6.1. 종료“ 메뉴 부분
            {
                program_exit();
                is_program_exit = 1;
                break;;
            }
            return;
            }
        }
        }
    }
}

/*
Function : join
Description : generate SignUp
Return type :
Parameters  :
*/
void join()
{
    SignUp signUp;
}

/*
Function : withdrawal
Description : generate Withdrawal
Return type :
Parameters  :
*/
void withdrawal()
{
    Withdrawal withdrawal;
}

/*
Function : logIn
Description : generate  Login
Return type :
Parameters  :
*/
void logIn()
{
    Login logIn;
}

/*
Function : logOut
Description : generate  Logout
Return type :
Parameters  :
*/
void logOut()
{
    Logout logOut;
}

/*
Function : enrollEmployment
Description : generate  AddEmployment
Return type :
Parameters  :
*/
void enrollEmployment()
{
    AddEmployment addEmployment;
}

/*
Function : showEnrolledEmploymentList
Description : generate  ShowEnrolledEmploymentList
Return type :
Parameters  :
*/
void showEnrolledEmploymentList()
{
    ShowEnrolledEmploymentList showEnrolledEmploymentList;
}

/*
Function : showEmploymentList
Description : generate  ShowEmploymentList
Return type :
Parameters  :
*/
void showEmploymentList()
{
    ShowEmploymentList showEmployment;
}

/*
Function : apply
Description : generate Appliance
Return type :
Parameters  :
*/
void apply()
{
    Appliance appliance;
}

/*
Function : showApplyList
Description : generate ViewApplyList
Return type :
Parameters  :
*/
void showApplyList()
{
    ViewApplyList viewApplyList;
}

/*
Function : cancelApply
Description : generate CancelApply
Return type :
Parameters  :
*/
void cancelApply()
{
    CancelApply cancelApply;
}

/*
Function : viewStat
Description : generate CompanyApplicationStat or CommonApplicationStat
Return type :
Parameters  :
*/
void viewStat()
{
    if (memberList->getNowLoginMember()->getIsCompany())
    {
        CompanyApplicationStat companyApplicationStat;
    }
    else
    {
        CommonApplicationStat commonApplicationStat;
    }
}

/*
Function : program_exit
Description : print exit and close file
Return type :
Parameters  :
*/
void program_exit()
{
    fout << "6.1. 종료" << endl;
    fin.close();
    fout.close();
}










