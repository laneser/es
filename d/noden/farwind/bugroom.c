//modify by Hch..////#pragma save_binary
#include <mudlib.h>
#include <daemons.h>

inherit ROOM;

void create()
{
        ::create();
        set_short( "公告大廳" );
        set_long(@C_LONG
你現在正站在一間寬廣寧靜的大殿之中, 你看到四周均是耀眼的七彩水晶,
這些水晶發出的光芒令人目眩神移, 讓人幾乎忘記自己的置身所在。而這些光芒
全都射向大殿中央一具魔法雕像(statue)的身上。南邊的水晶大門通往任務殿堂。
C_LONG
        );
        
        set("item_desc",([
            "statue":"@@c_bug_master",
        ]) );
        set( "light", 1 );
        set( "exits", ([
            "south" : "/d/noden/farwind/quest_room",
        ]) );
}
void init()
{
    add_action("do_ask","ask");
}

string c_bug_master()
{
   int hour;

   sscanf(WEATHER_D->query_game_time(),"%d",hour);
   if( hour >= 6 && hour < 18)
      write("\n當你看著這雕像時, 一道金黃色的光芒由雕像射出\n"
              "聚集成了一個人型, 同時一個莊嚴而低沉的聲音對\n"
              "你說道:「我是日之守護靈,孩子,你有什麼困難嗎?」\n" );
   else
      write("\n當你看著這雕像時, 一道柔和的藍色光芒由雕像射出\n"
              "聚集成了一個人型, 同時一個清脆而悅耳的聲音對你\n"
              "說道:「我是夜之守護靈,孩子,你有什麼困難嗎?」\n" );
   cat( "/d/doc/domain_master/domain_list" );
   return "你可以問(ask)我有誰可以「有效地」幫助你.\n";
}
int do_ask(string arg)
{
       mixed num;
    if( !arg ) {
        write("你可以使用 ask <number> 獲得更多的資料.\n");
       return 1;
    } else if( sscanf(arg,"%d",num) == 1 ) {
        cat( "/d/doc/domain_master/bug_master_"+num );

        return 1;
    }
    write("你可以使用 ask <number> 獲得更多的資料.\n");
    return 1;
}

