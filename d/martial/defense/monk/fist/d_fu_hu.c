// 少林寺武功「伏虎拳」 part3
// angel
// Jun 4 1994

varargs int can_use(object me, object victim, object weapon)
{
        if( weapon) return 0;
        return 1;
}
string *defense_msg = ({
        "%s雙手用力向前一擋", 
        "%s使出『黑虎盤山』雙掌護身",
        "%s身形下沉，左手護額",
        "%s硬生生的承受此一攻擊",
        "%s左手往前用力一架",
        "%s旋轉身形，揮出雙拳一架",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon )
{
        return 6;
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon)
{
        return 4;
}

varargs int damage_modify(int damage, object me, object victim, object weapon)
{
        return 0;
}

varargs string query_defense_msg(object me, object victim, object weapon)
{
        if( !can_use(me, victim, weapon) ) return 0;
        return defense_msg[random(6)];
}
