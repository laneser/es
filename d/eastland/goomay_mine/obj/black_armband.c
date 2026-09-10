#include "../zeus.h"
inherit ARMOR;

void create()
{
        set_name("wooden armband","黑木臂環");
        add( "id", ({ "wooden","armband" }) );
        set_short("wooden armband", "黑木臂環");
        set_long(@CLONG
這是一雙由千年鐵樹樹心磨製成的臂環，不知道是什麼緣故使它的
顏色變成了墨黑色，如果和黑色的盔甲搭配的話，剛好渾然一體好
看的不得了
CLONG
);
        set( "unit", "雙");
        set( "type", "arms" );
        set( "material", "wood");
        set( "armor_class", 3 );
        set( "defense_bonus", 4 );
        set( "equip_func","bonus_up");
        set( "unequip_func","stop_bonus_up");
        set( "special_defense",
               ([ "all":4 ]));
        set( "weight", 70 );
        set( "value", ({ 1800, "silver" }) );
}
void bonus_up()
{     object ob;
      if((ob=present("black platemail",environment(this_object()) ))&&
         (ob->query("equipped"))){
         set( "defense_bonus",5);
         set( "armor_class",4);
         tell_object(environment(this_object()),
 "當你穿上黑木臂環時發現它和黑色盔甲緊密結合，形成一套非常合身的裝備！\n"
         );
         return 0;
         }
         }
void stop_bonus_up()
 {
 set("defense_bonus",4);
 set("armor_class",3);
 }
