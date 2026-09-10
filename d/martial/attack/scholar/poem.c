// Unknow sword, a sword gonfu for scholars.
inherit "/d/martial/attack/modify";

varargs int can_use(object me, object victim, object weapon)
{
	int type, lvl, i;
	string last;

	lvl = (int)me->query("scholar_gonfu/poem");
	if( undefinedp(lvl) ) return 0;
	if( last = (string)me->query_temp("last_attack_skill") )
		switch( last ) {
			case "poem1"  : type = 1;  break;
			case "poem2"  : type = 2;  break;
			case "poem3"  : type = 3;  break;
			case "poem4"  : type = 4;  break;
			case "poem5"  : type = 5;  break;
			default	     : type = 0;  break;
		}
	i = type * 15 + lvl * 2 + 1;
	if( type > 0 && type < 5 && random(i) > 15 * type ) type++;
	else type = 1;
	me->set_temp("last_attack_skill", ("poem"+type));
	return type;
}

int query_need_fp()
{
	return 4;
}

string *attack_msg = ({
"的%s泛出點點寒光，以古詩劍法之「孟冬寒氣至，北風何慘慄」向%s急速刺去",
"長嘆一聲：「白楊多悲風，蕭蕭愁殺人」手中%s一圈，自下而上，向%s斜斜撩出一劍，勢勁力強",
"的%s嗡嗡作響，劍發琴音，光環亂轉，以古詩劍法之「音響一何悲，弦急知柱促」在半空中劃一道弧線的向%s急刺過去",
"運足內力，用%s施展古詩劍法中的「玉衡指孟冬，眾星何歷歷」只見一片白光籠罩著%s",
"用%s施展出劍法中最強的「人生天地間，忽如遠行客」如河海翻騰之勢往%s刺去"
});

int *hits = ({ 30, 55, 45, 65, 40 });
int *pens = ({ 15, 27, 35, 45, 50 });
int *dams = ({ 35, 41, 47, 53, 60 });

varargs int hit_modify(int hit, object me, object victim, object weapon, int type)
{
	if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -20;
	return ((hits[type-1] + random((int)me->query("scholar_gonfu/poem")))*scholar_modify(victim)/100);
}

varargs int penetrate_modify(int pene, object me, object victim, object weapon, int type)
{
	if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -20;
	return ((pens[type-1] + random((int)me->query("scholar_gonfu/poem")))*scholar_modify(victim)/100);
}

varargs int damage_modify(int damage, object me, object victim, object weapon, int type)
{
	if( type < 1 || type > 5 ) return 0;
	if( (int)me->query("force_points") < query_need_fp() ) return -5;
	me->add("force_points", -query_need_fp());
        if (!environment(me)->query("PK_ZONE"))
	me->add("gonfus_exp/poem", 2*type+random(2*type));
	return (dams[type-1]*scholar_modify(victim)/100);
}

varargs string query_attack_msg(object me, object victim, int type)
{
	if( type < 1 || type > 5 ) return 0;
	return attack_msg[(type-1)];
}
