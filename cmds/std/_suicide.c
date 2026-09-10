//#pragma save_binary

//	File	:  /cmds/std/_suicide.c
//	Creator	:  Watcher@TMI	(02/08/93)
//
//	This command allows a player to commit suicide and have
//	the character file deleted from the database.

#include <config.h>
#include <mudlib.h>
#include <logs.h>
#define mssg ({ "冷酷無情", "殘忍邪惡", "暴力血腥", "陰狠狡詐", "爾虞我詐", })

inherit DAEMON ;

//  If you do not wish suicided files to be saved in the
//  archive directory, simply #undef ARCHIVE_DIR

int busy;

int cmd_suicide()
{
	//	Block any attempts by wizards to suicide
	if(wizardp(this_player())) {
		write(
			"巫師不能自殺，如果你不想繼續當巫師，請 mail 給 God。\n");
		return 1;
	}

	// 	Prevent someone from suiciding the Guest character
	if((string)this_player()->query("name") == "guest") {
		write(
			"訪客不能自殺，不然別人就不能用了。\n");
		return 1;
	}

	//	Check to see if the command's busy flag is set
	if(busy) {
		write(
			"自殺指令同時只能有一個人用，現在有其他人正在考慮當中，請稍候。\n");
		return 1;
	}

	busy = 1;				//  Set busy flag on
	write(
		"如果你自殺的話，會把你這個人物的資料檔永遠刪除掉，你確定\n"
		"要結束這個人物嗎？ [y/n] ");
	input_to("confirm_suicide");

	return 1;
}

protected int confirm_suicide(string str)
{
	if(!str || member_array(lower_case(str), ({ "yes", "y" })) == -1) {
		write(
			"很好，留得青山在，不怕沒柴燒——好死不如賴活著。\n");
		busy = 0;
		return 1;
	}

	write(
		"\n為了安全起見，請輸入您的密碼確認: ");
	input_to("pass_check", 1);

	return 1;
}

protected int pass_check(string str)
{
	string password, name;
	object *items, *usrs;
	int i;

	busy = 0;				// Reset busy flag

	//	Get player's name for backup purposes
	name = (string)this_player()->query("name");

	//	Get the user's password from the linked connection object
	password = ((object)this_player()->query_link())->query("password");

	//	Check to see the inputed password matches the actual password
	if(!verify_password(str, password)) {
		write(
			"密碼錯誤。\n");
		return 1;
	}

	write(
		"好吧，就如你所願。\n"
		"一道閃電由天而降，然後你的眼前一片漆黑....。\n");

	tell_room(environment(),
		"一道閃電突然從天而降，直直的打在"+this_player()->query("c_name")+
		"的頭上，\n閃光過後，地上只剩下一堆灰。",
		this_player());

	//	Save the players attributes before file transfer

	this_player()->save_data();

	//	If SUICIDE defined, write all suicides to a log file

#ifdef SUICIDE
	log_file(SUICIDE, capitalize(name) + " committed suicide from " +
		 query_ip_name(this_player()) + " [" +
		 extract(ctime(time()), 4, 15) + "]\n");
#endif

	//	Either move data files to ARCHIVE_DIR dir, or completely delete

	if(ARCHIVE_DIR) {
	rename(user_data_file(this_player()) + SAVE_EXTENSION, ARCHIVE_DIR + "user/" +
	  name + SAVE_EXTENSION);
	rename(PDATA_DIR + name[0..0] + "/" + name + SAVE_EXTENSION, ARCHIVE_DIR +
	  "connection/" + name + SAVE_EXTENSION);
    "/adm/daemons/backup"->remove_backup(this_player());
	}

	else {
	rm( user_data_file(this_player()) + SAVE_EXTENSION );
	rm( PDATA_DIR + name[0..0] + "/" + name + SAVE_EXTENSION );
	"/adm/daemons/backup"->remove_backup(this_player());
	}

	//	Remove the user object and connection from the game

    usrs = users();
    for( i=0 ; i<sizeof(usrs); i++ ) {
      if( !environment(usrs[i]) || usrs[i]==this_player() ) continue;
      tell_object( usrs[i],
        sprintf("一個叫做 %s (%s) 的傻瓜終於忍受不了這個\n%s的世界，剛剛自我了斷了!\n",
          this_player()->query("c_name"), this_player()->query("name"),
          mssg[random(5)] ) );
    }
    items = all_inventory( this_player() );
    for( i=0 ; i<sizeof(items); i++ )
      if( items[i]->query("prevent_drop") )
        items[i]->remove();
	destruct( this_player()->query_link() );
	destruct( this_player() );
	return 1;
}

int help() {
	write(@HELP
使用格式: suicide

這個指令將刪除你的資料，請認真考慮，小心使用！
HELP
);
	return 1;
}
