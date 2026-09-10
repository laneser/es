inherit MONSTER;
void create()
{
        ::create();
        set_level(3);
        set_name( "Servant","僕人" );
        add("id",({"servant"}) );
        set_short( "僕人" );
        set_long(@LONG
雷多家的僕人，身上穿的破破爛爛，不過工作的滿認真的，頗得雷多的喜愛。
LONG
        );
        set( "alignment", 200 );
        set( "gender","male" );
        set( "race","hawkman" );
        set( "chat_chance",12);
        set("chat_output",({"僕人自言自語: 雷多大人的酒呢...?\n"}));
        set( "wealth/silver", 300 );
}
