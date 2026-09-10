#include <mudlib.h>

inherit WEAPON;
void create()
{
        set_name( "scale blade","絞鱗長刀");
        add( "id",({ "blade" }) );
        set_short( "絞鱗長刀");
        set_long(
@CLONG
　　　　這是一把黑色無光澤的長劍，據說在數百年前，最偉大的勇者賽亞
        達曾獨闖禁斷之地，與司娜可女神熬戰數回，由於女神的神力，賽
　　　　亞達不敵而被打敗，後來的冒險家奇維在禁斷之地探險時，發現了
　　　　一副盔甲，據說就是賽亞達所留下的，裡面有許多不知名的大鱗片
　　　　於是奇姆就用這些鱗片打造成這把劍，劍身全是大鱗片所鑲成，具
　　　　有相當的傷害力。

CLONG
                );
        set( "unit", "把" );
        set( "weapon_class", 26 );
        set( "type", "longblade" );
        set( "min_damage", 25 );
        set( "max_damage", 38 );
        set( "nosecond", 1 );
        set( "bleeding", 16);        
        set( "weight", 140 );
        set( "value", ({ 1700, "silver" }) );
}
// WC, damage, bleeding is ok, suggest that:
// add some limit for 66 longblade(confused players*grin*)
// QCing.

int stop_wield(object owner)
{
   int lbskill;

   lbskill = (int)owner->query_skill("longblade");

   if( lbskill> 65 ) return 0;
      write( "你無法裝備此一武器。\n" );
   return 1;
}
