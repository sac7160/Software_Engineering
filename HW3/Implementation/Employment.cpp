#include "RequirementSystem.h"

/*
Function : Employment
Description : Employment class constructer
Return type :
Parameters  : string, int, string
*/
Employment::Employment(string work, int numOfPeople, string deadline)
{
	this->work = work;
	this->numOfPeople = numOfPeople;
	this->deadline = deadline;
}

/*
Function : getWork
Description : return work
Return type : string
Parameters  :
*/
string Employment::getWork()
{
	return work;
}

/*
Function : getNumOfPeople
Description : return numOfPeople
Return type : int
Parameters  :
*/
int Employment::getNumOfPeople()
{
	return numOfPeople;
}

/*
Function : getDeadline
Description : return deadline
Return type : string
Parameters  :
*/
string Employment::getDeadline()
{
	return deadline;
}

/*
Function : getApplyNum
Description : return applyNum
Return type : int
Parameters  :
*/
int Employment::getApplyNum()
{
	return applyNum;
}

/*
Function : plusApplyNum
Description : increase applyNum 
Return type :
Parameters  :
*/
void Employment::plusApplyNum()
{
	applyNum++;
}

/*
Function : minusApplyNum
Description : decrease applyNum
Return type :
Parameters  :
*/
void Employment::minusApplyNum()
{
	applyNum--;
}