// 少林寺武功「龍爪手」 part2
// Text Data from book 「倚天屠龍記」
// modify by Wind
// May 28 1994
// second modify by Wind
// Jun 4 1994

int query_need_fp()

{ 
    return 5;
}
int gonfu_level(object me)
{
        // 傳回熟練值
        return (int)me->query("gonfus/windleg");
        //                     ^^^^^^^^^^^^^^^^^^熟練度
}

varargs int can_use(object me, object victim, object weapon)
{
        // 確定所使用武器是否正確
        if( weapon ) return 0; // 徒手武功
        return 1;
}

// 各式戰鬥訊息
string *attack_msg = ({
        "%s腿如旋風的踢向%s",
        "%s身形一動，腿已踢到了%s",
        "%s使出「風捲殘樓」一招，連續踢出，踢到%s",
        "%s身形一落，踢向對手下盤",
        "%s突然閃到了對手面前，踢向%s",
        "%s拔身而起，從高處踢向%s",
});

varargs int hit_modify(int hit_chance, object me, object victim, object weapon,int type)
{
	int i,delta_dex;
        // 命中率調整
        if( !(type) ) return 0;
        delta_dex = (int)me->query_stat("dex")-(int)victim->quert_stat("dex");
        if ( delta_dex<0) { delta_dex=0; } 
        // 命中率調整值為 百分之（ 30 + 熟練度/3 + 雙方敏捷度差/2 ）
        i = 30 + gonfu_level(me)/20 + delta_dex*5 ;
   	if( (int)me->query("force_points") < query_need_fp() ){	i = -5; }
        return i;
}

varargs int penetrate_modify(int pene_chance, object me, object victim, object weapon,int type)
{
        // 穿透率調整減百分之十（速度快，穿透率就小了）
        return -10;
}

varargs int damage_modify(int damage, object me, object victim, object weapon,int type)
{
        int i;
        // 攻擊力調整
        if( !type ) return 0;
        i = gonfu_level(me)/5+10;
        // 攻擊力調整為百分之（  熟練度/5+20）
        if( (int)me->query("force_points") < query_need_fp() ){	i = -5; }
            else {me->add("force_points",-query_need_fp()); } 
        return i;
}

varargs string query_attack_msg(object me, object victim, int type)
{
        string a_msg;
        if( !(type) ) return 0;
        a_msg = attack_msg[random(sizeof(attack_msg))];
        if( (int)me->query("force_points") < query_need_fp() )
        { a_msg = a_msg+"，但是出腿時顯得內力不足的感覺";}
return a_msg;
}
