inherit MONSTER;

void create()
{
        ::create();
        set_level(3);
        set_name( "hawkman man", "鳥人族壯丁" );
        add("id",({"man","hawkman"}) );
        set_short( "鳥人族壯丁" );
        set_long(
                "身體強壯的鳥人壯丁，不過因為某些緣故所以沒有接受軍事訓練.\n"
        );
        set( "gender", "male" );
        set( "race", "hawkman" );
        set( "alignment", 300 );
        set( "time_to_heal", 15 );
        set_natural_armor( 13, 7 );
        set_natural_weapon( 13 , 15 , 7 );
        set_perm_stat( "dex", 6 );
        set( "wealth/silver", 90 );
}

