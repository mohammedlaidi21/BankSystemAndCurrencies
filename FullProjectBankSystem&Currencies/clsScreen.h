#pragma once
#include <iostream>
#include "clsDate.h"
#include "Global.h"

using namespace std;


class clsScreen
{

protected:
    static void _DrawActionHeaderScreen(string title, string SubTitle = "")
	{
		cout << "\t\t\t\t\t____________________________________";
		cout << "\n\n\t\t\t\t\t" << title;
		if (SubTitle != "")
		{
			cout << "\n\t\t\t\t\t" << SubTitle;
		}
		cout << "\n\t\t\t\t\t____________________________________\n\n";
		cout << "\t\t\t\t\tUser: " << CurrentUser.UserName;
		cout << "\n\t\t\t\t\tDate: " << clsDate::DateToString(clsDate()) << "\n\n";
	}


	static bool isCheckPermission(clsUser::enPermission Permission)
	{
		if (!CurrentUser.isPermissionUser(Permission))
		{
			cout << "\t\t\t\t\t____________________________________";
			cout << "\n\n\t\t\t\t\t" << " Access Denied! Contact Your Admin.";
			cout << "\n\t\t\t\t\t____________________________________\n\n";
			return false;
		}

		else
			return true;
	}
};

