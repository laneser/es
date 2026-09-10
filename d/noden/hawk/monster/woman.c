inherit MONSTER;

void create()
{
        ::create();
        set_level(3);
        set_name( "hawkman woman", "鳥人族婦人" );
        add("id",({"woman","hawkman"}) );
        set_short( "鳥人族婦人" );
        set_long(
                "你看到一個正為家事操勞的鳥人主婦.\n"
        );
        set( "gender", "female" );
        set( "race", "hawkman" );
        set( "alignment", 200 );
        set_natural_armor( 11, 6 );
        set_natural_weapon( 11 , 11 , 5 );
        set_perm_stat( "dex", 5 );
        set( "wealth/silver", 70 );
}

