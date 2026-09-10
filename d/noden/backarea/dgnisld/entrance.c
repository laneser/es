#include "dgnisld.h"

inherit ROOM;


int cropps;
void create()
{
	::create();
	cropps = 0;
	set( "cropp",1);
	set( "outside" ,"dgnisld" ) ;
   set_short(
	           "龍島的入口" ) ;
	set_long(
	    "這是龍島的入口，你可以看到一個畫有龍族符號的告示(sign)。\n"
	"北方似乎有一片大草原(campo)，有一條小徑通往西北方的森林(forest)\n"
	"，東邊則是一叢高聳濃密的草叢(brush)。\n"
        ) ;

	set( "item_desc", ([
	     "sign" : 
  "這張告示寫著：\n"
  "——————————————————————————————————\n"
  "歡迎來到龍島！\n"
  "  這島乃由龍王巴哈姆特所管轄，不過卻不曾有人看過它的真面目。島上有\n"
  "草原、沼澤、湖泊、森林、火山等地形，到處充滿了危險，也因此保留了一\n"
  "些原始生物。此處鮮為人煙，到處都是未開發地區，因而朦上了一層神秘的\n"
  "色彩。請小心那些兇暴的肉食性恐龍，它們可能在你能抵抗之前就把你一口\n"
  "吞掉。有一種種族——龍騎士居住在這裡，他們是唯一可與龍族溝通的種族\n"
  "，不過他們根本不會理你，除非他們承認你是他們的一員。\n"
  "                                            一刻館管理人  音無響子\n"
  "——————————————————————————————————\n",
           "brush" : "十分茂密的草叢，似乎這兒的雨水充足。\n",
           "forest": "很大的森林，看起來既陰森又恐怖。\n",
           "campo" : "一望無際的草原，到處雜草叢生。\n",
           ]) );
    set( "objects", ([
        "bahamut" : "/u/k/kyoko/FF-V/bahamut",   ]) );
	set( "exits", ([
	   "northwest"    : DGNISLD"forest1-10",
	       "north"    : DGNISLD"campo10-1",        ]) );
   reset();
}

void init()
{
        add_action("enter_hole","enter");
}

int to_find_cropp(string str)
{
      if ( !str || str!="brush" )
        write("You can't cropp it!\n");
      else {
        if (cropps==0) {
          cropps=1;
          add( "item_desc",([ 
                 "hole" : "一個小洞。不過它小到一次只能讓一人通過，而且\n"
                          "看起來危危欲墜，好像隨時都會崩壞。\n",              
                "brush" : "這草叢看起來毫無生氣，它被砍得一蹋糊塗。\n",            
                         ]) );
          write(
            "當你割掉草叢時，很幸運地發現一個小洞(hole)。不過它小到只\n"
            "能讓一人通過(enter) ，看起來危危欲墜，好像隨時都會崩壞。\n");
          say(
            this_player()->query("c_cap_name")+"割了一些東西。\n");
        }
        else 
          write("They have been cropped!\n");
      }
      return 1;
}

int enter_hole(string str)
{        
         if ( !str || str=="" )
           write("enter what ?\n");
         else if ( str!="hole" )
           write("There are no "+str+" here!\n");
         else if (cropps==1){
           write("You climb into the hole and walk forward. The hole is\n"
                 "broken when you enter it. You enter a very dark place.\n"  );
           say( this_player()->query("cap_name")+
                " enter a hole and disappear.\n");
           cropps = 2;
           add( "item_desc",([
                "hole" : "當你探頭往裡面看，你發現這洞已經毀了！\n" ])  );
                                 
           this_player()->move_player(DGNISLD"hole1", "", "") ;
         }
         else if (cropps==2)
           write( !can_read_chinese() ? 
             "The hole has been broken!\n":"這洞已經毀了！\n");
         return 1;
}

int get_cropps()
{
         return cropps;
}
         
void reset()
{
    ::reset();
    cropps=0;
}
