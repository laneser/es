inherit ARMOR;

void create()
{
        set_name("sky amulet","天空守護徽章");
        add("id",({"amulet","sky amulet"}) );
        set_long(@LONG
這是天空之城自古相傳的徽章，由天空之城所獨有的奇里斯金屬
所打造，外加上天界神聖的力量加諸其上，傳說裡誰要是能得到這枚
守護徽章，就能和大地融為一體，得到無窮無盡的力量。不過老一輩
的鳥人都說，把這枚徽章放到吸收過神聖太陽光芒的三角錐裡，在祭
壇神聖力的催化之下，可以釋放出徽章蘊含的能量。
LONG
        );
        set_short( "sky amulet","天空守護徽章");
        set( "no_sale",1);
        set( "unit", "枚" );
        set( "weight", 10 );
        set( "type", "misc" );
        set( "armor_class", 0 );
        set("material","light_metal");
        set( "defense_bonus", 6 ); //hope can higher ....
        set( "value", ({ 1290, "silver" }) );
}
