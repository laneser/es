inherit WEAPON;

void create()
{
        set_name("Hell Wand","幽冥權杖");
        add("id",({"wand",}) );
        set_short("幽冥權杖");
        set_long(@C_LONG
這是黑帝斯賜給所有冥界修道士的權杖，唯有經過重重的考驗才能拿到這把
法杖，因此所有的修道士都十分珍惜這把得來不易的法杖
C_LONG
        );
        set( "unit", "把" );
        set( "weapon_class", 35 );
        set("type","wand");
        set( "min_damage", 10 );
        set( "max_damage", 25 );
        set( "weight", 70 );
        set( "value", ({ 1370, "silver" }) );
        set( "power_on", 1);
        set( "hit_func", "wand_hit" );
        set( "charge_left", 10 );
        set( "max_charge", 10 );
        set( "special_damage_type", "evil" );
        set( "special_damage", 40 + random(10) );
        set( "special_c_msg",@LONG
中所儲存黑帝斯的魔力放射出來，魔力籠罩在所有敵人的身上，這股
極其邪惡的力量讓所有的人受到無與倫比的傷害
LONG
        );
}
