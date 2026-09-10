// godleg.c
// This is a defense skill that is only available for wizards.

varargs int can_use(object me, object victim, object weapon)
{
	if( wizardp(me) || (string)me->query("name") == "lucia" ) return 1;
	return 0;
}

string *defense_msg = ({
	"%s身形一晃，向後退了七步",
	"%s縱身向上一躍",
	"%s腳踏乾宮，轉艮位",
	"%s雙掌一格",
	"%s袖袍一揮",
	"%s突然低身前進",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon)
{
	if( !can_use(me, victim, weapon) ) return 0;
	return 100;
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon)
{
	if( !can_use(me, victim, weapon) ) return 0;
	return 100;
}

varargs int damage_modify(int damage, object me, object victim, object weapon)
{
	if( !can_use(me, victim, weapon) ) return 0;
	return 100;
}

varargs string query_defense_msg(object me, object victim, object weapon)
{
	if( !can_use(me, victim) ) return 0;
	return defense_msg[random(sizeof(defense_msg))];
}
