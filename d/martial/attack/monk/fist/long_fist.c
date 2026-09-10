// 少林寺武功「少林長拳」 
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
        "%s使出『馬步架打』右手向%s揮出",
        "%s使出一招『二龍分水』，砍向%s",
        "%s連續兩招『老樹盤根』『葉下藏花』，攻向%s",
        "%s左手護額，右手襲向%s，一招『頂心標拳』打出",
        "%s前弓後箭，使出一招『弓步頂肘』，打向%s",
        "%s一招『力劈華山』，砍向%s",
        "%s『舞花臥枕』、『□貓上樹』連續使出，抓向%s",
        "%s幾聲輕嘯，使出『天地相照』，擊向%s",
        "%s使出『掃堂腿』，飛腿卷向%s",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon,int type)
{
        return (20*monk_modify(victim)/100);
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon, int type)
{
        return (18*monk_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{
        return ((random(4)+3)*monk_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim,int type)
{
        if( !type ) return 0;
        return attack_msg[random(9)];
}
