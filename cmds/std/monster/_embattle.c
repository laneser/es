//#pragma save_binary

#include <mudlib.h>

#define SCHOLAR_EMBATTLE_DIR "/d/scholar/embattle/"
#define SCHOLAR_EMBATTLE_SKILL "embattle/"

inherit DAEMON;

int help();

void delete_effect(object man,int ac_effect,int db_effect,int wc_effect)
{
  if (man) {
    if (man->query_temp("embattle_busy")) {
      man->delete_temp("embattle_busy");
      man->set_temp("extra_ac/body",(int)man->query_temp("extra_ac/body")-ac_effect);
      man->set_temp("extra_db/body",(int)man->query_temp("extra_db/body")-db_effect);
      man->calc_armor_class();
      man->set_temp("extra_wc",(int)man->query_temp("extra_wc")-wc_effect);
    }
  }
}

void delete_embattle_effect(object me)
{
  int i,ac,db,wc;
  object *party;

  party=me->query_temp("embattle_party");
  ac=(int)party[0]->query_temp("embattle_ac");
  db=(int)party[0]->query_temp("embattle_db");
  wc=(int)party[0]->query_temp("embattle_wc");
  for(i=0;i<sizeof(party);i++)
    delete_effect(party[i],ac,db,wc);
  return;
}

void check_eight(object me,string other)
{
  int member=0,i;
  object leader,*total_party;

  if (!leader = present(other,environment(me))) {
     tell_object(me,"喂 !! 你在這裡要和誰結陣 ?\n");
     return;
  }
  if (me->query_temp("other_party_leader")) {
    tell_object(me,"你現在就可以發動八卦游龍陣了。\n");
    return;
  }
  if (me->query_temp("depend_on_eight")) {
     tell_object(me,"你現在要靠別人來發動陣勢。\n");
     return;
  }
  if ((string)leader->query_temp("leader") != (string)leader->query("name")) {
     tell_object(me,"你必須和另一隊伍的領導人合作，不是隨便亂找。\n");
     return;
  }
  if ((string)leader->query("class")!="scholar") {
     tell_object(me,"要施展八卦游龍陣必須和另一書生所領導的隊伍結陣。\n");
     return;
  }
  if ( (string)me->query_temp("leader") != (string)me->query("name")) {
     tell_object(me,"唉 ～ 又不是你領導作戰，下什麼命令嘛 ...\n");
     return;
  }
  if( (int)me->query("stop_attack")>0 ) {
     tell_object(me,"( 你上一個動作還沒有完成，無法佈陣。 )\n");
     return;
  }
  for( i=0;i<sizeof(total_party=(mixed *)me->query_temp("party_members"));i++ )
     if(total_party[i]) {
        if (environment(total_party[i]) == environment(me))
           member++;
     }
  if (member!=4) {
    tell_object(me,"你的隊伍不到四個人還想玩八卦游龍陣。\n");
    return;
  }
  leader->set_temp("other_party_leader",me);
  me->set_temp("depend_on_eight",leader);
  tell_object(leader,(string)me->query("c_name")+"和你形成八卦連鎖關係。\n");
  tell_object(me,"八卦游龍陣連鎖完成。\n");
  return ;
}

void party_disband(object me)
{ 
  object other;

  if (other=me->query_temp("other_party_leader")) {
    other->delete_temp("depend_on_eight");
    me->delete_temp("other_party_leader");
    tell_object(me,"解開八卦游龍陣連鎖關係。\n");
    tell_object(other,"解開八卦游龍陣連鎖關係。\n");
  }
  else if (other=me->query_temp("depend_on_eight")) {
    other->delete_temp("other_party_leader");
    me->delete_temp("depend_on_eight");
    tell_object(other,"解開八卦游龍陣連鎖關係。\n");
    tell_object(me,"解開八卦游龍陣連鎖關係。\n");
  }
  else
    write("你要解散啥 ?\n");
  return; 
}

int cmd_embattle(string str)
{
        mapping check1;
	object me,victim,target;
	string name,who,*check2,other,disband;
        int flag;

        if( !str ) return help();

        me=this_player();

	if (sscanf(str,"%s at %s",name,who) != 2) {
          if (sscanf(str,"eight with %s",other) != 1) {
            if (sscanf(str,"eight %s",disband)==1) {
              if (disband=="disband") {
                call_out("party_disband",0,me);
                return 1;
              }
              else 
                return help();
            }
            else
              return help();
          }
          else {
            call_out("check_eight",0,me,other);
            return 1;
          }
        }

	if (!me->query(SCHOLAR_EMBATTLE_SKILL+name)) 
                return notify_fail("咦？你聽過這種陣法嗎？\n");

	if (!(victim = present(who,environment(me))))
		return notify_fail("喂 !! 你要扁人至少也要找好對象吧 !!\n");

        if ( victim->query("user") ) {
            if( !member_group((string)me->query("name"), "admin") &&
                    (victim->query_level()<5 || me->query_level()<5) )
            return notify_fail("在東方故事中五級以下的玩家不準 PK 和 PK 別人。\n");
        }

        if ((int)victim->query("no_attack"))
            return notify_fail("別輕舉妄動，這個東東不能殺就是不能殺 !!\n");

	if ( (string)me->query_temp("leader") != (string)me->query("name"))
		return notify_fail("唉 ～ 又不是你領導作戰，下什麼命令嘛 ... 沒人理你很糗吧。\n");

	if( (int)me->query("stop_attack")>0 )
		return notify_fail (
			"( 你上一個動作還沒有完成，無法佈陣。 )\n");

	if( environment(me)->query("no_embattle"))
		return notify_fail( 
			"你正準備列陣時，竟然發現這裡是個難以列陣的絕地。\n");

        if( me->query_temp("embattle_busy") ) {
          if( !me->query_attacker() )
            delete_embattle_effect(me);
          else if( member_array(me->query_temp("embattle_victim"),me->query_attackers(),flag)==-1 )
            delete_embattle_effect(me);
          else 
            return notify_fail("你目前正忙著推動陣勢，沒空想別的事情。\n");
        }

        switch(name) {
        case "eight" :
          call_out("check_party",0,me,victim);
          break;
        default :
          (SCHOLAR_EMBATTLE_DIR+name)->start_embattle(me,victim);
          break;
        };
	return 1;
}

int check_party(object me,object victim)
{
   if (me->query_temp("depend_on_eight"))
     return notify_fail("你現在必須等另一人啟動陣勢。\n");
   if (!me->query_temp("other_party_leader"))
     return notify_fail("施展八卦游龍陣需要兩個對伍一起佈陣。\n");
   (SCHOLAR_EMBATTLE_DIR+"eight")->start_embattle(me,victim);
   return 1;
}

int help()
{
		write( @C_HELP
指令格式: embattle <陣勢名稱> at <攻擊目標>

這個指令讓你用來推動陣勢。一般來說一個由書生為隊伍領導人的單一隊伍
即可運用陣法攻敵，陣法運作時，可以增加隊伍的防禦力及破壞力，不過你
也可能被敵人發現破綻或有人臨陣脫逃而使得陣法失效。
唯一的例外是當你要施展八卦陣時，需要按照下列步驟：
1. 需要兩組四人組成的隊伍，當然是書生領隊。
2. 一個書生先下 embattle eight with <another leader name>
3. 另一真正啟動陣式的書生下 embattle eight at <victim name>
4. 假如沒錯誤,則八卦游龍陣會開始運作。
5. 想要使兩個隊伍的關係拆散，可用 embattle eight disband
你可以用 embattles 指令回想你還記得的陣勢。
C_HELP
		);
    return 1;
}
