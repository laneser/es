#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name( "red sleeve blade", "紅袖刀" );
        add( "id", ({ "blade","red sleeve blade" }) );
        set_short( "紅袖刀" );
        set_long(@LONG
這是一把讓人一見鍾情的刀。刀鋒是透明的，刀身緋紅，刀光漾映，像透明的玻璃
鑲裹著緋紅色的骨脊。刀略短，刀彎處如絕代佳人的纖腰，揮動時帶著一種音賴似
的清吟，還掠起微微的香氣。這就是名聞江湖的～  紅袖刀  ～。
LONG);

        set( "unit", "把" );
        set( "type", "longblade" );
        set( "weight", 70 );
        set( "weapon_class", 35 );
        set( "min_damage", 25 );
        set( "max_damage", 40 );
        set( "value", ({ 720, "gold" }) );
        set_c_verbs( ({
           "手執%s，身形一掠，刀鋒在空中劃出一道長虹斬向%s",
           "運勁一震%s，刀身發出一聲清吟，\n一式【黃鶯出谷】，～～刀鋒直取%s",
           "使出亂披風刀法，%s狠狠的揮向%s",
           "攻勢一變，%s刀身暴熾，四周空氣變得燥熱，\n無數的刀影伴著如烈焱一般的內勁卷向%s",
           "使出【運轉七星】，只見%s刀光點點，瞬間罩住了%s",
           "刀法一緩，%s如鑿刻般的砍向%s",
           "倒轉%s，刀柄直扣%s",
           "刀勢一變，倏地，%s刀身上結了一層薄霜，四周氣溫驟降，\n一道陰寒的刀勁攻向%s",
        }) );
}
