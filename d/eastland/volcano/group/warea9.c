#include "../oldcat.h"

inherit ROOM;

int east_totem,west_totem,south_totem,north_totem;
int can_search_fire;

void create()
{
	::create();
    set_short("矮靈族部落廣場");
	set_long( 
@LONG_DESCRIPTION
這裡是矮靈族部落廣場，每當有慶典或是祭典，所有的矮靈族人都會在這裡聚會，廣
場中央是一堆用石頭圍起來的營火區，熊熊烈火正在那裡燃燒，廣場東西南北還有四
個圖騰，圖騰上刻著一些怪物的頭，或猙獰、或嚴肅、或閉眼、或狂笑，一截截的圖
騰(totem)顯示矮靈族豐富的想像力及表示他們心裡對自然界一些景像的畏懼。
LONG_DESCRIPTION
	);
set( "exits", ([
     "south" : OGROUP"warea4",
     "north" : OGROUP"warea6",
     "east" : OGROUP"warea10" ]) );
set( "item_desc", ([
     "totem":"這四個圖騰是矮靈族的藝術結晶，你注意到每個圖騰怪物的頭似乎可以轉動(turn)。\n",
     "fire" : "@@look_fire",
     "tunnel" : "@@look_tunnel",
     ]) );
set("search_desc", ([
    "fire":"@@search_fire",
    ]) );
set_outside("eastland");
reset();
}

void init()
{
  add_action("do_turn","turn");
  add_action("do_enter","enter");
}

/* <east totem>=west, <south totem>=south, <west totem>=west, <north totem>=east
   then can see secret tunnel. */

string search_fire()
{ 
  string str;

  if (east_totem==3 && south_totem==2 && west_totem==3 && north_totem==1) {
    this_player()->set_temp("fire/check",1);
    return "在烈火熄了之後，你搜尋中央營地，發現一條似是秘道(tunnel)的入口。\n";
  }
  return "在熊熊烈火之下，做什麼動作都是無義意的。\n";
}

string look_fire()
{
  if (east_totem==3 && south_totem==2 && west_totem==3 && north_totem==1) {
     return "你發現原來中央的熊熊烈火突然消失的無影無蹤。\n";
  }
  return "一片熊熊烈火正在中央營地日以繼夜的燃燒著。\n";
}

string look_tunnel()
{
  if(this_player()->query_temp("fire/check"))
    return "一條似是秘道的入口，從入口看進去，黑漆漆的。\n";
  return "你要看什麼?\n";
}

int do_enter(string arg)
{
  if (!arg || arg!="tunnel")
    return 1;

  if (east_totem==3 && south_totem==2 && west_totem==3 && north_totem==1) {
   if (this_player()->query_temp("fire/check")) {
    east_totem=1;
    south_totem=1;
    west_totem=1;
    north_totem=1;
    write("\n你走進秘道。\n\n");
    this_player()->move_player(OGROUP"tunnel1","SNEAK");
    return 1;
   }
  }

  return 1;
}

int do_turn(string arg)
{
  string str1;

  if (!arg || arg=="")
    return notify_fail("The syntax: turn <direction> totem\n");

  if (sscanf(arg, "%s totem",str1) == 1) {
    switch(str1) {
    case "east" : switch(east_totem) {
                  case 4 :
                        write("你將東方圖騰的怪物頭轉向東方。\n");
                        east_totem=1;
                        break;
                  case 2 :
                        write("你將東方圖騰的怪物頭轉向西方。\n");
                        east_totem=3;
                        break;
                  case 1 :
                        write("你將東方圖騰的怪物頭轉向南方。\n");
                        east_totem=2;
                        break;
                  case 3 :
                        write("你將東方圖騰的怪物頭轉向北方。\n");
                        east_totem=4;
                        break;
                  default:
                    return 1;
                  };
         break;
    case "west" : switch(west_totem) {
                  case 4 :
                        write("你將西方圖騰的怪物頭轉向東方。\n");
                        west_totem=1;
                        break;
                  case 2 :
                        write("你將西方圖騰的怪物頭轉向西方。\n");
                        west_totem=3;
                        break;
                  case 1 :
                        write("你將西方圖騰的怪物頭轉向南方。\n");
                        west_totem=2;
                        break;
                  case 3 :
                        write("你將西方圖騰的怪物頭轉向北方。\n");
                        west_totem=4;
                        break;
                  default:
                    return 1;
                  };
         break;
    case "south" : switch(south_totem) {
                  case 4 :
                        write("你將南方圖騰的怪物頭轉向東方。\n");
                        south_totem=1;
                        break;
                  case 2 :
                        write("你將南方圖騰的怪物頭轉向西方。\n");
                        south_totem=3;
                        break;
                  case 1 :
                        write("你將南方圖騰的怪物頭轉向南方。\n");
                        south_totem=2;
                        break;
                  case 3 :
                        write("你將南方圖騰的怪物頭轉向北方。\n");
                        south_totem=4;
                        break;
                  default:
                    return 1;
                  };
         break;
    case "north" : switch(north_totem) {
                  case 4 :
                        write("你將北方圖騰的怪物頭轉向東方。\n");
                        north_totem=1;
                        break;
                  case 2 :
                        write("你將北方圖騰的怪物頭轉向西方。\n");
                        north_totem=3;
                        break;
                  case 1 :
                        write("你將北方圖騰的怪物頭轉向南方。\n");
                        north_totem=2;
                        break;
                  case 3 :
                        write("你將北方圖騰的怪物頭轉向北方。\n");
                        north_totem=4;
                        break;
                  default:
                    return 1;
                  };
          break;
    default :
          return notify_fail("The syntax: turn <direction> totem\n");
    }; 
    return 1;
  }
  return notify_fail("The syntax: turn <direction> totem\n");
}

void reset()
{
  ::reset();
  east_totem=1;
  west_totem=1;
  south_totem=1;
  north_totem=1;
  can_search_fire=0;
}
