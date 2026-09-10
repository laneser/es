#include "mudlib.h"

inherit WEAPON;

int damage_count=0;

void create()
{       set_name("silver_spear","繡絲爛銀槍");
       add("id",({"spear","silver spear",}) );
       set_short("繡絲爛銀槍");
	   set_long(@C_LONG
一把用銀製成的短槍，拿在手上頗有份量，在手持處有美麗的刺繡．
根據東方大陸的傳說，銀有對抗邪惡的神聖力量...也許好人使用它會
更加得心應手??
C_LONG	);
	set( "second",1);
	set( "unit", "把" );
 	set( "weapon_class", 50 );
        set("type","thrusting");
	set( "min_damage", 16 );
	set( "max_damage", 22 );
	set( "weight", 140 );
	set( "value", ({ 400, "gold" }) );
        set( "wield_func","wield_spear" );
        set( "unwield_func","unwield_spear" );
}
void unwield_spear()
{
        object holder;
                
        if( !holder=environment(this_object()) ) return;
        set( "min_damage",16 );
        set( "max_damage",22 );
        return ;
 }                                                                                                                                                                 
 void wield_spear()
{
    object holder,we1;
    int align,ext_dam;
    if( !holder=environment(this_object()) ) return;
    we1 = holder->query("weapon1");
    if ( !we1 || we1->query("c_name") != this_object()->query("c_name") ) return;
    align = holder->query("alignment");
    if ( align < 8000 ) return ;
    ext_dam = align/6000 ;
    if ( ext_dam > 30 ) ext_dam = 30; 
    set( "min_damage", ext_dam );
    set( "max_damage", 18 + ext_dam );
    we1->set( "min_damage", 1 + ext_dam );
    we1->set( "max_damage", 19 + ext_dam );
     
    return;
}    
