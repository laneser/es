#include "../iigima.h"

inherit MONSTER;
void create()
{
        ::create();
        set_level(6);
        set_name( "Drow  child", "黑暗精靈小孩" );
        add ("id", ({ "child", "drow", }) );
        set_short( "Drow  child", "黑暗精靈小孩" );
        set_long(
@C_LONG
這是個淘氣的小孩子，由他胸前的小紋章你知道他是個貴族。
C_LONG
              );
        set( "alignment",70);
        set( "gender", "male" );
        set( "race", "drow" );
        set( "unit", "個" );
        set_perm_stat( "str", 5 );
        set ("wealth", ([ "silver": 30 ]) );
        set_natural_weapon(3,2,5);
        set_natural_armor(30,0);
        set("weight", 210);
          set( "special_defense", ([
      "all":7,"fire":-10,"cold":-10,"evil":15,"divine":-30,]) );
        equip_armor("/d/noden/item/sandal");
        wield_weapon(OBJ"sb" );
}
// Ending QC.
