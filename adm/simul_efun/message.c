/* Programed by Moon 1998.03.23      */

#include <config.h>
#include <commands.h>
#include <daemons.h>
#include <login.h>
#include <uid.h>

void message(string cla,  string  mess,  mixed  target,
             mixed exclude)
{
     string * str;
     string new_mess;
     int i;
     str=explode(mess,"$");
     new_mess="";
     for(i=0;i<sizeof(str);i+=2)
     {
        if(i+1<sizeof(str) )
        {
           new_mess+=set_color(str[i+1],str[i]);
           continue;
         }
        else
        {
           new_mess+=str[i];
           break;
         }
     }
     //  FluffOS 2019 以後 efun::message() 的第四個參數只接受 object 或 array，
     //  但舊碼慣用「省略參數」（值為 0）表示不排除任何人 —— 例如 tell_room()
     //  全樹 2561 個呼叫點裡絕大多數都只傳三個參數。這裡統一規範化，
     //  否則會拋出 Bad argument 4 to EFUN message() 打斷呼叫端的流程。
     if( objectp(exclude) ) exclude = ({ exclude });
     else if( !pointerp(exclude) ) exclude = ({ });

     efun::message(cla,new_mess,target,exclude);
}

