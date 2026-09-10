//#pragma save_binary
 
// guild.c
// Written by Mobydick@TMI-2, 11-15-92
// Almost rewritten by Annihilator@Eastern.Stories, 10-26-93
// Please leave the credits part of this header in place.
// You can delete the rest of it.
 
#include <daemons.h>
#include <stats.h>
#include <explore.h>
#include <mudlib.h>
#include <move.h>
#include <org.h>
 
inherit ROOM;
 
// The variable trainable_skills stores the skills which this guild can
// train you in.
 
string this_guild;
 
void set_guild(string class);
 
int do_list(string arg);
int do_cost(string arg);
int do_advance(string arg);
int do_train(string arg);
int do_help(string arg);
int do_explore(string area);

// This function announce all member of this guild some message.
void announce_guild_members(string type, object me)
{
        string *master, class, c_msg;
        object *urs;
        int i;
        
        urs = users();
        master = this_guild->query_guild_master();
        if( !master ) master = ({ "Master", "公會老大" });
        class = (string)me->query("organization");
        c_msg = "["+to_chinese(class)+"] "+master[1]+" : ";
        if( type == "join" ) {
                c_msg += "歡迎 "+me->query("c_name")+"("+me->query("name")+") "+
                  "正式加入我們的行列!\n";
        } else return;
        for( i=0; i<sizeof(urs); i++ )
                if( this_guild->is_guild_member(urs[i]) )
                        urs[i]->quick_message(c_msg);
}

// This function sets the classes that are allowed to train/advance in
// the guild. If you pass the string argument ALL, then all classes can
// train/advance here. Otherwise, you should pass an array of strings 
// containing the names of classes that are allowed to train/advance
// in this guild.

void set_guild(string guild)
{
        if( file_size(guild)>0 )
                this_guild = guild;
        else
                this_guild = GUILD_MASTER(guild);
}

// Init adds the cost and train commands. You must call this if you
// add your own init functions. (i.e. you must call guild::init();
// in the init() of your guild.

void init()
{
        add_action("do_cost", "cost");
        add_action("do_list", "list");
        add_action("do_advance", "advance");
        add_action("do_train", "train");
        add_action("do_join", "join");
        add_action("do_verify", "verify");
        add_action("do_help", "help");
        add_action("do_explore", "explore");
        add_action("do_quests", "quests");
}

int do_list(string arg)
{
        int i;
        string msg, *skills;

        skills = this_guild->query_skill_list();
        msg = "在這裡你所能訓練的技能有:\n";
        for( i=0; i<sizeof(skills); i++)
                        msg += sprintf("    %-30s ( 經驗值比例 = %3d%%, 上限 = %3d )\n", 
                                to_chinese(skills[i]) + "("+skills[i]+")",
                                this_guild->query_skill_cost(skills[i]),
                                this_guild->query_skill_max(skills[i]) );
        write(msg);
        return 1;
}
int query_org_exp(int lv)
{
	int i,exp;
	if(lv>MAX_ORG_LEVEL) lv= MAX_ORG_LEVEL;
	if(lv<0) lv=0;
	exp=LOW_ORG_EXP;
	for(i=0;i<lv;i++)	exp+=exp/3;
	return exp;
}

int query_exp_train(object me)
{
	int lv, exp;
	lv = (int)me->query("level");
	exp = (int)me->query_experience() - query_org_exp(lv-1);
	return exp;
}

int query_org_quest(object me)
{
	int lv, quest;
	lv = (int)me->query("level");
	if(lv<0) lv=0;
	quest = LOW_ORG_QUEST+lv*LEVEL_UP_QUEST;
	return quest;
}
int query_org_explore(object me)
{
	int lv,expl;
	lv = (int)me->query("level");
	if(lv<0) lv=0;
        expl = LOW_ORG_EXPLORE + lv*LEVEL_UP_EXPLORE;
	if(expl>1000) expl=1000;
	return expl;
}

int do_cost(string arg)
{
        int i, exp, lvl, s, stock, none;
        string *attrs, *skills, msg;
        object me;

        me = this_player();
        if( !this_guild->is_guild_member(me) )
                return notify_fail("很抱歉，你不是這個公會的成員。\n");

        lvl = me->query("level");
        exp = query_org_exp(lvl) - (int)me->query_experience();

        if( lvl >= MAX_ORG_LEVEL ) msg ="你已經升到最高級了。\n";
        else if( exp > 0 ) msg ="你還需要 "+exp+" 點經驗才能升級。\n";
        else msg = "你的經驗值已經達到升級標準了。\n";
                
        stock = query_exp_train(me);
        if( stock < 1 ) 
                msg +="你目前沒有任何額外的經驗可以用來提升技能。\n";
        else 
	{
              msg +="並且你有 "+stock+" 點經驗可以用來提升技能。\n";

              none = 1;
                msg += "訓練技能 :";
                skills = this_guild->query_skill_list();
                for( i=0; i<sizeof(skills); i++) {
                        s = (int)me->query_perm_skill(skills[i]);
                        exp = this_guild->query_skill_exp_cost(skills[i], s);
                        if( exp > 0 ) {
                            none = 0;
                                msg +=sprintf("\n    %30-s -> %2d    %d 點經驗。",
                                              to_chinese(skills[i])+"("+skills[i]+")", s+1, exp) ;
                        }
                }
                if( none )
          msg +=" 你的技能均已達本公會最大值了。\n" ;
        else msg += "\n";
        }
        write(msg);
        return 1;
}


int do_advance(string arg)
{
    mapping quests;
        int lvl, stat, exp, chinese_mode,expl,max;
        object me;
        string *attrs;

        me = this_player();
        chinese_mode = can_read_chinese();

      if( me->id("guest") )
              return notify_fail("很抱歉, GUEST 不能提升任何等級。\n") ;
              
        if( !this_guild->is_guild_member(me) )
                return notify_fail("很抱歉，你不是這個公會的成員。\n");

        
        // prevent wrong keyin, added by Kyoko.
        if( !arg ) return do_help("advance");
        
        // Advance attribute?

        if( arg == "level" ) {
                lvl = (int)me->query("level");
                if( lvl >= MAX_ORG_LEVEL )
                        return notify_fail("你已經升到最高級了。\n");
                        
                // check exp...
                exp =  query_org_exp(lvl);
                if( exp > (int)me->query_experience() )
                        return notify_fail("你的經驗值還不到升級標準。\n");

                // check quest point, added by Kyoko.
                if( query_org_quest(me)>me->query_quest_points())
                        return notify_fail("抱歉, 你的任務點數還不到升級標準。\n");

                // check explored, add by Kyoko.

                expl = (int)me->query_explore_points();
                max = (int)EXPLORE_D->query_total_explore();
                if( max < 1 ) expl = 0;
                  else expl = expl * 1000 / max;
                if( expl > 1000 ) expl = 1000;

                if( expl < query_org_explore(me) )
                      return notify_fail("抱歉, 你的探險度還未達到升級標準，再多去逛逛吧。\n");

        }
	lvl=me->query("level");
	lvl++;
	me->set("level",lvl);
        write(sprintf("你現在是第 %d 級了。\n",lvl));
        me->set("title",me->query_title());
        tell_room( environment(me), 
                  sprintf("%s現在是第 %d 級了。\n",
                           me->query("c_name"),lvl) , me );
        return 1;
}

int do_train(string arg)
{
        int exp, skill;
        object me;

        me = this_player();
        if( !this_guild->is_guild_member(me) )
                return notify_fail("很抱歉，你不是這個組織的成員。\n");

        if( !arg || !this_guild->query_skill_exp_cost(arg,0) )
                return notify_fail("請用 list 指令察看這裡所能提供的訓練內容。\n");

        skill = (int)me->query_perm_skill(arg);
        exp = this_guild->query_skill_exp_cost(arg, skill);

        if( exp < 1 )
                return notify_fail("你的"+to_chinese(arg)+"技能已經達到最大值了。\n");

        if( exp > query_exp_train(me) )
                return notify_fail("你的經驗值不夠。\n");

        if( skill >= ((int)me->query("level") * LEVEL_UP_SKILL+LEVEL_UP_SKILL) )
                return notify_fail("很抱歉，你目前的等級只能訓練到目前這種地步。\n");

        me->gain_experience( -exp );
        STATS_D->train_skill( me, arg );
                printf( "你的%s技能現在提升到 %d 了。\n", to_chinese(arg), me->query_perm_skill(arg));
        return 1;
}

int do_join(string arg)
{
        object ob, token,me;
        int join_ok,exp,expl,max,lvl;

        if( arg ) return 0;

        ob = this_player();
        if( this_guild->is_guild_member(ob) )
                return notify_fail("你已經是本公會的成員了！\n");
        
        if( ob->id("guest") )
              return notify_fail("Guest 不能加入任何公會。\n") ;

        // Check if the player is a wizard or didn't join other guilds yet.
        if( wizardp(ob) ) {
                join_ok = (int)this_guild->join_player(ob);
                if( join_ok ) announce_guild_members("join", ob);
                return join_ok;
        } else if(ob->query("level")>0)
               return notify_fail( "你已經加入了其它公會了，請你先退出原來的公會！\n");
        else  {

	        me=ob;   
                exp =  query_org_exp(0);
                if( exp > (int)me->query_experience() )
                        return notify_fail("你的經驗值太低。\n");

                // check quest point, added by Kyoko.
                if( query_org_quest(me)>me->query_quest_points())
                        return notify_fail("你的任務點數太低。\n");

                // check explored, add by Kyoko.

                expl = (int)me->query_explore_points();
                max = (int)EXPLORE_D->query_total_explore();
                if( max < 1 ) expl = 0;
                  else expl = expl * 1000 / max;
                if( expl > 1000 ) expl = 1000;

                if( expl < query_org_explore(me) )
                      return notify_fail("你的探險度太底。\n");

             }
             join_ok = (int)this_guild->join_player(ob);
             if( join_ok ) 
	     {
               announce_guild_members("join", ob);
               ob->set("title",this_guild->query_title(ob));
             }

             return join_ok;
}


int do_explore(string arg)
{
        int expl, max, i, need_exp;
        object me;
        
        me = this_player();
        need_exp = query_org_explore(me)/10 ;
        if( need_exp < 0 ) need_exp = 0;
        if( !this_guild->is_guild_member(me) )
                return notify_fail("很抱歉，這裡並沒有你的資料，請回到自己的公會查詢探險度。\n");

        for( i=0; i<sizeof(AREAS); i++ ) {
                expl = (int)me->query_explore_points(AREAS[i]);
                max = (int)EXPLORE_D->query_total_explore(AREAS[i]);
                if( max < 1 ) continue;
                expl = expl * 1000 / max;
                if( expl > 1000 ) expl = 1000;
                printf("區域 : "+set_color("%13s", "HIG")+"    探險度 : "+
                        set_color("%2d.%1-d%%\n", "HIY"),
                        to_chinese(AREAS[i]), expl/10, expl%10);
        }
        expl = (int)me->query_explore_points();
        max = (int)EXPLORE_D->query_total_explore();
        if( max < 1 ) expl = 0;
        else expl = expl * 1000 / max;
        if( expl > 1000 ) expl = 1000;
        printf(set_color("平均探險度 : %2d.%1-d%%    升級標準：%d%%.\n","HIC"), 
                         expl/10, expl%10,need_exp);
    return 1;
}

int do_quests(string arg)
{
        string *sloved;
        int i,size_quest;
        object me;

        me = this_player();
        if( !this_guild->is_guild_member(me) )
                return notify_fail("很抱歉，這裡並沒有你的資料，請回到自己的公會查詢。\n");

        sloved = me->query_finish_quests();
        if( !sloved || !( size_quest=sizeof(sloved) ) )
                write(set_color("你目前尚未完成任何的任務, 加點油吧!\n", "HIR"));
        else {
                for( i=0; i<size_quest; i++ )
                        printf("你完成了 "+set_color("%s", "HIG")+
                                   " 的任務。\n", to_chinese( sloved[i] ) );
                printf( "共得到 %3d 點的任務點數。\n" ,(int)me->query_quest_points());
        }
    return 1;
}

int do_verify(string arg)
{
       this_guild->check_token(this_player());
       return 1;
}
int do_help(string arg)
{

        switch(arg) {
                case "guild": write( @C_USAGE_GUILD
在這裡你可以使用以下的指令，每一個指令都有更詳盡的說明( 請用 "help <指令>" ):

  list        - 列出在這裡你所能接受訓練的技能項目。
  cost        - 列出升級、提升屬性、或訓練技能所需的經驗值。
  advance     - 提升等級, 公會等級或屬性。
  train       - 訓練技能。
  join        - 加入這個公會，你的等級必須小於 5 級才能加入公會。
  explore     - 查尋你目前的冒險度。
  quests      - 列出你完成的所有任務。

C_USAGE_GUILD
                        ); break;
                case "list": write( @USAGE_LIST
指令格式: list

    這個指令能列出在這裡你所能接受訓練的技能項目。
USAGE_LIST
                        ); break;
                case "cost": write( @USAGE_COST
指令格式: cost

    這個指令能顯示升級、提升屬性、或訓練技能所需的經驗值。
USAGE_COST
                        ); break;
                case "advance" : write( @USAGE_ADVANCE
指令格式: advance level 

    當你的經驗值足夠時，這個指令能提升你的等級。可是，如果
你的探險度及任務點數未達標準時，即使經驗值足夠亦不能升級。
USAGE_ADVANCE
                        ); break;
                case "train": write( @USAGE_TRAIN
指令格式: train <技能>

    當你擁有足夠的經驗值時，這個指令能提升你的技能。
USAGE_TRAIN
                        ); break;
                case "join": write( @USAGE_JOIN
指令格式: join

    這個指令能讓你加入這個公會。另外要注意的是：某些公會加入前，或許會要
求具備某些特定條件；可以輸入指令「info」來得到有關這個公會的一些資訊。
USAGE_JOIN
                        ); break;
                case "info": write( @USAGE_INFO
指令格式: info [<主題>]

    這個指令能給你一些有關這個公會有用的資訊，所以在你決定加入一個公會前
，一定要先閱讀這些資訊。若在指令「info」後面沒有指定主題的話，會給你一張
所有主題的列表。
USAGE_INFO
                        ); break;
        case "explore": write( @USAGE_EXPLORE
指令格式: explore

    這個指令能查尋你目前的冒險度。
USAGE_EXPLORE
                        ); break;
        case "quests": write( @USAGE_QUESTS
指令格式: quests

    這個指令能列出你已完成的所有任務。
USAGE_QUESTS
                        ); break;
                default:
                        return 0;
        }
        return 1;
}
