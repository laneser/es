#include <mudlib.h>

inherit CONTAINER;

void create()
{
        ::create();
        set_name("Paper box", "字紙蔞");
        set("id",({ "box"}));
        set_short("字紙蔞");
        set_c_open_long(@LONG
這是專門用來回收收據的資源回收箱，請大家要有環保概念，
勿將非收據物品投入(put)。        
LONG
        );
        set( "weight", 20);
        set( "weight_apply", 10 );
        set( "max_load", 20000);
        set( "prevent_get",1 );
        set( "prevent_put_money", 1);
}

void init()
{
    add_action("do_put","put");
}

int do_put(string arg)
{
    string *name,id;
    object *obj;
    int i,j;
    
    obj=all_inventory(this_player());
    
    i=sizeof(obj);
    if ( arg !="bill in box" || arg != "bill into box"|| !arg )
    {
    while(i--)
    {
       name=obj[i]->query( "id" );
       j=sizeof(name);
       
       while(j--)
       {    id=name[j];
       if ( id+" in box" == arg || id+" into box"==arg );
       {
          obj[i]->remove();
          write("叫你不要丟還說不聽! 沒收!");
          tell_room(environment(this_player()), this_player()->query("c_name")+"的"+name+"被沒收了!",this_player());
          return 1 ;
        }
        }
     }
     }
       
     else 
     {
       
        if ( arg == "bill in box"|| arg == "bill into box" )
       
        {
           return 0;
        } 
       
        else
        {
          write("你要幹什麼!?");
          return 1;
        }
       } 
}               