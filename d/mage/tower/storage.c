#include "/d/mage/mage.h"
inherit ROOM;
 
void create()
{
	::create();
	set_short("儲藏室");
	set_long(@LONG
這是一間小儲藏室, 資深的魔法師們將不需要的裝備堆置在此, 好讓
其他的魔法師們使用。拉修帝還特地在房間的入口處設下一道魔法屏障,
以防惡意的竊賊冒充魔法師潛入偷取放在此處的物品。
LONG
	);

	set("exits", ([
		"up"	: MAGE"hall_of_fame",
		]) );

	set("class_name","mage") ;	
	set("clean_msg1",
	    "儲藏室管理員%s對你大喊:這裡太多東西了, 你先清一點掉再放。\n");
	set("msg_arg1","松林隱者");
	set ("light", 1);
}

int receive_object(object arg)
{
    string msg ;
    object *contents;
//    ::receive_object(arg) ;   
    if(living(arg)) return 1 ;    
     if (base_name(arg)=="/std/statue") return 1;
    contents = all_inventory(this_object());
    if(sizeof(contents) >60) 
       {
           tell_object(this_player(),
                       sprintf(query("clean_msg1"),query("msg_arg1"))) ;     
           return 0 ;
        }
   else 
	{
	tell_room(environment(this_player()),
		sprintf("一陣紅色光芒籠罩著%s，然後漸漸消失了。\n",arg->query("c_name")));
	arg->delete("value");
	return 1;
	}
}
int clean_up() { return 0; }
