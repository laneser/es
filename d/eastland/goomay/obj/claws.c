
#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name( "iron claws", "鐵爪");
        add ("id",({ "claws"}) );
        set_short( "鐵爪");
        set("unit", "對");
        set_long(
            "這是一對可以裝在手上的利爪，雖然看起來不起眼，但泛藍的爪刃卻有著異樣的光彩\n"
        );
        set( "weapon_class", 10 );
        set( "type", "unarmed" );
        set( "min_damage", 8);
        set( "max_damage", 16);
	set("wield_func","wield_claws");
	set("unwield_func","unwield_claws");
        set( "weight", 55 );
	set("nosecond",1);
        set_c_verbs(({"%s刺向%s","%s抓向%s","%s揮向%s"}));
        set( "value", ({ 180, "silver" }) );
}

void unwield_claws()
{
	object owner;
	owner = environment(this_object());
 if (query("form"))
	{
        set( "weapon_class", 10 );
        set( "min_damage", 8);
        set( "max_damage", 16);
		set("prevent_drop",0);
        tell_room( environment(owner), 
        	owner->query("c_name")+"的黃金爪光芒退去，變回原來的樣子。\n"
			, ({ owner }) );
        tell_object( owner, 
         "你的黃金爪奇光斂去，自動與你的手分離。\n");

        set_name( "iron claws", "鐵爪");
        set_short( "鐵爪");
		set("form",0);
		return ;
	}
	return ;
}

void wield_claws()
{
	int st,iq,dx,kr,i,j;
	object owner;
	owner = environment(this_object());
	if ( (string)owner->query("class")=="adventurer")
	{
	st=owner->query_perm_stat("str");
        iq=owner->query_perm_stat("int");
        dx=owner->query_perm_stat("dex");
        kr=owner->query_perm_stat("kar");
	i = (st+dx+iq+kr)/3+random(6);
	j = ((int)owner->query_skill("unarmed"))/2 ;
        set( "weapon_class", ( j > 40 ? 40 : j ) );
        set( "min_damage", ( i<11 ? i : i-10 ));
        set( "max_damage", i);
	set("no_sale",1);
	set("prevent_drop",1);
        tell_room( environment(owner), 
         owner->query("c_name")+"的鐵爪發出一陣光芒，與他的手結合，變成他身體的一部份。\n"
	, ({ owner }) );
        tell_object( owner, 
	      "你的鐵爪泛出一片奇光，自動與你的手緊密結合。\n");
        set_name( "golden claws", "黃金爪");
        set_short( "黃金爪");
	set("form",1);
		return ;
	}
        return ;
}
