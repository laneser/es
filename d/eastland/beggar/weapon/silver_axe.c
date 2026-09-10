#include <mudlib.h>      
        
inherit WEAPON;
        
void create()
{        
     set_name("silver axe","銀斧");
     add("id",({"silver","axe"}) );
     set_short("銀斧");
     set_long(@C_LONG
這是一把小巧精緻的銀製銀斧。
C_LONG
     );
     set("unit","柄");
     setup_weapon( "axe", 45, 30, 47 );
     set( "weight", 250 );
     set("second",1);
     set( "value", ({ 2800, "silver" }) );
}
int stop_wield()
{
     object holder;
     int my_ali;
     holder = this_player();
     my_ali = (int)holder->query("alignment");
     if (my_ali > 6000 )
        return 0;
     else {
        notify_fail(
          "你還不夠善良使得銀斧不聽你的指揮，令你握不住它。\n\n");
        return 1;
     }
}                                                                                                                                                                       