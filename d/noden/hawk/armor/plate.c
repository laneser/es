inherit ARMOR;

void create()
{
        set_name("heavy plate","重型盔甲");
        add("id",({"plate"}) );
        set_short( "heavy plate","重型盔甲");
        set( "no_sale",1);
        set_long(
                "這是一套你所看過最堅固耐用的盔甲，如果不是天賦"+
                "神力恐怕穿起來就連動都不能動羅。\n" );
        set( "unit", "件" );
        set( "weight", 410 );
        set( "type", "body" );
	set("armor_class", 30 );
        set( "material","heavy_metal");
        set( "defense_bonus", 7 );
        set( "value", ({ 2190, "silver" }) );
        set( "extra_stats",([
                        "con" : -1,"int" : -1,"dex" : -1,
                        "pie" : -1,"kar" : -1,"str" : -1,
                                ]) );

}
