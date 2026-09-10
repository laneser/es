#include <mudlib.h>
inherit OBJECT;

int inked;

string query_c_long()
{
   if ( inked )
     return  "這張畫布上面拓印了古壁上奇怪的文字，應該去找個會解讀的人看看吧!!\n" ;
   else
     return  "這張畫布似乎可以用來寫字、畫畫或拓印(squeeze)東西。\n" ;
}

void create()
{
	set_name("paper", "畫布");
	add( "id", ({ "paper" }) );
	set_short( "畫布" );
	set("long","@@query_c_long");
	set( "weight", 1 );
	inked = 0;
}

int query_inked() { return inked; }

void init()
{
	add_action( "squeeze_wall", "squeeze" );
}

int squeeze_wall(string str)
{
        object obj1, obj2;
        if ( !str || str=="" || str !="wall" )
          write("你找不到適當的東西!!\n");
        else {
          obj1=environment(this_object());
          if (living(obj1)) {
            obj2 = environment(obj1);
            if ((int)obj2->query("apply_wall")==1) { 
              write("你將紙置於石壁上，並順利地將壁上古文拓印下來!!\n");
              inked = 1 ; 
            }
            else
              write("請用用大腦吧！這裡沒有辦法拓印！\n");
          }
        }
        return 1;
}
