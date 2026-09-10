#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("村莊道路");
	set_long(@LONG
你來到了一處羽民族居住的村莊道路上，西邊是一排排的小屋，南邊是大樹群
。由於這村落置身在一大片樹叢裡，顯得格外神秘又隱敝，好似一座天然的住處。
另外在道路上種植了許多葡萄樹，樹上的果實平時供羽民族食物，而果實中的液汁
也是羽民族賴以為生的水源。這村落由於沒什麼活動的空間，小孩子們都會跑到村
外的草原去遊玩，但大人們都深以為憂，恐怕這裡被人發現。東邊是羽民族大首領
居住的地方。另外在路旁有座大石雕，雕刻著羽民族傳說中的英雄，你可以向它膜
拜(worship)祈求它賜予你力量與勇氣。另外在在石雕旁還有塊黃色大石(stone)。

LONG
	);
	set("light",1);
	set("exits", ([ 
                "east" : SAREA"house3",
                "west" : SAREA"house4",
               "north" : SAREA"village1",
        ]) );
        set("objects", ([
               "stone" : SITEM"statue1"
        ]) );
        set( "c_item_desc", ([
               "stone" : @LONG
一顆有著純黃色的大石，黃色代表著東方和平的象徵，上面有被摸過(touch)的痕跡。
LONG
        ]) );
	reset();
}
void init()
{
     add_action("do_worship","worship");
     add_action("do_touch","touch"); 
}
int do_touch(string arg)
{
   if ( !arg || arg !="stone" )
       return notify_fail("你要摸什麼東西？\n");
   write("\n你好奇地摸一摸這塊黃色的大石，只見一道黃色的光線貫穿你的身子！\n\n\n
");
   this_player()->move_player("/d/eastland/8,5.east",({
      "%s的身子被一道黃色的光線貫穿！\n",
      "%s借著一道黃色來到了這裡.\n"}),"");
   write("\n在黃光之後，你被帶到了東方大陸。\n");
   return 1;
}
int do_worship()
{
     tell_object(this_player(),
        "你雙手合什，向雕像的神像膜拜，你感覺到全身似乎充滿了力量！\n");
     this_player()->save_me();
        "/adm/daemons/backup"->user_backup(this_player());
     return 1;
}