#include "../tsunami.h"
#include "/include/move.h"
inherit ROOM;

int left_hole,mid_hole,right_hole;
void create()
{
    ::create();
    set_short("破邪鎮");
    set_long(@LONG
『破邪鎮』是早在建都之前就已經存在於此的天然巨石，相傳當年魔族
祖先遷徙至此地時，遭遇到一隻非常可怕的大惡魔襲擊，當時三位守護靈顯
靈，集合三把主鑰的力量，在一番苦鬥後，把惡魔封印予此巨石之下中。目
前是用來告誡後世子孫，勿忘祖先為守衛疆土所作的努力。
LONG
             );
    set_outside("island");
    set("objects",([
         "stone":TOBJ"stone"]) );
    set("exits",([
        "south":CITY"inway3"]) );
    set("light",1);
    left_hole=0;
    mid_hole=0;
    right_hole=0;
    reset();
}

void init()
{
    add_action("do_insert","insert");
}

int do_insert(string arg)
{
  string name,dir;
  object obj,ob;
  
  ob=new(TOBJ"ball");
  
  if ( !arg || (sscanf(arg,"%s into %s hole",name,dir)!=2 ) )
    return notify_fail( "格式:insert <key name> into <dir> hole\n" );
  
  if( dir!="right" && dir!="middle" && dir!="left" )
    return notify_fail("有left，middle，right三個洞，插那個洞ㄋㄟ？\n");
  
  if ( !( obj=present( name,this_player() ) ) )
    return notify_fail("你沒有這樣東西\n");
    
  if( name!="luoko" && name!="janser" && name!="tsunami" )
  {
    obj->remove();
    return notify_fail( 
    "石頭中冒出一陣猙獰的笑聲：謝謝你！這東西味道不錯喔！\n" );
   } 
    
    switch(name) {
    case "luoko" : switch(dir) {
                  case "left" :
                        if( left_hole == 1){
                        write("這個洞已經插過鑰匙了啦...真是的！\n");
                        return 1;
                        }                 
                        write("你將手中的主鑰插入左邊的洞中，哇～～!成功了。\n");
                        left_hole=1;
                        obj->remove();
                        break;
                  case "middle" :
                        write("你將手中的主鑰插入中間的洞中，可是好像大小不合耶。\n");
                        return 1;
                  case "right" :
                        write("你將手中的主鑰插入右邊的洞中，可是好像大小不合耶。\n");
                        return 1;
                  default:
                    return 0;
                  };
         break;
         
    case "janser" : switch(dir) {
                  case "left" :
                        write("你將手中的主鑰插入左邊的洞中，可是大小好像不合耶。\n");
                        return 1;
                  case "middle" :
                        write("你將手中的主鑰插入中間的洞中，可是大小好像不合耶。\n");
                        return 1;
                  case "right" :
                        if( right_hole == 1){
                        write("這個洞已經插過鑰匙了啦...真是的！\n");
                        return 1;
                        }
                        write("你將手中的主鑰插入右邊的洞中，哇～～！成功了。\n");
                        right_hole=1;
                        obj->remove();
                        break;
                  default:
                    return 0;
                  };
         break;
         
    case "tsunami" : switch(dir) {
                  case "left" :
                        write("你將手中的主鑰插入左邊的洞中，可是大小好像不合耶。\n");
                        return 1;
                  case "middle" :
                        if( mid_hole == 1){
                        write("這個洞已經插過鑰匙了啦...真是的！\n");
                        return 1;
                        }
                        write("你將手中的主鑰插入中間的洞中，哇～～！成功了。\n");
                        mid_hole=1;
                        obj->remove();
                        break;
                  case "right" :
                        write("你將手中的主鑰插入右邊的洞中，可是大小好像不合耶。\n");
                        return 1;
      		  default:
      		    return 0;
                  };
         break;
         
    default :
          return notify_fail("The syntax: insert <key name> into <position> hole\n");
    }
    
    if ( left_hole==1 && mid_hole==1 && right_hole==1 )
    {
       if( (int)this_player()->query_temp("get_key") == 1 ) {
              tell_room( environment(this_player()),@ALONG

突然破邪鎮的周圍產生劇烈的震動，一聲巨響之後，一棵光球浮現在岩石上方.......

ALONG
                );    
              ob->move(environment(this_player())); 
              this_player()->set_temp("holy_knight",1);
//              if( (int)this_player()->query_quest_level("get_ball") < 1) {
//              write("恭喜你能忍痛完成拯救元神任務，你得到15000點經驗點\n");
//              this_player()->finish_quest("get_ball",1);
//              this_player()->gain_experience(15000);
//              }
              left_hole=0;
              mid_hole=0;
              right_hole=0;
              this_player()->set_explore("island#5");
              return 1;
          }
          else{
    write(@LONG
      你順利的插完鑰匙，但是由於沒有一把鑰匙是你親自拿到手的，
      所以四周仍是一片寂靜，啊～～有啦，有一隻蜻蜓緩緩飛過......-|:
LONG
         ); 
          left_hole=0;
          mid_hole=0;
          right_hole=0; 
              }        
        return 1;
    } 
    return 1;
}
