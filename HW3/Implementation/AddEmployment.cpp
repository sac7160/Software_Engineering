#include "RequirementSystem.h"

/*
Function : AddEmployment
Description : AddEmployment class constructer
Return type : 
Parameters  :
*/
AddEmployment::AddEmployment()
{
	AddEmploymentUi addEmploymentUi;
	addEmploymentUi.selectAddEmployment(this);
}

/*
Function : addNewEmployment
Description : add new Employment
Return type :
Parameters  : Company *, string , integer
*/
void AddEmployment::addNewEmployment(Company* company, string work, int num, string deadline)
{
	EmploymentList* employmentList = company->getEmploymentList();	
	employmentList->addEmployment(work, num, deadline);
}