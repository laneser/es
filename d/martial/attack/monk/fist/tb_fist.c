// 少林寺武功「少林通臂拳」 
// modify by angel 
// 6/1 1994
inherit "/d/martial/attack/modify";
varargs int can_use(object me, object victim, object weapon)
{
        if( weapon ) return 0; // 徒手武功
        return 1;
}

// 各式戰鬥訊息
string *attack_msg = ({
        "%s使出『金沙飛掌』雙手開板向%s揮出",
        "%s使出一招『二郎擔山』，擊向%s",
        "%s平心一擊『閃門飛炮』，攻向%s",
        "%s由下往上襲向%s，此乃『天王託塔』",
        "%s雙手快攻，使出一招『雙風灌耳』，打向%s",
        "%s一招『執印翻天』，砍向%s",
        "%s弓步斜形雲飛天，一招『珍珠捲簾』擊向%s",
        "%s一聲低嘯，使出『追風相連』，飛撲%s",
        "%s使出『繇子翻身』，反身踢向%s",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon,int type)
{
        return (25*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon, int type)
{
        return (18*monk_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{
        return ((random(6)+4)*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim,int type)
{
        if( !type ) return 0;
        return attack_msg[random(9)];
}
