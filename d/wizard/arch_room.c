
#include <ansi.h>
#include <command.h>

inherit ROOM;

int do_start();
int do_say(string msg);
int do_over();

private string filename;

void create()
{
        set("short", "会议室");
        set("long", 
"这是一间宽敞的会议室，里面静悄悄的，只听见窗外杨柳轻击窗梁的\n"
"声音。这时不断走来三两个人，围着圆桌坐了下来，原来是"+MUD_NAME+
"\n的巫师门正前来开会。墙上订着个便筏(pad)。\n");
        set("item_desc", ([
                "pad" : "\n会议室的使用方法：\n"
"start  :       开始会议。\n"
"over :         结束会议。\n\n"
        ]));
        set("exits", ([
                "down" : __DIR__"wizard_room", ])
        );
        set("objects", ([
                "/adm/object/bm" : 1,
        ]));

        set("coor/x",-20);
        set("coor/y",30);
        set("coor/z",20);
        set("coor/x",-20);
        set("coor/y",30);
        set("coor/z",20);
        set("coor/x",-20);
        set("coor/y",30);
        set("coor/z",20);
        
        set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",20);
	setup();
}

void init()
{
        add_action("do_say", "say");
        add_action("do_say", "'");
        add_action("do_start", "start");
        add_action("do_over", "over");
}

int do_start()
{
	string str;
        object* ob,me;
        int i;
        me = this_player();
        if(wiz_level(me) < wiz_level("(arch)"))
          return notify_fail("对不起，您无权召开巫师会议。\n");

        if ( (int)query("meeting_trigger") != 0 )
                return notify_fail("会议正在进行中。\n");

        set("meeting_trigger", 1);

        ob = users();
        for ( i=sizeof(ob); i>0; i-- ) {
                if( wiz_level(ob[i-1]) < 1) continue;

                tell_object(ob[i-1],
                sprintf(GRN"%s(%s)告诉你：巫师会议现在召开，请到巫师会议室开会。\n"NOR, 
                        me->query("name"),me->query("id")) );
                ob[i-1]->move("/d/wizard/mtr");
                message_vision("$N到了。\n",ob[i-1]);
        }
        str = me->query("id");
        if( !str )
                return notify_fail("Put meeting record to where??\n");

        message_vision(HIW"\n$N大声宣布：“会议现在开始。\n"NOR, me);
        filename = "meeting/" + str;
        return 1;
}

int do_say(string msg)
{
        if( !msg ) return 0;
        else
        "/cmds/std/say.c"->main(this_player(), msg);
        if ((int)query("meeting_trigger") == 1)
        log_file(filename,sprintf("%s(%s)：" + msg + "\n",this_player()->name(1),this_player()->query("id")) );
        return 1;
}

int do_over()
{
        if( !wizardp(this_player()) )
                return notify_fail("你没有权力终止会议。\n");
        if ( (int)query("meeting_trigger") == 0 )
                return notify_fail("现在没有进行任何会议。\n");

        delete("meeting_trigger");
        message_vision(HIW"\n$N大声宣布：“会议现在结束。”\n"NOR, this_player());
        return 1;
}
