inherit ARMOR;
void create()
{
     set_name( "captain's cloth","長袖對襟棉袍" );
     add( "id",({ "cloth" }) );
     set_short( "長袖對襟棉袍" );
     set_long(@C_LONG
以棉布製成的一件烏黑色棉袍，它的重量非常的輕，適合那些行動敏捷的人所穿。
C_LONG
     );
     set( "weight",50 );
     set( "unit", "件");
     set( "type", "body" );
     set( "material","cloth" );
     set( "defense_bonus",5 );
     set( "value",({ 2000,"silver" }) );
     set("special_defense",
        (["evil":-20]) );
}
