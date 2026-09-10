#include <mudlib.h>

inherit WEAPON;

string C_NAME=("天空之劍");
void create()
{
        set_name( "Sky Sword",C_NAME );
        add( "id",({ "sword","sky","sky sword" }) );
        set_short( C_NAME );
        set_long(@LONG
天空之劍是鳥人族歷代相傳的聖物，鋒利異常，更有著招喚天雷的神聖力量，
意圖染指天空之城的蠻族戰士血濺其下者不可勝數。
LONG
                );
        set( "unit","把" );
        set( "type","longblade" );
        set( "weapon_class",35 );
        set( "min_damage",18 );
        set( "max_damage",35 );
        set( "weight",130 );
        set( "value",({ 1200,"silver" }) );
        set( "second",0 );
        set( "prevent_insert",1 );
        set( "hit_func","hit_fun" );
}

void report(object holder, object victim )
{
   seteuid(getuid());
   tell_object( victim,
   sprintf("( 你%s )\n","/adm/daemons/statsd"->status_string(victim)));
}

int hit_fun(object victim,int dis)
{
        object holder;
        string guild;
        int dam,skill,point1,point2,rate,hp,sp;
        string name1,name2;

        if( !victim ) return 0;
        if( !(holder=environment( this_object() )) || !living(holder) ) return 0;
        skill=(int)holder->query_skill("longblade");
        name1=holder->query("c_name");
        name2=victim->query("c_name");
        hp = (int)holder->query("hit_points");
        sp = (int)holder->query("spell_points");
        point1=holder->query_perm_stat("int");
        point2=victim->query_perm_stat("int");
        guild = holder->query("class");
        rate = point1 - point2;
        if (rate > 6) rate = 6;
        if( random(100) < (160 - skill - rate) ) return 0;
        dam = 20 + random(holder->query_skill("ethics")/8);
                // 要懂得辨別人心的善惡才能有效的打擊敵人....:p
                // 其實是因為某些scholar 自做聰明說不用練ethics ...有點不爽
        victim->receive_special_damage( "electric", dam );
        tell_room(environment(victim),"\n"+name1+"手中的天空之劍忽然發出一道"+
                "閃光直衝天際，\n頓時風雲變色，緊接著一道閃電從天而降，精準"+
                "的打在"+name2+"的頭上，造成難以言喻的傷害。\n",this_player()
        );
        tell_object(holder,"\n你手中的劍呼喚出"+set_color("雷神","HIB")
                +"的力量徹底的擊潰了你的敵人，造成了"
                +set_color("「難以想像」","HIR")+"的破壞！\n\n" );
        victim->set("last_attacker",holder);
        holder->set("hit_points",hp - 5);
        holder->set("spell_points",sp - 8);
        return dam;
}
