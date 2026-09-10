
#include "../echobomber.h"

inherit ROOM;

int be_searched;
void create()
{
	::create();
    set_short("矮人村落的會議室");
    set_long(
@CLong
一間長滿蜘蛛網的會議室,灰塵的厚度大概可以留下你完整的腳印或手印,由於
這矮人村落已經和和平平地渡過數百年,因此矮人們開會的興趣也不高,除了每二十
年的例行會議外,這地方幾乎沒有人會進來閒晃.
CLong
    );
    set("search_desc",([
        "here":"@@to_search_here",
        ]) );
    set("exits",([
                "west":Deathland"/village/v52",
             ]));
    reset();
}
string to_search_here()
{
   object *items,ob1;
   int i;
   
   if ( be_searched==1 ) return 
       "似乎已經有人把這裡翻箱倒櫃地徹底搜查一遍了.\n";
   items=all_inventory(this_player());
   for(i=0;i<sizeof(items);i++) 
      if ((string)items[i]->query("name")=="broom") {
        ob1=new(Object"/key03");
        ob1->move(this_object());
        be_searched=1;
        this_player()->set_explore("deathland#9");
        return "當你一邊清掃,一邊找尋的時候,一把黑灰色的"
        "鑰匙赫然出現在你的面前.\n";
        }
   return 
     "這裡的灰塵很厚,\或許一邊拿著掃把一邊尋找會好一點.\n";  

}
void reset()
{
   ::reset();
   be_searched=0;
}
