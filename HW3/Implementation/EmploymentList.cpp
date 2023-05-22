#include "RequirementSystem.h"

/*
Function : addEmployment
Description : add new employment
Return type :
Parameters  : string, int, string
*/
void EmploymentList::addEmployment(string work, int num, string deadline)
{
	enrolledEmployment[numOfEmployment++] = new Employment(work,num,deadline);
}

/*
Function : getNumOfEmployment
Description : return numOfEmployment
Return type : int
Parameters  :
*/
int EmploymentList::getNumOfEmployment()
{
	return numOfEmployment;
}

/*
Function : listEmployments
Description : return enrolledEmployment
Return type : Employment**
Parameters  :
*/
Employment** EmploymentList::listEmployments()
{
	return enrolledEmployment;
}