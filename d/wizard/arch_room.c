
#include <ansi.h>
#include <command.h>

inherit ROOM;

int do_start();
int do_say(string msg);
int do_over();

private string filename;

void create()
{
        set("short", "������");
        set("long", 
"����һ����Ļ����ң����澲���ĵģ�ֻ���������������������\n"
"��������ʱ���������������ˣ�Χ��Բ������������ԭ����"+MUD_NAME+
"\n����ʦ����ǰ�����ᡣǽ�϶��Ÿ��㷤(pad)��\n");
        set("item_desc", ([
                "pad" : "\n�����ҵ�ʹ�÷�����\n"
"start  :       ��ʼ���顣\n"
"over :         �������顣\n\n"
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
          return notify_fail("�Բ�������Ȩ�ٿ���ʦ���顣\n");

        if ( (int)query("meeting_trigger") != 0 )
                return notify_fail("�������ڽ����С�\n");

        set("meeting_trigger", 1);

        ob = users();
        for ( i=sizeof(ob); i>0; i-- ) {
                if( wiz_level(ob[i-1]) < 1) continue;

                tell_object(ob[i-1],
                sprintf(GRN"%s(%s)�����㣺��ʦ���������ٿ����뵽��ʦ�����ҿ��ᡣ\n"NOR, 
                        me->query("name"),me->query("id")) );
                ob[i-1]->move("/d/wizard/mtr");
                message_vision("$N���ˡ�\n",ob[i-1]);
        }
        str = me->query("id");
        if( !str )
                return notify_fail("Put meeting record to where??\n");

        message_vision(HIW"\n$N�������������������ڿ�ʼ��\n"NOR, me);
        filename = "meeting/" + str;
        return 1;
}

int do_say(string msg)
{
        if( !msg ) return 0;
        else
        "/cmds/std/say.c"->main(this_player(), msg);
        if ((int)query("meeting_trigger") == 1)
        log_file(filename,sprintf("%s(%s)��" + msg + "\n",this_player()->name(1),this_player()->query("id")) );
        return 1;
}

int do_over()
{
        if( !wizardp(this_player()) )
                return notify_fail("��û��Ȩ����ֹ���顣\n");
        if ( (int)query("meeting_trigger") == 0 )
                return notify_fail("����û�н����κλ��顣\n");

        delete("meeting_trigger");
        message_vision(HIW"\n$N�������������������ڽ�������\n"NOR, this_player());
        return 1;
}
