inherit ARMOR;

void create()
{
        set_name("sky plate","天空之鎧");
        add("id",({"plate"}) );
        set_long(@LONG
這是天空之城自古相傳的鎧甲，由天空之城所獨有的奇里斯金屬所打造，外加
上天界神聖的力量加諸其上，因此成為史上最強大的防具之一。\n"
LONG
        );
        set_short( "sky plate","天空之鎧");
        set( "no_sale",1);
        set( "unit", "件" );
        set( "weight", 140 );
        set( "type", "body" );
	set( "armor_class", 31 );
        set("material","light_metal");
        set( "defense_bonus", 6 ); // 希望能高一點 *因為是輕金屬 ac 不大高*
	set("special_defese",(["cold" :10 ,"fire" : -20," electric": 10 ]) );
        set( "value", ({ 290, "silver" }) );
}
