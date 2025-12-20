#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include <string>
#include <cctype>
#include "clsUser.h"
#include "clsScreen.h"
#include <vector>
class clsPermistions : protected clsScreen
{

public:
    static int _ReadPermisions()
    {
        int permistions = 0;


        if (toupper(clsInputValidate::ReadLetter("Do you want to give all permissions? [Y/N]: ")) == 'Y')
            return clsUser::enPermistions::All;
        else
        {
            std::vector < std::string> vMenuItems = { "Show Client List","Add New Client",
            "Delete Client","Update Client Info","Find Client","Transaction","Manage Users",
            };
            std::vector < clsUser::enPermistions > vPermisions = { clsUser::enPermistions::pList, clsUser::enPermistions::pAdd,
                clsUser::enPermistions::pDelete, clsUser::enPermistions::pUpdate, clsUser::enPermistions::pFind,
                clsUser::enPermistions::pTransactions, clsUser::enPermistions::pManage };

            for (short i = 0; i < (int)vMenuItems.size(); i++)
            {
                if (toupper(clsInputValidate::ReadLetter("Do you want to give access to \"" +
                    vMenuItems.at(i) + "\" ? [Y / N] : ")) == 'Y')
                {
                    permistions |= vPermisions.at(i);
                }
            }
        }
        return permistions;
    }

};

