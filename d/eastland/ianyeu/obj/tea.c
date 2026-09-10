inherit "/d/noden/asterism/item/drink.c" ;

void create()
{
    ::create();
    seteuid(getuid());
    set_name( "tea", "碧螺春" );
    set_short( "碧螺春" );
    set_long(
        "你看到一杯色澤青翠, 香氣清淡怡人的綠茶。令你忍不住想喝下它。\n" );
    set( "unit", "杯" );
    set( "container", 0 );
    set( "tp", 60 );
    set( "hp", 5 );
    set( "value",({ 100, "silver" }) ) ;
    set( "amount", 0 );
    set( "c_succ", "你喝下一杯碧螺春, 一陣清香停於口頰, 久久不散。\n" );
   set( "c_osucc", "$CN喝下了一杯碧螺春。\n" );
}
