#include <mudlib.h>

inherit OBJECT;

void create()
{
        seteuid( getuid() );
        set_name("news plaque", "佈告欄");
        set_short("佈告欄");
        add( "id", ({"news","plaque",}) );
        set( "long", "@@query_long" );
        set( "unit", "塊" );
        set( "weight", 10000 );
        set( "prevent_get", 1);
}

string query_long()
{
   write( "東方故事最新公告：\n" );
   cat( "/adm/news/c_motd" );
   write( @MORE
發現BUG 欲直接報告於巫師者，請前往冒險者公會地下室北邊之公告
大廳，參考STATUE給予之資料，直接聯繫各主管之巫師，相信你能得
到更滿意的答覆。

MORE
   );
   return "或者直接POST於BUG 佈告欄，巫師們亦會及早處理該問題。\n";
}
