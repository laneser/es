// 少林寺武功「羅漢拳」 part3
// angel
// Jun 4 1994

varargs int can_use(object me, object victim, object weapon)
{
       
        if( weapon ) return 0;
        return 1;
}

string *defense_msg = ({
        "%s回身向後一閃", 
        "%s雙掌護身，順勢一偏",
        "%s身體順勢一偏",
        "%s左手護頭，身子一低",
        "%s左手上前架住",
        "%s沉肩退步，微一旋轉身形",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon )
{
        return 0;
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon)
{
        return 6;
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
