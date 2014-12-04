/* 
 * File:   message.h
 * Author: kevhnmay94
 *
 * Created on November 28, 2014, 5:56 AM
 */

/* Type
 * 1 = login
 * 2 = user message
 * 3 = group message
 * 4 = create
 * 5 = join
 * 6 = leave
 * 7 = show user
 * 8 = show group
 * 9 = logout
 * 10 = signup
 * 11 = sent user
 * 12 = sent group
 */

#ifndef MESSAGE_H
#define	MESSAGE_H

#include <ctime>

typedef struct
{
    // bagian mana yang akan membaca pesan, 1 untuk server, 0 untuk client
    char type; // tipe pesan yang dikirimkan
    char s_user[20];
    char d_user[20];
    struct tm timedate;
    char content[150];
}message;

#endif	/* MESSAGE_H */

