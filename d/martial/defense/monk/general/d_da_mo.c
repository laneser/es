
varargs int can_use(object me, object victim, object weapon)
{
	if( !weapon || (string)weapon->query("type") != "blunt" )
		return 0;
	return 1;
}

string *defense_msg = ({
        "後退一步",
        "向後一閃", 
        "舉棍護身",
        "身體順勢一偏",
        "舉%s護頭，身子一低",
        "雙手前舉，微一旋轉身形",
});

varargs int hit_modify(object me, object victim, object weapon)
{
 if( !can_use(me, victim, weapon) ) return 0;
	return 5;
}

varargs int penetrate_modify(object me, object victim, object weapon)
{
	return 0;
}

varargs int damage_modify(object me, object victim, object weapon)
{
	return 0;
}

varargs string query_defense_msg(object me, object victim, object weapon)
{
	if( !can_use(me, victim, weapon) ) return 0;
        return defense_msg[random(6)];
}
