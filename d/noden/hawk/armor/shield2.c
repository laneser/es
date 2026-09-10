inherit ARMOR;

void create()
{
        set_name("Heaven shield","聖光盾");
        add( "id", ({ "shield" }) );
        set_short( "聖光盾") ;
        set_long(@LONG
這是一只經過詩摩爾聖力冶冶過的盾牌，威力自是不在話下，不過要能完全
發揮出它的力量，你自己也是要有點斤兩。
LONG
        );
        set("unit","面");
        set( "type", "shield" );

        set( "material", "mage");
        set( "armor_class", 6 );
        set( "defense_bonus", 3 );
        set( "no_sell",1);
        set( "weight", 100 );
        set( "equip_func","wear_func");
        set( "unequip_func","unwear_func");
        set( "value", ({ 100, "silver" }) );
}

void wear_func()
{
        if( (int)this_player()->query_level() < 15)
        {
                tell_object( this_player(),
                "唉..你的能力不夠..恐怕無法充份利用到盾牌的能力\n");
        }
        else
        {
                set( "armor_class",8);
                set( "defend_bonus",3);
        }

        if( ((int)this_player()->query("spell_levels/guild") < 45)||
          ((int)this_player()->query("spell_levels/black-magic") < 42))
        {
                tell_object( this_player(),
                "你對魔法的瞭解還不夠..無法讓盾真正發揮出它的威力\n");
        }
        else
        {
                set( "armor_class",8);
                set( "defend_bonus",6);
                set( "special_defense",
			([ "fire": -15, "evil": 10, "cold": 15,
				"divine": -10, "poison":-15, "energy": 15]));
                write( set_color(
                        "\n聖光盾呼應著你的魔力，散出一道金光籠罩在你的身邊...\n\n"
                        ,"HIW") );
        }
}

void unwear_func()
{
        set( "armor_class", 6 );
        set( "defense_bonus", 3 );
}
