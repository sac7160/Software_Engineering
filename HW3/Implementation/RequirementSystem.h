#pragma once

#include <iostream>
#include <string.h>
#include <typeinfo>
#include <vector>

using namespace std;


/*
class : Member
Description : member class
*/
class Member
{
private:
	string id;
	string password;
	bool isCompany;
public:
	Member(string id, string password, bool isCompany);
	string getId();
	string getPassword();
	bool getIsCompany();
};

/*
class : MemberList
Description : list of members
*/
class MemberList
{
private:
	Member* members[100];	
	int memberNum = 0;
	int nowLoginIndex = 0;

public:
	void addNewMembers(int menu_level_3, string arg1, string arg2, string id, string password);
	string deleteMember(int nowLogin);
	int getNowLoginIndex();
	int getMemberNum();
	Member** getMembers();
	Member* getNowLoginMember();	//getNowLoginIndex수정 -> 삭제해도 될듯
	string getNowLoginId();
	bool isMember(string id, string password);
};

/*
class : Employment
Description : company's employment
*/
class Employment
{
private:
	string work;
	int numOfPeople;
	string deadline;
	int applyNum = 0;
public:
	Employment(string work, int numOfPeople, string deadline);
	int getApplyNum();
	void plusApplyNum();
	void minusApplyNum();
	string getWork();
	int getNumOfPeople();
	string getDeadline();
};

/*
class : EmploymentList
Description : list of Employments
*/
class EmploymentList
{
private:
	Employment* enrolledEmployment[100];
	int numOfEmployment = 0;
public:
	void addEmployment(string work, int num, string deadline);
	int getNumOfEmployment();
	Employment** listEmployments();	
};

/*
class : Apply
Description : common member's apply
*/
class Apply
{
private:
	string companyName;
	string companyNum;
	string work;
	int numOfPeople;
	string deadline;
public:
	Apply(string companyName, string companyNum, string work, int num, string deadline);
	string getCompanyName();
	string getCompanyNum();
	string getWork();
	int getNumOfPeople();
	string getDeadline();
};

/*
class : ApplyList
Description : list of Applies
*/
class ApplyList
{
private:
	Apply* ownedApply[100];
	int numOfApply = 0;
public:
	Apply* addApply(string companyName, string companyNum, string work, int num, string deadline );
	int getNumOfApply();	
	void deleteApply(int canceledApplyIndex);
	Apply** listApplies();
};

/*
class : Company
Description : Company member class
*/
class Company : public Member
{
private:
	EmploymentList enrolledEmploymentCollection;
	string companyName;
	string companyNumber;
public:
	Company(string companyName, string companyNumber, string id, string password,bool company);
	EmploymentList * getEmploymentList();
	string getCompanyName();
	string getCompanyNumber();
};

/*
class : CommonMember
Description : Common Member class
*/
class CommonMember : public Member
{
private:
	ApplyList applyCollection;
	string name;
	string residentNumber;
public:
	CommonMember(string name, string residentNumber, string id, string password, bool company);
	
	ApplyList * getApplyList();
};

/*
class : SignUp
Description : SignUp control class
*/
class SignUp
{
public:
	SignUp();
	void newMember(MemberList* members, int menu_level_3, string arg1, string arg2, string id, string password);
};

/*
class : SignUpUi
Description : SignUpUi boundary class
*/
class SignUpUi
{
public:
	void selectSignUp(SignUp* signUp);
};

/*
class : Withdrawal
Description : Withdrawal control class
*/
class Withdrawal
{
public:
	Withdrawal();
	string callDeleteMember(MemberList* members);
};

/*
class : WithdrawalUi
Description : WithdrawalUi boundary class
*/
class WithdrawalUi
{
public:
	void selectWithdrawal(Withdrawal* withdrawal);
};

/*
class : Login
Description : Login control class
*/
class Login
{
public:
	Login();
	bool loginMember(MemberList* members,string id, string password);
};

/*
class : LoginUi
Description : LoginUi boundary class
*/
class LoginUi
{
public:
	void selectLogin(Login* login);
};

/*
class : Logout
Description : Logout control class
*/
class Logout
{
public:
	Logout();
	string logoutMember(MemberList* members);
};

/*
class : LogoutUi
Description : LogoutUi boundary class
*/
class LogoutUi
{
public:
	void selectLogout(Logout* logout);
};

/*
class : AddEmployment
Description : AddEmployment control class
*/
class AddEmployment
{
public:
	AddEmployment();
	void addNewEmployment(Company* company, string work, int num, string deadline);
};

/*
class : AddEmploymentUi

Description : AddEmploymentUi boundary class
*/
class AddEmploymentUi
{
public:
	void selectAddEmployment(AddEmployment* addEmployment);
};

/*
class : ShowEnrolledEmploymentList
Description : ShowEnrolledEmploymentList control class
*/
class ShowEnrolledEmploymentList
{
public:
	ShowEnrolledEmploymentList();
	Employment** showList(Company* company, int& num);
};

/*
class : ShowEnrolledEmploymentListUi
Description : ShowEnrolledEmploymentListUi boundary class
*/
class ShowEnrolledEmploymentListUi
{
public:
	void selectLookUpList(ShowEnrolledEmploymentList* showEnrolledEmploymentList);
};

/*
class : ShowEmploymentList
Description : ShowEmploymentList control class
*/
class ShowEmploymentList
{
public:
	ShowEmploymentList();
	Employment** showEmployments(MemberList* members, string companyName, int &num, string &companyNum);
};

/*
class : ShowEmploymentListUi
Description : ShowEmploymentListUi boundary class
*/
class ShowEmploymentListUi
{
public:
	void searchEmploymentList(ShowEmploymentList* showEmploymentList);
};

/*
class : Appliance
Description : Appliance control class
*/
class Appliance
{
public:
	Appliance();
	Apply* newApply(CommonMember* commonMember, MemberList* memberList, string companyNum);
};

/*
class : ApplianceUi
Description : ApplianceUi boundary class
*/
class ApplianceUi
{
public:
	void selectAppliance(Appliance* appliance);
};

/*
class : CancelApply
Description : CancelApply control class
*/
class CancelApply
{
public:
	CancelApply();
	void callCancelApply(MemberList* memberList, CommonMember* commonMember, string& companyName, string companyNum, string& work);
};

/*
class : CancelApplyUi
Description : CancelApplyUi boundary class
*/
class CancelApplyUi
{
public:
	void selectCancelApply(CancelApply* cancelApply);
};

/*
class : ViewApplyList
Description : ViewApplyList control class
*/
class ViewApplyList
{
public:
	ViewApplyList();
	Apply** showApplyList(CommonMember* commonMember, int& num);
};

/*
class : ViewApplyListUi
Description : ViewApplyListUi boundary class
*/
class ViewApplyListUi
{
public:
	void selectApplyInfo(ViewApplyList* viewApplyList);
};

/*
class : CommonApplicationStat
Description : CommonApplicationStat control class
*/
class CommonApplicationStat
{
public:
	CommonApplicationStat();
	void getCommonApplicationStat(CommonMember* commonMember,vector<pair<string,int>>& applyNumforWork);
};

/*
class : CommonApplicationStatUi
Description : CommonApplicationStatUi boundary class
*/
class CommonApplicationStatUi
{
public:
	void selectCommonApplicationStat(CommonApplicationStat* commonApplicationStat);
};

/*
class : CompanyApplicationStat
Description : CompanyApplicationStat control class
*/
class CompanyApplicationStat
{
public:
	CompanyApplicationStat();
	void getCompanyApplicaitonStat(Company* company, vector<pair<string, int>>& applyNumforWork);
};

/*
class : CompanyApplicationStatUi
Description : CompanyApplicationStatUi boundary class
*/
class CompanyApplicationStatUi
{
public:
	void selectCompanyApplicationStat(CompanyApplicationStat* companyApplicationStat);
};