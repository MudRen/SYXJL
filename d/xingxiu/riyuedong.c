// riyuedong.c ���¶�
// by QingP

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "���¶�");
        set("long", @LONG
�������������ܶ����ڵ����¶������ڵƻ�ͨ��������һ�ѻ�Ƥ���϶�����
�����������˶����������װ���Ż�Ƥ��¹ͷ�����𣬼�һЩ�ֻ�(zihua)��
���������������ܣ��������еĴ���Ǹ��ֹ�����
LONG
        );
        set("exits", ([
             "south" : __DIR__"xxh2",
        ]));

        set("item_desc", ([
                "zihua" : "\n\n"

HIY"		����������������������������������\n"NOR
HIY"		����������������������������������\n"NOR
HIY"		����������"HIG"�š������¡��ǡ�"HIY"��������\n"NOR
HIY"		����������"HIG"�����䡡�ޡ�"HIY"��������\n"NOR
HIY"		����������"HIG"�ޡ�御��졡�ϡ�"HIY"��������\n"NOR
HIY"		����������"HIG"�ȡ���ء��ɡ�"HIY"��������\n"NOR
HIY"		����������������������������������\n"NOR
HIY"		����������������������������������\n\n"NOR

        ]) );

        set("objects", ([
                "/kungfu/class/xingxiu/ding" : 1,
                __DIR__"npc/dizi" : 2,
                 "/kungfu/class/xingxiu/tianlang" : 1,
        ]) );

        set("no_clean_up", 0);

        set("coor/x",-120);
	set("coor/y",70);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",70);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",70);
	set("coor/z",0);
	set("coor/x",-120);
	set("coor/y",70);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}
