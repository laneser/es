#include <mudlib.h>

inherit ARMOR;

void create()
{
      set_name("fish cloth","漁衣");
      add("id",({"cloth"}) );
      set_short("漁衣");
      set_long(@C_LONG
一件尋常打漁人家所穿的衣服。雖然設計的不是很新潮，但是，對於長期在外討生
活的漁夫，卻也提供了良好的防護。
C_LONG           );
      set( "unit", "件" );
      set( "weight",50 );
      set( "type", "body" );
      set("material","cloth");
      set( "armor_class", 20);
      set( "defense_bonus", 5 );
      set("special_defense",
          (["poison":20,"acid":20,]) );
      set( "value", ({700, "silver" }) );
}                                                                                                             