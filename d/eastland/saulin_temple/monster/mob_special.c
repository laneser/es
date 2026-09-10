// 怪物的特殊攻擊參考 : Mobs' special attack inherit
// Code by : Ruby of ES at 7/30/94
// 注意 : 引用(inherit)本程式後，要在程式碼中定義特殊攻擊的參數
// 例:  set("special_attack",(["damage_type" : "none","main_damage" : 10,
//                              "random_dam" : 5 , "hit_rate" : 20]));
//      set( "tactic_func", "my_tactic" );
// 及所需的文字訊息，包含中英文的 enemy_msg,room_msg,room_msg2 共六個。

#include <mudlib.h>
inherit MONSTER;

// 顯示被擊中後的受傷情形 : write by Echobomber
void report( object attacker, object victim )
{
   string message;
   seteuid(getuid());
   message= "/adm/daemons/statsd"->status_string(victim);
   tell_object( victim,"( 你"+message+" )\n");
}

// 以下所有內定函式都可被重新定義以增加變化性。

// 使用特殊攻擊失敗而遭反擊的條件 : fail_to_use()
int fail_to_use()       { return 0; }

// 特殊攻擊的出現機率  : special_hit_rate()
int special_hit_rate() 
 { return (int)query("special_attack/hit_rate") ; }

// 特殊攻擊所造成的傷害 : special_damage()
int special_damage(object victim)
    { return (int)query("special_attack/main_damage")+
		random(query("special_attack/random_damage")) ; }

// 特殊傷害的類型 : special_type() ，現有 11 種
// 為 : fire,code,electric,energy,mental,acid,poison,magic,evil,divine,none
string special_type() 
     { return (string)query("special_attack/damage_type") ; }

// 第二種特殊攻擊預留區 : 可以再定義一種以上的特殊攻擊形態
int second_special_attack() { return 0 ; }

int my_tactic()
{
        object victim;

if( random(100) > special_hit_rate() ||
	!(victim= query_attacker()) ) return 0;

// 如果有重新定義 fail_to_use() ! 那麼別忘了也得設定中英文的 fail_room_msg
    if ( fail_to_use() ) {
                tell_room( environment(), 
			query("c_name") + query("c_fail_room_msg"),
			this_object() );
	receive_special_damage( special_type() , special_damage(victim));
        report(this_object(), this_object() );
        return 0;
    }
      if ( second_special_attack() ) return 1;

        tell_object( victim, query("c_enemy_msg")   );
        tell_room( environment(), 
	query("c_room_msg")+ victim->query("c_name") +query("c_room_msg2") 
        , ({ victim, this_object() }) );

        victim->receive_special_damage( special_type() ,special_damage(victim) );

	report(this_object(),victim);
	return 1;

}
