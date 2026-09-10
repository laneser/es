#include <mudlib.h>
#include "../legend.h"
inherit ROOM;

void create()
{
    ::create();
    set_short( "mountain1", "山巔" );
    set_long(@C_LONG
你身處一大片浮雲裡,白茫茫地使你看不到任何東西。 遠遠望去,隱隱約約有
幾座突出雲層的小山群,小山群好似戴著一頂頂白色的帽子。在你旁邊有好像有一
面光滑的峭壁 ( bluff ) 。
C_LONG
    );
    set( "light",1);
    set( "exit_suppress", ({
           "west"}) );
    set( "exits", ([
       "west":LAKE"mountain2"
    ]) );
    set("c_item_desc",([
        "bluff":"一面光滑的峭壁,似乎要很好的技術才能爬過去。\n"
    ]) );
    reset();
}
init()
{
   add_action("do_climb","climb");
}
int do_climb(string arg)
{
    object player;
    int probability;
    if ( !arg || arg != "bluff" )
       return notify_fail("你要爬什麼?\n");
    player=this_player();
    probability=(int)player->query_skill("climbing")/(int)player->query_level();
    if ( probability+random(5)>7 ) {
       tell_object(player,"你停也不停地一口氣爬過了峭壁。\n\n\n\n");
       tell_room(environment(player),sprintf(
          "%s停也不停地一口氣爬過了峭壁。\n",player->query("c_name")),player);
       player->move_player(LAKE"mountain4","SNEAK");
       player->receive_damage(10);
       tell_object(player,
          "該死!你由於落下的速度太快而被旁邊的樹藤給割傷!\n");
       "/d/magic/magic"->report( this_object(), player );
       return 1;  
    } 
    tell_object(player,
        "你使勁吃奶的力氣想爬過峭壁,卻因為攀爬的技術不好滑了下來。你滾啊滾"+
        ",滾到山腳下去了!\n");
    tell_room(environment(player),sprintf(
       "%s使勁吃奶的力氣想爬過峭壁,卻因為攀爬的技術不好滑了下來,滾啊滾,滾到山腳下去了!你不禁捧腹大笑。\n",player->query("c_name")),player);
    player->move(LAKE"mountain0","SNEAK");
    player->receive_damage(10);
    "/d/magic/magic"->report( this_object(), player );
    tell_room(environment(player),"有某一個東西滾到你的腳邊～～\n",player);
    return 1;    
}
