#include "RequirementSystem.h"

/*
Function : Apply
Description : Apply class constructer
Return type :
Parameters  : string, string, string, int, string
*/
Apply::Apply(string companyName, string companyNum, string work, int num, string deadline)
{
	this->companyName = companyName;
	this->work = work;
	this->companyNum = companyNum;
	this->work = work;
	this->numOfPeople = num;
	this->deadline = deadline;
}

/*
Function : getCompanyName
Description : return companyName
Return type : string
Parameters  :
*/
string Apply::getCompanyName() { return companyName; }

/*
Function : getCompanyNum
Description : return companyNum
Return type : string
Parameters  :
*/
string Apply::getCompanyNum() { return companyNum; }

/*
Function : getWork
Description : return work
Return type : string
Parameters  :
*/
string Apply::getWork() { return work; }

/*
Function : getNumOfPeople
Description : return numOfPeople
Return type : int
Parameters  :
*/
int Apply::getNumOfPeople() { return numOfPeople; }

/*
Function : getDeadline
Description : return deadline
Return type : string
Parameters  :
*/
string Apply::getDeadline() { return deadline; }