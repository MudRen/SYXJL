// wizard_room.c ��ʦ��Ϣ��
// writed by shadow

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC "��ʦ��Ϣ��" NOR );
        set("long",
"������ǡ�"HIB"��Եϴ��¼"NOR"����ʦ����Ϣ���ڣ��շ�ˢ��������ǽ��\n"
"�Ϲ�ͺͺ��ʲô��û�У����ӵ����������һ���ľ�����������һ����\n"
"ʦ���Բ�(board)��\n"
HIR"WIZ�������κ��˲����������Ҹ������ݣ�Υ��PURGE��\n"
"         ˽�Ը��������Ʒ��й©�����ߣ�����������\n"NOR);
        set("valid_startroom", 1);
        set("no_fight", "1");
        set("no_clean_up", 0);


        set("exits", ([
                "up" : __DIR__"arch_room",
//              "enter" : "/adm/room/meeting_room",
                "down" : __DIR__"guest_room",
        ]));

        set("coor/x",-20);
        set("coor/y",30);
        set("coor/z",10);
        set("coor/x",-20);
        set("coor/y",30);
        set("coor/z",10);
        set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",10);
	setup();

        call_other("/clone/board/wiz_b", "???");
}

void init()
{
        object ob=this_player();
        if ( !wizardp(ob) && wizhood(ob) !="(immortal)" )
        {
                ob->move(__DIR__"guest_room");
                return;
        }
}




