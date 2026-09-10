// 少林寺武功「少林通臂拳」 part3
// angel
// Jun 4 1994

varargs int can_use(object me, object victim, object weapon)
{
       
        if( weapon ) return 0;
        return 1;
}

string *defense_msg = ({
        "%s後退幾步",
        "%s向後一閃", 
        "%s斜身一閃",
        "%s身體順勢一偏",
        "%s端臂一頂",
        "%s劈腿轉身一躲",
        "%s旋轉身形，單腳飛天",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon )
{
        return 4;
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
        return defense_msg[random(7)];
}
