#include "mumar.h"
inherit ROOM;
 
void create()
{
        ::create();
  set_short("馬房");
  set_long( @CLong
這兒是牧馬關的馬房，飼養著遠近馳名的牧馬關戰馬。由於牧馬關的馬兒們戰績輝
煌，所以在馬房裡也十分受到禮遇。這兒打掃得乾淨舒適，可能比士兵住得還服舒些。
西北邊有條小路通往教場。
CLong
);
set_outside("eastland");
set("exits",([
               "northwest":MUMAR"square03",
             ]));
 
set( "pre_exit_func", ([ "northwest" : "can_pass" ]) );
set("objects",([
               "groom":MOB"groom",
               "horse#1":MOB"horse",
               "horse#2":MOB"horse"]));
reset();
}
 
int can_pass()
{ if(this_player()->query_temp("mounting") && !wizardp(this_player()) &&
       present("groom") )
   {  if(this_player()->query_temp("cavalry_mark") )  {
           tell_object(this_player(),
                       "馬伕輕聲地對你說道：長官，您請慢走!\n" );
           this_player()->set_temp("cavalry_mark",0) ;
           return 0;
             }
      else   {
      tell_object(this_player(),
"馬伕狠狠地瞪著你說：我最討厭自以為騎術很好的人卻不瞭解馬的人到我這來！\n"
"馬伕說話的同時，輕拍著你的座騎，並用一種柔和的語調對馬說話。\n"
"你的座騎忽然間有點不聽使喚，一步也不肯動...\n" );
      return 1;
             }
   }
else
    return 0;
}
