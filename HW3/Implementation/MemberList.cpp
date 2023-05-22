#include "RequirementSystem.h"


/*
Function : addNewMembers
Description : add new member on MemberList
Return type :
Parameters : int, string, string, string, string
*/
void MemberList::addNewMembers(int menu_level_3, string arg1, string arg2, string id, string password)
{

	if (menu_level_3 == 1) this->members[memberNum++] = new Company(arg1, arg2, id, password,true);
	else if (menu_level_3 == 2) this->members[memberNum++] = new CommonMember(arg1, arg2, id, password,false);
}

/*
Function : getNowLoginIndex
Description : get current login member index
Return type : int
Parameters :
*/
int MemberList::getNowLoginIndex()
{
	return nowLoginIndex;
}

/*
Function : getMemberNum
Description : get number of members
Return type : int
Parameters : 
*/
int MemberList::getMemberNum()
{
	return memberNum;
}

/*
Function : getMembers
Description : get member list
Return type : Member**
Parameters :
*/
Member** MemberList::getMembers()
{
	return members;
}

/*
Function : getNowLoginMember
Description : get member logined now
Return type : Member*
Parameters :
*/
Member* MemberList::getNowLoginMember()
{
	return members[getNowLoginIndex()];
}

/*
Function : getNowLoginId
Description : get member id logined now
Return type : string
Parameters :
*/
string MemberList::getNowLoginId()
{
	int index = getNowLoginIndex();
	return members[index]->getId();
}

/*
Function : deleteMember
Description : delete member
Return type : string
Parameters : int
*/
string MemberList::deleteMember(int nowLogin)
{
	string withdrawalId = members[nowLogin]->getId();
	delete members[nowLogin];
	members[nowLogin] = NULL;
	return withdrawalId;
}

/*
Function : isMember
Description : get such id is Member
Return type : bool
Parameters : string, string
*/
bool MemberList::isMember(string id, string password)
{
	for (int i = 0; i < memberNum; i++)
	{
		if (members[i]->getId() == id && members[i]->getPassword() == password)
		{
			nowLoginIndex = i;
			return true;
		}
	}
	return false;
}