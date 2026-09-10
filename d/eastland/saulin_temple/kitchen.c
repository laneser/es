#include "saulin_temple.h"

inherit SELLER;
inherit ROOM;

int book_found = 0;

void create()
{
	object ob,ob2;
	::create();
	set_short("香積廚");
	set_long( @C_LONG_DESCRIPTION
這是一間四周有著大窗戶的房間，房子的中央是兩個大火爐其上各
有一飯鍋，北邊放有許多的餐具，西邊則是一個洗潔槽，此處供應少林
寺數千僧侶的伙食，此刻正有許多人在裡面忙著切菜煮飯，而煮飯產生的
蒸氣正嫋嫋的上升，使整個房間瀰漫著蒙濃白霧。你看到門口貼了張紙
(paper) 好像是價目表。  
C_LONG_DESCRIPTION
	);
	set("light", 1);
	set("exits", ([
        "east"  : SAULIN"grass5",
	]) );
    set( "item_func",([ "paper" : "show_menu" ]));
    set_inventory( ({
//       ({ SAULIN_OBJ"vege_food", 10, 10 }),
       ({ SAULIN_OBJ"apple" , 5, 5 }),
       ({ SAULIN_OBJ"banana", 5, 5 }),
    }) );

        ob = new( SAULIN_MONSTER"cooking_monk" );
        ob->move( this_object() );
        ob2 = new( SAULIN_MONSTER"gin_ping" );
        ob2->move( this_object() );

	reset();	
}

void init()
{
   seller::init();
   add_action("do_search","search");
}

int do_search()
{
   object obj,obj2;
   obj = this_player();
   if ( obj->query_temp("monk_movement") && book_found == 0 &&
        obj->query_temp("book_quest/step") == 3)
   {
       tell_object(obj,@MSG1

你聽了火工頭陀的話後, 在這兒仔細尋找, 果然在角落發現了一本經書。
你趕緊拿起來看看, 書名正是－－楞枷經。

你心想皇天不負苦心人, 你終於找到它, 趕快去回報給方丈知道吧!!
MSG1
);
       obj2 = new("/d/eastland/saulin_temple/obj/sutra.c");
       obj->set_temp("book_quest/step",4);
       obj2->move(obj);
       book_found = 1;
       return 1;
   }
   return 0;
}
void reset()
{
    ::reset();
    book_found = 0;
}
