// 修改by think

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "比武场贵宾席");
	set("long", @LONG
这里是比武场的贵宾席，几张紫檀太师椅排成一行，每张太师椅上面
都披着一张虎皮。只有巫师有资格坐在这里。
LONG);
	set("no_fight",1);
	set("exits", ([
		"south" : __DIR__"biwutai",
		"down" : __DIR__"houtai",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
        object tai=load_object(__DIR__"biwutai");
        object *inv=all_inventory(tai);
	object ob, where;
        int i=sizeof(inv);

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);

	if ( !wizardp(me) && dir=="south" ) {
		if( ob->query("start/start") && !me->query("biwu_fighter") )
			return notify_fail("比武已经开始了，你不是选手不能上台。\n");
		if(i>=2)
			return notify_fail("比武台上已经有两名选手，你现在不能上台。\n");
	}
        return ::valid_leave(me, dir);
}

void init()
{
//	add_action ("do_start","start");
	add_action ("do_urged","urged");
	add_action ("do_check","check");
	add_action ("do_next","next");
	add_action ("do_xsave","xsave");
	add_action ("do_work","quit");
}

int do_urged()
{
	object where, ob, ob1, ob2;
	string id1, id2;

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);

	if(!ob->query("start"))
		return notify_fail("比武尚未开始啊！\n");

	id1=ob->query("start/biwu_fighter1");
	id2=ob->query("start/biwu_fighter2");

	if(id1) ob1=find_player(id1);
	if(id2) ob2=find_player(id2);

	if(!ob1) ob->keep_biwu(id2);
	if(!ob2) ob->keep_biwu(id1);

	message_vision(CYN"$N把"+ob1->query("name")+"和"+
		ob2->query("name")+"一脚踹上比武台！\n"NOR, this_player());
	if(environment(ob1)->query("short")!="比武大擂台") {
		message_vision (CYN"公平子一脚把"+ob1->query("name")+
		"踹上比武台，嘴里嘟哝着：怎么拖拖拉拉的！\n"NOR, ob1);
		ob1->move(__DIR__"biwutai");
	}
	if(environment(ob2)->query("short")!="比武大擂台") {
		message_vision (CYN"公平子一脚把"+ob2->query("name")+
			"踹上比武台，嘴里嘟哝着：怎么拖拖拉拉的！\n"NOR, ob2);
		ob2->move(__DIR__"biwutai");
	}
	return 1;
}

int do_start(string arg)
{
	object where, ob;

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);
	if(!arg)
		return notify_fail("你要开始什么？？！\n");
	ob->do_start(arg);
	return 1;
}

int do_check()
{
	object where, ob;
	object me=this_player();
	int i, j, k, a, b, c;
	string arg, id, msg, *str, *menpai;

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);
	i=ob->query("biwudahui");
	j=ob->query("start/lunxu");
	k=(ob->query("start/huihe")-1);
	arg=ob->query("start/start");
	menpai=ob->query("fenzu");

	if(!arg)
		return notify_fail("目前还没有开始比武！\n");

	if(arg=="xunhuan") {
		message_vision(WHT"第"+CHINESE_D->chinese_number(i)+"届比武大会！\n"NOR, me);
	} else {
		message_vision(WHT"正在进行"MAG+arg+WHT"掌门大弟子选拔比武！\n"NOR, me);
	}

	message_vision (WHT"第"+CHINESE_D->chinese_number(j)+"轮！\n"NOR, me);

	for(a=1; a<(sizeof(menpai)+1); a++) {
		msg=WHT"第"+CHINESE_D->chinese_number(a)+"组：";
		str=ob->query("fenzu/"+a+"/");
		for(b=1; b<(sizeof(str)+1); b++) {
			id=ob->query("fenzu/"+a+"/"+b+"");
			c=ob->query("jifen/"+id);
			msg+="("+id+") 积分=="+c+"\t";
		}
		message_vision (WHT""+msg+"\n"NOR, me);
	}
	message_vision (WHT"\n现在进行到第"+CHINESE_D->chinese_number(k)+"回合！\n"NOR, me);
	return 1;
}

int do_xsave()
{
	object where, ob, me;
	me=this_player();
	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);
	message_vision (CYN"比武进度储存完毕！\n"NOR, me);
	ob->save();
	return 1;
}

int do_next(string arg)
{
	object where, ob, me;
	me=this_player();
	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);
	message_vision (CYN"继续进行下一轮比武！\n"NOR, me);
	if(!arg) {
		ob->keep_biwu("adx");
	}
		ob->keep_biwu(arg);
	return 1;
}

int do_work()
{
	write("这里不能使用这个指令！\n");
	return 1;
}
