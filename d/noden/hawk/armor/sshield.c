inherit ARMOR;

void create()
{
        set_name("sky shield","天界之盾");
        add("id",({"shield"}) );
        set_long(@LONG
這把盾牌外形非常怪異，像一隻猛虎作勢要撲向敵人一樣，看來拿這把
盾牌不但可以充當防具，還有嚇唬敵人的效果唷。
LONG
        );
        set_short( "sky plate","天界之盾");
        set( "no_sale",1);
        set( "unit", "把" );
        set( "weight", 100 );
        set( "type", "shield" );
        set( "armor_class", 6 );
        set("material","light_metal");
        set( "defense_bonus", 6 );
        set( "value", ({ 720, "silver" }) );
}
