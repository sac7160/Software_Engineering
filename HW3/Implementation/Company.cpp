#include "RequirementSystem.h"

/*
Function : Company
Description : Company class constructer
Return type :
Parameters  : string, string, string, string, bool
*/
Company::Company(string companyName, string companyNumber, string id, string password, bool company) : Member(id, password, company)
{
	this->companyName = companyName;
	this->companyNumber = companyNumber;
}

/*
Function : getEmploymentList
Description : return EmploymentList
Return type : EmploymentList*
Parameters  :
*/
EmploymentList * Company::getEmploymentList()
{
	return &enrolledEmploymentCollection;
}

/*
Function : getCompanyName
Description : return companyName
Return type : string
Parameters  :
*/
string Company::getCompanyName()
{
	return companyName;
}

/*
Function : getCompanyNumber
Description : return companyNumber
Return type : string
Parameters  :
*/
string Company::getCompanyNumber()
{
	return companyNumber;
}