// logind.c
//modified by bsd 12/13/2000

#include <ansi.h>
#include <command.h>
#include <login.h>
#include <net/daemons.h>
#include <net/macros.h>

inherit F_DBASE;

int wiz_lock_level = WIZ_LOCK_LEVEL;

string *banned_name = ({
	"Äã", "ÎÒ", "Ëû", "Ëı", "Ëü", "×Ô¼º", 
	});

void encoding_to_mudlist(string arg, object ob);
void login(string arg, object ob);
void get_id(string arg, object ob);
void confirm_id(string yn, object ob);
object make_body(object ob);
void init_new_player(object user);
varargs void license(object ob, object user);
varargs void to_enter(string arg, object ob, object user);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg);

void random_gift(mapping my, int select)
{
	int i = 10, j;
	int tmpstr, tmpint, tmpcon, tmpdex,tmpbac;

	tmpstr = tmpint = tmpcon = tmpdex = tmpbac = 10;

	switch (select) {
		case 1: tmpstr = i = my["str"]; break;
		case 2: tmpint = i = my["int"]; break;
		case 3: tmpcon = i = my["con"]; break;
		case 4: tmpdex = i = my["dex"]; break;
		case 5: tmpbac = i = my["bac"];
	}
	i = 50 - i;
	while (i--) {
		j = random(5);
		if (j == select - 1) {
			i++;
			continue;
		}
		switch (j) {
		case 0: tmpstr++; break;
		case 1: tmpint++; break;
		case 2: tmpcon++; break;
		case 3: tmpdex++; break;
		case 4: tmpbac++; break;
		}
	}
	if (tmpstr <= 30) my["str"] = tmpstr; else my["str"] = 30;
	if (tmpint <= 30) my["int"] = tmpint; else my["int"] = 30;
	if (tmpcon <= 30) my["con"] = tmpcon; else my["con"] = 30;
	if (tmpdex <= 30) my["dex"] = tmpdex; else my["dex"] = 30;
	if (tmpbac <= 30) my["bac"] = tmpbac; else my["bac"] = 30;	
	// next 2 are randomly selected
	my["kar"] = 10 + random(21);
	my["per"] = 10 + random(21);
}

void create()
{
	seteuid(getuid());
	set("channel_id", "Á¬Ïß¾«Áé");
}

void logon(object ob)
{
	write("\n"HIG"\n\n¡¼ËæÔµÏ´½£Â¼¡½"NOR"»¶Ó­ÄúÀ´·Ã£¡Ê¹ÓÃ¹ú±êÂëµÄÍæ¼ÒÇë¼üÈë£º¡¼GB¡½\n");
	write(HIG"¡¼ ·s³À¹©°O ¡½"NOR"Åwªï±z¨Ó³X¡I¨Ï¥Î¤j¤­½Xªºª±®a½ĞÁä¤J¡G¡¼Big5¡½\n");

	write("\nPlease select ¹ú±êÂë ¡¼GB¡½ or ¤j¤­½X ¡¼Big5¡½ (GB/Big5):\n");
	input_to( "encoding_to_mudlist", ob );
}

void encoding_to_mudlist(string arg, object ob)
{
	int encode;

	mapping mud_list;
        mapping mud_svc;
        mixed *muds;
        string output;
        int loop, size, total, count=0, p_count=0;

	if(!arg || arg=="") {
	    write("\nPlease select ¹ú±êÂë ¡¼Gb¡½ or ¤j¤­½X ¡¼Big5¡½ (Gb/Big5):");
	    input_to( "encoding_to_mudlist", ob );
	    return;
	}
	else if(arg[0..0]=="g" || arg[0..0]=="G")
	    encode=0;
	else if(arg[0..0]=="b" || arg[0..0]=="B")
	    encode=1;
	else {
	    write("\nPlease select ¹ú±êÂë ¡¼Gb¡½ or ¤j¤­½X ¡¼Big5¡½ (Gb/Big5):");
	    input_to( "encoding_to_mudlist", ob );
	    return;
	}

	if(encode==0)
//		write("[H[J                       Use GB encoded Chinese.\n\n\n");
//		write("                       Use GB encoded Chinese.\n\n");
		write("\n»¶Ó­Äú½øÈë"HIG"¡¼ËæÔµÏ´½£Â¼¡½"NOR"µÄ´«ÆæÊÀ½ç¡£\n\n");
	else
//		write("[H[J                       Use BIG5 encoded Chinese.\n\n\n");
//		write("                       Use BIG5 encoded Chinese.\n\n");
		write("\nÅwªï±z¶i¤J"HIG"¡¼ ·s³À¹©°O ¡½"NOR"ªº¶Ç©_¥@¬É¡£\n\n");
	ob->set_encoding(encode);
	
        if( !find_object(DNS_MASTER) )
		write("ÍøÂ·¾«Áé²¢Ã»ÓĞ±»ÔØÈë¡£\n");

        //      Obtain mapping containing mud data
        mud_list = (mapping)DNS_MASTER->query_muds();

        // so we recognise ourselves as a DNS mud
        mud_svc = DNS_MASTER->query_svc() + ([ Mud_name() : 0 ]);

        if(!mud_list)
		write( MUD_NAME + "Ä¿Ç°²¢Ã»ÓĞ¸úÍøÂ·ÉÏÆäËû Mud È¡µÃÁªÏµ¡£\n");

        //      Get list of all mud names within name server
        muds = keys( mud_list ) - ({ "DEFAULT" });

        //      Place mudlist into alphabetical format
        muds = sort_array(muds, 1);

	output = 
"Mud                  ÖĞÎÄÃû³Æ                ¹ú¼ÊÍøÂ·Î»Ö·     ²ººÅ  ÈËÊı\n"+
"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n";
        //      Loop through mud list and store one by one
	for(loop = 0, size = sizeof(muds); loop<size; loop++)
	{
		if( mud_list[muds[loop]]["VERSION"] != MUDLIB_VERSION )
			continue;
                if( mud_list[muds[loop]]["_dns_no_contact"] > 0 ) {
//			if( !wizardp(me) || (wizardp(me) && me->query("env/debug")) )
                                continue;
                }

                if( htonn(upper_case(muds[loop])) == htonn(upper_case(INTERMUD_MUD_NAME)) )
                        output += HIW;
                else
                        output += WHT;

                if( undefinedp(mud_list[muds[loop]]["MUDNAME"]) ) {
                        output +=  sprintf("%-43s  %-15s  %4s", 
                                upper_case(muds[loop]),
                                mud_list[muds[loop]]["HOSTADDRESS"],
                                mud_list[muds[loop]]["PORT"]);
                }
                else {
                        output +=  sprintf("%-20s %-23s %-15s  %4s", 
                                upper_case(muds[loop]),
                                undefinedp(mud_list[muds[loop]]["MUDNAME"])?
                                "":mud_list[muds[loop]]["MUDNAME"],
                                mud_list[muds[loop]]["HOSTADDRESS"],
                                mud_list[muds[loop]]["PORT"]);
                }
                if(!undefinedp(mud_list[muds[loop]]["USERS"]))
                {
				output+=sprintf("  %-4s", mud_list[muds[loop]]["USERS"] );
				if(sscanf(mud_list[muds[loop]]["USERS"], "%d", count)==1)
					p_count+=count;
		}
                else
                                output+=sprintf("  ----", mud_list[muds[loop]]["USERS"] );

                output +=NOR"\n";
                total ++;
        }
        //      Display dumped mudlist output through user's more pager
	output += "©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n";
	output += sprintf("¹²ÓĞ %d ¸ö¡¶ËæÔµÏ´½£Â¼¡·ÏµÁĞÕ¾µãÓë±¾Õ¾Á¬ÏßÖĞ¡£¹²ÓĞ %d ¸öÍæ¼ÒÔÚÏß¡£\n\n",total==0?0:total-1,p_count);
//	write(read_file("/adm/etc/front_b"));
	write(output);

	write(HIG"Press Enter to Continue..."NOR);
	input_to( "login", ob );
}

void login(string arg, object ob)
{
	string *lognum, *dir, *ppls,welcome_msg,welcome_msg1,welcome_msg2;
	object *usr;
	int i, wiz_cnt, wiz_cnt2, ppl_cnt, ppl1_cnt, login_cnt, ip_cnt, login_num, login_num2;
	welcome_msg = "/adm/etc/welcome";	
	welcome_msg1 = "/adm/etc/welcome";	
	welcome_msg2 = "/adm/etc/welcome";		
        switch( random(3) ) 
        {
                case 0:
			write("[H[J" + read_file(welcome_msg));
			break;
		case 1:
			write("[H[J" + read_file(welcome_msg1));
			break;
		case 2:
			write("[H[J" + read_file(welcome_msg2));
			break;
	}					
	usr = users();
	ip_cnt =0;
	wiz_cnt = 0;
	ppl_cnt = 0;
	ppl1_cnt = 0;
	login_cnt = 0;
	dir = get_dir(DATA_DIR + "login/");

	for(i=0; i<sizeof(dir); i++) {
		reset_eval_cost();
		ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
		ppl1_cnt += sizeof(ppls);
	}

	for(i=0; i<sizeof(usr); i++) {
		if( !environment(usr[i]) )
		{
			login_cnt++;
		}
		else
		{
			wiz_cnt2 = (int)usr[i]->query("env/invisibility");
			if ( ( !intp(wiz_cnt2)
			|| ( intp(wiz_cnt2) && (wiz_cnt2 <= 0) ) )
			&& !usr[i]->is_ghost() )
			{
				if ( query_ip_name(ob) == query_ip_name(usr[i]) ) ip_cnt++;
			     if (ip_cnt >= 20){
		  write("´ÓÄúµÄÖ÷»ú´´ÔìµÄÈËÎïÌ«¶àÁË£¬ÄúµÄÖ÷»ú½«±»¾Ü¾øÍùÀ´Ò»¶ÎÊ±¼ä¡£\n");
		  destruct(ob);
		      return;}
				if ( wizardp(usr[i]) )
				{
					wiz_cnt++;
				}
				else
				{
					ppl_cnt++;
				}
			}
		}
	}

        if (BAN_D->is_banned(query_ip_name(ob)) == 1) {
                write("ÄãµÄµØÖ·ÔÚ±¾ MUD ²»ÊÜ»¶Ó­¡£\n");
                destruct(ob);
                return;
        }

	login_num = 0;
	if ( file_size(LOG_DIR + "loginnum") >=0 )
	{
		lognum = explode(read_file(LOG_DIR + "loginnum"), "\n");
		for(i=0; i<sizeof(lognum); i++) {
			if( lognum[i][0]=='#'
			|| sscanf(lognum[i], "%d", login_num2)!=1 ) continue;
			if ( i=1 ) login_num = login_num2;
		}
	}
	else
	{
		login_num = wiz_cnt + ppl_cnt;
		log_file( "loginnum", sprintf("%d\n", login_num ) );
	}
    printf(" "HIC"¡¾"HIM"ËæÔµÏ´½£Â¼"HIC"¡¿"NOR"Ä¿Ç°¹²±£´æ×Å"YEL"%s"NOR"¸öÍæ¼ÒµÄµµ°¸¡£ \n"NOR,chinese_number(ppl1_cnt) );
    printf(" "HIC"¡¾"HIM"ËæÔµÏ´½£Â¼"HIC"¡¿"NOR"×Ô¶şÁãÁãÁãÄêÊ®¶şÔÂÒ»ÈÕÆğ£¬¹²ÓĞ"+YEL"%s"+NOR"ÈË´ÎÀ´·Ã¡£\n"NOR,chinese_number(login_num-1) );
    printf(" "HIC"¡¾"HIM"ËæÔµÏ´½£Â¼"HIC"¡¿"NOR"Ö÷Ò³µØÖ·: "+YEL"http://Mud.jztele.Com"+NOR"¡£\n" );

	UPTIME_CMD->main(1);
	printf("ÄúµÄIPµØÖ·ÊÇ£º"HIY"%s"NOR"£¬´ËµØÖ·Ä¿Ç°¹²ÓĞ %d ¸ö"+HIC"Íæ¼Ò"+NOR"ÔÚÏß¡£\n",
		query_ip_name(ob), ip_cnt + 1);
	printf("Ä¿Ç°¹²ÓĞ %d Î»"+HIW"Î×Ê¦"+NOR"¡¢%d Î»"+HIC"Íæ¼Ò"+NOR"ÔÚÏßÉÏ£¬ÒÔ¼° %d Î»"+HIG"Ê¹ÓÃÕß"+NOR"³¢ÊÔÁ¬ÏßÖĞ¡£\n",
		wiz_cnt, ppl_cnt, login_cnt );

	write("ÄúµÄÓ¢ÎÄÃû×Ö£º");
	input_to( (: get_id :), ob );
}

void get_id(string arg, object ob)
{
	int i;
	object ppl, *usr;
//	string ip = query_ip_number(ob);

	arg = lower_case(arg);

	if( !check_legal_id(arg)) {
		write("ÄúµÄÓ¢ÎÄÃû×Ö£º");
		input_to("get_id", ob);
		return;
	}
/*
	if (!"/adm/daemons/sited"->is_valid(arg, ip)) {
		write("¶Ô²»Æğ£¬Õâ¸öÓ¢ÎÄÃû×Ö²»ÄÜ´Óµ±Ç°µØÖ·µÇÂ¼¡£\n");
		confirm_id(" ", ob);
		return;
	}
*/
	if( (string)ob->set("id", arg) != arg ) {
		write("Failed setting user name.\n");
		destruct(ob);
		return;
	}		

#ifdef MAX_USERS
	if( (string)SECURITY_D->get_status(arg)=="(player)"
	&& sizeof(users()) >= MAX_USERS ) {
		ppl = find_body(arg);
		// Only allow reconnect an interactive player when MAX_USERS exceeded.
		if( !ppl || !interactive(ppl) ) {
			write("¶Ô²»Æğ£¬" + MUD_NAME + "µÄÊ¹ÓÃÕßÒÑ¾­Ì«¶àÁË£¬Çë´ı»áÔÙÀ´¡£\n");
			destruct(ob);
			return;
		}
	}
/*	
	if (!ppl && "/adm/daemons/sited"->is_multi(arg, ip)) {
		destruct(ob);
		return;
	}	
*/	
#endif

	if( wiz_level(arg) < wiz_lock_level ) {
		write("¶Ô²»Æğ£¬" + MUD_NAME + "Ä¿Ç°ÏŞÖÆÎ×Ê¦µÈ¼¶ " + WIZ_LOCK_LEVEL
			+ " ÒÔÉÏµÄÈË²ÅÄÜÁ¬Ïß¡£\n");
		destruct(ob);
		return;
	}

	if( (string)ob->set("id", arg) != arg ) {
		write("Failed setting user name.\n");
		destruct(ob);
		return;
	}

	if( arg=="guest" ) {
		// If guest, let them create the character.
		confirm_id("Yes", ob);
		return;
	} else if( file_size(ob->query_save_file() + ".o") >= 0 ) {
		if( ob->restore() ) {
			write("ÇëÊäÈëÃÜÂë£º");
			input_to("get_passwd", 1, ob);
			return;
		}
		write("ÄúµÄÈËÎï´¢´æµ²³öÁËÒ»Ğ©ÎÊÌâ£¬ÇëÀûÓÃ guest ÈËÎïÍ¨ÖªÎ×Ê¦´¦Àí¡£\n");
		destruct(ob);
		return;
	}
// ·ÀÖ¹Á½¸öÒÔÉÏµÄÍæ¼ÒÓÃÍ¬Ò» id
	usr = filter_array(children(LOGIN_OB), (: interactive :));
	i = sizeof(usr);
	while (i--) if (usr[i] != ob && usr[i]->query("id") == arg) break;
	if (i >= 0) {
		write("ÓĞÆäËûÍæ¼ÒÕıÔÚÊ¹ÓÃÕâ¸ö ID£¬ÇëÖØĞÂÊäÈë¡£\n");
		write("ÄúµÄÓ¢ÎÄÃû×Ö£º");
		input_to("get_id", ob);
		return;
	}
	write("Ê¹ÓÃ " + (string)ob->query("id") + " Õâ¸öÃû×Ö½«»á´´ÔìÒ»¸öĞÂµÄÈËÎï£¬ÄúÈ·¶¨Âğ(y/n)£¿");
	input_to("confirm_id", ob);
}

void get_passwd(string pass, object ob)
{
	string my_pass,temp_pass;
	object user;
	write("\n");
	my_pass = ob->query("password");
	temp_pass= ob->query("temp_password");
	//temp_passwordÊôĞÔÊÇÍæ¼Ò³õ´Î×¢²áÊ±Ê¹ÓÃµÄÁÙÊ±ÃÜÂë
	if(my_pass&&my_pass==crypt(pass,my_pass))
	{
		//ÕâÊ±ËµÃ÷×¢²á³É¹¦£¬ÉèÖÃ×¢²áÊôĞÔ
		ob->set("register",1);
	}
	else
	if(	crypt(pass, temp_pass) != temp_pass ) 
	{
		write("ÃÜÂë´íÎó£¡\n");
		destruct(ob);
		return;
	}
	else
	{
		//ÊÔÎªÒÅÍüÃÜÂë´¦Àí
		//ËùÒÔÉèÖÃµÇÂ¼µ½×¢²áÊÒ£¡
		ob->set_temp("go_reg_room",1);
	}

	// Check if we are already playing.
	user = find_body(ob->query("id"));
	if (user) {
		if( user->query_temp("netdead") ) {
			reconnect(ob, user);
			return;
		}
		write("ÄúÒª½«ÁíÒ»¸öÁ¬ÏßÖĞµÄÏàÍ¬ÈËÎï¸Ï³öÈ¥£¬È¡¶ø´úÖ®Âğ£¿(y/n)");
		input_to("confirm_relogin", ob, user);
		return;
	}

	if( objectp(user = make_body(ob)) ) {
		if( user->restore() ) {
			log_file( "USAGE", sprintf("%s%s loggined from %s (%s) %s %s\n", user->query("name"), "(" + user->query("id") + ")" ,
				query_ip_name(ob), ctime(time()), "exp:" + user->query("combat_exp"), "mud_age:" + user->query("mud_age") ) );
			if(time()-(int)user->query("kickout_time") < 3600)
			{
			write("ÄãÏÖÔÚÃ»ÓĞ½øÈëËæÔµÏ´½£Â¼µÄÈ¨Àû£¬ÇëÒ»Ğ¡Ê±ºóÔÙÁªÏß¡£\n");
			destruct(user);
			destruct(ob);
			return;
		}
		
                        if(time()-(int)user->query("quit_time") < 30)
			{
                        write("¸ÕÍË³ö¾ÍÒª½øÀ´£¿»¹ÊÇµÈ°ë·ÖÖÓ°É¡£\n");
			destruct(user);
			destruct(ob);
			return;
			}

			license(ob, user);
			return;
		} else {
			destruct(user);
		}
	}
	write("ÇëÄúÖØĞÂ´´ÔìÕâ¸öÈËÎï¡£\n");
	confirm_id("y", ob);
}

void confirm_relogin(string yn, object ob, object user)
{
	object old_link;

	if( yn=="" ) {
		write("ÄúÒª½«ÁíÒ»¸öÁ¬ÏßÖĞµÄÏàÍ¬ÈËÎï¸Ï³öÈ¥£¬È¡¶ø´úÖ®Âğ£¿(y/n)");
		input_to("confirm_relogin", ob, user);
		return;
	}

	if( yn[0]!='y' && yn[0]!='Y' ) {
		write("ºÃ°É£¬»¶Ó­ÏÂ´ÎÔÙÀ´¡£\n");
		destruct(ob);
		return;
	} else {
		tell_object(user, "ÓĞÈË´Ó±ğ´¦( " + query_ip_number(ob)
			+ " )Á¬ÏßÈ¡´úÄãËù¿ØÖÆµÄÈËÎï¡£\n");
		log_file( "USAGE", sprintf("%s%s replaced by %s (%s) %s %s\n", user->query("name"), "(" + user->query("id") + ")" ,
			query_ip_name(ob), ctime(time()), "exp:" + user->query("combat_exp"), "mud_age:" + user->query("mud_age") ) );
	}

	// Kick out tho old player.
	old_link = user->query_temp("link_ob");
	if( old_link ) {
		user->set_encoding(ob->query_encoding());
		exec(old_link, user);
		destruct(old_link);
	}

	reconnect(ob, user);
}

void confirm_id(string yn, object ob)
{
	if( yn=="" ) {
		write("Ê¹ÓÃÕâ¸öÃû×Ö½«»á´´ÔìÒ»¸öĞÂµÄÈËÎï£¬ÄúÈ·¶¨Âğ(y/n)£¿");
		input_to("confirm_id", ob);
		return;
	}

	if( yn[0]!='y' && yn[0]!='Y' ) {
		write("ºÃ°É£¬ÄÇÃ´ÇëÖØĞÂÊäÈëÄúµÄÓ¢ÎÄÃû×Ö£º");
		input_to("get_id", ob);
		return;
	}
	write( @TEXT

ÇëÊäÈëÄúµÄ¸ßĞÕ´óÃû£¬ÓÉÓÚÕâ¸öÃû×Ö´ú±íÄãµÄÈËÎï£¬¶øÇÒÒÔºó²»ÄÜ¸ü¸Ä£¬
Îñ±ØÉ÷ÖØÔñÃû£¨²»ÑÅ¹ÛµÄĞÕÃû½«±»É¾³ı£©¡£Áí£ºÇë²»ÒªÑ¡Ôñ½ğÓ¹Ğ¡ËµÖĞ
ÒÑÓĞÈËÎïĞÕÃû¡£

TEXT
	);
	write("ÄúµÄÖĞÎÄÃû×Ö£º");
	input_to("get_name", ob);
}

string display_attr(int gift)
{
	if (gift > 24) return HIY + gift + NOR;
	if (gift < 16) return RED + gift + NOR;
	return "" + gift;
}

void get_name(string arg, object ob)
{
        arg = CONVERT_D->input(arg,ob);

	if( !check_legal_name(arg) ) {
		write("ÄúµÄÖĞÎÄÃû×Ö£º");
		input_to("get_name", ob);
		return;
	}
	printf("%O\n", ob);
	ob->set("name", arg);
	write("ÇëÉè¶¨ÄúµÄÃÜÂë£º");
	input_to("new_password", 1, ob);
}

void new_password(string pass, object ob)
{
	write("\n");
	if( strlen(pass)<5 ) {
		write("ÃÜÂëµÄ³¤¶ÈÖÁÉÙÒªÎå¸ö×ÖÔª£¬ÇëÖØÉèÄúµÄÃÜÂë£º");
		input_to("new_password", 1, ob);
		return;
	}
	ob->set("password", crypt(pass,0) );
	write("ÇëÔÙÊäÈëÒ»´ÎÄúµÄÃÜÂë£¬ÒÔÈ·ÈÏÄúÃ»¼Ç´í£º");
	input_to("confirm_password", 1, ob);
}

void confirm_password(string pass, object ob)
{
	string old_pass;
	write("\n");
	old_pass = ob->query("password");
	if( crypt(pass, old_pass)!=old_pass ) {
		write("ÄúÁ½´ÎÊäÈëµÄÃÜÂë²¢²»Ò»Ñù£¬ÇëÖØĞÂÉè¶¨Ò»´ÎÃÜÂë£º");
		input_to("new_password", 1, ob);
		return;
	}

	write(@TEXT

Ò»¸öÈËÎïµÄÌì¸³¶ÔÓÚËû»òËıËùĞŞÏ°µÄÎäÒÕÏ¢Ï¢Ïà¹Ø¡£ËæÔµÏ´½£Â¼ÖĞµÄÈËÎï´ó¶à¾ßÓĞ
ÒÔÏÂËÄÏîÌì¸³£º

       ¡î ëöÁ¦£ºÓ°Ïì¹¥»÷ÄÜÁ¦¼°¸ººÉÁ¿µÄ´óĞ¡¡£
       ¡î ÎòĞÔ£ºÓ°ÏìÑ§Ï°Îä¹¦ÃØ¼®µÄËÙ¶È¼°Àí½âÊ¦¸µµÄÄÜÁ¦¡£
       ¡î ¸ù¹Ç£ºÓ°ÏìÌåÁ¦»Ö¸´µÄËÙ¶È¼°Éı¼¶ºóËùÔö¼ÓµÄÌåÁ¦¡£
       ¡î Éí·¨£ºÓ°Ïì·ÀÓù¼°¶ã±ÜµÄÄÜÁ¦¡£
       ¡î ÓÂÆø£ºÓ°Ïì¶·Ö¾µÄËğÊ§ºÍ»Ö¸´ËÙ¶È¡£
	   Äú¿ÉÒÔ×Ô¼ºÖ¸¶¨ÆäÖĞÒ»ÏîµÄÖµ£¬»òÕßÊäÈë 0 ½»ÓÉÏµÍ³Ëæ»ú²úÉú¡£
	   ÇëÊäÈëÄúµÄÑ¡Ôñ(0-5)£º
TEXT);
		input_to("select_gift", ob);
}
void get_gift(string yn, object ob, mapping my, int select)
{
	if (yn[0] != 'y' && yn[0] != 'Y') {
		random_gift(my, select);
		printf("\nëöÁ¦[%s]£¬ÎòĞÔ[%s]£¬¸ù¹Ç[%s]£¬Éí·¨[%s]£¬ÓÂÆø[%s]\n",
			display_attr(my["str"]),
			display_attr(my["int"]),
			display_attr(my["con"]),
			display_attr(my["dex"]),
			display_attr(my["bac"]));
		write("ÄúÍ¬ÒâÕâÒ»×éÌì¸³Âğ£¿");
		input_to("get_gift", ob, my, select);
		return;
	}
	write("\nÄúµÄµç×ÓÓÊ¼şµØÖ·£º");
	input_to("get_email", ob, my);
}

void select_gift(string yn, object ob)
{
	int i;
	mapping my = ([]);
	if (!sscanf(yn, "%d", i) || i < 0 || i > 5) {
		write("\nÊäÈë´íÎó£¬ÇëÖØĞÂÑ¡Ôñ£º");
		input_to("select_gift", ob);
		return;
	}
	if (i) {
		write("\nÇëÊäÈëÄúÏëÒªµÄÊıÖµ(10-30)£º");
		input_to("set_gift", ob, my, i);
	} else get_gift(" ", ob, my, i);
}

void set_gift(string yn, object ob, mapping my, int select)
{
	int i;

	if (!sscanf(yn, "%d", i) || i < 10 || i > 30) {
		write("\nÊıÖµ´íÎó£¬ÇëÖØĞÂÊäÈë£º");
		input_to("set_gift", ob, my, select);
		return;
	}
	switch (select) {
		case 1: my["str"] = i; break;
		case 2: my["int"] = i; break;
		case 3: my["con"] = i; break;
		case 4: my["dex"] = i; break;
		case 5: my["bac"] = i;
	}
	get_gift(" ", ob, my, select);
}
void get_email(string email, object ob, mapping my)
{
	object user;
	string id,address;	

	write("\n");
	if (email == "" || strsrch(email, "@") == -1||
		sscanf(email,"%s@%s",id,address)!=2||strsrch(address,".")==-1)
	{
		write("µç×ÓÓÊ¼şµØÖ·ĞèÒªÊÇ id@address µÄ¸ñÊ½¡£\n");
		write("ÄúµÄµç×ÓÓÊ¼şµØÖ·£º");
		input_to("get_email", ob, my);
		return;
	}
	ob->set("email", email);
	ob->set("registered", 1);

	// If you want do race stuff, ask player to choose one here, then you can
	// set the user's body after the question is answered. The following are
	// options for player's body, so we clone a body here.
	ob->set("body", USER_OB);
	if( !objectp(user = make_body(ob)) )
		return;
	user->set("str", my["str"]);
	user->set("dex", my["dex"]);
	user->set("con", my["con"]);
	user->set("bac", my["bac"]);	
	user->set("int", my["int"]);
	user->set("kar", my["kar"]);
	user->set("per", my["per"]);
	ob->set("registered", 1);
	user->set("registered", 1);

	write("ÄúÒª°çÑİÄĞĞÔ(m)µÄ½ÇÉ«»òÅ®ĞÔ(f)µÄ½ÇÉ«£¿");
	input_to("get_gender", ob, user);
}

void get_gender(string gender, object ob, object user)
{
	write("\n");
	if( gender=="" ) {
		write("ÄúÒª°çÑİÄĞĞÔ(m)µÄ½ÇÉ«»òÅ®ĞÔ(f)µÄ½ÇÉ«£¿");
		input_to("get_gender", ob, user);
		return;
	}

	if( gender[0]=='m' || gender[0]=='M' )
		user->set("gender", "ÄĞĞÔ");
	else if( gender[0]=='f' || gender[0]=='F' )
		user->set("gender", "Å®ĞÔ" );
	else {
		write("¶Ô²»Æğ£¬ÄúÖ»ÄÜÑ¡ÔñÄĞĞÔ(m)»òÅ®ĞÔ(f)µÄ½ÇÉ«£º");
		input_to("get_gender", ob, user);
		return;
	}

	log_file( "USAGE", sprintf("%s%s was created from %s (%s)\n", user->query("name"), "(" + user->query("id") + ")" ,
		query_ip_name(ob), ctime(time()) ) );
	init_new_player(user);
	license(ob, user);
	write("\n");
}

object make_body(object ob)
{
	string err;
	object user;

	user = new(ob->query("body"));
	if(!user) {
		write("ÏÖÔÚ¿ÉÄÜÓĞÈËÕıÔÚĞŞ¸ÄÊ¹ÓÃÕßÎï¼şµÄ³ÌÊ½£¬ÎŞ·¨½øĞĞ¸´ÖÆ¡£\n");
		write(err+"\n");
		return 0;
	}
	seteuid(ob->query("id"));
	export_uid(user);
	export_uid(ob);
	seteuid(getuid());
	user->set("id", ob->query("id"));
	user->set_name( ob->query("name"), ({ ob->query("id")}) );
	return user;
}

void init_new_player(object user)
{
	user->set("title", "ÆÕÍ¨°ÙĞÕ");
	user->set("birthday", time() );
	user->set("newbie",1);
        user->set("potential", 99);
	user->set("food", (user->query("str")+10) *10 );
	user->set("water", (user->query("str")+10) *10 );

	user->set("channels", ({ "chat", "rumor","bidd", "ldj" }) );
}

varargs void license(object ob, object user)
{
	string *lognum;
	int i, login_num, login_num2;
	login_num = 0;

	if ( file_size(LOG_DIR + "loginnum") >=0 )
	{
		lognum = explode(read_file(LOG_DIR + "loginnum"), "\n");
		for(i=0; i<sizeof(lognum); i++) {
			if( lognum[i][0]=='#'
			|| sscanf(lognum[i], "%d", login_num2)!=1 ) continue;
			if ( i=1 ) login_num = login_num2;
		}
		rm(LOG_DIR + "loginnum");
		log_file( "loginnum", sprintf("%d\n", login_num + 1 ) );
	}

	if (ob->query("registered") == 0)
		write(read_file(UNREG_MOTD));
	else
		write(read_file(MOTD));

//        input_to( "to_enter", ob, user );
        enter_world(ob, user);
}

//added by bsd
int check_news(object me) 
{ 
  int num,i,last_time_read; 
  mapping *notes,last_read_time; 
  string myid,msg=""; 
  notes=query("notes"); 
  last_read_time=me->query("board_last_read"+(string)query("board_id")); 
  myid=query("board_id"); 
  if(!pointerp(notes)||!sizeof(notes)) return  1; 

  if(userp(me)) 
  { 
	i=sizeof(notes)-me->query("LastReadNews"); 

	if(i<6&&i>0)//Ğ¡ÓÚ6ÌõĞÂÎÅ²ÅÏÔÊ¾±êÌâ£¬²»È»»áFLOOD 
	{ 
	msg=HIC"\n¡Ô"HIY"©¤©¤©¤©¤ËæÔµÏ´½£Â¼×îĞÂÏûÏ¢©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤"HIC"¡Ô\n\n"NOR; 
 
	if(!mapp(last_read_time)||undefinedp(last_read_time[myid])) 
	num=1; 
 
       else 
	for(num=1;num<=sizeof(notes);num++) 
	  if(notes[num-1]["time"]>last_read_time[myid]) break; 
 
	if(mapp(last_read_time)) last_time_read=last_read_time[myid]; 
	for(i=sizeof(notes)-1;i>num-2;i--) 
	{ 
	 msg+=sprintf(HIY"¡¾"NOR"%3d"HIY"¡¿"NOR,i+1); 
	 msg+=sprintf("%-=25s%18s(%s)\n", 
	 notes[i]["title"],notes[i]["author"], 
	 ctime(notes[i]["time"])[0..9]);
     } 
 
	msg+=HIC"\n¡Ô"HIY"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤ËæÔµĞ¡ÁéÍ¨©¤©¤©¤©¤©¤"HIC"¡Ô"NOR; 
	me->start_more(msg); 
    } 
 
    i=sizeof(notes)-me->query("LastReadNews"); 
    if(i<0) i=0; 
    write(HIY"¡¾ËæÔµĞ¡ÁéÍ¨¡¿¸æËßÄú£º´ÓÄúÉÏ´ÎÊÕÌıµ½ÏÖÔÚ"+((i==0)?"Ã»ÓĞÈÎºÎ":"¹²ÓĞ"+WHT+chinese_number(i)+HIY"Ìõ")+"ĞÂÎÅ£¡\n"NOR); 
    if(i>10)write("Äã¿ÉÒÔHelp newsÀ´²é¿´¡¾ËæÔµĞ¡ÁéÍ¨¡¿µÄÊÕÌı·½·¨¡£\n");//ÌáĞÑ²»ÖªµÀÓĞNEWSÏµÍ³µÄÍæ¼ÒÊ¹ÓÃnews 
  } 
} 

varargs void to_enter(string arg, object ob, object user)
{
	enter_world(ob, user);
}

varargs void enter_world(object ob, object user, int silent)
{
	object cloth, box, weapon, token, card, armor,lp1,lp2;
	string startroom, *filename, id;
	string week,month;
	int day,hour,minute,second,year;
	int files_n;

	user->set_temp("link_ob", ob);
	ob->set_temp("body_ob", user);
	user->set("registered", ob->query("registered"));
	user->set_encoding(ob->query_encoding());
	exec(user, ob);

	write("\nÄ¿Ç°È¨ÏŞ£º" + wizhood(user) + "\n");
	user->setup();

	if (!user->query("food") && !user->query("water") && ob->query("age") == 14) {
		user->set("food", user->max_food_capacity());
		user->set("water", user->max_water_capacity());
	}

	// In case of new player, we save them here right aftre setup
	// compeleted.
	user->save();
	ob->save();

	if ( user->query_condition("autosave") )
	{
		user->clear_condition("autosave");
	}
	if (user->query("leader")==user->query("id")) {
		token = new("/u/yanzi/token");
		token->move(user);
	}
	if (user->query("weapon/type")) {
		switch((string)user->query("weapon/type"))
		{
			case "½£":
			weapon = new("/d/npc/m_weapon/weapon/m_sword");
			weapon->move(user);
			break;
			case "µ¶":
			weapon = new("/d/npc/m_weapon/weapon/m_blade");
			weapon->move(user);
			break;
			case "±Ş":
			weapon = new("/d/npc/m_weapon/weapon/m_whip");
			weapon->move(user);
			break;
			case "ÕÈ":
			weapon = new("/d/npc/m_weapon/weapon/m_staff");
			weapon->move(user);
			break;
			case "¹÷":
			weapon = new("/d/npc/m_weapon/weapon/m_club");
			weapon->move(user);
			break;
			default:
		}
	}

	if (user->query("created_item")) {
		id = user->query("id");
		filename = get_dir(DATA_DIR+"login/" + id[0..0] + "/" + id);
		for(files_n = 0; files_n < sizeof(filename); files_n++)
		{
			armor= new(DATA_DIR+"login/" + id[0..0] + "/" + id + "/" + filename[files_n]);
			armor->move(user);
		}
	}

	if (user->query("couple")) {
		card = new("/d/city/obj/marry_card");
		card->set("name","ÄãºÍ"+user->query("couple/couple_name")+"µÄ½á»éÖ¤");
		card->move(user);
	}

/*	if (!user->query("opend/ĞÂÄêºØËê¿¨")) {
	new("/u/tender/obj/card")->move(user);
	write("ĞÂÄê¿ìÀÖ£¡¹§Ï²ÄãµÃµ½ÁËËæÔµÏ´½£Â¼µÄĞÂÄêºØËê¿¨£¡\n");
	}
*/

//Ôö¼ÓÔªµ©µÄÀñÆ·£¬Ö»·¢Ò»Ìì
	sscanf(ctime(time()),"%s %s %d %d:%d:%d %d",week,month,day,hour,minute,second,year);
	if (year==1999 && day==24 && month=="dec" && user->query("shou-lp",1)!=1)
	{
		lp1=new("/u/byt/baowu/obj/bjitui");
		lp1->move(user);
		lp2=new("/u/byt/baowu/obj/bjiudai");
		lp2->move(user);

		write(HIR+"\t   ¹§Ï²¹§Ï²£¡ĞÂµÄÒ»ÄêÓÖµ½ÁË£¬×£ÄãĞÂÄêÓä¿ì£¡\n\n\t\t"+BLINK+"ĞÄÏëÊÂ³É£¡ÍòÊÂÈçÒâ£¡ÃÀÃÎ³ÉÕæ¡£\n\n"NOR);		write(HIG"\t ÓÖµ½ÁËÒ»ÄêÒ»¶ÈµÄÔªµ©½ÚÁË£¬ÎÒÃÇÓĞÒ»µãĞ¡ÀñÎï\n\t\t   ËÍ¸øÄã£¬ÇëÄã²éÊÕÒ»ÏÂ¡£\n"NOR);
		user->set("shou-lp",1);
	}

//Ôö¼ÓÔªµ©µÄÀñÆ·£¬Ö»·¢Ò»Ìì

	cloth = new("/clone/misc/cloth");
	cloth->move(user);
	cloth->wear();
	box = new("/clone/misc/mailbox");
	box->move(user);

	if( box->query("new_mail") ) {
		write( HIY + "\nÓĞÄúµÄĞÅ£¡Çë²é¿´ÄúµÄĞÅÏä¡£\n\n" + NOR);
		box->set("new_mail", 0);
		box->save();
	}

	if( !silent )
	{
		if( !user->is_ghost()&&user->query("newbie")&&!ob->query("zhuce"))
		{
			startroom = NEW_PLAYER_START;
		}
		else
		if( user->is_ghost() )
		{
			startroom = DEATH_ROOM;
		}
		else
		if( !stringp(startroom = user->query("startroom")))
		{
			write("ÇëÄúÏÈµ½×¢²á´¦°É£¡\n");
			startroom = NEW_PLAYER_START;
		}
		if ( wiz_level( user->query("id") ) > 1 )
		{
			user->move(WIZ_START_ROOM);
			CHANNEL_D->do_channel( user, "wiz*",
			sprintf("Á¬Ïß½øÈë"+CHINESE_MUD_NAME+"¡£") );
		}
		else
		{
			if(stringp(user->query("startroom")))
				startroom=user->query("startroom");
			if( !catch(load_object(startroom)) )
				user->move(startroom);
			else
			{
				user->move(START_ROOM);
				startroom = START_ROOM;
				user->set("startroom", START_ROOM);
			}
			tell_room(startroom, user->query("name") + "Á¬Ïß½øÈëÕâ¸öÊÀ½ç¡£\n",({user}));
		}
	}
	if( !silent || !wizardp(user) ) {
		CHANNEL_D->do_channel( this_object(), "sys",
			sprintf("%s(%s)ÓÉ%sÁ¬Ïß½øÈë¡£", user->name(), user->query("id"), query_ip_name(user)) );
         user->set_temp("temp_exp",user->query("combat_exp"));
	user->set_temp("temp_time",time());
                        TOPTEN_D->topten_checkplayer(user);
	}
}


varargs void reconnect(object ob, object user, int silent)
{
	user->set_temp("link_ob", ob);
	ob->set_temp("body_ob", user);
	user->set_encoding(ob->query_encoding());
	exec(user, ob);

	user->reconnect();
	if( !silent ) {
		    message_vision(HIW"$NÖØĞÂÁ¬Ïß»Øµ½"HIG"Õâ¸öÊÀ½ç¡£\n"NOR, user);
	}
	CHANNEL_D->do_channel( this_object(), "sys",
		sprintf("%s(%s)ÓÉ%sÖØĞÂÁ¬Ïß½øÈë¡£", user->query("name"), user->query("id"), query_ip_name(user)) );
}

int check_legal_id(string id)
{
	int i;

	i = strlen(id);

	if( (strlen(id) < 3) || (strlen(id) > 12 ) ) {
		write("¶Ô²»Æğ£¬ÄãµÄÓ¢ÎÄÃû×Ö±ØĞëÊÇ 3 µ½ 12 ¸öÓ¢ÎÄ×ÖÄ¸¡£\n");
		return 0;
	}
	while(i--)
		if( id[i]<'a' || id[i]>'z' ) {
			write("¶Ô²»Æğ£¬ÄãµÄÓ¢ÎÄÃû×ÖÖ»ÄÜÓÃÓ¢ÎÄ×ÖÄ¸¡£\n");
			return 0;
		}

	return 1;
}

int check_legal_name(string name)
{
	int i;

	i = strlen(name);

	if( (strlen(name) < 2) || (strlen(name) > 8 ) ) {
		write("¶Ô²»Æğ£¬ÄãµÄÖĞÎÄÃû×Ö±ØĞëÊÇ 1 µ½ 4 ¸öÖĞÎÄ×Ö¡£\n");
		return 0;
	}
	while(i--) {
		if( name[i]<=' ' ) {
			write("¶Ô²»Æğ£¬ÄãµÄÖĞÎÄÃû×Ö²»ÄÜÓÃ¿ØÖÆ×ÖÔª¡£\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) ) {
			write("¶Ô²»Æğ£¬ÇëÄúÓÃ¡¸ÖĞÎÄ¡¹È¡Ãû×Ö¡£\n");
			return 0;
		}
	}

	if ( file_size(CONFIG_DIR + "banned_name") >=0 )
	{
		banned_name = explode(read_file(CONFIG_DIR + "banned_name"), "\n");
	}
	else
	{
		i = sizeof(banned_name);
		while(i--)
		{
			write_file(CONFIG_DIR + "banned_name", banned_name[i] + "\n", 0);
		}
	}

	if( member_array(name, banned_name)!=-1 ) {
		write("¶Ô²»Æğ£¬ÕâÖÖÃû×Ö»áÔì³ÉÆäËûÈËµÄÀ§ÈÅ¡£\n");
		return 0;
	}

	return 1;
}

object find_body(string name)
{
	object ob, *body;

	if( objectp(ob = find_player(name)) )
		return ob;
	body = children(USER_OB);
	for(int i=0; i<sizeof(body); i++)
		if( clonep(body[i])
		&&      getuid(body[i]) == name ) return body[i];

	return 0;
}

int set_wizlock(int level)
{
	if( wiz_level(this_player(1)) <= level )
		return 0;
	if( geteuid(previous_object()) != ROOT_UID )
		return 0;
	wiz_lock_level = level;
	return 1;
}
