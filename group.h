/* 
 * File:   group.h
 * Author: kevhnmay94
 *
 * Created on November 28, 2014, 5:53 AM
 */

#ifndef GROUP_H
#define	GROUP_H

#include "user.h"
#include <vector>

using std::vector;

struct group
{
    char g_name[20];
    vector<user *> userlist;
};

#endif	/* GROUP_H */

