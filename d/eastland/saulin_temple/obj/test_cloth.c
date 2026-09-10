	set( "equip_func", "angel" );



void angel()
{
string name; 
object holder;

 holder = environment(this_object());
 name=(string)holder->query("name");
 if (name!="angel") {

     tell_object( holder, can_read_chinese(holder)?
     "\n\n衣服突然射出一陣光芒，它似乎不願臣服於你，蹦的一聲大力的打了你一下
你受到嚴重的傷害。\n"
        this_object()->move(environment(environment(this_object())) );
                   }
       else {

    tell_object( holder, can_read_chinese(holder)?
 bold("\n『我服從陛下的領導，請帶領我去屠殺世間的生靈吧!!!』衣服傳來一陣狂笑
『但是別忘了，要加油啊!』你發現你的手掌流出大量的鮮血...\n"):
         "\nThe sword obeyb your control.\n" );
	holder->receive_damage(40);
            }   
}

